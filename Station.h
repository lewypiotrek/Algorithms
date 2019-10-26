#pragma once
#include<string>
#include<iostream>
using namespace std;

class Station
{
private:
	string name;
	short x, y;
public:
	short h, m;

public:
	Station(short h,short m);
	Station();
	~Station();

	void view()
	{
		cout << h << " " << h << "\n";
	}

	Station operator=(const Station &s2)
	{
		this->h = s2.h;
		//cout << this->x;
		return *this;
	}

	friend ostream & operator<< (ostream & out, Station const * s)
	{
		out << "test " << s->h;
		return out;
	}

};

