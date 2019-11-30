#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include"Station.h"
#include"List.h"
#define M_PI 3.14159265358979323846   // pi

using namespace std;

class Simulator
{
public:
	struct Plane
	{
		string name;
		double speed;
		Plane(string n, double s)
		{
			name = n;
			speed = s;
		}
		void Set(string n, double s) 
		{
			name = n;
			s = speed;
		}
	};

private:
	Plane * P1;
public:
	List<Station> * StationsList;
	int size;
	int hour;	// temporary hour to calculate time
	int min;	// temporary minutes  to calculate time

public:
	Simulator();
	~Simulator();
	void LoadStationsByFile(string FileName);
	void CalculateDistance();
	long double toRadians(const long double degree);
	long double Distance(long double lat1, long double long1, long double lat2, long double long2);
	void ConvertHour(double distanceTime, int & h, int & m);
};

