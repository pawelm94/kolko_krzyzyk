#include "main.h"

bool Komputer::Ruch()
{
	// Dopisanie krzy¿yka w miejscu, w którym istnieje mo¿liwoœæ wygranej przez komputera.
	for (i = 0; i<3; i++)
	{
		for (j = 0; j<3; j++)
		{
			if ((plansza->pole[i][j] == 'X') && (plansza->pole[i][(j + 1) % 3] == 'X') &&
				(plansza->pole[i][(j + 2) % 3] == ' '))
			{
				plansza->pole[i][(j + 2) % 3].Wypelnij('X');
				return true;
			}
			if ((plansza->pole[j][i] == 'X') && (plansza->pole[(j + 1) % 3][i] == 'X') &&
				(plansza->pole[(j + 2) % 3][i] == ' '))
			{
				plansza->pole[(j + 2) % 3][i].Wypelnij('X');
				return true;
			}
		}

		if ((plansza->pole[i][2 - i] == 'X') &&
			(plansza->pole[(i + 1) % 3][2 - (i + 1) % 3] == 'X') &&
			(plansza->pole[(i + 2) % 3][2 - (i + 2) % 3] == ' '))
		{
			plansza->pole[(i + 2) % 3][2 - (i + 2) % 3].Wypelnij('X');
			return true;

		}
	}

	// Blokowanie gracza (cz³owieka) na wypadek jakby posiada³ ju¿ dwa miejsca zape³nione kó³kami.
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if ((plansza->pole[i][j] == 'O') && (plansza->pole[i][(j + 1) % 3] == 'O') &&
				(plansza->pole[i][(j + 2) % 3] == ' '))
			{
				plansza->pole[i][(j + 2) % 3].Wypelnij('X');
				return true;

			}
			if ((plansza->pole[j][i] == 'O') && (plansza->pole[(j + 1) % 3][i] == 'O') &&
				(plansza->pole[(j + 2) % 3][i] == ' '))
			{
				plansza->pole[(j + 2) % 3][i].Wypelnij('X');
				return true;
			}
		}

		if ((plansza->pole[i][2 - i] == 'O') &&
			(plansza->pole[(i + 1) % 3][2 - (i + 1) % 3] == 'O') &&
			(plansza->pole[(i + 2) % 3][2 - (i + 2) % 3] == ' '))
		{
			plansza->pole[(i + 2) % 3][2 - (i + 2) % 3].Wypelnij('X');
			return true;

		}
	}

	// Strategia w grze kó³ko i krzy¿yk dla komputera polega na tym, ¿e najpierw komputer stawia krzy¿yk na œrodku planszy (o ile istnieje taka mo¿liwoœæ).
	if (plansza->pole[1][1] == ' ')
	{

		plansza->pole[1][1].Wypelnij('X');
		return true;
	}

	// Nastêpnie komputer stawia krzy¿yk w rogach, które ze sob¹ s¹siaduj¹. W ten sposób ma najwiêksz¹ mo¿liwoœæ wygranej.
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (plansza->pole[2 * i][2 * j] == 'X')
			{
				if (plansza->pole[2 * i][(2 * j + 2) % 2] == ' ')
				{
					plansza->pole[2 * i][(2 * j + 2) % 4].Wypelnij('X');
					return true;
				}
				if (plansza->pole[(2 * i + 2) % 2][(2 * j)] == ' ')
				{
					plansza->pole[(2 * i + 2) % 4][(2 * j)].Wypelnij('X');
					return true;
				}

			}
		}
	}

	for (k = 0; k < 100; k++)
	{
		i = randim(2, 0);
		j = randim(2, 0);
		if (plansza->pole[2 * i][2 * j] == ' ')
		{
			plansza->pole[2 * i][2 * j].Wypelnij('X');
			return true;
		}
	}

	// Je¿eli nie istnieje mo¿liwoœæ postawienia krzy¿yka to komputer tak, ¿eby wygraæ to komputer stawia krzy¿yk w dowolne miejsce.
	do
	{
		i = randim(2, 0);
		j = randim(2, 0);
	} while (plansza->pole[i][j] != ' ');
	plansza->pole[i][j].Wypelnij('X');
	return true;

}

bool Czlowiek::Ruch()
{

	cout << "Wybierz ruch: " << endl;
	cout << "Wpisz wiersz: " << endl;
	cin >> i;
	cout << "Wpisz kolumne: " << endl;
	cin >> j;
	if (((plansza->pole[i - 1][j - 1] != 'X') && (plansza->pole[i - 1][j - 1] != 'O')) && ((i > 0 && i < 4) && (j > 0 && j < 4)))
	{
		plansza->pole[i - 1][j - 1].Wypelnij('O');
		return true;
	}
	else
	{
		throw "\nPonow probe\n\n";
	}
}

