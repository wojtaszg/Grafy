#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include "grafy.hh"

using namespace std;



		int main()
		{
			int  n, v ,p;
			// Zbiory Q i S

			//graf a(10);
			//a.najkrotszaDrogaMiedzyWierzcholkami(0, 3,10);

			graf *tab[100];
			
			cout << "Podaj rozmiar grafu: ";
			cin >> n;
			cout << "Podaj gestosc grafu: ";
			cin >> p;
			cout << "Podaj wierzcholek poczatkowy: ";
			cin >> v;


				for (int i = 0; i < 100; i++)
				{
					tab[i] = new graf(n);
					tab[i]->poczatek(n, v);
					tab[i]->wypelnijMacierz(n, p);
				}
				double start = clock();
				for (int j = 0; j < 100; j++)
					tab[j]->wyznaczSciezkiMacierz(n);
				double czas = (clock() - start) / CLOCKS_PER_SEC;

				cout << "Czas dla 100 grafow: " << czas << endl;
				cout << "Sredni czas dla 1 grafu: " << czas / 100 << endl;
				/*graf a(6);
					a.poczatek(6, 0);
					a.wczytajGraf('l');
					a.wyznaczSciezki(6);
					a.wyswietlWynik(6);
					cout << "Czy chcesz zapisac wynik? \n1 - tak\n2 - nie\n";
					cin >> x;
					if (x == 1)
						a.zapiszWyniki(6);*/


			/*
			cout << "Wybierz sposob implementacji grafu:\n1 - wczytaj z pliku\n2 - wypelnij losowo\n";
			cin >> x;
			start:
			switch (x)
			{
			case 1:
			{
				cout << endl << "Wybierz strukture danych:\n1 - lista sasiedztwa\n2 - macierz sasiedztwa\n";
				cin >> x;
				if (x == 1)
				{
					graf a(6);
					a.poczatek(6, 0);
					a.wczytajGraf('l');
					a.wyznaczSciezki(6);
					a.wyswietlWynik(6);
					cout << "Czy chcesz zapisac wynik? \n1 - tak\n2 - nie\n";
					cin >> x;
					if (x == 1)
						a.zapiszWyniki(6);
				}
				else if (x == 2)
				{
					graf a(6);
					a.poczatek(6, 0);
					a.wczytajGraf('m');
					a.wyznaczSciezkiMacierz(6);
					a.wyswietlWynik(6);
					cout << "Czy chcesz zapisac wynik? \n1 - tak\n2 - nie\n";
					cin >> x;
					if (x == 1)
						a.zapiszWyniki(6);

				}
				else
					goto start;

				break;
			}

			case 2:
			{
				graf *tab[100];
				cout << endl << "Wybierz strukture danych:\n1 - lista sasiedztwa\n2 - macierz sasiedztwa\n";
				cin >> x;
				cout << "Podaj rozmiar grafu: ";
				cin >> n;
				cout << "Podaj gestosc grafu: ";
				cin >> p;
				cout << "Podaj wierzcholek poczatkowy: ";
				cin >> v;
				
				if (x == 1)
				{

					for (int i = 0; i < 100; i++)
					{
						tab[i] = new graf(n);
						tab[i]->poczatek(n, v);
						tab[i]->wypelnijLosowo(n, p);
					}
					double start = clock();
					for (int j = 0; j < 100; j++)
						tab[j]->wyznaczSciezki(n);
					double czas = (clock() - start) / CLOCKS_PER_SEC;

					cout << "Czas dla 100 grafow: " << czas << endl;
					cout << "Sredni czas dla 1 grafu: " << czas / 100 << endl;
				}
				else if (x == 2)
				{
					for (int i = 0; i < 100; i++)
					{
						tab[i] = new graf(n);
						tab[i]->poczatek(n, v);
						tab[i]->mac.wypelnijLosowoMacierz(n, p);
					}
					double start = clock();
					for (int j = 0; j < 100; j++)
						tab[j]->wyznaczSciezkiMacierz(n);
					double czas = (clock() - start) / CLOCKS_PER_SEC;
					//tab[0]->wyswietlWynikMacierzy(n);
					cout << "Czas dla 100 grafow: " << czas << endl;
					cout << "Sredni czas dla 1 grafu: " << czas / 100 << endl;
				}
				else
					goto start;
				for (int j = 0; j < 100; j++)
				{
					delete[] tab[j]->dojscia;
					delete[] tab[j]->poprzedni;
					delete[] tab[j]->QS;
					delete[] tab[j]->Stos;


					for (i = 0; i < n; i++)
					{
						tab[i]->pw = tab[i]->grafy[i];
						while (tab[i]->pw)
						{
							tab[i]->rw = tab[i]->pw;
							tab[i]->pw = tab[i]->pw->kolejny;
							delete tab[i]->rw;
						}
					}

					delete[] tab[j]->grafy;
				}
				for (int i = 0; i < 100; i++)
					delete[] tab[i];

				break;
			}

			default:
				cout << "Bledny wybor" << endl;
				goto start;
				break;
			}*/



			int c;
			cin >> c;
			return 0;
		}
	
