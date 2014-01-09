//szyfrowanie.c
#include <stdio.h>
#include <stdlib.h>
#include "szyfrogram.h"
#include "konsola.h"
#include "pliki.h"

#define PLIK "plik.txt"

void glowny_program();
void reczne_wpisywanie_danych();
void dane_z_pliku();
void czysc_wszystko(szyfrogram**);
void czysc_szyfrogram(szyfrogram*);

int liczba_ciagow;
szyfrogram** tablica_szyfrogramow;

int main ()
{
	printf("Program do lamania kodu.\n");
	int wejscie=0;
	while(1) {
		printf("==== Menu glowne ====\n"
				"(1) uruchom program\n"
				"(0) wyjscie\n");
		scanf("%d", &wejscie);
		if(wejscie == 1) {		//wykonanie programu
			glowny_program();
		}
		else if(wejscie == 0) { //wyjscie z programu
			return 1;
		}
		else { 	//bledna liczba
			continue;
		}
	}

	wypisz_wyniki(tablica_szyfrogramow, liczba_ciagow);
	czysc_wszystko(tablica_szyfrogramow);
	return 0;

}

void glowny_program()
{
	int komenda = 0;
	while(1)
	{
		printf("\n\n---- Menu programu ----\n"
				"(1) reczne wpisywanie danych\n"
				"(2) pobieranie danych z pliku\n"
				"(3) zakonczenie programu\n");
		scanf("%d", &komenda);
		switch(komenda)
		{
		case 1: reczne_wpisywanie_danych(); break;
		case 2: dane_z_pliku(); break;
		case 3: return;
		default: break;
		}
	}
}

void reczne_wpisywanie_danych()
{
	liczba_ciagow=pobierz_liczbe_ciagow();
	tablica_szyfrogramow= (szyfrogram**) malloc(liczba_ciagow);
	pobierz_szyfrogramy(tablica_szyfrogramow, liczba_ciagow);

}

void dane_z_pliku()
{
	FILE* plik = fopen(PLIK, "r");
	if(plik == NULL)
	{
		printf("Nie mozna otworzyc pliku!\n");
		return;
	}
	fscanf(plik, "%d\n", &liczba_ciagow);
	tablica_szyfrogramow= (szyfrogram**) malloc(liczba_ciagow);

	pobierz_z_pliku(tablica_szyfrogramow, liczba_ciagow, plik);

	fclose(plik);
}

void czysc_wszystko(szyfrogram** tablica_szyfrogramow)
{
	if(tablica_szyfrogramow == NULL)
	{
		return;
	}
	int i=0;
	while(i<liczba_ciagow)
	{
		czysc_szyfrogram(tablica_szyfrogramow[i]);
		free(tablica_szyfrogramow[i]);
		i++;
	}
	free(tablica_szyfrogramow);
}

void czysc_szyfrogram(szyfrogram* szyfrogram)
{
	free(szyfrogram->ciag_znakow);
	free(szyfrogram->wiadomosc);
}
