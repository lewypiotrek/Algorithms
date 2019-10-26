#pragma once
#include<string>
#include<iostream>
using namespace std;

class Station
{
private:
	string name;
	short x, y;
	short h, m;

public:
	Station(short h,short m);
	Station();
	~Station();

	Station operator=(const Station &s2)
	{
		this->h = s2.h;
		return *this;
	}

	// Przeci��enie = dla wska�nika (dla dynamicznej listy)
	friend ostream & operator<< (ostream & out, Station const * s)
	{
		out << s->name <<" | Hour: " << s->h << ":" << s->m << " | Coordinate:(" << s->x << "," << s->y << ")\n";
		return out;
	}

	// Przeci��enie = dla referencji (dla statycznej listy)
	friend ostream & operator<< (ostream & out, Station const & s)
	{
		out << s.name << " | Hour: " << s.h << ":" << s.m << " | Coordinate:(" << s.x << "," << s.y << ")\n";
		return out;
	}

};

