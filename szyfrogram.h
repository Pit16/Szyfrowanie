//szyfrogram.h
#ifndef SZYFROGRAM_H
#define SZYFROGRAM_H

typedef struct {
	int liczba_znakow;		// liczba liczb trzycyfrowych w tym szyfrogramie
	int* ciag_znakow;
	int klucz;		// odpowiednia liczba pierwsza z przedzialu (120;150)
	char* wiadomosc;
} szyfrogram;

#endif	//SZYFROGRAM_H
