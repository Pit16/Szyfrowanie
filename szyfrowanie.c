//szyfrowanie.c
#include <stdio.h>
#include <stdlib.h>
#include "szyfrogram.h"
#include "konsola.h"
#include "deszyfrowanie.h"
#include "lamanie_kodu.h"

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
		szukanie_klucza(nowy_szyfrogram);
		char* wiadomosc = deszyfrowanie_wiadomosci(nowy_szyfrogram);
		printf("%s\n", wiadomosc);
		i++;
	}
	/*
	int liczba_ciagow = 2;
	szyfrogram* s1 = (szyfrogram*) malloc(sizeof(szyfrogram));
	szyfrogram* s2 = (szyfrogram*) malloc(sizeof(szyfrogram));
	int z1[] = {720, 739, 477};
	int z2[] = {720, 739, 477};
	s1->liczba_znakow = 3;
	s2->liczba_znakow = 3;
	s1->ciag_znakow = z1;
	s2->ciag_znakow = z2;
	szyfrogram** tablica_szyfrogramow = (szyfrogram**) malloc(liczba_ciagow);
	tablica_szyfrogramow[0] = s1;
	tablica_szyfrogramow[1] = s2;
	szyfrogram* nowy_szyfrogram;
	int i=0;
	while(i<liczba_ciagow)
	{
	nowy_szyfrogram=tablica_szyfrogramow[i];
	szukanie_klucza(nowy_szyfrogram);
	char* wiadomosc = deszyfrowanie_wiadomosci(nowy_szyfrogram);
	printf("%s\n", wiadomosc);
	i++;
	}
	*/

	return 0;
}
