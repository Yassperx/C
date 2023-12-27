CC = gcc
CFLAGS = -Isrc/include
LIBS = -lSDL2main -lSDL2

all: main

main: main.c
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

.PHONY: clean
clean:
	@rm -f main
