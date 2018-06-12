#pragma once
using namespace std;

class Gra
{
private:

	// Utworzenie wskaŸników na obiekt typu Plansza, Sedzia oraz wektora wskaŸnika na typ Gracz.
	Plansza *plansza;
	Sedzia *sedzia;
	vector <Gracz*> gracze;

public:

	Gra();
	~Gra();

	// Metoda w której jest pêtla while odpowiedzialna za ca³¹ grê. Za pomoc¹ algorytmu for_each odbywa siê rozgrywka. 
	int Rozgrywka();

private:

	// Obiekt typu stan, który koñczy pêtle while odpowiedzialn¹ za rozgrywkê.
	bool stan = true;

	// Metoda do której odwo³uje siê algorytm for_each. 
	void run(Gracz* gracz);

};