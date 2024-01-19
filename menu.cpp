#include <iostream>
#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include <fstream>
#include <string>

#include"headers.h"

using namespace std;

bool gameOn = true;

void menu()
{
	bool wrongChoiceFlag = false;
	while (gameOn)
	{
		system("CLS");
		cout << "2048\n";
		cout << "Wybierz opcje (1,2,3)\n\n";
		cout << "1. Graj\n";
		cout << "2. Sterowanie\n";
		cout << "3. Wyjdź\n\n";

		if (wrongChoiceFlag)
		{
			cout << "Nieprawidłowa opcja\n";
			wrongChoiceFlag = false;
		}

		char ch = _getch();
		switch (ch)
		{
		case '1': gameStart(); break;
		case '2': sterowanie(); break;
		case '3': exitGame(); break;
		default:
			wrongChoiceFlag = true;
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
}

void saveScore(int score)
{
	fstream plik;
	if (score > readHighscore())
	{
		plik.open("highscore.txt", ios::out);
		plik << to_string(score);
		plik.close();
	}
}

void exitGame()
{
	gameOn = false; 
	gameStarted = false;
	saveScore(getScore());
}