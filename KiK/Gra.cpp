#include "main.h"

Gra::Gra()
{
	// Inicjalizacja obiekt�w i tablic. 
	
	// Inicjalizacja obiektu plansza.
	plansza = new Plansza();

	// Zainicjalizowanie wektor�w na wska�nik typu gracze i powi�zanie je z obiektami typu Komputer i Czlowiek.
	gracze.push_back(new Komputer(plansza));
	gracze.push_back(new Czlowiek(plansza));

	// Inicjalizacja obiektu sedzia i powi�zanie go z obiektem typu plansza.
	sedzia = new Sedzia(plansza);

	// Narysowanie planszy.
	plansza->Rysuj();
}



Gra::~Gra()
{
	// Czyszczenie obiekt�w sedzia, plansza oraz wektora gracze. 
	delete sedzia;
	delete plansza;
	gracze.clear();
}

int Gra::Rozgrywka()
{
	// Ca�a gra jest rozgrywana w p�tli while. Algorytm for_each s�u�y do tego, �eby wykona� metod� run dla poszczeg�lnego gracza. 
	while (stan)
	{
		for_each(gracze.begin(), gracze.end(), [this](Gracz* gracz) {run(gracz); }); // lambda solution c++11 stackoverflow.com
	}
	return 0;
}

void Gra::run(Gracz* gracz) 
{
	if (!stan) return;
	while (1)
	{
		// Wyj�tki s� "chwytane" wtedy, je�li gracz (cz�owiek) wpisze pole, kt�re jest zaj�te lub nie istnieje. P�tla while jest przerywana gdy Gracz wpisze poprawnie pole. 
		try
		{
			if (gracz->Ruch()) break;
		}
		catch (const char *e)
		{
			cout << e;
		}
	}
	// Rysowanie planszy.
	plansza->Rysuj();

	// Sprawdzenie warunku czy dany gracz wygra�. Je�eli tak to wysy�ane jest zapytanie czy gracz (cz�owiek) chce zagra� ponownie.
	// Je�eli si� zgodzi to gra jest rozgrywana ponownie, je�eli nie to ko�czy si� p�tla while w metodzie Rozgrywka i zwalniana jest pami�� komputera.
	if (sedzia->Sprawdz(gracz->znak))
	{
		if (!sedzia->Powtorka()) stan = false;
	}
}



