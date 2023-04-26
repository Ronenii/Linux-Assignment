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
# Searches from the in LIBDIR directory.
LIB_SRCS := $(wildcard $(LIBDIR)/*.cpp)

# Create corresponding object files from shared library source files.
# Takes the cpp files from LIBDIR directory and creates corresponding object files in the OBJDIR directory.
LIB_OBJS := $(patsubst $(LIBDIR)/%.cpp,$(OBJDIR)/%.o,$(LIB_SRCS)) #$(LIB_SRCS:.cpp=.o)


# Array of the source files of the programs.
# Searches for them in SRCDIR directory.
PROG_SRCS := $(wildcard $(SRCDIR)/*.cpp)

# Create out files from corresponding programs' source files.
# Takes the cpp files from SRCDIR directory and creates corresponding out files in the root directory.
PROG_OBJS := $(patsubst $(SRCDIR)/%.cpp,%.out,$(PROG_SRCS))


# Default target
.PHONY: all clean
all: $(LIB) $(PROG_OBJS)

# Rule for creating the shared library:
$(LIB) : $(LIB_OBJS)
	$(CC) -shared -fPIC -o $@ $^

# Rule for compiling source files for the shared library:
$(OBJDIR)/%.o : $(LIBDIR)/%.cpp
	mkdir -p obj
	$(CC) -c $(CFLAGS) $< -o $@

# Rule for compiling source files for the programs:
$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	mkdir -p obj
	$(CC) -c $(CFLAGS) $< -o $@

# Rule for making the .out files for the programs:
%.out : $(OBJDIR)/%.o
	$(CC) $^ -o $@ $(LDFLAGS) $(LIB)

# Rule to prevent the makefile from deleting the "intermediate" object files:
.PRECIOUS: $(OBJDIR)/%.o


# Clean up- remove .obj/.out/.so files.
# 1.	Delete objects directory (with the files within it)
# 2.	Delete .out files.
# 3.	Delete .so shared library file.
clean:
	rm -rf $(OBJDIR)
	find . -name "*.out" -exec rm -rf {} \;
	find . -name "*.so" -exec rm -rf {} \;