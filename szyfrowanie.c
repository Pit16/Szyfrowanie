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
	szukanie_klucza(tablica_szyfrogramow[0]);

	return 0;
}
