#include "QueuePL.h"



QueuePL::QueuePL()
{
	first = nullptr;
	last = nullptr;
}


QueuePL::~QueuePL()
{
}

void QueuePL::add(int v)
{
	ElementQueue * e = new ElementQueue(v);

	// sprawdzam czy jest to pierwszy ElementQueue w kolejce
	if (first == nullptr || last == nullptr)
	{
		first = e;
		last = e;
	}
	else 
	{
		last->next = e; // ostatni ElementQueue teraz wskazuje na obecnie dodawany
		last = e;	    // obecnie dodawany staje siê ostatnim ElementQueueem
	}
}

void QueuePL::view()
{
	ElementQueue * temp = first;

	while (temp != nullptr)
	{
		std::cout << temp->value << " ";
		temp = temp->next;
	}
}

int QueuePL::size()
{
	ElementQueue * temp = first;
	int size = 0;

	while (temp != nullptr)
	{
		size++;
		temp = temp->next;
	}

	return size;

}

void QueuePL::remove()
{
	if (first != nullptr)
	{
		ElementQueue * temp = first;
		first = temp->next;
		delete temp;
	}
}
