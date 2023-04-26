# Compiler and flags

CC = g++
CFLAGS = -fPIC -std=c++17

# Linker flags
LDFLAGS = -L. -I./lib -lshared_library -Wl,-rpath=$(PWD)

# Directories
SRCDIR=src# Source files directory
LIBDIR=lib# Shared library files directory
OBJDIR=obj# Object files directory
PARENT_DIR := .# path from root to the parent directory

# File Names
LIB = libshared_library.so	# name of shared library.


# Array of the source files of the shared library.
LIB_SRCS := $(wildcard $(LIBDIR)/*.cpp)

# Create corresponding object files from shared library source files.
LIB_OBJS := $(LIB_SRCS:.cpp=.o)


# Array of the source files of the programs.
PROG_SRCS := $(wildcard $(SRCDIR)/*.cpp)

# Create out files from corresponding programs' source files.
PROG_OBJS := $(patsubst %.cpp,%.out,$(PROG_SRCS))


# Default target
.PHONY: all clean
all: $(LIB) $(PROG_OBJS) out_move obj_move

# Rule for creating the shared library:
$(LIB) : $(LIB_OBJS)
	$(CC) -shared -fPIC -o $@ $^

# Rule for compiling source files:
%.o : %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

# Rule for making the .out files:
%.out : %.o
	$(CC) $^ -o $@ $(LDFLAGS) $(LIB)

# Rule to move a .out file to the parent directory.
out_move:
	mv ./$(SRCDIR)/*.out $(PARENT_DIR)

# Rule to move a .out file to the obj directory.
# 	create obj directory if doesn't already exists,
# 	move .obj files to it.
obj_move:
	mkdir -p obj
	mv ./$(LIBDIR)/*.o $(PARENT_DIR)/$(OBJDIR)

# Clean up- remove .obj/.out/.so files.
# 1.	Delete objects directory (with the files within it)
# 2.	Delete .out files.
# 3.	Delete .so shared library file.
clean:
	rm -rf $(OBJDIR)
	find . -name "*.out" -exec rm -rf {} \;
	find . -name "*.so" -exec rm -rf {} \;