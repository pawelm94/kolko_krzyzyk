#include "main.h"

void Plansza::Rysuj()
{
	system("CLS");

	for (int q = 0; q < 3; q++)
	{
		for (int k = 0; k < 3; k++)
		{
			cout << pole[q][k];

			if (k != 2)           cout << "|";
			if (k == 2 && q != 2) cout << "\n-----\n";
		}
	}

	cout << endl;
}

void Plansza::Czysc()
{
	for (int q = 0; q < 3; q++)
	{
		for (int k = 0; k < 3; k++)
		{
			pole[q][k].Wyczysc();
		}

		Rysuj();
	}
}