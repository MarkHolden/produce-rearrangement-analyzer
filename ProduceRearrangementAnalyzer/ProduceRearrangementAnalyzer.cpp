
#include <iostream>
#include <Windows.h>
#include <cmath>
#include "PythonConnector.h"

using namespace std;

/// <summary>
/// Main entry point for the application.
/// </summary>
/// <returns>Exit code</returns>
int main()
{
	PythonConnector::callProcedure("PrintSomething");
	cout << PythonConnector::callIntFunc("SquareValue", 2);
	return 0;
}