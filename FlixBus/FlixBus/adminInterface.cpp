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
	menuLogic(acctRep);
}

adminInterface::adminInterface(accountRepo& acctRep, routeRepo* routeRepo)
{
	this->routeRep = routeRepo;
	preLoad(acctRep);
	menuLogic(acctRep);
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

int adminInterface::menuLogic(accountRepo &AcctRep)
{
	int max = display_menu_items(0);
	int choice_int = enterChoice(max);
	int accountID = -1;
	bool confirm = confirm_Menu_Choice(0, choice_int - 1);
	Customer customer;
	std::string nameEdit;
	Account account;

	if (!confirm)
	{
		menuLogic(AcctRep);
	}
	else
	{
		//TODO: Change to allow going back to menu
		if (choice_int == 1)
		{
			std::cout << "AVAILABLE ROUTES: " << std::endl;
			int route_choice = 0;
			int route_index = 0;
			for (auto item : *this->routeRep->getRoutes())
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
			std::vector<route>* selected_vector = this->routeRep->getRoutes();
			route* current_route = &selected_vector->at(choice_index);
			int adminChoice;
			std::cout << "\nAdd a vehicle to the fleet:\n";
			std::cout << "1. Luxury Bus \n2. Mini Bus \n3. Minivan\n-1. Exit\n";
			std::cout << "Enter your choice: ";

			std::cin >> adminChoice;
			fleet* current_fleet = current_route->get_fleet();
			switch (adminChoice) {

				case 1:
				{
					luxuryBus luxBus;
					current_fleet->addLuxuryBus(luxBus);
					std::cout << "Bus added successfully.\n";
					break; 
				}
				case 2:
				{
					miniBus miniBus;
					current_fleet->addMiniBus(miniBus);
					std::cout << "Bus added successfully.\n";
					break;
				}
				case 3:
				{
					miniVan miniVan;
					current_fleet->addMiniVan(miniVan);
					std::cout << "Bus added successfully.\n";
					break;
				}
				default:
					std::cout << "Please select correct choice!";
			}
			std::cout << "\nCurrent buses for route:" << current_route->get_source() <<" - " << current_route->get_destination() << std::endl;
			current_fleet->displayLuxuryBusFleet();
			current_fleet->displayMiniBusFleet();
			current_fleet->displayMiniVanFleet();
			system("PAUSE");
		}
		if (choice_int == 2)
		{
			return 0;
		}
		if (choice_int == 3)
		{
			std::cout << "Choose an account number.\n";
			std::cin >> accountID;
			if (accountID < 0 || accountID >= acctRep.getAccts().size()) {
				std::cout << "The account does not exist.\n";
				return 0;
			}
			account = acctRep.getAccts().at(accountID);
			std::cout << "Edit passenger's name and charges:\n";
			customer = account.get_customer();
			std::cout << "Change first name.\n";
			std::cin >> nameEdit;
			customer.setFirstName(nameEdit);
			std::cout << "Change last name.\n";
			std::cin >> nameEdit;
			customer.setLastName(nameEdit);
			account.set_customer(customer);
			//****Add Charges****//

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
