#pragma once
using namespace std;

// W klasie Plansza utworzony jest obiekt tablicowy typu Pole. 
class Plansza
{
public:
	Pole pole[3][3];

	// Metoda odpowiedzialna za rysowanie planszy. 
	void Rysuj();

	// Metoda odpowiedzialna za wyczyszczenie planszy. 
	void Czysc();
};