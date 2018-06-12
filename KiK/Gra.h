#pragma once
using namespace std;

class Gra
{
private:

	// Utworzenie wska�nik�w na obiekt typu Plansza, Sedzia oraz wektora wska�nika na typ Gracz.
	Plansza *plansza;
	Sedzia *sedzia;
	vector <Gracz*> gracze;

public:

	Gra();
	~Gra();

	// Metoda w kt�rej jest p�tla while odpowiedzialna za ca�� gr�. Za pomoc� algorytmu for_each odbywa si� rozgrywka. 
	int Rozgrywka();

private:

	// Obiekt typu stan, kt�ry ko�czy p�tle while odpowiedzialn� za rozgrywk�.
	bool stan = true;

	// Metoda do kt�rej odwo�uje si� algorytm for_each. 
	void run(Gracz* gracz);

};