#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <set>
#include "AIRPLANE.h"

using namespace std;

void Input(unordered_set<AIRPLANE, Hash, Equal>& Airplane)
{
	cout << "Input method:" << endl;
	cout << "1 - manual input, 2 - input from file, 3 - generate array" << endl;
	int command;
	cin >> command;

	if (command == 1)
	{
		cout << "Enter the count of plane tickets" << endl;
		int size = 0;
		cin >> size;

		cout << "Enter: name of the destination, flight number, departure time, aircraft type" << endl;
		for (int i = 0; i < size; i++)
		{
			AIRPLANE newAirplane;
			cin >> newAirplane;
			Airplane.insert(newAirplane);

			cout << i + 1 << " of " << size << " tickets entered" << endl;
		}
	}

	if (command == 2)
	{
		ifstream read;
		read.open("Input.txt");
		while (!read.eof())
		{
			AIRPLANE newAirplane;
			read >> newAirplane;

			cout << rowOutput <<newAirplane << endl;

			Airplane.insert(newAirplane);
		}
		read.close();
	}

	if (command == 3)
	{
		cout << "Enter the count of plane tickets" << endl;
		int size = 0;
		cin >> size;

		string cityArray[3] = { "NSK", "SPB", "KRD" };
		string timeArray[5] = { "10:25", "11:45", "12:35", "13:00", "14:00" };
		for (int i = 0; i < size; i++)
		{
			AIRPLANE newAirplane;
			newAirplane.setDestination(cityArray[rand() % 3]);
			newAirplane.setFlightNumber(to_string(rand() % 1000));
			newAirplane.setDepartureTime(timeArray[rand() % 5]);
			newAirplane.setAirplaneType("Airplane");
			cout << "[" << i << "] " << rowOutput<< newAirplane << endl;
			Airplane.insert(newAirplane);
		}
	}
}


set<AIRPLANE, AIRPLANE::AirplaneSortCriterion> Sort(unordered_set<AIRPLANE, Hash, Equal>& Airplane)
{
	set<AIRPLANE, AIRPLANE::AirplaneSortCriterion> sortedSet;

	for (auto iter = Airplane.begin(); iter != Airplane.end(); iter++)
	{
		sortedSet.insert(*iter);
	}

	return sortedSet;
}


void Output(unordered_set<AIRPLANE, Hash, Equal> Airplane)
{
	set<AIRPLANE, AIRPLANE::AirplaneSortCriterion> sortedSet = Sort(Airplane);

	cout << "Output method" << endl;
	cout << "1 - Console output, 2 - Output to file" << endl;
	int command;
	cin >> command;

	cout << "Output format" << endl;
	cout << "1 - Output in row, 2 - Output in column" << endl;
	int format;
	cin >> format;

	if (command == 1)
	{
		if (format == 1)
		{
			for (auto i = sortedSet.begin(); i != sortedSet.end(); i++)
			{
				cout << rowOutput << *i << endl;
			}
		}
		if (format == 2)
		{
			for (auto i = sortedSet.begin(); i != sortedSet.end(); i++)
			{
				cout << columnOutput << *i << endl;
			}
		}

		cout << "Successfully outputted" << endl;
	}

	if (command == 2)
	{
		ofstream write;
		write.open("Output.txt", ofstream::out | ofstream::trunc);

		if (format == 1)
		{
			for (auto i = sortedSet.begin(); i != sortedSet.end(); i++)
			{
				write << rowOutput << *i << endl;
			}
		}
		if (format == 2)
		{
			for (auto i = sortedSet.begin(); i != sortedSet.end(); i++)
			{
				write << columnOutput << *i << endl;
			}
		}

		write.close();
		cout << "Successfully outputted" << endl;
	}
}


void Add(unordered_set<AIRPLANE, Hash, Equal>& Airplane)
{
	cout << "1 - Adding from the file, 2 - Adding from the keyboard" << endl;
	int command;
	cin >> command;

	if (command == 1)
	{
		string fileName = "Add.txt";
		ifstream read;
		read.open(fileName);

		while (!read.eof())
		{
			AIRPLANE newAirplane;
			read >> newAirplane;

			cout << rowOutput << newAirplane << endl;

			Airplane.insert(newAirplane);
		}
		cout << "Successfully added" << endl;
		read.close();
	}

	if (command == 2)
	{
		AIRPLANE newAirplane;

		cout << "Enter new elem: name of the destination, flight number, departure time, aircraft type" << endl;
		cin >> newAirplane;

		Airplane.insert(newAirplane);
		cout << "Successfully added" << endl;
	}
}


