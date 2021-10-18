// *****************************************
// 
// Author: Mark Holden
// Date: 10/18/2021
// CS-210-R1971 Programming Languages 21EW1
// 
// *****************************************

#include <iostream>
#include <Windows.h>
#include <cmath>
#include "PythonConnector.h"
#include "Menu.h"
#include <fstream>
#include <iomanip>

using namespace std;

/// <summary>
/// Displays produce frequencies.
/// </summary>
void printFrequencies()
{
    PythonConnector::callProcedure("PrintFrequencies");
}

/// <summary>
/// Prompts the user for a search term and displays the frequency for that produce.
/// </summary>
void printItemFrequency()
{
    cout << "Name of the item for which to display frequency: ";
    string searchTerm;
    getline(cin, searchTerm);
    int count = PythonConnector::callIntFunc("GetItemFrequency", searchTerm);
    cout << "Item: " << searchTerm << "\tQuantity:" << count << endl;
}

/// <summary>
/// Displays the characters for the histogram in a fun way.
/// </summary>
void printRainbowSpecialCharacters(int count)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // Handle for standard output.
    for (unsigned int i = 0; i < count; ++i)
    {
        SetConsoleTextAttribute(h, i + 1); // skip 0 becase it's black, so you can't see it.
        cout << "#";
    }
    SetConsoleTextAttribute(h, 15);             // Sets console output color back to white.
}

/// <summary>
/// Displays a histogram for produce frequencies.
/// </summary>
void printHistogram()
{
    PythonConnector::callProcedure("SaveHistogramData");

    ifstream infile("frequency.dat");
    string name;
    int freq;
    while (infile >> name >> freq)
    {
        cout << std::setw(14) << left << name;
        printRainbowSpecialCharacters(freq);
        cout << endl;
    }
}

/// <summary>
/// Main entry point for the application.
/// </summary>
/// <returns>Exit code</returns>
int main()
{
    Menu menu{};
    while (!menu.IsExit())
    {
        switch (menu.GetMenuSelection())
        {
        case '1':
            printFrequencies();
            break;
        case '2':
            printItemFrequency();
            break;
        case '3':
            printHistogram();
            break;
        default:
            break;
        }
    }

	return 0;
}