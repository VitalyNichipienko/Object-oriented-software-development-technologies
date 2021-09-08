#include "AIRPLANE.h"

#pragma region Ctor

AIRPLANE::AIRPLANE(){}

AIRPLANE::~AIRPLANE(){}

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

ostream& operator << (ostream& os, AIRPLANE& airplane) 
{
	os << "Destination - " << airplane.getDestination() << endl;
	os << "Flight number - " << airplane.getFlightNumber() << endl;
	os << "Departure time - " << airplane.getDepartureTime() << endl;
	os << "Airplane type - " << airplane.getAirplaneType() << endl;

	return os;
}

#pragma endregion