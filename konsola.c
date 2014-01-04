/*
 * konsola.c
 *
 *  Created on: 27 gru 2013
 *      Author: PiotreK
 */
#include<stdio.h>
#include <stdlib.h>
#include "konsola.h"

int pobierz_liczbe_ciagow(){
	int n=0;
	while(1>0)
	{
		printf("Podaj liczbe ciagow \n");
		scanf("%d", &n);
		if(n>0 && n<25)
			break;
		else
			printf("Podaj liczbe z zakresu 0;25 \n");
	}
	return n;
}
/*
 * funkcja pobiera dene do szyfrogramów z konsoli, tworz¹c nowe szyfrogramy
 * zapisuje liczbe znaków oraz tablice trzycyfrowych liczb
 */
void pobierz_szyfrogramy(szyfrogram** tablica_szyfrogramow, int liczba_ciagow){
	int i;
	for(i=0;i<liczba_ciagow;i++)
	{
			szyfrogram* nowy_szyfrogram= (szyfrogram*) malloc(sizeof(szyfrogram));
			int k=0;
		while(1)
			{
				printf("Podaj liczbe liczb trzycyfrowych w tym ciagu\n");
				scanf("%d", &k);
				if(k>0 && k<25)
					break;
				else
					printf("Podaj liczbe z zakresu 0;25 \n");
			}
		nowy_szyfrogram->liczba_znakow=k;

		int* ciag_znakow= (int*) malloc(k);
		int j=0;
		printf("Podaj (po spacji) trzycyfrowe liczby dla tego ciagu\n");
		for(j=0; j<k; j++)
		{
			scanf("%d", &ciag_znakow[j]);
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

// TODO: czyszczenie pamieci!
