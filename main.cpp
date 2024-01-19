#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cwchar>

#include"headers.h"

using namespace std;

int board[BOARD_SIZE][BOARD_SIZE];

int main()
{
    setlocale(LC_CTYPE, "Polish");
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);

    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 26;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

    MoveWindow(console, r.left, r.top, 1000, 1000, TRUE);

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
            board[i][j] = 0;
    }

    menu();
}
