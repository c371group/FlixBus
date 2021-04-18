#include "customerInterface.h"

/*Display menu options of 1. login and 2. register. once selected, ask user to confirm.
 * If they don't confirm, send them back to login and register menu. if they do confirm,
 * send them to either register or login interface
 */
customerInterface::customerInterface(accountRepo acctRep)
{
	preLoad(acctRep);
	menuLogic();
}

void customerInterface::preLoad(accountRepo acctRep)
{
	this->acctRep = acctRep;
	std::vector<std::string> menu1 = { "Login", "Register" };
	std::vector<std::vector<std::string>> temp = { menu1 };
	set_vecMen(temp);
}

accountRepo customerInterface::getAcctRep()
{
	return acctRep;
}

int customerInterface::menuLogic()
{
	int max = display_menu_items(0);
	int choice_int = enterChoice(max, get_intcon());
	bool confirm = confirm_Menu_Choice(0, choice_int - 1, get_intcon());

	if (!confirm)
	{
		menuLogic();
	}
	else
	{
		//TODO: Change to allow going back to menu
		if (choice_int == 1)
		{
			login log = login(acctRep);
			return 0;
		}
		else
		{
			registration reg = registration(acctRep);
			menuLogic();
			return 0;
		}
	}
	return 0;
}



