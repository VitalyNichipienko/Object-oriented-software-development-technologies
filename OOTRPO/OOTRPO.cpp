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
            cin >> Airplane[i];
        }
    }

    if (command == 2)
    {
        ifstream read;
        read.open("Input.txt");
        for (int i = 0; i < size; i++)
        {
            cout << "--- Flight ticket number [" << i << "] ---" << endl;
            read >> Airplane[i];
            cout << Airplane[i] << endl;
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
            Airplane[i].setDestination(cityArray[rand() % 3]);
            Airplane[i].setFlightNumber(to_string(rand() % 1000));
            Airplane[i].setDepartureTime(timeArray[rand() % 5]);
            Airplane[i].setAirplaneType("Airplane");
            cout << Airplane[i] << endl;
        }
    }
}


void Output(AIRPLANE* Airplane, int size)
{
    ofstream write;
    write.open("Output.txt");
    for (int i = 0; i < size; i++)
    {
        write << Airplane[i] << endl;
    }
    write.close();
}


void Add(AIRPLANE*& Airplane, int& size)
{
    cout << "Enter 1 for file write or 2 for keyboard write" << endl;
    int command;
    cin >> command;

    AIRPLANE* newArray = new AIRPLANE[size + 1];
    for (int i = 0; i < size; i++)
    {
        newArray[i] = Airplane[i];
    }

    if (command == 1) // Из файла
    {
        cout << "Enter file name for add" << endl;
        string fileName = "Add.txt";
        cin >> fileName;
        ifstream read;
        read.open(fileName);
        read >> newArray[size];
        read.close();
    }

    if (command == 2) // C клавиатуры
    {
        cout << "Enter new elem: name of the destination, flight number, departure time, aircraft type" << endl;
        cin >> newArray[size];
    }

    ofstream write;
    write.open("Output.txt", ostream::app);
    write << newArray[size];
    write.close();

    size++;
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

    Output(Airplane, size);
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
}


void Select(AIRPLANE* Airplane, int size)
{
    cout << "Enter destination for search" << endl;
    string sign;
    cin >> sign;
    AIRPLANE* searchArray1 = new AIRPLANE[size];
    AIRPLANE* searchArray2 = new AIRPLANE[size];
    int k = 0;

    for (int i = 0; i < size; i++)
    {
        if (Airplane[i].getDestination() == sign)
        {
            cout << "k = " << k << endl;
            searchArray1[k] = Airplane[i];
            cout << "Search 1, New array elem = " << searchArray1[k].getDestination() << endl;
            k = k + 1;
        }
    }


    cout << "Enter time for search" << endl;
    cin >> sign;
    int j = 0;
    time_t signTime = (time_t)atoi(sign.c_str());

    for (int i = 0; i < size; i++)
    {
        time_t time = (time_t)atoi(Airplane[i].getDepartureTime().c_str()) - signTime;
        if ((time <= 1) && (time >= 0))
        {
            cout << "j = " << j << " ";
            searchArray2[j] = Airplane[i];
            cout << "Search 2, New array elem = " << searchArray2[j].getDepartureTime() << endl;
            j = j + 1;
        }
    }
}


void main()
{
    int size = 10;

    AIRPLANE* airplane = new AIRPLANE[size];

    Input(airplane, size);

    cout << "Array is full, what's next?" << endl;
    cout << "1 - Add, 2 - Delete, 3 - Edit, 4 - Select" << endl;
    int command;

    while (true)
    {
        cin >> command;

        if (command == 1)
        {
            cout << "Add" << endl;
            Add(airplane, size);
        }

        if (command == 2)
        {
            cout << "Delete" << endl;
            Delete(airplane, size);
        }

        if (command == 3)
        {
            cout << "Edit" << endl;
            Edit(airplane, size);
        }

        if (command == 4)
        {
            cout << "Select" << endl;
            Select(airplane, size);
        }
    }
}