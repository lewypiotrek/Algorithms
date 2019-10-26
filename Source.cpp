#include <iostream>
#include"QueuePL.h"
#include "List.h"
#include <string>

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

	
	List<string> * l = new List<string>;
	l->Add("dsa");
	l->Add("sda");
	//l->Add(1443421);
	//l->Add(144221);
	l->View();
	

	system("pause");


	return 0;
}