#pragma once
#include"Station.h"
#include"List.h"
#include <iostream>
#include <string>
#include <fstream>

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
};

