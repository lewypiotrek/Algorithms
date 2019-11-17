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

double Simulator::CalculateDistance()
{




	return 0.0;
}

long double Simulator::toRadians(const long double degree)
{
	long double one_deg = (M_PI) / 180;
	return (one_deg * degree);
}

long double Simulator::Distance(long double lat1, long double long1, long double lat2, long double long2)
{
	// Convert the latitudes  
	// and longitudes 
	// from degree to radians. 
	lat1 = toRadians(lat1);
	long1 = toRadians(long1);
	lat2 = toRadians(lat2);
	long2 = toRadians(long2);

	// Haversine Formula 
	long double dlong = long2 - long1;
	long double dlat = lat2 - lat1;

	long double ans = pow(sin(dlat / 2), 2) +
		cos(lat1) * cos(lat2) *
		pow(sin(dlong / 2), 2);

	ans = 2 * asin(sqrt(ans));

	// Radius of Earth in  
	// Kilometers, R = 6371 
	// Use R = 3956 for miles 
	long double R = 6371;

	// Calculate the result 
	ans = ans * R;

	return ans;
}


