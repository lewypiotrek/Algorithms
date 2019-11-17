#pragma once
#include"Station.h"
#include"List.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#define M_PI 3.14159265358979323846   // pi

using namespace std;

class Simulator
{

public:
	List<Station> * StationsList;
	int size;
public:
	Simulator();
	~Simulator();
	void LoadStationsByFile(string FileName);
	double CalculateDistance();
	long double toRadians(const long double degree);
	long double Distance(long double lat1, long double long1, long double lat2, long double long2);
};

