#pragma once

class Gramy
{
public:
	Gramy(Gracz& abc) :o(abs); 
	void operator()(Gracz& abc);
private:
	Gracz* o;

};