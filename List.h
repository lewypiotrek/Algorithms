#pragma once
#include<iostream>
/*
	Piotr Lewandowski - Lista jednokierunkowa z szablonami
	17.10.2019r
*/

// Struktra pojedynczego elementu
template <class Ts>
struct Element
{
	Element * next;
	Ts value;
	Element(Ts v)
	{
		this->value = v;
		this->next = nullptr;
	}
};

// Klasa do kontroli elementów
template <class Tc>
class List
{
public:
	List();

	void Add(Tc v);
	void Remove(int index);
	void View();
	bool isEmpty();
	void ViewIndex(int index);
	int GetSize();

private:
	Element<Tc> * first;
};

///////////////////////////////////////////////////////

template <class Tc>
List<Tc>::List()
{
	first = nullptr;
}

template <class Tc>
void List<Tc>::Add(Tc v)
{
	Element<Tc> * newElement = new Element<Tc>(v);

	if (first == nullptr)
	{
		first = newElement;

	}
	else
	{
		Element<Tc> * temp = first; // ustawiam na pocz¹tek 
		while (temp->next)
		{
			temp = temp->next; // idziemy na koniec listy
		}

		temp->next = newElement;
		newElement->next = nullptr;
	}
}

template <class Tc>
void List<Tc>::Remove(int index)
{
	if (index < this->GetSize() - 1)
	{

		if (index == 0)
		{
			Element<Tc> * temp = first;
			first = temp->next;
			delete[] temp;
		}
		else if (index >= 1)
		{
			Element<Tc> * temp = first;
			Element<Tc> * n;
			Element<Tc> * n1;

			int i = 0;

			while (temp)
			{
				if ((i + 1) == index)
					break;
				temp = temp->next;
				i++;
			}

			if (temp->next->next == nullptr)
			{
				delete[]temp->next->next;
				temp->next = nullptr;
			}
			else
			{
				n = temp->next;
				n1 = n->next;
				temp->next = n1;
				delete[]n;
			}
		}
	}
	else
	{
		std::cout << "This index doesn't exist \n";
	}
}

template <class Tc>
void List<Tc>::View()
{
	if (!isEmpty())
	{
		Element<Tc> * start = first;
		int nr = 0;
		while (start != nullptr)
		{
			std::cout << nr << ": " << start->value << "\n";
			start = start->next;
			nr++;
		}
	}
}

template <class Tc>
bool List<Tc>::isEmpty()
{
	if (first == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class Tc>
void List<Tc>::ViewIndex(int index)
{
	Element<Tc> * temp = first;
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

template<class Tc>
inline int List<Tc>::GetSize()
{
	Element<Tc> * start = first;
	int size = 0;
	while (start)
	{
		size++;
		start = start->next;
	}
	return size;
}
