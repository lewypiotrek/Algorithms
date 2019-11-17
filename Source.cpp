#include <iostream>
#include"QueuePL.h"
#include "List.h"
#include <string>
#include "Station.h"
#include "Simulator.h"
/*
	Piotr Lewandowski 
	Last update: 17.11.2019r
	JPZ III
*/
using namespace std;

int main()
{	

	Simulator *s = new Simulator();
	s->LoadStationsByFile("src/Stations.txt");
	s->StationsList->View();
	cout << "\n" << s->Distance(50, 50, 30, 30) << "\n";

	system("pause");
	return 0;
}