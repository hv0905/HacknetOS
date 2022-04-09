//
// Created by epiphyllum on 22/04/09.
//

#include "Util.h"

#include <Windows.h>
#include <iostream>

void Util::clearScreen()
{
//    setCursorPos(0,0);
//    std::cout << "\033[2J\033[1;1H";
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordScreen = { 0, 0 };    // home for the cursor
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;


    // Get the number of character cells in the current buffer.
    if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
    {
        return;
    }

    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    // Fill the entire screen with blanks.

    if( !FillConsoleOutputCharacter( hConsole,        // Handle to console screen buffer
                                     (TCHAR) ' ',     // Character to write to the buffer
                                     dwConSize,       // Number of cells to write
                                     coordScreen,     // Coordinates of first cell
                                     &cCharsWritten ))// Receive number of characters written
    {
        return;
    }

    // Get the current text attribute.

    if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
    {
        return;
    }

    // Set the buffer's attributes accordingly.

    if( !FillConsoleOutputAttribute( hConsole,         // Handle to console screen buffer
                                     csbi.wAttributes, // Character attributes to use
                                     dwConSize,        // Number of cells to set attribute
                                     coordScreen,      // Coordinates of first cell
                                     &cCharsWritten )) // Receive number of characters written
    {
        return;
    }

    // Put the cursor at its home coordinates.

    SetConsoleCursorPosition( hConsole, coordScreen );
}

std::pair<int, int> Util::getScreenSize()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    return std::pair<int, int>(columns, rows);
}

void Util::sleep(int ms)
{
    Sleep(ms);
}

void Util::setCursorPos(int x, int y)
{
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = x;
    Position.Y = y;

    SetConsoleCursorPosition(hOut, Position);

}
