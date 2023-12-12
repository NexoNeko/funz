CC = gcc
CFLAGS = $(shell pkg-config --cflags gtk4)
LIBS = $(shell pkg-config --libs gtk4)
TARGET = test
SRC = test.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LIBS)

clean:
	rm -f $(TARGET)

