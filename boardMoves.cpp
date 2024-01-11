#include <iostream>

#include "headers.h"

using namespace std;


void boardMoveLeft()
{
	int boardBefore[BOARD_SIZE][BOARD_SIZE];
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
			boardBefore[i][j] = board[i][j];
	}

	for (int y = 0; y < BOARD_SIZE; y++)
	{
		short empties = 0;
		int* previous = &board[y][0];
		bool prevExists = false;
		for (int x = 0; x < BOARD_SIZE; x++)
		{
			if (board[y][x])
			{
				if (prevExists)
				{
					if (board[y][x] == *previous) // merge 2 numbers
					{
						if (&board[y][x - empties - 1] != previous)
						{
							board[y][x - empties - 1] = *previous * 2;
							*previous = 0;
						}
						else
							*previous *= 2;
						board[y][x] = 0;
						empties += 1;
					}
					else      // dont merge
					{
						if (&board[y][x - empties - 1] != previous)
						{
							board[y][x - empties - 1] = *previous;
							*previous = 0;
						}
						if (empties)
						{
							board[y][x - empties] = board[y][x];
							board[y][x] = 0;
						}
						previous = &board[y][x - empties];
						prevExists = !prevExists;
					}
				}
				else
					previous = &board[y][x];
				prevExists = !prevExists;
			}
			else
				empties++;
		}
		if (prevExists)
		{
			if (board[y][BOARD_SIZE - empties - 1] != *previous)
			{
				board[y][BOARD_SIZE - empties - 1] = *previous;
				*previous = 0;
			}
		}
	}
	createRandomElement();
	if(gameStarted)
	displayBoard();
}




void boardMoveRight()
{
	for (int y = 0; y < BOARD_SIZE; y++)
	{
		short empties = 0;
		int* previous = &board[y][0];
		bool prevExists = false;
		for (int x = BOARD_SIZE - 1; x > -1; x--)
		{
			if (board[y][x])
			{
				if (prevExists)
				{
					if (board[y][x] == *previous) // merge 2 numbers
					{
						if (&board[y][x + empties + 1] != previous)
						{
							board[y][x + empties + 1] = *previous * 2;
							*previous = 0;
						}
						else
							*previous *= 2;
						board[y][x] = 0;
						empties += 1;
					}
					else      // dont merge
					{
						if (&board[y][x + empties + 1] != previous)
						{
							board[y][x + empties + 1] = *previous;
							*previous = 0;
						}
						if (empties)
						{
							board[y][x + empties] = board[y][x];
							board[y][x] = 0;
						}
						previous = &board[y][x + empties];
						prevExists = !prevExists;
					}
				}
				else
					previous = &board[y][x];
				prevExists = !prevExists;
			}
			else
				empties++;
		}
		if (prevExists)
		{
			if (board[y][empties] != *previous)
			{
				board[y][empties] = *previous;
				*previous = 0;
			}
		}
	}
	createRandomElement();
	displayBoard();
}




void boardMoveUp()
{
	for (int x = 0; x < BOARD_SIZE; x++)
	{
		short empties = 0;
		int* previous = &board[0][0];
		bool prevExists = false;
		for (int y = 0; y < BOARD_SIZE; y++)
		{
			if (board[y][x])
			{
				if (prevExists)
				{
					if (board[y][x] == *previous) // merge 2 numbers
					{
						if (&board[y - empties - 1][x] != previous)
						{
							board[y - empties - 1][x] = *previous * 2;
							*previous = 0;
						}
						else
							*previous *= 2;
						board[y][x] = 0;
						empties += 1;
					}
					else      // dont merge
					{
						if (&board[y - empties - 1][x] != previous)
						{
							board[y - empties - 1][x] = *previous;
							*previous = 0;
						}
						if (empties)
						{
							board[y - empties][x] = board[y][x];
							board[y][x] = 0;
						}
						previous = &board[y - empties][x];
						prevExists = !prevExists;
					}
				}
				else
					previous = &board[y][x];
				prevExists = !prevExists;
			}
			else
				empties++;
		}
		if (prevExists)
		{
			if (board[BOARD_SIZE - empties - 1][x] != *previous)
			{
				board[BOARD_SIZE - empties - 1][x] = *previous;
				*previous = 0;
			}
		}
	}
	createRandomElement();
	displayBoard();
}




void boardMoveDown()
{
	for (int x = 0; x < BOARD_SIZE; x++)
	{
		short empties = 0;
		int* previous = &board[0][0];
		bool prevExists = false;
		for (int y = BOARD_SIZE - 1; y > -1; y--)
		{
			if (board[y][x])
			{
				if (prevExists)
				{
					if (board[y][x] == *previous) // merge 2 numbers
					{
						if (&board[y + empties + 1][x] != previous)
						{
							board[y + empties + 1][x] = *previous * 2;
							*previous = 0;
						}
						else
							*previous *= 2;
						board[y][x] = 0;
						empties += 1;
					}
					else      // dont merge
					{
						if (&board[y + empties + 1][x] != previous)
						{
							board[y + empties + 1][x] = *previous;
							*previous = 0;
						}
						if (empties)
						{
							board[y + empties][x] = board[y][x];
							board[y][x] = 0;
						}
						previous = &board[y + empties][x];
						prevExists = !prevExists;
					}
				}
				else
					previous = &board[y][x];
				prevExists = !prevExists;
			}
			else
				empties++;
		}
		if (prevExists)
		{
			if (board[empties][x] != *previous)
			{
				board[empties][x] = *previous;
				*previous = 0;
			}
		}
	}
	createRandomElement();
	displayBoard();
}