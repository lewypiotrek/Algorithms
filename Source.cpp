#include <iostream>
#include"QueuePL.h"
#include "List.h"
#include <string>
#include "Station.h"
#include "Simulator.h"
/*
	Piotr Lewandowski 
	Last update: 21.11.2019r
	JPZ III

	NIE ZNAJDUJE SIÊ W COMMICIE:
	- Dodane obliczenie odleg³oœci do testów
	- Dodany samolot i liczenie czasu lotu. 
*/
using namespace std;

int main()
{	

	Simulator *s = new Simulator();
	s->LoadStationsByFile("src/Stations.txt");
	cout << "\n" << s->Distance(50, 50, 30, 30) << "\n";
	s->CalculateDistance();

	// po zliczeniu
	s->StationsList->View();

	system("pause");
	return 0;
}