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

	cout << "\n* * *   SYMULATOR LOTOW - PIOTR LEWANDOWSKI   * * *\n\n";

	cout << "\nCALKOWITY DYSTANS TRASY: " << s->Distance(50, 50, 30, 30) << "\n";
	s->CalculateDistance();

	cout << "\n----------------------------------------------\n";
	cout << "WYBRANY SAMOLOT";
	cout << "\n----------------------------------------------\n";
	s->P1->View();



	cout << "\n\n\n----------------------------------------------\n";
	cout << "TRASA PRZELOTU";
	cout << "\n----------------------------------------------\n";
	// po zliczeniu
	s->StationsList->View();
	cout << "----------------------------------------------\n";
	system("pause");
	return 0;
}