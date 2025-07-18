CC = gcc
CFLAGS = -Wall -std=c11
LDFLAGS = -lX11

TARGET = renderer
SRC = main.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

clean:
	rm -f $(TARGET)

