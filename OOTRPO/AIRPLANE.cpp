#include "AIRPLANE.h"

#pragma region Ctor

	AIRPLANE::AIRPLANE() {}

	AIRPLANE::~AIRPLANE() {}

#pragma endregion



#pragma region Methods

	void AIRPLANE::setDestination(string destination)
	{
		this->destination = destination;
	}

	void AIRPLANE::setFlightNumber(string flightNumber)
	{
		this->flightNumber = flightNumber;
	}

	void AIRPLANE::setDepartureTime(string departureTime)
	{
		while (true)
		{
			vector<string> arr;
			string inputStr = departureTime;
			string delim = ":";
			size_t prev = 0;
			size_t next;
			size_t delta = delim.length();

			while ((next = inputStr.find(delim, prev)) != string::npos)
			{
				string tmp = inputStr.substr(prev, next - prev);
				arr.push_back(inputStr.substr(prev, next - prev));
				prev = next + delta;
			}
			arr.push_back(inputStr.substr(prev));

			int watches = stoi(arr[0]);
			int	minutes = stoi(arr[1]);

			if (watches >= 24 || watches < 0 || minutes >= 60 || minutes < 0 || arr.size() != 2)
			{
				cout << "Please enter the correct time, time format - \"HH:MM\" " << endl;
				cin >> departureTime;
				continue;
			}
			break;
		}

		this->departureTime = departureTime;
	}

	void AIRPLANE::setAirplaneType(string airplaneType)
	{
		this->airplaneType = airplaneType;
	}

	string AIRPLANE::getDestination()
	{
		return destination;
	}

	string AIRPLANE::getFlightNumber()
	{
		return flightNumber;
	}

	string AIRPLANE::getDepartureTime()
	{
		return departureTime;
	}

	string AIRPLANE::getAirplaneType()
	{
		return airplaneType;
	}

#pragma endregion



#pragma region Operators

	istream& operator >> (istream& in, AIRPLANE& airplane)
	{
		string str1, str2, str3, str4;
		in >> str1 >> str2 >> str3 >> str4;

		airplane.setDestination(str1);
		airplane.setFlightNumber(str2);
		airplane.setDepartureTime(str3);
		airplane.setAirplaneType(str4);

		return in;
	}

#pragma endregion