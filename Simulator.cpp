#include "Simulator.h"



Simulator::Simulator()
{
	StationsList = new List<Station>;
}


Simulator::~Simulator()
{
	
}

void Simulator::LoadStationsByFile(string FileName)
{
	fstream file;

	file.open(FileName, ios::in);

	if (file.good())
	{
		cin >> size;

		


		for (int i = 0; i < size; i++)
		{

		}
	}
}
