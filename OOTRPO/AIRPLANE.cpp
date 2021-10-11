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
		if (CheckTime(departureTime) == true)
		{
			this->departureTime = departureTime;
		}
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

	bool AIRPLANE::CheckTime(string time)
	{
		vector<string> arr;
		string inputStr = time;
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
			cout << "Incorrect time entered" << endl;
			return false;
		}

		return true;
	}

#pragma endregion



#pragma region Operators

	istream& operator >> (istream& in, AIRPLANE& airplane)
	{
		string destination, flightNumber, departureTime, airplaneType;
		in >> destination >> flightNumber >> departureTime >> airplaneType;


		if (airplane.CheckTime(departureTime) == true)
		{
			airplane.setDestination(destination);
			airplane.setFlightNumber(flightNumber);
			airplane.setDepartureTime(departureTime);
			airplane.setAirplaneType(airplaneType);
		}
		else
		{
			in.clear(ios::failbit);
			return in;
		}

		return in;
	}

#pragma endregion