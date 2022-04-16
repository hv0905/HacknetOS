//
// Created by epiphyllum on 22/04/09.
//

#include "Util.h"

#include <Windows.h>
#include <iostream>

/* https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c
 * Name            FG  BG
 * Black           30  40
 * Red             31  41
 * Green           32  42
 * Yellow          33  43
 * Blue            34  44
 * Magenta         35  45
 * Cyan            36  46
 * White           37  47
 * Bright Black    90  100
 * Bright Red      91  101
 * Bright Green    92  102
 * Bright Yellow   93  103
 * Bright Blue     94  104
 * Bright Magenta  95  105
 * Bright Cyan     96  106
 * Bright White    97  107
 * */

void Util::clearScreen()
{
//    setCursorPos(0,0);
//    std::cout << "\033[2J\033[1;1H";
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordScreen = {0, 0};    // home for the cursor
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;


    // Get the number of character cells in the current buffer.
    if( !GetConsoleScreenBufferInfo(hConsole, &csbi ))
    {
        return;
    }

    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    // Fill the entire screen with blanks.

    if( !FillConsoleOutputCharacter(hConsole,        // Handle to console screen buffer
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

    if( !FillConsoleOutputAttribute(hConsole,         // Handle to console screen buffer
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

void Util::printOneByOne(const std::wstring& str, int breakTime)
{
    for(auto& i : str)
    {
        std::wcout << i;
        Util::sleep(breakTime);
    }
}

void Util::setupScreenSize(int w, int h) {
    char setting[30];
    sprintf_s(setting, "mode con:cols=%d lines=%d", w, h);
    system(setting);
}

void Util::moveCursorPos(int vecX, int vecY)
{
    auto initPos = getCursorPos();
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = initPos.first + vecX;
    Position.Y = initPos.second + vecY;

    SetConsoleCursorPosition(hOut, Position);
}

std::pair<int, int> Util::getCursorPos()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleScreenBufferInfo(hOut, &csbi);

    Position.X = csbi.dwCursorPosition.X;
    Position.Y = csbi.dwCursorPosition.Y;

    return std::pair<int, int>(Position.X, Position.Y);
}

