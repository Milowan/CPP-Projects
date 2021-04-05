#include <iostream>
#include <ctime>

#define NUMSIZE 4

int main()
{

	int codeNum[NUMSIZE];
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < NUMSIZE; ++i)
	{
		codeNum[i] = (int) rand() % 2;
	}

	int correctCnt = 0;
	int triesLeft = 5;

	while (triesLeft > 0)

	{
		correctCnt = 0;

		for (int i = 0; i < NUMSIZE; ++i)
		{
			std::cout << "please guess digit number " << i + 1 << ": ";
			bool invalid = false;
			int guess = 0;
			do
			{
				if (invalid || guess > 1)
				{
					std::cout << "invalid input, please guess either 0 or 1: ";
				}
				std::cin >> guess;

				invalid = std::cin.fail();

				std::cin.clear();
				std::cin.ignore();
			} while (invalid || guess > 1);

			if (guess == codeNum[i])
			{
				++correctCnt;
			}
		}

		std::cout << "You guessed " << correctCnt << " of " << NUMSIZE << " correctly\n";

		if (correctCnt == NUMSIZE)
		{
			std::cout << "Congradulations! you win!\n";
			break;
		}

		--triesLeft;
		if (triesLeft > 0)
		{
			std::cout << "Tries left: " << triesLeft << std::endl;

			system("pause");
			system("cls");
		}
		else
		{
			std::cout << "Out of tries, please play again!\n";
		}
	}



	system("pause");
	return 0;
}