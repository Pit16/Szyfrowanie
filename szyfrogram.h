//szyfrogram.h

typedef struct {
	int liczba_znakow;
	int* ciag_znakow;
	int klucz;		// odpowiednia liczba pierwsza z przedzialu (120;150)
	char* wiadomosc;
}szyfrogram;
