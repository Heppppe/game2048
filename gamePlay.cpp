#include <iostream>
#include <cstdlib>
#include <conio.h>

#include "headers.h"

int board[BOARD_SIZE][BOARD_SIZE] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };

using namespace std;

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
		board[y][x] = 2;
	else
		board[y][x] = 4;
}

void createRandomElement()
{
	createRandomElement(emptySlotsCount());
}


void gameStart()
{
	createRandomElement(BOARD_SIZE * BOARD_SIZE);
	createRandomElement(BOARD_SIZE * BOARD_SIZE - 1);

	displayBoard();
}


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void displayBoard()
{
	system("CLS");
	cout << "\n";

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	detectMovement();
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