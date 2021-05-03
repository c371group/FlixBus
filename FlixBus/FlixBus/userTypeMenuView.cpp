#include "userTypeMenuView.h"

userTypeMenuView::userTypeMenuView(accountRepo* acctRep)
{
	preLoad(acctRep);
	menuLogic();
}

userTypeMenuView::userTypeMenuView(accountRepo* acctRep, routeRepo* routeRepo, revenue* revenue)
{
	this->routeRep = routeRepo;
	this->revenue_ = revenue;
	preLoad(acctRep);
	menuLogic();
}

void userTypeMenuView::preLoad(accountRepo* acctRep)
{
	this->acctRep = acctRep;
	std::vector<std::string> menu1 = { "User", "Admin", "Exit" };
	std::vector<std::vector<std::string>> temp = { menu1 };
	set_vecMen(temp);
}

accountRepo* userTypeMenuView::getAcctRep()
{
	return this->acctRep;
}

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