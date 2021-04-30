#include "customerInterface.h"

/*Display menu options of 1. login and 2. register. once selected, ask user to confirm.
 * If they don't confirm, send them back to login and register menu. if they do confirm,
 * send them to either register or login interface
 */

customerInterface::customerInterface() = default;
customerInterface::customerInterface(accountRepo& acctRep)
{
	
	preLoad(acctRep);
	menuLogic();
}

customerInterface::customerInterface(accountRepo& acctRep, routeRepo* routeRepo)
{
	this->routeRep = routeRepo;
	preLoad(acctRep);
	menuLogic();
}

void customerInterface::preLoad(accountRepo& acctRep)
{
	
	this->acctRep = acctRep;
	std::vector<std::string> menu1 = { "Login", "Register" };
	std::vector<std::vector<std::string>> temp = { menu1 };
	set_vecMen(temp);
}

accountRepo customerInterface::getAcctRep()
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
				login log = login(acctRep, this->routeRep);
			}
			else
			{
				registration reg = registration(acctRep);
			}
		}
	}
	return 0;
}



