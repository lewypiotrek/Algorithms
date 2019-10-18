#pragma once
/*
	Piotr Lewandowski - Kolejka na int
*/
#include <iostream>


struct ElementQueue
{
	//int * pre;
	int value;
	ElementQueue * next;
	ElementQueue(int v)
	{
		this->value = v;
		this->next = nullptr;
	}
};

class QueuePL
{
public:
	ElementQueue * first;
	ElementQueue * last;

	QueuePL();
	~QueuePL();

	void add(int v);
	void view();
	int size();
	void remove();

};

