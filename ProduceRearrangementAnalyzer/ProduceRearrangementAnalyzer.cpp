
#include <iostream>
#include <Windows.h>
#include <cmath>
#include "PythonConnector.h"
#include "Menu.h"

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
    int count = PythonConnector::callIntFunc("PrintItemFrequency", searchTerm);
    cout << "Item: " << searchTerm << "\tQuantity:" << count << endl;
}

/// <summary>
/// Displays a histogram for produce frequencies.
/// </summary>
void printHistogram()
{
    PythonConnector::callProcedure("PrintHistogram");
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