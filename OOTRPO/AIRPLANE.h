#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class AIRPLANE
{
private:
	#pragma region Fields

	string destination;
	string flightNumber;
	string departureTime;
	string airplaneType;

	#pragma endregion


public:
	#pragma region Ctor
	
	AIRPLANE();

	~AIRPLANE();

	#pragma endregion



	#pragma region Methods

	void setDestination(string destination);
	void setFlightNumber(string flightNumber);
	void setDepartureTime(string departureTime);
	void setAirplaneType(string airplaneType);

	string getDestination();
	string getFlightNumber();
	string getDepartureTime();
	string getAirplaneType();

	friend ostream& operator << (ostream& os, AIRPLANE& airplane);
	friend istream& operator >> (istream& in, AIRPLANE& airplane);

	#pragma endregion
};

