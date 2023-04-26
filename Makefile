# Compiler and flags
export LD_LIBRARY_PATH := $(LD_LIBRARY_PATH):./lib

CC = g++
CFLAGS = -fPIC -Wall -std=c++17

# Linker flags
LDFLAGS = -L. -I./lib -lshared_library -Wl,-rpath=$(PWD)

# Directories
SRCDIR=src# Source files directory
LIBDIR=lib# Shared library files directory
OBJDIR=obj# Object files directory

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
all: $(LIB)

# Rule for creating the shared library:
$(LIB) : $(LIB_OBJS)
	$(CC) -shared -fPIC -o $@ $^

# Rule for compiling source files:
%.o : %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

# Rule for making the .out files:
%.out : %.o
	$(CC) $^ -o $@ $(LDFLAGS) $(LIB)

# Remove object files and programs
clean:
	rm -rf $(OBJDIR)							# Delete objects directory (with the files within it)
	find . -name "*.out" -exec rm -rf {} \; 	# Delete .out files.
	find . -name "*.so" -exec rm -rf {} \;		# Delete .so shared library file.