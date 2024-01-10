#include <iostream>
#include <conio.h>
#include <io.h>
#include <fcntl.h>

#include"headers.h"

using namespace std;


void menu()
{
	system("CLS");
	cout << "2048\n";
	cout << "Wybierz opcje (1,2,3)\n\n";
	cout << "1. Graj\n";
	cout << "2. Sterowanie\n";
	cout << "3. Wyjdź\n\n";

	bool wrongChoiceFlag = true;
	bool messageShown = false;
	while (wrongChoiceFlag)
	{
		wrongChoiceFlag = false;
		char ch = _getch();
		switch (ch)
		{
		case '1': gameStart(); break;
		case '2': sterowanie(); break;
		case '3': break;
		default: 
			wrongChoiceFlag = true;
			if (!messageShown)
			{
				cout << "Nieprawidłowa opcja\n";
				messageShown = true;
			}
		}
	}
}

void sterowanie()
{
	system("CLS");
	cout << "STEROWANIE\n\n";
	_setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"Żeby poruszać wszystkie elementy na klawiaturze, należy użyć strzałek na klawiaturze (↑, ↓, ←, →), lub (w, s, a, d)\n";
	_setmode(_fileno(stdout), _O_TEXT);
	cout << "Wciśnij dowolny klawisz, żeby powrócić do menu.\n";
	_getch();
	menu();
}