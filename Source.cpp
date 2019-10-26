#include <iostream>
#include"QueuePL.h"
#include "List.h"
#include <string>
#include "Station.h"


using namespace std;

int main()
{	
	/*
	QueuePL<int> * q = new QueuePL<int>;
	q->add(15);
	q->add(16);
	q->add(116);
	q->view();
	if (!q->isEmpty())
		cout << "\n nie jest pusty \n";
	cout << q->size() << endl;
	q->ViewIndex(16);
	*/

	
	//List<Station *> * l = new List<Station *>;
	Station * s = new Station();
	cout << s;

	system("pause");


	return 0;
}