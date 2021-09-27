#include <iostream>
#include <fstream>
#include <string>
#include "AIRPLANE.h"

using namespace std;


void Input(AIRPLANE* Airplane, int size)
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
            Airplane[i] = newAirplane;

            cout << i + 1 << " of " << size << " tickets entered" << endl;
        }
    }

    if (command == 2)
    {
        ifstream read;
        read.open("Input.txt");
        for (int i = 0; i < size; i++)
        {
            read >> Airplane[i];
            cout << "[" << i << "] " << rowOutput << Airplane[i] << endl;
        }
        read.close();
    }

    if (command == 3)
    {
        string cityArray[3] = { "NSK", "SPB", "KRD" };
        string timeArray[5] = { "10:25", "11:45", "12:35", "13:00", "14:00" };
        for (int i = 0; i < size; i++)
        {
            Airplane[i].setDestination(cityArray[rand() % 3]);
            Airplane[i].setFlightNumber(to_string(rand() % 1000));
            Airplane[i].setDepartureTime(timeArray[rand() % 5]);
            Airplane[i].setAirplaneType("Airplane");
            cout << "[" << i << "] " << rowOutput <<Airplane[i] << endl;
        }
    }
}


void Output(AIRPLANE* Airplane, int size)
{
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
            for (int i = 0; i < size; i++)
            {
                cout << rowOutput << Airplane[i] << endl;
            }
        }
        if (format == 2)
        {
            for (int i = 0; i < size; i++)
            {
                cout << columnOutput << Airplane[i] << endl;
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
            for (int i = 0; i < size; i++)
            {
                write << rowOutput << Airplane[i] << endl;
            }
        }
        if (format == 2)
        {
            for (int i = 0; i < size; i++)
            {
                write << columnOutput << Airplane[i] << endl;
            }
        }

        write.close();
        cout << "Successfully outputed" << endl;
    }
}


void Add(AIRPLANE*& Airplane, int& size)
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
            AIRPLANE* newArray = new AIRPLANE[size + 1];
            for (int i = 0; i < size; i++)
            {
                newArray[i] = Airplane[i];
            }

            read >> newArray[size];
            cout << newArray[size] << endl;

            size++;

            delete[] Airplane;

            Airplane = newArray;
        }
        cout << "Successfully added" << endl;
        read.close();
    }

    if (command == 2)
    {
        AIRPLANE* newArray = new AIRPLANE[size + 1];
        for (int i = 0; i < size; i++)
        {
            newArray[i] = Airplane[i];
        }

        cout << "Enter new elem: name of the destination, flight number, departure time, aircraft type" << endl;

        cin >> newArray[size];
        size++;

        delete[] Airplane;
        Airplane = newArray;

        cout << "Successfully added" << endl;
    }
}


void Delete(AIRPLANE*& Airplane, int& size)
{
    cout << "Sign for removal - destination" << endl;

    int k = 0;
    AIRPLANE* newArray = new AIRPLANE[size];
    string sign;
    cout << "Enter destination for removal: " << endl;
    cin >> sign;

    for (int i = 0; i < size; i++)
    {
        if (Airplane[i].getDestination() != sign)
        {
            cout << "k = " << k << endl;
            newArray[k] = Airplane[i];
            cout << "New array elem = " << newArray[k].getDestination() << endl;
            k = k + 1;
        }
    }

    size = k;
    delete[] Airplane;

    Airplane = newArray;

    cout << "Successfully deleted" << endl;
}


void Edit(AIRPLANE* Airplane, int size)
{
    cout << " Enter the ticket number to change " << endl;
    string sign;
    cin >> sign;

    for (int i = 0; i < size; i++)
    {
        if (Airplane[i].getFlightNumber() == sign)
        {
            cout << "Enter new ticket parameters" << endl;
            cout << "Name of the destination, flight number, departure time, aircraft type" << endl;
            cin >> Airplane[i];
        }
    }

    cout << "Successfully edited" << endl;
}


void Select(AIRPLANE* Airplane, int size)
{
    cout << "Enter destination for search" << endl;
    string sign;
    cin >> sign;

    cout << "Search 1, Airplanes to destination = " << endl;

    for (int i = 0; i < size; i++)
    {
        if (Airplane[i].getDestination() == sign)
        {
            cout << columnOutput << Airplane[i] << endl;
        }
    }

    cout << "Enter time for search" << endl;
    cin >> sign;
    cout << "Search 2, Airplanes that departed within an hour after the specified time = " << endl;
    time_t signTime = (time_t)atoi(sign.c_str());

    for (int i = 0; i < size; i++)
    {
        time_t time = (time_t)atoi(Airplane[i].getDepartureTime().c_str()) - signTime;
        if ((time <= 1) && (time >= 0))
        {
            cout << columnOutput << Airplane[i] << endl;
        }
    }
}


void main()
{
    cout << "Enter the count of plane tickets" << endl;
    int size = 0;
    cin >> size;

    AIRPLANE *airplane = new AIRPLANE[size];

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