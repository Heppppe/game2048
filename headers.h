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

const int BOARD_SIZE = 4;

extern int board[4][4];

#endif
