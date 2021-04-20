#include "adminInterface.h"
/*Display menu options of 1. login and 2. register. once selected, ask user to confirm.
 * If they don't confirm, send them back to login and register menu. if they do confirm,
 * send them to either register or login interface
 */

adminInterface::adminInterface()
{
}
adminInterface::adminInterface(accountRepo& acctRep)
{
	preLoad(acctRep);
	menuLogic();
}

void adminInterface::preLoad(accountRepo& acctRep)
{
	this->acctRep = acctRep;
	std::vector<std::string> menu1 = { "Add a vehicle to the fleet", "View reservation by bus and date", "Edit passenger's name and charges", "Change reservation charges", "View income", "Exit"};
	std::vector<std::vector<std::string>> temp = { menu1 };
	set_vecMen(temp);
}

accountRepo adminInterface::getAcctRep()
{
	return acctRep;
}

int adminInterface::menuLogic()
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
		if (choice_int == 1)
		{
			return 0;
		}
		if (choice_int == 2)
		{
			return 0;
		}
		if (choice_int == 3)
		{
			
			return 0;
		}
		if (choice_int == 4)
		{
			
			return 0;
		}
		if (choice_int == 5)
		{
			
			return 0;
		}
		else //exit
		{
			return 0;
		}
	}
	return 0;
}
