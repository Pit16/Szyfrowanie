//szyfrowanie.c
#include <stdio.h>
#include <stdlib.h>
#include "konsola.h"

int main ()
{
	printf("Program do lamania kodu.\n");
	int liczba_ciagow=pobierz_liczbe_ciagow();
	printf("Wypisanie pobranej liczby ciagow: %d \n", liczba_ciagow);
	szyfrogram** tablica_szyfrogramow= (szyfrogram**) malloc(liczba_ciagow);
	pobierz_szyfrogramy(tablica_szyfrogramow, liczba_ciagow);
	int i=0;
	while(i<liczba_ciagow)
	{
	szyfrogram* nowy_szyfrogram=tablica_szyfrogramow[i];
	//printf("Szyfrogram numer %d\n liczba znakow: %d ciag znakow: % klucz: %d", i, nowy_szyfrogram->liczba_znakow, nowy_szyfrogram->ciag_znakow, nowy_szyfrogram->klucz);
	szukanie_klucza(tablica_szyfrogramow[i]);
	char* wiadomosc = deszyfrowanie_wiadomosci(tablica_szyfrogramow[i]);
	printf("%s\n", wiadomosc);
	i++;
	}

	return 0;
}
