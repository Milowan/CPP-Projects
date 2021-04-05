#include "Node.h"
#include "Stack.h"
#include <iostream>

using namespace std;

#define PEGS 3
#define DISKS 4

int main()
{
	Stack pegs[PEGS];
	bool win = false;
	for (int i = DISKS; i > 0; --i)
	{
		pegs->Push(i);
	}

	Stack *comparisonStack = new Stack;
	*comparisonStack = *pegs;

	while (!win)
	{
		bool retry = false;
		for (int i = 0; i < PEGS; ++i)
		{
			cout << "Peg " << i << ":\n";
			Stack *tmp = &pegs[i];
			Node *node = tmp->End();
			for (int i = 0; i < DISKS; ++i)
			{
				if (tmp->Count() < (DISKS - i))
				{
						cout << "   |\n";
				}
				else
				{
					if (node->GetData() == 4)
						cout << "*******\n";
					else if (node->GetData() == 3)
						cout << " *****\n";
					else if (node->GetData() == 2)
						cout << "  ***\n";
					else if (node->GetData() == 1)
						cout << "   *\n";
				}
				if (node != NULL && !(tmp->Count() < (DISKS - i)))
				{
					node = node->GetPrev();
				}
			}

		}

		bool invalid = false;
		cout << "Please select which Peg to move the disk from:\n";
		int uIn1;
		do
		{
			if (invalid)
				cout << "Pegs can only be 0, 1 or 2\n";
			cout << ">>";

			cin >> uIn1;

			invalid = cin.fail();
			if (uIn1 < 0 || uIn1 > 2)
				invalid = true;

			cin.clear();
			cin.ignore(INT_MAX, '\n');
		} while (invalid);

		cout << "Now please select which Peg to move the disk to:\n";
		int uIn2;
		do
		{
			if (invalid)
				cout << "Pegs can only be 0, 1 or 2\nAnd you cannot place a larger disk on a smaller one\n";
			cout << ">>";
			cin >> uIn2;

			invalid = cin.fail();
			if (uIn2 < 0 || uIn2 > 2)
				invalid = true;
			if (pegs[uIn1].Top() > pegs[uIn2].Top() && pegs[uIn2].Top() != -1)
				retry = true;

			cin.clear();
			cin.ignore(INT_MAX, '\n');
		} while (invalid);
		if (!retry)
		{
			Stack *tmp1 = &pegs[uIn1];
			Stack *tmp2 = &pegs[uIn2];
			tmp2->Push(tmp1->Top());
			tmp1->Pop();
			if (*tmp2 == *comparisonStack)
				win = true;
		}
		else
		{
			cout << "inappropriate selection, returning to loop start\n";
		}
	}
	for (int i = 0; i < PEGS; ++i)
	{
		Stack *tmp = &pegs[i];
		tmp->Clear();
	}

	cout << "You Win!\n";

	system("pause");
	return 0;
}