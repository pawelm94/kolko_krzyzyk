#include "main.h"

bool Sedzia::Sprawdz(char znak)
{

	if ((plansza->pole[0][0] == znak && plansza->pole[0][1] == znak && plansza->pole[0][2] == znak) | (plansza->pole[1][0] == znak && plansza->pole[1][1] == znak && plansza->pole[1][2] == znak) | (plansza->pole[2][0] == znak && plansza->pole[2][1] == znak && plansza->pole[2][2] == znak)
		| (plansza->pole[0][0] == znak && plansza->pole[1][0] == znak && plansza->pole[2][0] == znak) | (plansza->pole[0][1] == znak && plansza->pole[1][1] == znak && plansza->pole[2][1] == znak) | (plansza->pole[0][2] == znak && plansza->pole[1][2] == znak && plansza->pole[2][2] == znak)
		| (plansza->pole[0][0] == znak && plansza->pole[1][1] == znak && plansza->pole[2][2] == znak) | (plansza->pole[0][2] == znak && plansza->pole[1][1] == znak && plansza->pole[2][0] == znak))
	{
		if (znak == 'X')
		{

			cout << "Wygral komputer" << endl;
			return true;

		}
		if (znak == 'O')
		{

			cout << "Wygral gracz" << endl;
			return true;
		}

	}
	if (plansza->pole[0][0] != ' ' && plansza->pole[0][1] != ' ' && plansza->pole[0][2] != ' ' && plansza->pole[1][0] != ' ' && plansza->pole[1][1] != ' ' && plansza->pole[1][2] != ' ' && plansza->pole[2][0] != ' ' && plansza->pole[2][1] != ' ' && plansza->pole[2][2] != ' ')
	{
		cout << "Remis" << endl;
		return true;
	}

	return false;
}

bool Sedzia::Powtorka()
{
	cout << "Rozegrac ponownie? t/n\n" << endl;
	cin >> z;
	if (z == 't')
	{
		plansza->Czysc();

		return true;
	}
	else
	{
		return false;
	}
}