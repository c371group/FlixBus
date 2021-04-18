#include "loggedInInterface.h"

loggedInInterface::loggedInInterface(Account& account)
{
	system("CLS");
	std::cout << "Welcome, " << account.get_customer().getFirstName() << std::endl;
	preLoad();
	menuLogic();
}

void loggedInInterface::preLoad()
{
	std::vector<std::string> menu = { "Account Info", "Your Upcoming Trips", "Browse Available Trips", "Book Trip", "Account Trip History", "Log Out"};
	std::vector<std::vector<std::string>> temp = { menu };
	set_vecMen(temp);
}

int loggedInInterface::menuLogic()
{
	int max = display_menu_items(0);
	int choice_int = enterChoice(max);
	bool confirm = confirm_Menu_Choice(0, choice_int - 1);

	if (!confirm)
	{
		menuLogic();
	}
	else
	{
		//TODO: Change to allow going back to menu
		switch (choice_int)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		default: 
			break;
		}
	}
	return 0;
}