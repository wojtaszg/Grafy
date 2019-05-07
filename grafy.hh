#ifndef GRAFY_HH
#define GRAFY_HH

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>

const int MAXINT = 2147483647;
// Typy danych
//ifstream wczytaj("wczytaj.txt");
//ofstream zapis("zapisz.txt");


	const int wymiar = 1000;
	class macierz
	{
	public:
		int rozmiar;
		//int **tab;
		int tab[wymiar][wymiar];
		int *a;
		int pocz;
		int kon;
		int waga;
		int dystans[wymiar];
		int poprzednik[wymiar];
		bool odwiedzony[wymiar];

		macierz();
		macierz(int n);
		int wyliczKrawedzie(int wierzcholki, int procent);
		void wypelnijLosowoMacierz(int wierzcholki, int procent);


	};


class lista
	{
	public:
		lista *kolejny;
		int v, w;
	};


	class graf
	{
	public:

		int wierzcholek;
		bool *QS;	//zbiór Q i S
		int *dojscia;
		int *poprzedni;
		int *Stos;
		int wsk;
		lista **grafy;                 // Tablica list sšsiedztwa ***
		lista *pw, *rw;				// ****
		macierz mac;
		

		graf(int n);
		void poczatek(int n, int v);
		int wyliczKrawedzie(int wierzcholki, int procent);
		void wypelnijLosowo(int wierzcholki, int procent);
		void wyznaczSciezki(int n);
		void wypelnijMacierz(int n, int procent);
		void wyznaczSciezkiMacierz(int n);
		void wyswietlWynik(int n);
		void wyswietlWynikMacierzy(int n);
		void wczytajGraf(char x);
		void zapiszWyniki(int n);
		void wyswietlWynikNajDrogi(int n,int w);
		void najkrotszaDrogaMiedzyWierzcholkami(int w1, int w2,int n)
		{
			poczatek(n,w1);
			wyznaczSciezki(n);
			wyswietlWynikNajDrogi(n,w2);
		}
		
	
		

		};






#endif
