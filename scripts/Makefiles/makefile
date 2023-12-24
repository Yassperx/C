CFLAGS = -Wno-implicit-function-declaration

all: final

final: main.o hello.o
	@gcc $(CFLAGS) main.o hello.c -o final
	@chmod +x final

main.o: main.c
	@gcc $(CFLAGS) -c main.c

hello.o: hello.c 
	@gcc $(CFLAGS) -c hello.c

clean:
	@rm main.o hello.o final
