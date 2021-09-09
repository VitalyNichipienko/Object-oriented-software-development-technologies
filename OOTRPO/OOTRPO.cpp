#include <iostream>
#include <fstream>
#include <string>
#include "AIRPLANE.h"
#include <list>
using namespace std;


void Input(list<AIRPLANE> Airplane, int size)
{
    cout << "Input method:" << endl;
    cout << "1 - manual input, 2 - input from file, 3 - generate array" << endl;
    int command;
    cin >> command;

    if (command == 1)
    {
        cout << "Enter: name of the destination, flight number, departure time, aircraft type" << endl;
        for (int i = 0; i < size; i++)
        {
            AIRPLANE newAirplane;
            cin >> newAirplane;
            Airplane.push_back(newAirplane);
            
            cout << i  << "of" << size << "tickets entered" << endl;
        }
    }

    if (command == 2)
    {
        ifstream read;
        read.open("Input.txt");
        for (int i = 0; i < size; i++)
        {
            cout << "--- Flight ticket number [" << i << "] ---" << endl;
            AIRPLANE newAirplane;
            read >> newAirplane;
            cout << newAirplane << endl;
            Airplane.push_back(newAirplane);
        }
        read.close();
    }

    if (command == 3)
    {
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
            cout << newAirplane << endl;
            Airplane.push_back(newAirplane);
        }
    }
}


void Output(list<AIRPLANE> Airplane, int size)
{
    cout << "Output method" << endl;
    cout << "1 - Console output, 2 - Output to file" << endl;
    int command;
    cin >> command;

    if (command == 1)
    {
        for (auto i = Airplane.begin(); i != Airplane.end(); i++)
        {
            cout << *i << endl;
        }
    }

    if (command == 2)
    {
        ofstream write;
        write.open("Output.txt", ofstream::out | ofstream::trunc);

        for (auto i = Airplane.begin(); i != Airplane.end(); i++)
        {
            write << *i << endl;
        }

        write.close();
        cout << "Successfully writed" << endl;
    }
}


void Add(list<AIRPLANE>& Airplane, int& size)
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

            cout << newAirplane << endl;

            Airplane.push_back(newAirplane);
        }
        read.close();
    }

    if (command == 2)
    {
        AIRPLANE newAirplane;

        cout << "Enter new elem: name of the destination, flight number, departure time, aircraft type" << endl;
        cin >> newAirplane;

        Airplane.push_back(newAirplane);
    }
}


void Delete(list<AIRPLANE>& Airplane, int& size)
{
    cout << "Sign for removal - destination" << endl;

    int k = 0;
    AIRPLANE* newArray = new AIRPLANE[size];
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


void Edit(list<AIRPLANE> Airplane, int size)
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

    cout << "Ticket successfully edited" << endl;
}


void Select(list<AIRPLANE> Airplane, int size)
{
    cout << "Enter destination for search" << endl;
    string sign;
    cin >> sign;
    list<AIRPLANE> searchList1;
    list<AIRPLANE> searchArray2;

    for (auto i = Airplane.begin(); i != Airplane.end(); i++)
    {
        AIRPLANE newAirplane = *i;
        if (newAirplane.getDestination() == sign)
        {
            searchList1.push_back(newAirplane);
            cout << "Search 1, Airplanes to destination = " << newAirplane.getDestination() << endl;
        }
    }


    cout << "Enter time for search" << endl;
    cin >> sign;
    int j = 0;
    time_t signTime = (time_t)atoi(sign.c_str());

    for (auto i = Airplane.begin(); i != Airplane.end(); i++)
    {
        AIRPLANE newAirplane = *i;
        time_t time = (time_t)atoi(newAirplane.getDepartureTime().c_str()) - signTime;
        if ((time <= 1) && (time >= 0))
        {
            cout << "j = " << j << " ";
            searchArray2.push_back(newAirplane);
            cout << "Search 2, New array elem = " << newAirplane.getDepartureTime() << endl;
            j = j + 1;
        }
    }
}


void main()
{
    cout << "Enter the count of plane tickets" << endl;
    int size = 0;
    cin >> size;

    list<AIRPLANE> airplane(size);

    Input(airplane, size);

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
            Input(airplane, size);
        }

        if (command == 2)
        {
            cout << "Output" << endl;
            Output(airplane, size);
        }

        if (command == 3)
        {
            cout << "Add" << endl;
            Add(airplane, size);
        }

        if (command == 4)
        {
            cout << "Delete" << endl;
            Delete(airplane, size);
        }

        if (command == 5)
        {
            cout << "Edit" << endl;
            Edit(airplane, size);
        }

        if (command == 6)
        {
            cout << "Select" << endl;
            Select(airplane, size);
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