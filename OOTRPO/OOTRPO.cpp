#include <iostream>
#include <fstream>
#include <string>
#include "AIRPLANE.h"
#include <list>
#include <vector>

using namespace std;


void Input(list<AIRPLANE>& Airplane)
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
            Airplane.push_back(newAirplane);

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

            cout << newAirplane << endl;

            Airplane.push_back(newAirplane);
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
            cout << "--- Flight ticket number [" << i << "] ---" << endl;
            AIRPLANE newAirplane;
            newAirplane.setDestination(cityArray[rand() % 3]);
            newAirplane.setFlightNumber(to_string(rand() % 1000));
            newAirplane.setDepartureTime(timeArray[rand() % 5]);
            newAirplane.setAirplaneType("Airplane");
            cout << rowOutput << newAirplane << endl;
            Airplane.push_back(newAirplane);
        }
    }
}


void Sort(list<AIRPLANE>& Airplane)
{
    Airplane.sort([](AIRPLANE& airplane1, AIRPLANE& airplane2) 
        {
            int number1 = stoi(airplane1.getFlightNumber());
            int number2 = stoi(airplane2.getFlightNumber());
            return number1 < number2; 
        });
}


void Output(list<AIRPLANE>& Airplane)
{
    Sort(Airplane);

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
            for (auto i = Airplane.begin(); i != Airplane.end(); i++)
            {
                cout << rowOutput << *i << endl;
            }
        }
        if (format == 2)
        {
            for (auto i = Airplane.begin(); i != Airplane.end(); i++)
            {
                cout << columnOutput << *i << endl;
            }
        }

        cout << "Successfully outputed" << endl;
    }

    if (command == 2)
    {
        ofstream write;
        write.open("Output.txt", ofstream::out | ofstream::trunc);

        if (format == 1)
        {
            for (auto i = Airplane.begin(); i != Airplane.end(); i++)
            {
                write << rowOutput << *i << endl;
            }
        }
        if (format == 2)
        {
            for (auto i = Airplane.begin(); i != Airplane.end(); i++)
            {
                write << columnOutput << *i << endl;
            }
        }

        write.close();
        cout << "Successfully outputed" << endl;
    }
}


void Add(list<AIRPLANE>& Airplane)
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

            Airplane.push_back(newAirplane);
        }
        read.close();
        cout << "Successfully added" << endl;
    }

    if (command == 2)
    {
        AIRPLANE newAirplane;

        cout << "Enter new elem: name of the destination, flight number, departure time, aircraft type" << endl;
        cin >> newAirplane;

        Airplane.push_back(newAirplane);
        cout << "Successfully added" << endl;
    }
}


void Delete(list<AIRPLANE>& Airplane)
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

    cout << "Successfully deleted" << endl;
}


void Edit(list<AIRPLANE>& Airplane)
{
    cout << " Enter the ticket number to change " << endl;
    string sign;
    cin >> sign;

    for (auto i = Airplane.begin(); i != Airplane.end(); i++)
    {
        AIRPLANE newAirplane = *i;
        if (newAirplane.getFlightNumber() == sign)
        {
            cout << "Enter new ticket parameters" << endl;
            cout << "Name of the destination, flight number, departure time, aircraft type" << endl;
            cin >> *i;
        }
    }

    cout << "Successfully edited" << endl;
}


void Select(list<AIRPLANE>& Airplane)
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


void main()
{
    list<AIRPLANE> airplane;

    Input(airplane);

    cout << "Array is full, what's next?" << endl;
    cout << "1 - Input " << endl;
    cout << "2 - Output" << endl;
    cout << "3 - Add" << endl;
    cout << "4 - Delete" << endl;
    cout << "5 - Edit" << endl;
    cout << "6 - Select" << endl;
    cout << "7 - Help" << endl;
    
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
            cout << "Array is full, what's next?" << endl;
            cout << "1 - Input " << endl;
            cout << "2 - Output" << endl;
            cout << "3 - Add" << endl;
            cout << "4 - Delete" << endl;
            cout << "5 - Edit" << endl;
            cout << "6 - Select" << endl;
            cout << "7 - Help" << endl;
        }
    }
}