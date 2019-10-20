#pragma once
/*
	Piotr Lewandowski - Kolejka 
	15.10.2019r
*/
#include <iostream>

template <class Te>
struct ElementQueue
{
	//int * pre;
	Te value;
	ElementQueue * next;
	ElementQueue(Te v)
	{
		this->value = v;
		this->next = nullptr;
	}
};

template <class Tc>
class QueuePL
{
private:
	ElementQueue<Tc> * first;
	ElementQueue<Tc> * last;

public:
	QueuePL();
	~QueuePL();

	void add(Tc v);
	void view();
	void ViewIndex(int index);
	int size();
	void remove();
	bool isEmpty();

};

///////////////////////////////////////////////////////

template <class Tc>
QueuePL<Tc>::QueuePL()
{
	first = nullptr;
	last = nullptr;
}

template <class Tc>
QueuePL<Tc>::~QueuePL()
{
	delete[]first;
	delete[]last;
}

template <class Tc>
void QueuePL<Tc>::add(Tc v)
{
	ElementQueue<Tc> * e = new ElementQueue<Tc>(v);

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

template <class Tc>
void QueuePL<Tc>::view()
{
	ElementQueue<Tc> * temp = first;

	while (temp != nullptr)
	{
		std::cout << temp->value << " ";
		temp = temp->next;
	}
}

template<class Tc>
void QueuePL<Tc>::ViewIndex(int index)
{
	if (index < this->size())
	{
		ElementQueue<Tc> * temp = first;
		int i = 0;
		while (i != index)
		{
			temp = temp->next;
			i++;
		}
		std::cout << "Wartosc indexu: " << temp->value << "\n";
		if (temp->next != nullptr)
			std::cout << "Wartosc nastepnego: " << temp->next->value << "\n";
	}
}

template <class Tc>
int QueuePL<Tc>::size()
{
	ElementQueue<Tc> * temp = first;
	int size = 0;

	while (temp != nullptr)
	{
		size++;
		temp = temp->next;
	}

	return size;

}

template <class Tc>
void QueuePL<Tc>::remove()
{
	if (first != nullptr)
	{
		ElementQueue<Tc> * temp = first;
		first = temp->next;
		delete temp;
	}
}

template<class Tc>
inline bool QueuePL<Tc>::isEmpty()
{
	if (first == nullptr)
	{
		return true;
	}
	else {
		return false;
	}
}
