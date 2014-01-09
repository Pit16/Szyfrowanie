/*
 * konsola.c
 *
 *  Created on: 27 gru 2013
 *      Author: PiotreK
 */
#include<stdio.h>
#include <stdlib.h>
#include "konsola.h"
#include "lamanie_kodu.h"
#include "deszyfrowanie.h"

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
 * funkcja pobiera dene do szyfrogram�w z konsoli, tworz�c nowe szyfrogramy
 * zapisuje liczbe znak�w oraz tablice trzycyfrowych liczb
 */
void pobierz_szyfrogramy(szyfrogram** tablica_szyfrogramow, int liczba_ciagow){
	int i;
	for(i=0;i<liczba_ciagow;i++)
	{
		szyfrogram* nowy_szyfrogram= (szyfrogram*) malloc(sizeof(szyfrogram));
		int k=0;
		while(1)
		{
			printf("Prosze podac liczbe liczb trzycyfrowych w ciagu %d\n",i+1);
			scanf("%d", &k);
			if(k>0 && k<25)
				break;
			else
				printf("Uwaga! Prosze podac liczbe z zakresu 0;25 \n");
		}
		nowy_szyfrogram->liczba_znakow=k;

		int* ciag_znakow= (int*) malloc(k);
		int j=0;
		printf("Prosze podac (po spacji) trzycyfrowe liczby dla ciagu numer %d\n",i+1);
		for(j=0; j<k; j++)
		{
			scanf("%d", &ciag_znakow[j]);
			if(ciag_znakow[j]<100 || ciag_znakow[j]>999)
			{
				printf("Podana liczba nie jest trzycyfrowa, ciag %d nie bedzie sprawdzany\n", i+1);
				break;
			}
		}
		nowy_szyfrogram->ciag_znakow=ciag_znakow;
		tablica_szyfrogramow[i]=nowy_szyfrogram;
	}

}


void wypisz_wyniki(szyfrogram** tablica_szyfrogramow, int liczba_ciagow)
{
	int i=0;
	while(i<liczba_ciagow)
	{
		szyfrogram* nowy_szyfrogram=tablica_szyfrogramow[i];
		szukanie_klucza(nowy_szyfrogram);
		char* wiadomosc = deszyfrowanie_wiadomosci(nowy_szyfrogram);
		printf("%s\n", wiadomosc);
		i++;
	}
}
