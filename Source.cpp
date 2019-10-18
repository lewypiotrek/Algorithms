#include <iostream>
#include"QueuePL.h"
#include "List.h"

using namespace std;

int main()
{
	List<int> *l = new List<int>;
	
	l->Add(55);
	l->Add(33);
	l->Add(36);
	l->Add(32);
	cout << "Rozmiar: " << l->GetSize() << "\n";
	l->View();
	cout << "-------------\n";

	List<char> *k = new List<char>;

	k->Add('r');
	k->Add('t');
	k->Add('a');
	k->Add('t');
	k->View();

	

	system("pause");
	return 0;
}