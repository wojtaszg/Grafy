#include "grafy.hh"
#include <iostream>

using namespace std;
ifstream wczytaj("wczytaj.txt");
	ofstream zapis("zapisz.txt");

		macierz::macierz()
		{
			for (int p = 0; p < wymiar; p++)
			{
				dystans[p] = MAXINT;
				poprzednik[p] = -1;
			}
			dystans[0] = 0;
			
		}

		macierz::macierz(int n)
		{
			rozmiar = n;
			
			for (int p = 0; p < wymiar; p++)
			{
				dystans[p] = MAXINT;
				poprzednik[p] = -1;
			}
			dystans[0] = 0;
			
		}



		int macierz::wyliczKrawedzie(int wierzcholki, int procent)
		{
			int k = (wierzcholki*(wierzcholki - 1)*procent) / 200;
			return k;
		}

		void macierz::wypelnijLosowoMacierz(int wierzcholki, int procent)
		{
			int k = wyliczKrawedzie(wierzcholki, procent);
			int i = 0, m, n, l = wierzcholki - 2, z = 0, s = 0, tab[500], suma = 0,w;
			
			for (int i = 0; i < wierzcholki; i++)
			{
				
				m = i;
				if (i == (wierzcholki - 1))
					m = 0;
				else
					n = i + 1; // Wierzchołek docelowy krawędzi

				w = rand() % 10 + 1;                    // Waga krawędzi
				this->tab[m][n] = w;
				
				
			}
			
			
			for (int j = l; j > 0; j--)
			{
				tab[i] = j;
				i++;
			}
			
			for (int i = 0; i < l; i++)
			{
				for (int j = 0; j < tab[i]; j++)
				{
					m = j;
					n = j + wierzcholki - tab[i];
					w = rand() % 10 + 1;                    // Waga krawędzi
					this->tab[m][n] = w;
				}
			}
		}


		
		graf::graf(int n)
		{
			wierzcholek = n;
			dojscia = new int[n];
			poprzedni = new int[n];                // Tablica poprzedników
			QS = new bool[n];
			grafy = new lista *[wyliczKrawedzie(n, 100)];
			Stos = new int[n];                // Stos
			wsk = 0;
		}

		void graf::poczatek(int n, int v)
		{
			for (int i = 0; i < n; i++)
			{
				dojscia[i] = MAXINT;
				poprzedni[i] = -1;
				QS[i] = false;
				grafy[i] = NULL;
				dojscia[v] = 0;
			}
		}
		
		int graf::wyliczKrawedzie(int wierzcholki, int procent)
		{
			int k = (wierzcholki*(wierzcholki - 1)*procent) / 200;
			return k;
		}


		void graf::wypelnijLosowo(int wierzcholki, int procent)
		{
			int k = wyliczKrawedzie(wierzcholki, procent);

			for (int i = 0; i < wierzcholki; i++)
			{
				pw = new lista;

				if (i == (wierzcholki-1) )
					pw->v = 0;
				else
					pw->v = i + 1; 
				
				pw->w = rand() % 10 + 1;                    // Waga krawędzi
				pw->kolejny = grafy[i];
				grafy[i] = pw;                // Element dołšczamy do listy
			}
			int i=0, m, n, l = wierzcholki-2,z=0,s=0, tab[500],suma=0;
			for (int j = l; j > 0 ; j--)
			{
				
				tab[i] = j;
				i++;
			}
	
			for (int i = 0; i < l; i++)
			{
				for (int j = 0; j < tab[i]; j++)
				{
					m = j;
					n = j+wierzcholki - tab[i];
					pw = new lista;
					pw->v = n;
					pw->w = rand() % 10 + 1;                    // Waga krawędzi
					pw->kolejny = grafy[m];
					grafy[m] = pw;
				}
			}
			
		}

		

		void graf::wyznaczSciezki(int n)
		{
			int i, j, u;
			for (i = 0; i < n; i++)
			{
				// Szukamy wierzchołka w Q o najmniejszym koszcie d

				for (j = 0; QS[j]; j++);
				for (u = j++; j < n; j++)
					if (!QS[j] && (dojscia[j] < dojscia[u])) u = j;

				// Znaleziony wierzchołek przenosimy do S

				QS[u] = true;
				//cout << u << endl;
				// Modyfikujemy odpowiednio wszystkich sšsiadów u, którzy sš w Q

				for (pw = grafy[u]; pw; pw = pw->kolejny)
					if (!QS[pw->v] && (dojscia[pw->v] > dojscia[u] + pw->w))
					{
						dojscia[pw->v] = dojscia[u] + pw->w;
						poprzedni[pw->v] = u;
					}

			}
		}

		void graf::wypelnijMacierz(int n, int procent)
		{
			this->mac.wypelnijLosowoMacierz(n, procent);
		}

		void graf::wyznaczSciezkiMacierz(int n)
		{
			
			int i, j, u;
			for (i = 0; i < n; i++)
			{
				// Szukamy wierzchołka w Q o najmniejszym koszcie d

				for (j = 0; QS[j]; j++);
				for (u = j++; j < n; j++)
					if (!QS[j] && (mac.dystans[j] < mac.dystans[u])) u = j;

				// Znaleziony wierzchołek przenosimy do S
				
				QS[u] = true;

				// Modyfikujemy odpowiednio wszystkich sšsiadów u, którzy sš w Q

				for (int k = 0; k < n; k++)
					if (this->mac.tab[u][k] > 0 && (mac.dystans[k] > mac.dystans[u] + this->mac.tab[u][k]))
					{
						mac.dystans[k] = mac.dystans[u] + this->mac.tab[u][k];
						//mac.poprzednik[k] = u;
						poprzedni[k] = u;
					}
				
			}
		}

		void graf::wyswietlWynik(int n)
		{
			int i, j;
			for (i = 0; i < n; i++)
			{
				cout << i << ": ";
				// cieżkę przechodzimy od końca ku poczštkowi,
				// Zapisujšc na stosie kolejne wierzchołki

				for (j = i; j > -1; j = poprzedni[j])
						Stos[wsk++] = j;

				// Wywietlamy cieżkę, pobierajšc wierzchołki ze stosu

				while (wsk)
				{
					cout << Stos[--wsk] << " ";
				}
				// Na końcu cieżki wypisujemy jej koszt
				cout << "$" << dojscia[i] << endl;
			}
		}
		
		void graf::wyswietlWynikNajDrogi(int n,int w)
		{
			int i, j;
			for (i = w; i < w+1; i++)
			{
				cout << i << ": ";
				// cieżkę przechodzimy od końca ku poczštkowi,
				// Zapisujšc na stosie kolejne wierzchołki

				for (j = i; j > -1; j = poprzedni[j])
						Stos[wsk++] = j;

				// Wywietlamy cieżkę, pobierajšc wierzchołki ze stosu

				while (wsk)
				{
					cout << Stos[--wsk] << " ";
				}
				// Na końcu cieżki wypisujemy jej koszt
				cout << "$" << dojscia[i] << endl;
			}
		}

		void graf::wyswietlWynikMacierzy(int n)
		{
			int i, j;
			for (i = 0; i < n; i++)
			{
				cout << i << ": ";
				// cieżkę przechodzimy od końca ku poczštkowi,
				// Zapisujšc na stosie kolejne wierzchołki

				for (j = i; j > -1; j = poprzedni[j])
					Stos[wsk++] = j;


				// Wywietlamy cieżkę, pobierajšc wierzchołki ze stosu

				while (wsk)
				{
					cout << Stos[--wsk] << " ";
				}
				// Na końcu cieżki wypisujemy jej koszt
				cout << "$" << this->mac.dystans[i] << endl;
			}
		}

		void graf::wczytajGraf(char x)
		{
			int krawedzie,wierzcholki, wezel;
			wczytaj >> krawedzie >> wierzcholki >> wezel; // liczba krawędzi i wierzchołków , Węzeł startowy 
			int poczatek, koniec, waga;
			if (x == 'l')
			{
				for (int i = 0; i < krawedzie; i++)
				{
					wczytaj >> poczatek >> koniec >> waga;
					pw = new lista;
					pw->v = koniec;
					pw->w = waga;                    // Waga krawędzi
					pw->kolejny = grafy[poczatek];
					grafy[poczatek] = pw;
				}
				cout << "Wczytano pomyslnie." << endl;
			}
			if (x == 'm')
			{
				for (int i = 0; i < krawedzie; i++)
				{
					wczytaj >> poczatek >> koniec >> waga;
					mac.tab[poczatek][koniec] = waga;
				}
				cout << "Wczytano pomyslnie." << endl;
			}
		}

		void graf::zapiszWyniki(int n)
		{
			int i, j;
			for (i = 0; i < n; i++)
			{
				zapis << i << ": ";
				// cieżkę przechodzimy od końca ku poczštkowi,
				// Zapisujšc na stosie kolejne wierzchołki

				for (j = i; j > -1; j = poprzedni[j])
					Stos[wsk++] = j;

				while (wsk)
				{
					zapis << Stos[--wsk] << " ";
				}
				// Na końcu cieżki wypisujemy jej koszt

				zapis << "$" << dojscia[i] << endl;
			}
			zapis.close();
		}
		
		/*~graf()
		{
			delete[] dojscia;
			delete[] poprzedni;
			delete[] QS;
			delete[] Stos;
			delete[] grafy;
		}*/
