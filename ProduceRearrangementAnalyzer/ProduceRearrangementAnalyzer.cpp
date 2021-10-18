
#include <iostream>
#include <Windows.h>
#include <cmath>
#include "PythonConnector.h"
#include "Menu.h"

using namespace std;

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
            PythonConnector::callProcedure("PrintFrequencies");
            break;
        case '2':
            PythonConnector::callProcedure("PrintItemFrequency", "banana");
            break;
        case '3':
            PythonConnector::callProcedure("PrintHistogram");
            break;
        default:
            break;
        }
    }

	return 0;
}