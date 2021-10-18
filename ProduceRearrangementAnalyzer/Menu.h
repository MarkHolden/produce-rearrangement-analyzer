// *****************************************
// 
// Author: Mark Holden
// Date: 10/17/2021
// CS-210-R1971 Programming Languages 21EW1
// Adapted from Clock Widget menu
// 
// *****************************************

#include <iostream>
#pragma once

/// <summary>
/// Class for displaying the menu and receiving input.
/// </summary>
class Menu
{
public:
    /// <summary>
    /// Default Constructor.
    /// <para>Creates a menu with isExit == false.</para>
    /// </summary>
    Menu();

    /// <summary>
    /// Get the menu selection in a loop, checking for valid input.
    /// </summary>
    /// <returns>Either '1', '2', '3', or '4'.</returns>
    char GetMenuSelection();

    /// <summary>
    /// Whether of not the command to exit has been given.
    /// </summary>
    /// <returns>bool isExit.</returns>
    bool IsExit() { return isExit; }

private:
    bool isExit;

    /// <summary>
    /// Prints the user's available choices to cout.
    /// </summary>
    void PrintMenu();

    /// <summary>
    /// Returns parsed input from cin.
    /// <para>If the user doesn't start typing within 1000 ms, returns '3' (Add Second).</para>
    /// </summary>
    /// <returns>Either '0', '1', '2', '3', or '4'.</returns>
    char GetInput();

    /// <summary>
    /// Verifies the input is valid, and returns 0 if invalid.
    /// <para>Has the side effect that if 4 is parsed, isExit is set to true.</para>
    /// </summary>
    /// <param name="input">Input from the user.</param>
    /// <returns>Either '0', '1', '2', '3', or '4'.</returns>
    char ParseInput(std::string input);
};

