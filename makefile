# makefile

all: szyfrowanie

szyfrowanie: szyfrowanie.o konsola.o
	gcc szyfrowanie.o konsola.o -o szyfrowanie

szyfrowanie.o: szyfrowanie.c
	gcc -c szyfrowanie.c

konsola.o: konsola.c
	gcc -c konsola.c 

clean: 
	@rm -rf *.o szyfrowanie

