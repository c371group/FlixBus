#include "userTypeMenuView.h"


// Constructor that assigns account repository reference.
userTypeMenuView::userTypeMenuView(account_repo* acctRep)
{
	preLoad(acctRep);
	menuLogic();
}

// Constructor takes account repository, route repository and revenue references.
userTypeMenuView::userTypeMenuView(account_repo* acctRep, route_repo* routeRepo, revenue* revenue)
{
	this->routeRep = routeRepo;
	this->revenue_ = revenue;
	preLoad(acctRep);
	menuLogic();
}

// Prepares menu options.
void userTypeMenuView::preLoad(account_repo* acctRep)
{
	this->acctRep = acctRep;
	std::vector<std::string> menu1 = { "User", "Admin", "Exit" };
	std::vector<std::vector<std::string>> temp = { menu1 };
	set_vecMen(temp);
}

// Returns reference of an account repository.
account_repo* userTypeMenuView::getAcctRep()
{
	return this->acctRep;
}

// Sets up menu logic. Gives the users two options. Customer and Admin interface are called.
int userTypeMenuView::menuLogic()
{
	int choice_int = 0;
	while (choice_int != 3) {
		int max = display_menu_items(0);
		choice_int = enterChoice(max);
		bool confirm = confirm_Menu_Choice(0, choice_int - 1);

		if (!confirm)
		{
			menuLogic();
		}
		else
		{
			//TODO: Change to allow going back to menu
			if (choice_int == 1) //This shouldn't impact performance at all, we just run into problems when we do switch statement here
			{
				customerInterface custInterface = customerInterface(this->acctRep, this->routeRep, this->revenue_);
			}
			else if (choice_int == 2) //ADMIN INTERFACE
			{
				adminInterface admininterface = adminInterface(this->acctRep, this->routeRep, this->revenue_);
			}
			else if (choice_int == 3)
			{
				std::cout << "Goodbye!" << std::endl;
				return 0;
			}
			else
			{
			}
		}
	}
	return 0;
}