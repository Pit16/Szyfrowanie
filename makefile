# makefile

all: szyfrowanie

szyfrowanie: szyfrowanie.o konsola.o lamanie_kodu.o deszyfrowanie.o pliki.o
	gcc szyfrowanie.o konsola.o lamanie_kodu.o deszyfrowanie.o pliki.o -o szyfrowanie
	
szyfrowanie.o: szyfrowanie.c
	gcc -c szyfrowanie.c
	
konsola.o: konsola.c
	gcc -c konsola.c
	
lamanie_kodu.o: lamanie_kodu.c
	gcc -c lamanie_kodu.c
	
deszyfrowanie.o: deszyfrowanie.c
	gcc -c deszyfrowanie.c
	
pliki.o: pliki.c
	gcc -c pliki.c

clean: 
	@rm szyfrowanie.exe