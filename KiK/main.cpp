#include "main.h"


// Program g³ówny. 
int main()
{
	Gra *gra = new Gra;

	gra->Rozgrywka();

	delete gra;
}