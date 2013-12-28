# makefile

all: szyfrowanie

szyfrowanie: szyfrowanie.c
	gcc szyfrowanie.c -o szyfrowanie

clean: 
	@rm szyfrowanie.exe