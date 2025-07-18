# Makefile for 2D pixel renderer

# Compiler and flags
CC = gcc #compiler 
CFLAGS = -Wall -std=c11 `sdl2-config --cflags` #-Wall  enable all warnings,-std=C11  c version 11, sdl config flag
LDFLAGS = `sdl2-config --libs` # library flags

# Target binary name
TARGET = renderer # binary generated from compiling

# Source files
SRC = main.c # main source code file

# Build rule
all: $(TARGET) #targets for compiling are specified with all

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

# Clean rule
clean:
	rm -f $(TARGET)

