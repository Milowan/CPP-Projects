#include <iostream>
#include <string>

//prototypes
int getUserIn(int sSize, int mTake);

int main()
{
	int stackMax = 13;
	int stackSize = stackMax;
	int grabMax = 4;
	int grabCnt = 0;
	bool p2 = false;
	while (stackSize > 0)
	{
		if (p2)
		{
			std::cout << "Player 2: \n";
			grabCnt = getUserIn(stackSize, grabMax);
		}
		else
		{
			std::cout << "Player 1: \n";
			grabCnt = getUserIn(stackSize, grabMax);
		}
		stackSize -= grabCnt;
		p2 = !p2;
	}

	if (p2)
	{
		std::cout << "Player One Wins!\n";
	}
	else
	{
		std::cout << "Player Two Wins!\n";
	}

	system("pause");

	return 0;
}

//definitions
int getUserIn(int sSize, int mTake)
{
	int pCount = 0;
	while (pCount < 1 || (pCount > mTake || pCount > sSize))
	{
		std::cout << "How many sticks will you take?\n";
		std::cout << "Please choose a value greater than one and\n";
		std::cout << "less than either 4 or the stack size if less than 4\n";
		char *uIn = new char[3];
		std::cin >> uIn;
		pCount = strtol(uIn, NULL, 10);
		system("cls");
	}
	return pCount;
}