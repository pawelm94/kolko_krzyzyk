#pragma once
 

class Sedzia
{
public:

	Plansza *plansza;

	char z;

	// Przekazywanie wska�nika obiektu plansza do Sedzia. Zosta�o to zastosowane, �eby nie tworzy� nowych obiekt�w (kopii). 
	Sedzia(Plansza *_plansza) : plansza(_plansza) {}
	
	// Metoda odpowiedzialna za sprawdzenie, kt�ry gracz wygra�. 
	bool Sprawdz(char znak);

	// Metoda odpowiedzialna za powt�rk� lub wy��czenie gry.
	bool Powtorka();

};