/*
 * pliki.c
 *
 *  Created on: 9 sty 2014
 *      Author: PiotreK
 */

#include <stdio.h>
#include <stdlib.h>
#include "pliki.h"



void pobierz_z_pliku(szyfrogram** tablica_szyfrogramow, int liczba_ciagow, FILE* plik)
{

	int i;
	for(i=0;i<liczba_ciagow;i++)
	{
		szyfrogram* nowy_szyfrogram= (szyfrogram*) malloc(sizeof(szyfrogram));
		int k=0;
		fscanf(plik, "%d", &k);

		nowy_szyfrogram->liczba_znakow=k;

		int* ciag_znakow= (int*) malloc(k);
		int j=0;

		for(j=0; j<k; j++)
		{
			fscanf(plik, "%d", &ciag_znakow[j]);
			if(ciag_znakow[j]<100 || ciag_znakow[j]>999)
			{
				printf("Podana liczba nie jest trzycyfrowa, dany ciag nie bedzie sprawdzany\n");
				break;
			}
		}
		nowy_szyfrogram->ciag_znakow=ciag_znakow;
		tablica_szyfrogramow[i]=nowy_szyfrogram;
	}
}
