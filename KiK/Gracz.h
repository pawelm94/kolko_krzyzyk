#pragma once

// Klasa abstrakcyjna w kt�rej znajduje si� metoda wirtualna Ruch. 
class Gracz
{
public:
	int i, j, k;
	char znak;

	// Metoda losuj�ca.
	inline int randim(int max, int min) { return rand() * (max - min) / (int)RAND_MAX + min; }

	// Metoda wirtualna Ruch.
	virtual bool Ruch() = 0;
};

class Komputer : public Gracz
{
public:
	Plansza *plansza;

	// Przekazywanie wska�nika obiektu plansza do Komputera. Zosta�o to zastosowane, �eby nie tworzy� nowych obiekt�w (kopii). 
	Komputer(Plansza* _plansza) : plansza(_plansza) { znak = 'X'; }
	
	// Metoda wirtualna w kt�rej Komputer wykonuj� ruch na planszy. 
	virtual bool Ruch();
};

class Czlowiek : public Gracz
{
public:
	Plansza *plansza;

	// Przekazywanie wska�nika obiektu plansza do Cz�owieka. Zosta�o to zastosowane, �eby nie tworzy� nowych obiekt�w (kopii). 
	Czlowiek(Plansza* _plansza) : plansza(_plansza) { znak = 'O'; }

	// Metoda wirtualna w kt�rej Cz�owiek wykonuj� ruch na planszy. 
	virtual bool Ruch();
};