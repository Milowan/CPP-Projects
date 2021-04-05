// Guess My Number
// The classic number guessing game

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
enum proximity
{
	High = 1,
	Low,
	Correct,
	Def
};

int main()
{
	srand(static_cast<unsigned int>(time(0)));  //seed random number generator
	int secretNumber = 0;  // random number between 1 and 100
	int tries = 0;
	int guess = 0;
	int max = 100;
	int min = 1;

	enum proximity rel = Def;



	cout << "\tWelcome to Guess My Number\n\n";
	cout << "Please enter your number: ";
	char *uIn = new char[4];
	cin >> uIn;
	secretNumber = strtol(uIn, NULL, 10);
	delete uIn;

	do
	{
		cout << "Guessing...\n";
		guess = (max - min) / 2 + min;
		cout << "Guess: " << guess << endl;
		++tries;
		cout << "Too High?: 1\n";
		cout << "Too Low?: 2\n";
		cout << "Just Right?: 3\n";
		char *uIn2 = new char[2];
		cin >> uIn2;
		rel = (proximity)strtol(uIn2, NULL, 10);


		if (rel == High)
		{
			max = guess;
		}
		else if (rel == Low)
		{
			min = guess;
		}

	} while (rel != Correct);

	cout << "\nYay! I got it in " << tries << " guesses!\n";

	system("pause");

	return 0;
}