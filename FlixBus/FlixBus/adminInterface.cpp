#include "adminInterface.h"
#include "routeRepo.h"

/*Display menu options of 1. login and 2. register. once selected, ask user to confirm.
 * If they don't confirm, send them back to login and register menu. if they do confirm,
 * send them to either register or login interface
 */

adminInterface::adminInterface()
{
}
adminInterface::adminInterface(accountRepo* acctRep)
{
	preLoad(acctRep);
	menuLogic(acctRep);
}

adminInterface::adminInterface(accountRepo* acctRep, routeRepo* routeRepo)
{
	this->routeRep = routeRepo;
	preLoad(acctRep);
	menuLogic(acctRep);
}

void adminInterface::preLoad(accountRepo* acctRep)
{
	this->acctRep = acctRep;
	std::vector<std::string> menu1 = { "Add a vehicle to the fleet", "View reservation by bus and date", "Edit passenger's name and charges", "Change reservation charges", "View income", "Exit"};
	std::vector<std::vector<std::string>> temp = { menu1 };
	set_vecMen(temp);
}

accountRepo* adminInterface::getAcctRep()
{
	return this->acctRep;
}

int adminInterface::menuLogic(accountRepo *AcctRep)
{
	int max = display_menu_items(0);
	int choice_int = enterChoice(max);
	int accountID = -1;
	bool confirm = confirm_Menu_Choice(0, choice_int - 1);
	Customer customer;
	std::string nameEdit;
	Account* account;

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
			while (true) {
				std::cout << "\nPlease select a route for your trip (or enter 0 to exit): ";
				if (std::cin >> route_choice) {
					break;
				}
				else {
					std::cout << "Enter a valid integer value!\n";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}
			while (route_choice < 0 || route_choice > route_index)
			{
				while (true) {
					std::cout << "\nWrong choice\nPlease select a route for your trip (or enter 0 to exit): ";
					if (std::cin >> route_choice) {
						break;
					}
					else {
						std::cout << "Enter a valid integer value!\n";
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
				}
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
					std::string bus_id_;
					std::cout << "Please enter bus id: ";
					std::cin >> bus_id_;
					luxuryBus luxBus(bus_id_);
					current_fleet->addLuxuryBus(luxBus);
					std::cout << "Bus added successfully.\n";
					break; 
				}
				case 2:
				{
					std::string bus_id_;
					std::cout << "Please enter bus id: ";
					std::cin >> bus_id_;
					miniBus miniBus(bus_id_);
					current_fleet->addMiniBus(miniBus);
					std::cout << "Bus added successfully.\n";
					break;
				}
				case 3:
				{
					std::string bus_id_;
					std::cout << "Please enter bus id: ";
					std::cin >> bus_id_;
					miniVan miniVan(bus_id_);
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
			for(auto & acc: AcctRep->getAccts())
			{
				std::cout << "******************************************************" << std::endl;
				std::cout << "Customer: " << acc.get_customer().getFirstName() << " " << acc.get_customer().getLastName()<<  std::endl;
				std::cout << "******************************************************" << std::endl;
				for(auto & item: acc.getTickets())
				{
					std::cout << "** From " << item.get_route()->get_source() << " To " << item.get_route()->get_destination() << std::endl;
					item.get_trip()->getDepartureDT().displayDate();
					std::cout << " - ";
					item.get_trip()->getEstArrivalDT().displayDate();
					std::cout << "\n** Total of " << item.get_route()->get_distance() << " miles." << std::endl;
					std::cout << "** Price: $" << item.get_cost() << std::endl;
					std::cout << "** Bus type: " << item.get_trip()->get_bus()->get_type() << std::endl;
					std::cout << "** Bus Id: " << item.get_trip()->get_bus()->get_id_no() << std::endl;
					std::cout << "** Bus Hire: " << item.get_bus_hire_status() << std::endl;
					std::cout << "** Seat number: " << item.get_seat_number() << std::endl;
					std::cout << "** Ticket cost: $" << item.get_cost() << std::endl;
				}
			}
		}
		if (choice_int == 3)
		{
			int index = 1;
			std::cout << "Current users: " << std::endl;
			for (auto& acc : AcctRep->getAccts())
			{
				std::cout << "Number: " << index << " " << acc.get_customer().getFirstName() << " " << acc.get_customer().getLastName() << std::endl;
				index++;
			}
			std::cout << "Choose an account number. Enter 0 to exit.\n";
			std::cin >> accountID;
			if (accountID < 0 || accountID >= acctRep->getAccts().size()) {
				std::cout << "The account does not exist.\n";
				return 0;
			}
			if(accountID == 0)
			{
				return 0;
			}
			int edit_customer_choice;
			account = acctRep->get_acc_by_index(accountID - 1);
			std::cout << "************************" << std::endl;
			std::cout << account->get_customer().getFirstName() << " " << account->get_customer().getLastName() << " selected." << std::endl;
			std::cout << "************************" << std::endl;
			std::cout << "1. Change passenger's name\n2. Modify charge.\n0. Exit" << std::endl;
			
			while (true) {
				std::cout << "Please select your choice: ";
				if (std::cin >> edit_customer_choice) {
					break;
				}
				else {
					std::cout << "Enter a valid integer value!\n";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}
			while (edit_customer_choice < 0 || edit_customer_choice > 2) {
				while (true) {
					std::cout << "Please select your choice: ";
					if (std::cin >> edit_customer_choice) {
						break;
					}
					else {
						std::cout << "Enter a valid integer value!\n";
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
				}
			}
			if (edit_customer_choice == 1) {
				std::cout << "Edit passenger's name and charges:\n";
				std::cout << "Change first name.\n";
				std::cin >> nameEdit;
				account->get_customer_reference()->setFirstName(nameEdit);
				std::cout << "Change last name.\n";
				std::cin >> nameEdit;
				account->get_customer_reference()->setLastName(nameEdit);
			}
			if (edit_customer_choice == 2) {
				int ticket_choice;
				int ticket_index = 1;
				double total_tickets_cost = 0;
				double new_ticket_cost = 0;
				for (auto& ticket : account->getTickets()) {
					std::cout << ticket_index << ". ticket charge: $" << ticket.get_cost() << " from "<< ticket.get_route()->get_source() << " to " << ticket.get_route()->get_destination() << std::endl;
					total_tickets_cost = total_tickets_cost + ticket.get_cost();
					ticket_index++;
				}
				std::cout << "Current charge for the user is: $" << total_tickets_cost << " for total of " << ticket_index-1 << " ticket(s)" << std::endl;
				while (true) {
					std::cout << "Please select ticket number, to edit it's cost or enter 0 to exit: ";
					if (std::cin >> ticket_choice) {
						break;
					}
					else {
						std::cout << "Enter a valid integer value!\n";
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
				}
				while (ticket_choice < 0 || ticket_choice > ticket_index) {
					while (true) {
						std::cout << "Wrong choice!\nPlease select your choice: ";
						if (std::cin >> ticket_choice) {
							break;
						}
						else {
							std::cout << "Enter a valid integer value!\n";
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						}
					}
				}
				std::string selected_ticket_id = account->getTickets().at(ticket_choice - 1).get_ticket_id();
				ticket* selected_ticket = account->get_ticket_by_id(selected_ticket_id);
				std::cout << "You selected ticket number " << ticket_choice << " from" << selected_ticket->get_route()->get_source() << " to " << selected_ticket->get_route()->get_destination() << std::endl;

				while (true) {
					std::cout << "Please enter new ticket cost: ";
					if (std::cin >> new_ticket_cost) {
						break;
					}
					else {
						std::cout << "Enter a valid value!\n";
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
				}
				selected_ticket->set_cost(new_ticket_cost);
				std::cout << "New ticket cost of $" << new_ticket_cost << " was set." << std::endl;
			}
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
