#include <iostream>
#include <cstdlib>
#include <conio.h>

#include "headers.h"

using namespace std;

const int BOARD_SIZE = 4;

int board[BOARD_SIZE][BOARD_SIZE] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };

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
	short slot = rand() % emptySlots;

	short x = 0;
	short y = 0;
	while (slot > 0)
	{
		if (!board[y][x])
			slot++;

		if (x < BOARD_SIZE - 1)
			x++;
		else
		{
			x = 0;
			y++;
			if (y == BOARD_SIZE)
				y = 0;
		}
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

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			cout << board[j][i] << " ";
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
			cout << endl << "Up" << endl;
			break;
		case 115:
			cout << endl << "Down" << endl;
			break;
		case 97:
			cout << endl << "Left" << endl;
			break;
		case 100:
			cout << endl << "Right" << endl;
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
			cout << endl << "Up" << endl;
			break;
		case KEY_DOWN:
			cout << endl << "Down" << endl;
			break;
		case KEY_LEFT:
			cout << endl << "Left" << endl;
			break;
		case KEY_RIGHT:
			cout << endl << "Right" << endl;
			break;
		}
	}
}

void boardMove(char direction)
{


//left
	for (int y = 0; y < BOARD_SIZE; y++)
	{
		short empties = 0;
		int furthest = 1;
		for (int x = 0; x < BOARD_SIZE; x++)
		{
			if (!board[y][x])
				empties++;
			else
			{
				int previous = board[y][x];
				x++;
				while (x < BOARD_SIZE)
				{
					if (board[y][x])
					{
						if (board[y][x] == previous)
						{

						}
					}
					else
						empties++;

					x++;
				}
				if (empties)
				{
					
				}
			}
		}
	}
}