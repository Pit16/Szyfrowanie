/*
 * deszyfrowanie.c
 *
 *  Created on: 27 gru 2013
 *      Author: PiotreK
 */
#include <stdio.h>
#include <stdlib.h>
#include "deszyfrowanie.h"

char* deszyfrowanie_wiadomosci(szyfrogram* szyfrogram)
{
	int i=0;
	int znak= 0;
	szyfrogram->wiadomosc = (char*) malloc(szyfrogram->liczba_znakow);
	while(i<szyfrogram->liczba_znakow)
	{
		znak = szyfrogram->ciag_znakow[i]% szyfrogram->klucz;		// rzutowanie int na char
		printf("\n %d %d ",szyfrogram->ciag_znakow[i], znak);
		szyfrogram->wiadomosc[i] = (char) znak;
		i++;

	}
	return szyfrogram->wiadomosc;
}

