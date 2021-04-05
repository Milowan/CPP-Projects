#include <iostream>
#include <string>
#include <vector>

using namespace std;

//prototypes
void displayInv(vector <string> inventory, string name);
void moveItem(vector <string> &source, vector <string> &destination);

int main()
{
	vector <string> pInv;
	vector <string> rInv;
	rInv.push_back("Item1");
	rInv.push_back("Item2");
	rInv.push_back("Item3");
	rInv.push_back("Item4");
	string uInput;
	while (uInput != "exit")
	{
		cout << ">>";
		bool validOpt = false;
		do
		{
			cin >> uInput;

			if (uInput != "look" && uInput != "inventory" && uInput != "grab" && uInput != "drop")
			{
				validOpt = false;
			}
			else
			{
				validOpt = true;
			}
		} while (!validOpt);

		system("cls");

		if (uInput == "look")
		{
			displayInv(rInv, "Room");
		}
		if (uInput == "inventory")
		{
			displayInv(pInv, "Inventory");
		}
		if (uInput == "grab")
		{
			moveItem(rInv, pInv);
		}
		if (uInput == "drop")
		{
			moveItem(pInv, rInv);
		}
	}
	return 0;
}

//definitions
void displayInv(vector <string> inventory, string name)
{
	if (inventory.size() != 0)
	{
		vector <string>::iterator scan = inventory.begin();
		while (scan != inventory.end())
		{
			cout << *scan << endl;
			++scan;
		}
	}
	else
	{
		cout << name << " is empty\n";
	}
}

void moveItem(vector <string> &source, vector <string> &destination)
{
	if (source.size() != 0)
	{
		cout << "Please chose the item you want to move: ";
		string target;
		bool invalid = false;
		bool runOnce = false;
		bool realItem = false;
		do
		{
			if (runOnce)
			{
				cout << "That item does not exist, please try again: ";
			}
			cin >> target;

			invalid = cin.fail();

			cin.clear();
			cin.ignore(INT_MAX, '\n');

			for (vector <string>::iterator scan = source.begin(); scan != source.end(); ++scan)
			{
				if (*scan == target)
				{
					realItem = true;

					destination.push_back(*scan);
					source.erase(scan);
					break;
				}
			}

			runOnce = true;
		} while (invalid || !realItem);
	}
	else
	{
		cout << "Cannot perform this operation\n";
	}
}