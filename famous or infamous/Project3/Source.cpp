#include <iostream>
#include "Game.h"

//this is project 1 and 2, I did project 1 then changed it for 2 because I was too lazy to make a new project
int main()
{
	Game famousInfamous;
	char again;

	famousInfamous.DisplayInstructions();

	do
	{
		famousInfamous.Play();
		cout << endl << "Play again? (y/n): ";
		cin >> again;
	} while (again == 'y');

	return 0;
}