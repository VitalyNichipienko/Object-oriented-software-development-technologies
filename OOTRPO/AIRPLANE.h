#pragma once
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;



#pragma region Custom flags

const int specialIndex = ios_base::xalloc();

template <typename charT, typename traits>
inline basic_ostream <charT, traits>& rowOutput(basic_ostream<charT, traits>& out)
{
	out.iword(specialIndex) = true;
	return out;
}


template <typename charT, typename traits>
inline basic_ostream<charT, traits>& columnOutput(basic_ostream<charT, traits>& out)
{
	out.iword(specialIndex) = false;
	return out;
}

#pragma endregion



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

	#pragma region Nested classes

	friend class Hash;
	friend class Equal;


	class AirplaneSortCriterion
	{
	public:

		bool operator()(const AIRPLANE& airplane1, const AIRPLANE& airplane2) const
		{
			int number1 = stoi(airplane1.flightNumber);
			int number2 = stoi(airplane2.flightNumber);

			return number1 < number2 ? true : false;
		}
	};

	#pragma endregion



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

	bool CheckTime(string time);

	friend istream& operator >> (istream& in, AIRPLANE& airplane);

	template <typename charT, typename traits> 
	friend basic_ostream<charT, traits>& operator << (basic_ostream<charT, traits>& out, const AIRPLANE& airplane);

	#pragma endregion
};



#pragma region Operators

template <typename charT, typename traits>
inline basic_ostream<charT, traits>& operator << (basic_ostream<charT, traits>& out, const AIRPLANE& airplane)
{
	basic_ostringstream<charT, traits> s;

	s.copyfmt(out);
	s.width(0);

	if (s.iword(specialIndex))
	{
		s << airplane.destination << " " << airplane.flightNumber << " " << airplane.departureTime << " " << airplane.airplaneType;
	}
	else
	{
		s << "Destination - " << airplane.destination << endl;
		s << "Flight number - " << airplane.flightNumber << endl;
		s << "Departure time - " << airplane.departureTime << endl;
		s << "Airplane type - " << airplane.airplaneType << endl;
	}

	out << s.str();
	return out;
}

#pragma endregion 



#pragma region Nested classes

class Hash
{
public:
	size_t operator() (const AIRPLANE& airplane) const
	{
		return hash<string>()(airplane.destination) ^
			hash<string>()(airplane.flightNumber) ^
			hash<string>()(airplane.departureTime) ^
			hash<string>()(airplane.airplaneType);
	}
};


class Equal
{
public:
	bool operator() (const AIRPLANE& airplane1, const AIRPLANE& airplane2) const
	{
		if (airplane1.destination == airplane2.destination &&
			airplane1.flightNumber == airplane2.flightNumber &&
			airplane1.departureTime == airplane2.departureTime &&
			airplane1.airplaneType == airplane2.airplaneType)
		{
			return true;
		}
		else
		{
			return false;
		}		
	}
};

#pragma endregion