void Delete(unordered_set<AIRPLANE, Hash, Equal>& Airplane)
{
	cout << "Sign for removal - destination" << endl;

	int k = 0;
	string sign;
	cout << "Enter destination for removal: " << endl;
	cin >> sign;

	for (auto i = Airplane.begin(); i != Airplane.end(); i++)
	{
		AIRPLANE newAirplane = *i;
		if (newAirplane.getDestination() == sign)
		{
			Airplane.erase(i);
		}
	}

	cout << "Ticket successfully deleted" << endl;
}


void Edit(unordered_set<AIRPLANE, Hash, Equal>& Airplane)
{
	cout << " Enter the ticket number to change " << endl;
	string sign;
	cin >> sign;

	int j = 0;
	for (auto i = Airplane.begin(); i != Airplane.end(); i++)
	{
		AIRPLANE newAirplane = *i;
		if (newAirplane.getFlightNumber() == sign)
		{
			break;
		}
		j++;
	}

	auto index = Airplane.begin();
	advance(index, j);
	Airplane.erase(index);

	cout << "Enter new ticket parameters" << endl;
	cout << "Name of the destination, flight number, departure time, aircraft type" << endl;

	AIRPLANE newAirplane;
	cin >> newAirplane;
	Airplane.insert(newAirplane);

	cout << "Ticket successfully edited" << endl;
}


void Select(unordered_set<AIRPLANE, Hash, Equal> Airplane)
{
	cout << "Enter destination for search" << endl;
	string sign;
	cin >> sign;

	cout << "Search 1, Airplanes to destination = " << endl;

	for (auto i = Airplane.begin(); i != Airplane.end(); i++)
	{
		AIRPLANE newAirplane = *i;
		if (newAirplane.getDestination() == sign)
		{
			cout << columnOutput << newAirplane << endl;
		}
	}

	cout << "Enter time for search" << endl;
	cin >> sign;
	cout << "Search 2, Airplanes that departed within an hour after the specified time = " << endl;
	time_t signTime = (time_t)atoi(sign.c_str());	

	for (auto i = Airplane.begin(); i != Airplane.end(); i++)
	{
		AIRPLANE newAirplane = *i;
		time_t time = (time_t)atoi(newAirplane.getDepartureTime().c_str()) - signTime;
		if ((time <= 1) && (time >= 0))
		{
			cout << columnOutput << newAirplane << endl;
		}
	}
}


void PrintContainerStructure(unordered_set<AIRPLANE, Hash, Equal>& Airplane)
{
	cout << "Size: " << Airplane.size() << endl;
	cout << "Buckets: " << Airplane.bucket_count() << endl;
	cout << "Load factor: " << Airplane.load_factor() << endl;
	cout << "Max load factor: " << Airplane.max_load_factor() << endl;

	cout << "Data: " << endl;
	for (int i = 0; i != Airplane.bucket_count(); i++)
	{
		if (Airplane.bucket_size(i) > 0)
		{
			cout << " b[" << i << "]: ";
			for (auto pos = Airplane.begin(i); pos != Airplane.end(i); ++pos)
			{
				cout << rowOutput << *pos << "	";
			}
			cout << endl;
		}
	}

	cout << endl;
}


void main()
{
	unordered_set<AIRPLANE, Hash, Equal> airplane;

	Input(airplane);

	cout << "Array is full, what's next?" << endl;
	cout << "1 - Input " << endl;
	cout << "2 - Output" << endl;
	cout << "3 - Add" << endl;
	cout << "4 - Delete" << endl;
	cout << "5 - Edit" << endl;
	cout << "6 - Select" << endl;
	cout << "7 - Print container structure" << endl;
	cout << "8 - Help" << endl;

	int command;

	while (true)
	{
		cin >> command;

		if (command == 1)
		{
			cout << "Input" << endl;
			Input(airplane);
		}

		if (command == 2)
		{
			cout << "Output" << endl;
			Output(airplane);
		}

		if (command == 3)
		{
			cout << "Add" << endl;
			Add(airplane);
		}

		if (command == 4)
		{
			cout << "Delete" << endl;
			Delete(airplane);
		}

		if (command == 5)
		{
			cout << "Edit" << endl;
			Edit(airplane);
		}

		if (command == 6)
		{
			cout << "Select" << endl;
			Select(airplane);
		}

		if (command == 7)
		{
			cout << "Print container structure" << endl;
			PrintContainerStructure(airplane);
			Add(airplane);
			PrintContainerStructure(airplane);
		}

		if (command == 8)
		{
			cout << "Array is full, what's next?" << endl;
			cout << "1 - Input " << endl;
			cout << "2 - Output" << endl;
			cout << "3 - Add" << endl;
			cout << "4 - Delete" << endl;
			cout << "5 - Edit" << endl;
			cout << "6 - Select" << endl;
			cout << "7 - Print container structure" << endl;
			cout << "8 - Help" << endl;
		}
	}
}