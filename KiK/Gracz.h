#pragma once

// Klasa abstrakcyjna w której znajduje siê metoda wirtualna Ruch. 
class Gracz
{
public:
	int i, j, k;
	char znak;

	// Metoda losuj¹ca.
	inline int randim(int max, int min) { return rand() * (max - min) / (int)RAND_MAX + min; }

	// Metoda wirtualna Ruch.
	virtual bool Ruch() = 0;
};

class Komputer : public Gracz
{
public:
	Plansza *plansza;

	// Przekazywanie wskaŸnika obiektu plansza do Komputera. Zosta³o to zastosowane, ¿eby nie tworzyæ nowych obiektów (kopii). 
	Komputer(Plansza* _plansza) : plansza(_plansza) { znak = 'X'; }
	
	// Metoda wirtualna w której Komputer wykonujê ruch na planszy. 
	virtual bool Ruch();
};

class Czlowiek : public Gracz
{
public:
	Plansza *plansza;

	// Przekazywanie wskaŸnika obiektu plansza do Cz³owieka. Zosta³o to zastosowane, ¿eby nie tworzyæ nowych obiektów (kopii). 
	Czlowiek(Plansza* _plansza) : plansza(_plansza) { znak = 'O'; }

	// Metoda wirtualna w której Cz³owiek wykonujê ruch na planszy. 
	virtual bool Ruch();
};