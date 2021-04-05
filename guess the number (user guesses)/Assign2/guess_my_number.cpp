// Guess My Number
// The classic number guessing game

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));  //seed random number generator

	int secretNumber = rand() % 100 + 1;  // random number between 1 and 100
	int tries = 0;
	int guess = 0;
	bool correct = false;
    
	cout << "\tWelcome to Guess My Number\n\n";

	do
	{
		cout << "Enter a guess: ";
		char *uIn = new char[4];
		cin >> uIn;
		guess = strtol(uIn, NULL, 10);
		++tries;

		if (guess > secretNumber)
		{
			cout << "Too high!\n\n";
		}
		else if (guess < secretNumber)
		{
			cout << "Too low!\n\n";
		}
		else
		{
			cout << "\nThat's it! You got it in " << tries << " guesses!\n";
			correct = true;
		}

	} while (guess != secretNumber && tries < 5);
	if (!correct)
	{
		cout << "You have run out of guesses, please play again\n";
	}

	system("pause");

    return 0;
}
