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
		file >> size;
		Station temp;
		string name;
		short x, y;

		// wczytywanie stacji
		for (int i = 0; i < size; i++)
		{
			file >> name;
			temp.SetName(name);
			file >> x;
			file >> y;
			temp.SetCoords(x, y);
			StationsList->Add(temp);
		}
	}
	else
	{
		cout << "ERROR: Cannot open file " << FileName << "...\n";
	}
}
