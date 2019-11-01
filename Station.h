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
	Station(short h,short m,string name);
	Station();
	~Station();
	void SetCoords(short x, short y);
	void SetTime(short h, short m);
	void SetName(string n);

	// Je¿eli parametr 'x' zwróci x je¿eli 'y' zwróci y.
	short GetValue(char v);
	
	// Przecia¿enie = 
	Station operator=(const Station &s2)
	{
		this->h = s2.h;
		return *this;
	}

	// Przeci¹¿enie << dla wskaŸnika (dla dynamicznej listy)
	friend ostream & operator<< (ostream & out, Station const * s)
	{
		out << s->name <<" | Hour: " << s->h << ":" << s->m << " | Coordinate:(" << s->x << "," << s->y << ")\n";
		return out;
	}

	// Przeci¹¿enie << dla referencji (dla statycznej listy)
	friend ostream & operator<< (ostream & out, Station const & s)
	{
		out << s.name << " | Hour: " << s.h << ":" << s.m << " | Coordinate:(" << s.x << "," << s.y << ")\n";
		return out;
	}

};

