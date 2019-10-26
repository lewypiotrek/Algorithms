#include "Station.h"



Station::Station(short h, short m)
{
	this->h = h;
	this->m = m;
	x = 0;
	y = 0;
	name = "Default Airport";
}

Station::Station()
{
	h = 0;
	m = 0;
	x = 0;
	y = 0;
	name = "Default Airport";
}


Station::~Station()
{
}
