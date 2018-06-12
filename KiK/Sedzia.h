#pragma once
 

class Sedzia
{
public:

	Plansza *plansza;

	char z;

	// Przekazywanie wskaŸnika obiektu plansza do Sedzia. Zosta³o to zastosowane, ¿eby nie tworzyæ nowych obiektów (kopii). 
	Sedzia(Plansza *_plansza) : plansza(_plansza) {}
	
	// Metoda odpowiedzialna za sprawdzenie, który gracz wygra³. 
	bool Sprawdz(char znak);

	// Metoda odpowiedzialna za powtórkê lub wy³¹czenie gry.
	bool Powtorka();

};