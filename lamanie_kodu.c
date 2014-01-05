/*
 * lamanie_kodu.c
 *
 *  Created on: 27 gru 2013
 *      Author: PiotreK
 */
#include "lamanie_kodu.h"
#include <stdio.h>
#include <stdlib.h>


/*
 * funkcja szukajaca liczby pierwszej dla danego szyfrogramu
 * zwraca znaleziony klucz lub -1 gdy nie znaleziono
 */
int szukanie_klucza(szyfrogram* szyfrogram)
{
	int liczby_pierwsze[5]={127, 131, 137, 139, 149};
	int k=0;
	int i=0;
	int klucz=0;
	int trzycyfrowa=0;

	while(k<5)
	{
		klucz=liczby_pierwsze[k];
		while(i<szyfrogram->liczba_znakow)
		{
			trzycyfrowa=szyfrogram->ciag_znakow[i];
			if (trzycyfrowa % klucz >= 65 && trzycyfrowa % klucz <=90)
				i++;
			else
				break;
		}

		if(i==szyfrogram->liczba_znakow)
		{
			printf("Znaleziono klucz, liczba szukana to %d ", klucz);
			szyfrogram->klucz=klucz;
			return klucz;
		}
		else
			k++;
	}
	klucz=-1;
	szyfrogram->klucz=klucz;
	return klucz;
}
