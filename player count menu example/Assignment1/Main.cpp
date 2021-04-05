#include <iostream>

//function prototype
char menu();

int main()
{
	char display = menu();
	while (true)
	{
		if (display <= '3' && display >= '1')
		{
			if (display == '1')
			{
				std::cout << "you have selected One Player\n";
				char cancel = '0';
				std::cout << "Enter 1 to cancel: ";
				std::cin >> cancel;
				system("cls");
				if (cancel == '1')
				{
					display = menu();
				}
				else
				{
					std::cout << "Not valid input\n";
					system("pause");
					system("cls");
				}
			}
			if (display == '2')
			{
				std::cout << "you have selected Two Player\n";
				char cancel = '0';
				std::cout << "Enter 1 to cancel: ";
				std::cin >> cancel;
				system("cls");
				if (cancel == '1')
				{
					display = menu();
				}
				else
				{
					std::cout << "Not valid input\n";
					system("pause");
					system("cls");
				}
			}
			if (display == '3')
			{
				std::cout << "Closing Game\n";
				system("pause");
				return 0;
			}
		}
		else
		{
			std::cout << "Not valid input\n";
			std::cout << "returning to menu\n";
			system("pause");
			system("cls");
			display = menu();
		}
	}
}

//function definition
char menu()
{
	std::cout << "	Game Menu\n";
	std::cout << "01. One Player\n";
	std::cout << "02. Two Player\n";
	std::cout << "03. Quit\n";

	char uIn = '0';

	std::cout << "Enter Selection: ";
	std::cin >> uIn;
	system("cls");

	return uIn;

}