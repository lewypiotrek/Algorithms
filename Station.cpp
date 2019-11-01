#include "Station.h"



Station::Station(short h, short m, string name)
{
	this->h = h;
	this->m = m;
	x = 0;
	y = 0;
	this->name = name;
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

void Station::SetCoords(short x, short y)
{
	this->x = x;
	this->y = y;
}

void Station::SetTime(short h, short m)
{
	this->h = h;
	this->m = m;
}

void Station::SetName(string n)
{
	this->name = n;
}

short Station::GetValue(char v)
{
	if (v == 'x')
		return x;
	else if (v == y)
		return y;
	else
		return 0;

	
}
