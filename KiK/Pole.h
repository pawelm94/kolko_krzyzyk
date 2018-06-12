#pragma once


class Pole
{
private:

	char znak;

public:

	// W konstruktorze wype�niamy pustymi znakami pola. 
	Pole();

	// Metoda odpowiedzialna za wyczyszczenie pola. 
	void Wyczysc();

	// Metoda, kt�ra wype�nia znakiem pole. 
	void Wypelnij(char _znak);

	// Operatory, kt�re pozwalaj� por�wna� znak z danym polem oraz go wy�wietli�.

	friend bool operator == (const Pole &_l, const char _p);

	friend bool operator != (const Pole &_l, const char _p);

	friend std::ostream & operator << (std::ostream &_strumien, Pole _znak);

};