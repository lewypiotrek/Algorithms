#include "Simulator.h"
Simulator::Simulator()
{
	StationsList = new List<Station>;
	hour = 0;
	min = 0;
	P1 = new Plane("Airbus", 871);
}

Simulator::~Simulator()
{
	delete P1;
	delete StationsList;
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
		short h, m;
		
		// wczytanie czasu odlotu
		file >> h;
		file >> m;
		temp.SetTime(h, m);

		// wczytywanie stacji
		for (int i = 0; i < size; i++)
		{			
			file >> name;
			temp.SetName(name);
			file >> x;
			file >> y;
			temp.SetCoords(x, y);
			StationsList->Add(temp);

			if (i == 0)
			{
				temp.h = 0;	temp.m = 0;
			}
		}
	}
	else
	{
		cout << "ERROR: Cannot open file " << FileName << "...\n";
	}
}

void Simulator::CalculateDistance()
{
	Station * temp;
	Station * temp2;
	
	/*
	temp = StationsList->GetPointer(0);
	temp2 = StationsList->GetPointer(1);

	cout << "T  E  S  T \n"<< temp <<"\n";
	cout  << temp2 << "\n T  E  S  T \n";

	cout << Distance(temp->x, temp->y, temp2->x, temp2->y) << "\n";
	double s = Distance(temp->x, temp->y, temp2->x, temp2->y);
	double v = P1->speed;

	cout << "Czas lotu samolotem "<< P1->name << ": " << s / v << "\n";
	ConvertHour(s / v, hour, min);
	*/
	for (int i = 0; i < size-1; i++)
	{
		temp = StationsList->GetPointer(i);
		temp2 = StationsList->GetPointer(i+1);

		double s = Distance(temp->x, temp->y, temp2->x, temp2->y);
		double v = P1->speed;

//		insert value of flight time
		ConvertHour(s / v, hour, min);

		int addMin = 0;

		if (temp->m + this->min > 60)
		{
			addMin = temp->m + this->min / 60;
			this->min = temp->m + this->min - 60;
		}

		if (temp->h + this->hour + addMin < 24)
		{
			temp2->h = temp->h + this->hour + addMin;
			temp2->m = temp->m + this->min;
			
		}
		else
		{
			temp2->h = (temp->h + this->hour) - 24;
			temp2->m = temp->m + this->min;
		}

		hour = 0;
		min = 0;
	}


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

void Simulator::ConvertHour(double distanceTime, int & h, int & m)
{
	int toMin = distanceTime * 60;
	h = toMin / 60;
	m = toMin - h * 60;
	cout << "czas przelotu " << h << ":" << m << "\n";
}


