// File				: minesweeper.cpp
// PROJECT			: Minesweeper
// PROGRAMMER		: Gavin McGuire

#include <iostream>
#include <ctime>
#include "Space.h"

#define ESQUARE 9

#define EMCNT 15

#define AXES 2

//prototypes
void draw(Space board[ESQUARE][ESQUARE]);
void setMineCnt(Space board[ESQUARE][ESQUARE]);
int setMineCnt(Space board[ESQUARE][ESQUARE], int height, int width);
int setMineCnt(Space board[ESQUARE][ESQUARE], int start, int end, int width);
int setMineCnt(Space *board, int start, int end);
int setMines(Space board[ESQUARE][ESQUARE], int nMines);
void activateZeros(Space board[ESQUARE][ESQUARE]);
void activateZeros(Space board[ESQUARE][ESQUARE], int height, int width);
void activateZeros(Space board[ESQUARE][ESQUARE], int start, int end, int width);
void activateZeros(Space *board, int start, int end);

int main()
{

	srand((unsigned int)time(0));

	Space display[ESQUARE][ESQUARE];

	int mineCnt = 0;
	bool over = false;

	//populate the minefield
	mineCnt = setMines(display, EMCNT);

	//count adjacent mines for each space
	setMineCnt(display);
	
	while (!over)
	{
		//refresh board multiple times
		for (int i = 0; i < ESQUARE; ++i)
		{
			system("cls");
			std::cout << "Mines: " << mineCnt << std::endl;
			activateZeros(display);

			//draw the board
			draw(display);
		}
		
		//player prompt
		std::cout << std::endl;
		std::cout << "Please enter tile coordinates one by one (horizontal then vertical): ";
		int coords[AXES];
		bool invalid = false;
		do
		{
			if (invalid)
			{
				std::cout << "Invalid input, please try again: ";
			}

			std::cin >> coords[0] >> coords[1];

			invalid = std::cin.fail();
			if (coords[0] < 0 || coords[0] > ESQUARE || coords[1] < 0 || coords[1] > ESQUARE)
			{
				invalid = true;
			}

			std::cin.clear();
			std::cin.ignore();
		} while (invalid);
		
		int x = coords[0];
		int y = coords[1];

		std::cout << "Do you want to flag or activate this tile? (f / a): ";
		char option = 'd';
		do
		{
			if (invalid)
			{
				std::cout << "Invalid input, please try again: ";
			}

			std::cin >> option;

			invalid = std::cin.fail();
			if (option != 'a' && option != 'f' && option != 'd')
			{
				invalid = true;
			}

			std::cin.clear();
			std::cin.ignore();
		} while (invalid);

		//flag space
		if (option == 'f')
		{
			display[x][y].toggleFlagState();
			if (display[x][y].getMineState())
			{
				mineCnt--;
			}
			if (mineCnt == 0)
			{
				std::cout << "You win!\n";
				over = true;
			}
		}

		//activate space
		if (option == 'a')
		{
			display[x][y].activateSpace();
			if (display[x][y].getMineState() && !display[x][y].getFlagState())
			{
				over = true;
				std::cout << "You lost!\n";
			}
			
		}
	}

	system("pause");
	return 0;
}

//definitions
void draw(Space board[ESQUARE][ESQUARE])
{
	std::cout << " ";
	for (int i = 0; i < ESQUARE; ++i)
	{
		std::cout << " " << i;
	}
	std::cout << std::endl;

	for (int i = 0; i < ESQUARE; ++i)
	{
		std::cout << i;
		for (int j = 0; j < ESQUARE; ++j)
		{
			if (board[i][j].getActiveState() && !board[i][j].getFlagState())
			{

				std::cout << " " << board[i][j].getMNum();
			}
			else if (board[i][j].getFlagState())
			{
				std::cout << " f";
			}
			else
			{
				std::cout << " +";
			}
		}
		std::cout << std::endl;
	}
}

void setMineCnt(Space board[ESQUARE][ESQUARE])
{
	for (int i = 0; i < ESQUARE; ++i)
	{
		for (int j = 0; j < ESQUARE; ++j)
		{
			int mCnt = 0;
			mCnt = setMineCnt(board, i, j);
			board[i][j].setMNum(mCnt);
		}
	}
}

int setMineCnt(Space board[ESQUARE][ESQUARE], int height, int width)
{
	int i = 0;
	if (height > 0 && height < ESQUARE - 1)
	{
		i = setMineCnt(board, height - 1, height + 2, width);
	}
	else if (height == 0)
	{
		i = setMineCnt(board, height, height + 2, width);
	}
	else if (height == ESQUARE - 1)
	{
		i = setMineCnt(board, height - 1, ESQUARE, width);
	}
	return i;
}

int setMineCnt(Space board[ESQUARE][ESQUARE], int start, int end, int width)
{
	int count = 0;
	for (int i = start; i < end; ++i)
	{
		if (width > 0 && width < ESQUARE - 1)
		{
			count += setMineCnt(&board[i][width], width - 1, width + 2);
		}
		else if (width == 0)
		{
			count += setMineCnt(&board[i][width], width, width + 2);
		}
		else if (width == ESQUARE - 1)
		{
			count += setMineCnt(&board[i][width], width - 1, ESQUARE);
		}
	}
	return count;
}

int setMineCnt(Space *board, int start, int end)
{
	int count = 0;
	for (int i = start; i < end; ++i)
	{
		if (board[i].getMineState())
			++count;
	}
	return count;
}

int setMines(Space board[ESQUARE][ESQUARE], int nMines)
{
	int mines = 0;
	while (mines < nMines)
	{
		int x = (int)rand() % ESQUARE;
		int y = (int)rand() % ESQUARE;

		if (!board[x][y].getMineState())
		{
			board[x][y] = Space(true);
			++mines;
		}
	}

	return mines;
}

/* Steven - you should consider breaking down this into functions, doing this will make it easier on you to debug less lines to write.
Try to avoid doing this in the future.
*/
void activateZeros(Space board[ESQUARE][ESQUARE])
{
	for (int i = 0; i < ESQUARE; ++i)
	{
		for (int j = 0; j < ESQUARE; ++j)
		{
			if (board[i][j].getMNum() == 0 && board[i][j].getActiveState())
			{
				activateZeros(board, i, j);
			}
		}
	}
}

void activateZeros(Space board[ESQUARE][ESQUARE], int height, int width)
{
	if (height > 0 && height < ESQUARE - 1)
	{
		activateZeros(board, height - 1, height + 2, width);
	}
	else if (height == 0)
	{
		activateZeros(board, height, height + 2, width);
	}
	else if (height == ESQUARE - 1)
	{
		activateZeros(board, height - 1, ESQUARE, width);
	}
}

void activateZeros(Space board[ESQUARE][ESQUARE], int start, int end, int width)
{
	for (int i = start; i < end; ++i)
	{
		if (width > 0 && width < ESQUARE - 1)
		{
			activateZeros(&board[i][width], width - 1, width + 2);
		}
		else if (width == 0)
		{
			activateZeros(&board[i][width], width, width + 2);
		}
		else if (width == ESQUARE - 1)
		{
			activateZeros(&board[i][width], width - 1, ESQUARE);
		}
	}
}

void activateZeros(Space *board, int start, int end)
{
	for (int i = start; i < end; ++i)
	{
		board[i].activateSpace();
	}
}