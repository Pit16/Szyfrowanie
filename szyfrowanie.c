//szyfrowanie.c
#include <stdio.h>
#include <stdlib.h>
#include "szyfrogram.h"
#include "konsola.h"
#include "deszyfrowanie.h"
#include "lamanie_kodu.h"

void czysc_wszystko(szyfrogram**, int);
void czysc_szyfrogram(szyfrogram*);

int main ()
{
	printf("Program do lamania kodu.\n");
	int liczba_ciagow=pobierz_liczbe_ciagow();
	szyfrogram** tablica_szyfrogramow= (szyfrogram**) malloc(liczba_ciagow);
	pobierz_szyfrogramy(tablica_szyfrogramow, liczba_ciagow);
	int i=0;
	while(i<liczba_ciagow)
	{
		szyfrogram* nowy_szyfrogram=tablica_szyfrogramow[i];
		szukanie_klucza(nowy_szyfrogram);
		char* wiadomosc = deszyfrowanie_wiadomosci(nowy_szyfrogram);
		printf("%s\n", wiadomosc);
		i++;
	}

	czysc_wszystko(tablica_szyfrogramow, liczba_ciagow);
	return 0;
}
void czysc_wszystko(szyfrogram** tablica_szyfrogramow, int liczba_ciagow)
{
	int i=0;
	while(i<liczba_ciagow)
	{
		czysc_szyfrogram(tablica_szyfrogramow[i]);
		free(tablica_szyfrogramow[i]);
		i++;
	}
	free(tablica_szyfrogramow);
}
void czysc_szyfrogram(szyfrogram* szyfrogram)
{
	free(szyfrogram->ciag_znakow);
	free(szyfrogram->wiadomosc);
}






