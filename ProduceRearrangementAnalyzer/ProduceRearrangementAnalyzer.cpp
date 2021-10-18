
#include <iostream>
#include <Windows.h>
#include <cmath>
#include "PythonConnector.h"
#include "Menu.h"

using namespace std;

void printFrequencies()
{
    PythonConnector::callProcedure("PrintFrequencies");
}

void printItemFrequency()
{
    int count = PythonConnector::callIntFunc("PrintItemFrequency", "banana");
    cout << "Item: " << "banana" << "\tQuantity:" << count << endl;
    count = PythonConnector::callIntFunc("PrintItemFrequency", "Apples");
    cout << "Item: " << "Apples" << "\tQuantity:" << count << endl;
}

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