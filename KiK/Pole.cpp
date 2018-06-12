#include "main.h"


Pole::Pole()
{
	znak = ' ';
}

void Pole::Wyczysc()
{
	znak = ' ';
}

void Pole::Wypelnij(char _znak)
{
	znak = _znak;
}

bool operator == (const Pole &_l, const char _p)
{
	if (_l.znak == _p) return true;
	else               return false;
}

bool operator != (const Pole &_l, const char _p)
{
	if (_l.znak != _p) return true;
	else               return false;
}

ostream & operator << (ostream & o, Pole _znak)
{
	return o << _znak.znak;
}