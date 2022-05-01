ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif

CC := g++
CFLAGS := -g -Wall

TARGET = mazeGenerator

all: $(TARGET)


$(TARGET):
	$(CC) $(CFLAGS) -Isrc src/cell.cc src/grid.cc src/main.cc -o $(TARGET) -lncurses

clean:
	$(RM) $(TARGET)

.PHONY: $(TARGET) clean


install: 
	install -m 0755 mazeGenerator $(PREFIX)/bin
