#pragma once


class Pole
{
private:

	char znak;

public:

	// W konstruktorze wype³niamy pustymi znakami pola. 
	Pole();

	// Metoda odpowiedzialna za wyczyszczenie pola. 
	void Wyczysc();

	// Metoda, która wype³nia znakiem pole. 
	void Wypelnij(char _znak);

	// Operatory, które pozwalaj¹ porównaæ znak z danym polem oraz go wyœwietliæ.

	friend bool operator == (const Pole &_l, const char _p);

	friend bool operator != (const Pole &_l, const char _p);

	friend std::ostream & operator << (std::ostream &_strumien, Pole _znak);

};