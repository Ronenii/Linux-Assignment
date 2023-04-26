# Compiler and flags
.DEFAULT_GOAL := all
CC = g++
CFLAGS = -fPIC -Wall -Wextra -std=c++17

# Linker flags
LDFLAGS = -L./lib -Ilib -Wl,-rpath='pwd'

# Directories
SRCDIR = src		# Source files directory
LIBDIR = lib		# Shared library files directory
OBJDIR = obj		# Object files directory

# File Names
LIB = libshared_library.so	# name of shared library.


# Array of the source files of the programs.
SRCS := $(wildcard $(SRCDIR)/*.cpp)

# Array of the source files of the shared library.
LIBS := $(wildcard $(LIBDIR)/*.cpp)

# Array of all corresponding object files created from the source files.
#OBJS := $(addprefix $OBJDIR/,$(patsubst %.cpp,%.o,$SRCS))
PROG_OBJS := $(patsubst %.cpp,%.o,$(SRCS))
LIB_OBJS := $(patsubst %.cpp,%.o,$(LIBS))

# Default target
.PHONY: all clean
all: $(PROG_OBJS)

# Rule for compiling source files:
%.o : %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

# Rule for making the .out files:
%.out : %.o
	$(CC) $^ -o $@ $(LDFLAGS) $(LIB)

# Rule for creating the shared library:
$(LIB) : $(LIBS)
	$(CC) -shared -fPIC $(CFLAGS) &< -o $@

# Remove object files and programs
clean:
	rm -rf $(OBJDIR)							# Delete objects directory (with the files within it)
	find . -name "*.out" -exec rm -rf {} \; 	# Delete .out files.
	find . -name "*.so" -exec rm -rf {} \;		# Delete .so shared library file.