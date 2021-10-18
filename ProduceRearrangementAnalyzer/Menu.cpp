#include "Menu.h"
#include <iostream>
#include <string>
// *****************************************
// 
// Author: Mark Holden
// Date: 9/11/2021
// CS-210-R1971 Programming Languages 21EW1
// 
// *****************************************

#include <windows.h>
#include <synchapi.h>

using namespace std;

Menu::Menu() : isExit(false) {}

char Menu::GetMenuSelection()
{
    bool validSelection = false;
    char input;
    PrintMenu();
    while (!validSelection)
    {
        input = GetInput();
        validSelection = input != '0';
        if (!validSelection)
        {
            cout << "Invalid entry. Please try again." << endl;
        }
    }
    return input;
}

void Menu::PrintMenu()
{
    cout << endl;
    cout << "What would you like to do?" << endl;
    cout << "1: Determine the number of times each individual item appears." << endl;
    cout << "2: Determine the frequency of a specific item." << endl;
    cout << "3: Graphically display a data file as a text-based histogram." << endl;
    cout << "4: Exit Program" << endl;
}

char Menu::GetInput()
{
    string selection;
    getline(cin, selection);
    return ParseInput(selection);
}

char Menu::ParseInput(string input)
{
    if (input.length() > 1)
    {
        return '0';
    }
    else
    {
        switch (input[0])
        {
        case '4':
            isExit = true;
        case '1':
        case '2':
        case '3':
            return input[0];
        default:
            return '0';
        }
    }
}
