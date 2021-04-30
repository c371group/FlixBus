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

adminInterface::adminInterface(accountRepo& acctRep, routeRepo* routeRepo)
{
	this->routeRep = routeRepo;
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
			std::cout << "AVAILABLE ROUTES: " << std::endl;
			int route_choice = 0;
			int route_index = 0;
			for (auto item : this->routeRep->getRoutes())
			{
				std::cout << route_index + 1 << ". " << item.get_source() << " - " << item.get_destination() << std::endl;
				route_index++;
			}
			std::cout << "\nPlease select a route for your trip (or enter 0 to exit): ";
			std::cin >> route_choice;
			while (route_choice < 0 || route_choice > route_index)
			{
				std::cout << "\nWrong choice! Please select a route for your trip (or enter 0 to exit): ";
				std::cin >> route_choice;
			}
			if (route_choice == 0)
			{
				return 0;
			}
			int choice_index = route_choice - 1;
			route* currentRoute = &this->routeRep->getRoutes()[choice_index];
			int adminChoice;
			std::cout << "Add a vehicle to the fleet:\n";
			std::cout << "1. Luxary Bus \n2. Mini Bus \n3. Minivan\n-1. Exit\n";
			std::cout << "Enter your choice: ";

			std::cin >> adminChoice;
			fleet* test = currentRoute->get_fleet();
			switch (adminChoice) {

			case 1:
			{luxuryBus luxBus;
			test->addLuxuryBus(luxBus);
			std::cout << "Bus added successfully.\n";
			break; 
			}
			case 2:
			{miniBus miniBus;
			test->addMiniBus(miniBus);
			std::cout << "Bus added successfully.\n";
			break;
			}
			case 3:
			{miniVan miniVan;
			test->addMiniVan(miniVan);
			std::cout << "Bus added successfully.\n";
			break;
			}
			}
			std::cout << "Current busses\n";
			test->displayLuxuryBusFleet();
			test->displayMiniBusFleet();
			test->displayMiniVanFleet();
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
