#include "main.h"

Gra::Gra()
{
	// Inicjalizacja obiektów i tablic. 
	
	// Inicjalizacja obiektu plansza.
	plansza = new Plansza();

	// Zainicjalizowanie wektorów na wskaŸnik typu gracze i powi¹zanie je z obiektami typu Komputer i Czlowiek.
	gracze.push_back(new Komputer(plansza));
	gracze.push_back(new Czlowiek(plansza));

	// Inicjalizacja obiektu sedzia i powi¹zanie go z obiektem typu plansza.
	sedzia = new Sedzia(plansza);

	// Narysowanie planszy.
	plansza->Rysuj();
}



Gra::~Gra()
{
	// Czyszczenie obiektów sedzia, plansza oraz wektora gracze. 
	delete sedzia;
	delete plansza;
	gracze.clear();
}

int Gra::Rozgrywka()
{
	// Ca³a gra jest rozgrywana w pêtli while. Algorytm for_each s³u¿y do tego, ¿eby wykonaæ metodê run dla poszczególnego gracza. 
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
		// Wyj¹tki s¹ "chwytane" wtedy, jeœli gracz (cz³owiek) wpisze pole, które jest zajête lub nie istnieje. Pêtla while jest przerywana gdy Gracz wpisze poprawnie pole. 
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

	// Sprawdzenie warunku czy dany gracz wygra³. Je¿eli tak to wysy³ane jest zapytanie czy gracz (cz³owiek) chce zagraæ ponownie.
	// Je¿eli siê zgodzi to gra jest rozgrywana ponownie, je¿eli nie to koñczy siê pêtla while w metodzie Rozgrywka i zwalniana jest pamiêæ komputera.
	if (sedzia->Sprawdz(gracz->znak))
	{
		if (!sedzia->Powtorka()) stan = false;
	}
}



