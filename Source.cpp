#include <iostream>
#include"QueuePL.h"
#include "List.h"
#include <string>
#include "Station.h"


using namespace std;

int main()
{	
	
	List<Station *> * l = new List<Station *>;
	Station * s = new Station(3,3,"Warszawa");
	Station * x = new Station(6, 5, "Lodz");
	Station * y = new Station(2, 6, "Poznan");
	s->SetCoords(5, 5);
	s->SetTime(14, 15);
	//cout << s;
	l->Add(s);
	l->Add(x);
	l->Add(y);
	l->View();


	system("pause");


	return 0;
}