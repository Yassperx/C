# Makefile for GTK application
%: %.c
	gcc $(shell pkg-config --cflags gtk4) -o $@ $< $(shell pkg-config --libs gtk4)

clean:
	rm -f main
