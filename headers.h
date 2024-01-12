#ifndef MENU_H
#define MENU_H

void menu();

void gameStart();

void sterowanie();

void createRandomElement(int emptySlots);

void createRandomElement();

void displayBoard();

void detectMovement();

void boardMoveLeft();
void boardMoveRight();
void boardMoveUp();
void boardMoveDown();

int numLen(int n);

void gameOver();

void update();

const int BOARD_SIZE = 4;

extern int board[BOARD_SIZE][BOARD_SIZE];
extern bool gameStarted;

#endif
