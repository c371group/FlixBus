#include "customerInterface.h"

/*Display menu options of 1. login and 2. register. once selected, ask user to confirm.
 * If they don't confirm, send them back to login and register menu. if they do confirm,
 * send them to either register or login interface
 */

customerInterface::customerInterface() = default;
customerInterface::customerInterface(account_repo* acctRep)
{
	
	preLoad(acctRep);
	menuLogic();
}

customerInterface::customerInterface(account_repo* acctRep, route_repo* routeRepo, revenue* revenue)
{
	this->routeRep = routeRepo;
	this->revenue_ = revenue;
	preLoad(acctRep);
	menuLogic();
}

void customerInterface::preLoad(account_repo* acctRep)
{
	
	this->acctRep = acctRep;
	std::vector<std::string> menu1 = { "Login", "Register", "Exit" };
	std::vector<std::vector<std::string>> temp = { menu1 };
	set_vecMen(temp);
}

account_repo* customerInterface::getAcctRep()
{
	return this->acctRep;
}

int customerInterface::menuLogic()
{
	
	int choice_int = 0;
	while (choice_int != 3) {
		system("CLS");
		int max = display_menu_items(0);
		choice_int = enterChoice(max);
		bool confirm = confirm_Menu_Choice(0, choice_int - 1);

		if (!confirm)
		{
			menuLogic();
		}
		else
		{
			if (choice_int == 1)
			{
				login log = login(this->acctRep, this->routeRep, this->revenue_);
			}
			else if (choice_int == 2)
			{
				registration reg = registration(this->acctRep);
			}
			else
			{
				return 0;
			}
		}
	}
	return 0;
}



