//szyfrowanie.c
#include <stdio.h>
#include <stdlib.h>
#include "konsola.h"

int main ()
{
	printf("Program do lamania kodu.\n");
	int liczba_ciagow = pobierz_liczbe_ciagow();
	printf("Wypisanie pobranej liczby ciagow: %d \n", liczba_ciagow);
	szyfrogram** szyfrogramy = (szyfrogram**) malloc(liczba_ciagow);
	pobierz_szyfrogramy(szyfrogramy, liczba_ciagow);
	printf("%d \n", szyfrogramy[0]->liczba_znakow);
	
	return 0;
}
