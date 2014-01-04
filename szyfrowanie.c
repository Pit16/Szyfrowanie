//szyfrowanie.c
#include <stdio.h>
#include <stdlib.h>
#include "konsola.h"
#include "szyfrogram.h"

int main ()
{
	printf("Program do lamania kodu.\n");
	int liczba_ciagow=pobierz_liczbe_ciagow();
	printf("Wypisanie pobranej liczby ciagow: %d \n", liczba_ciagow);
	szyfrogram** tablica_szyfrogramow= (szyfrogram**) malloc(liczba_ciagow);
	pobierz_szyfrogramy(tablica_szyfrogramow, liczba_ciagow);
	szukanie_klucza(tablica_szyfrogramow[0]);
	char* wiadomosc = deszyfrowanie_wiadomosci(tablica_szyfrogramow[0]);
	printf("%s", wiadomosc);

	return 0;
}
