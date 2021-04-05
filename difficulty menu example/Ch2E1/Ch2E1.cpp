#include <iostream>

enum difficulty
{
	easy = 1,
	normal,
	hard,
};

int main()
{
	std::cout << "Difficulty Levels\n\n";
	std::cout << "1 - Easy\n";
	std::cout << "2 - Normal\n";
	std::cout << "3 - Hard\n\n";

	char* uIn = new char;
	std::cout << "Choice: ";
	std::cin >> uIn;
	enum difficulty choice;
	choice = (difficulty) strtol(uIn, NULL, 10);

	switch (choice)
	{
	case easy:
		std::cout << "You picked Easy.\n";
		break;
	case normal:
		std::cout << "You picked Normal.\n";
		break;
	case hard:
		std::cout << "You picked Hard.\n";
		break;
	default:
		std::cout << "You made an illegal choice.\n";
	}

	system("pause");

	return 0;
}