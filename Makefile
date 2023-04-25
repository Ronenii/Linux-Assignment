# Compiler and flags
CC = g++
CFLAGS = -Wall -Wextra -std=c++11

# Linker flags
LDFLAGS = -L./objects -lutils

# Directories
SRCDIR = src
LIBDIR = lib
OBJDIR = objects
EXEDIR = executables

# Programs to compile
PROGRAMS = $(EXEDIR)/program1.out $(EXEDIR)/program2.out $(EXEDIR)/program3.out $(EXEDIR)/program4.out

# Default target
.PHONY: all clean
all: $(PROGRAMS)

# Compile object files from source files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Link program1.out
$(EXEDIR)/program1.out: $(OBJDIR)/program1.o
	$(CC) $< $(LDFLAGS) -o $@

# Link program2.out
$(EXEDIR)/program2.out: $(OBJDIR)/program2.o
	$(CC) $< $(LDFLAGS) -o $@

# Link program3.out
$(EXEDIR)/program3.out: $(OBJDIR)/program3.o
	$(CC) $< $(LDFLAGS) -o $@

# Link program4.out
$(EXEDIR)/program4.out: $(OBJDIR)/program4.o
	$(CC) $< $(LDFLAGS) -o $@

# Remove object files and programs
clean:
	rm -f $(OBJDIR)/*.o $(PROGRAMS)