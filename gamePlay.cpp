#include <iostream>
#include <cstdlib>
#include <conio.h>

#include "headers.h"

using namespace std;

int wynik = 0;

bool gameActive = false;

int numLen(int n)
{
	int c = 0;
	while (n > 0)
	{
		c++;
		n /= 10;
	}
	return c;
}

short emptySlotsCount()
{
	short count = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if(!board[i][j])
				count++;
		}
	}
	return count;
}

void createRandomElement(int emptySlots)
{
	if (!emptySlots)
	{
		gameStarted = false;
		gameActive = false;
	}
	else
	{
		srand((unsigned)time(NULL));
		short slot = rand() % emptySlots + 1;

		short x = -1;
		short y = 0;
		while (slot > 0)
		{
			if (x < BOARD_SIZE - 1)
				x++;
			else
			{
				x = 0;
				y++;
				if (y == BOARD_SIZE)
					y = 0;
			}
			if (!board[y][x])
				slot--;

		}
		if (rand() % 4)
		{
			board[y][x] = 2;
			wynik += 2;
		}
		else
		{
			board[y][x] = 4;
			wynik += 4;
		}
	}
}

void createRandomElement()
{
	createRandomElement(emptySlotsCount());
}

bool gameStarted = false;

void gameStart()
{
	if (!gameStarted)
	{
		gameStarted = true;
		createRandomElement(BOARD_SIZE * BOARD_SIZE);
		createRandomElement(BOARD_SIZE * BOARD_SIZE - 1);
	}
	gameActive = true;
	while (gameActive)
	{
		update();
	}
	if(!gameStarted)
		gameOver();
}

void update()
{
	displayBoard();
	detectMovement();
	createRandomElement();
}


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

int consoleSize = 2 + 9 * BOARD_SIZE;

void displayBoard()
{
	printf("\033[%d;%dH", 1, 1);
	cout << "\n";
	for (int i = 0; i < consoleSize; i++)
		cout << '-';
	cout << endl;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		cout << '|';
		for (int topPart = 0; topPart < BOARD_SIZE; topPart++)
		{
			if (board[i][topPart])
				cout << "---------";
			else
				cout << "         ";
		}
		cout << "|\n|";
		for (int sidePart = 0; sidePart < BOARD_SIZE; sidePart++)
		{
			if (board[i][sidePart])
				cout << "|       |";
			else
				cout << "         ";
		}
		cout << "|\n|";
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (board[i][j])
			{
				cout << '|';
				int numl = numLen(board[i][j]);
				int leftOffset = (7 - numl) / 2;
				int rightOffset = (7 - numl) - leftOffset;
				for (int l = 0; l < leftOffset; l++)
					cout << ' ';
				cout << board[i][j];
				for (int r = 0; r < rightOffset; r++)
					cout << ' ';
				cout << '|';
			}
			else
				cout << "         ";
		}
		cout << "|\n|";
		for (int sidePart = 0; sidePart < BOARD_SIZE; sidePart++)
		{
			if (board[i][sidePart])
				cout << "|       |";
			else
				cout << "         ";
		}
		cout << "|\n|";
		for (int topPart = 0; topPart < BOARD_SIZE; topPart++)
		{
			if (board[i][topPart])
				cout << "---------";
			else
				cout << "         ";
		}
		cout << "|\n";
	}
	for (int i = 0; i < consoleSize; i++)
		cout << '-';
	cout << "\nWynik: " << wynik;
	cout << "\n\nWciœnij 1, ¿eby powróciæ do menu";
}

void detectMovement()
{
	int c = _getch();

	if (c && c != 224)
	{
		switch (c)
		{
		case 119:
			boardMoveUp();
			break;
		case 115:
			boardMoveDown();
			break;
		case 97:
			boardMoveLeft();
			break;
		case 100:
			boardMoveRight();
			break;
		case 49:
			gameActive = false; break;
		default:
			detectMovement();
		}

	}
	else
	{
		switch (int ex = _getch())
		{
		case KEY_UP:
			boardMoveUp();
			break;
		case KEY_DOWN:
			boardMoveDown();
			break;
		case KEY_LEFT:
			boardMoveLeft();
			break;
		case KEY_RIGHT:
			boardMoveRight();
			break;
		}
	}
}


void gameOver()
{
	system("CLS");
	cout << "GAME OVER\n";
	cout << "Twój wynik: " << wynik;

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
			board[i][j] = 0;
	}
	gameStarted = false;
	cout << "\n\nWciœnij dowolny przycisk, ¿eby powróciæ do menu.";
	int c = _getch();
	if (c && c == 224)
		c = _getch();
}