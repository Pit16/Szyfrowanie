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
		printf("Podaj liczbe ciagów \n");
		scanf("%d", &n);
		if(n>0 && n<25)
			break;
		else
			printf("Podaj liczbe z zakresu 0;25 \n");
	}
	return n;
}

int pobierz_szyfrogramy(szyfrogram** tablica_szyfrogramow, int liczba_ciagow){
	
	szyfrogram* nowy = (szyfrogram*) malloc(sizeof(szyfrogram));
	int znaki[5] = {111,222,333,444,555};
	int ile_znakow = 5;
	nowy->liczba_znakow = ile_znakow;
	nowy->ciag_znakow = znaki;
	tablica_szyfrogramow[0] = nowy;

	return 0;
}


