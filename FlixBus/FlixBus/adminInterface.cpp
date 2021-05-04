#include "adminInterface.h"
#include "routeRepo.h"

/*Display menu options of 1. login and 2. register. once selected, ask user to confirm.
 * If they don't confirm, send them back to login and register menu. if they do confirm,
 * send them to either register or login interface
 */

// Base constructor.
adminInterface::adminInterface()
{
}

// Constructor, takes account repository reference and assigns it to routeRep attribute.
adminInterface::adminInterface(account_repo* acctRep)
{
	preLoad(acctRep);
	menuLogic(acctRep);
}

// Constructor, takes account repository, route repository and revenue references. Assign them to their corresponding attributes.
adminInterface::adminInterface(account_repo* acctRep, route_repo* routeRepo, revenue* revenue)
{
	this->routeRep = routeRepo;
	this->revenue_ = revenue;
	preLoad(acctRep);
	menuLogic(acctRep);
}

// Pre loading attributes and generates menu options.
void adminInterface::preLoad(account_repo* acctRep)
{
	this->acctRep = acctRep;
	std::vector<std::string> menu1 = { "Add a vehicle to the fleet", "View reservation by bus and date", "Edit passenger's name and charges", "Change reservation charges", "View income", "Exit"};
	std::vector<std::vector<std::string>> temp = { menu1 };
	set_vecMen(temp);
}

// Returns a reference to an account repository object.
account_repo* adminInterface::getAcctRep()
{
	return this->acctRep;
}

// Menu logic
int adminInterface::menuLogic(account_repo *AcctRep)
{
	int max = display_menu_items(0);
	int choice_int = enterChoice(max);
	int accountID = -1;
	bool confirm = confirm_Menu_Choice(0, choice_int - 1);
	customer customer;
	std::string nameEdit;
	account* account;

	if (!confirm)
	{
		menuLogic(AcctRep);
	}
	else
	{
		// Add vehicle to the fleet
		if (choice_int == 1)
		{
			// Displays all available routes.
			std::cout << "AVAILABLE ROUTES: " << std::endl;
			int route_choice = 0;
			int route_index = 0;
			for (auto item : *this->routeRep->get_routes())
			{
				std::cout << route_index + 1 << ". " << item.get_source() << " - " << item.get_destination() << std::endl;
				route_index++;
			}
			// Validates choice input
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
			// Takes reference to a vector.
			std::vector<route>* selected_vector = this->routeRep->get_routes();
			route* current_route = &selected_vector->at(choice_index);
			int adminChoice;
			std::cout << "\nAdd a vehicle to the fleet:\n";
			std::cout << "1. Luxury Bus \n2. Mini Bus \n3. Minivan\n-1. Exit\n";
			std::cout << "Enter your choice: ";

			std::cin >> adminChoice;
			fleet* current_fleet = current_route->get_fleet();
			switch (adminChoice) {
				//  Adding luxury bus
				case 1:
				{
					std::string bus_id_;
					std::cout << "Please enter bus id: ";
					std::cin >> bus_id_;
					luxury_bus luxBus(bus_id_);
					current_fleet->add_luxury_bus(luxBus);
					std::cout << "Bus added successfully.\n";
					break; 
				}
				// Adding mini bus
				case 2:
				{
					std::string bus_id_;
					std::cout << "Please enter bus id: ";
					std::cin >> bus_id_;
					mini_bus miniBus(bus_id_);
					current_fleet->add_mini_bus(miniBus);
					std::cout << "Bus added successfully.\n";
					break;
				}
				// Adding mini van
				case 3:
				{
					std::string bus_id_;
					std::cout << "Please enter bus id: ";
					std::cin >> bus_id_;
					mini_van miniVan(bus_id_);
					current_fleet->add_mini_van(miniVan);
					std::cout << "Bus added successfully.\n";
					break;
				}
				default:
					std::cout << "Please select correct choice!";
			}
			std::cout << "\nCurrent buses for route:" << current_route->get_source() <<" - " << current_route->get_destination() << std::endl;
			// Displaying all buses from the current fleet.
			current_fleet->display_luxury_bus_fleet();
			current_fleet->display_mini_bus_fleet();
			current_fleet->display_mini_van_fleet();
			system("PAUSE");
		}
		// View reservations.
		if (choice_int == 2)
		{
			// Goes through all accounts.
			for(auto & acc: AcctRep->get_accts())
			{
				// Checks size of tickets for each accoun. If there are not tickets, account is skipped.
				if(acc.get_tickets().size() > 0 )
				{
					std::cout << "******************************************************" << std::endl;
					std::cout << "Customer: " << acc.get_customer().get_first_name() << " " << acc.get_customer().get_last_name() << std::endl;
					std::cout << "******************************************************" << std::endl;
					for (auto& item : acc.get_tickets())
					{
						std::cout << "** From " << item.get_route()->get_source() << " To " << item.get_route()->get_destination() << std::endl;
						item.get_trip()->get_departure_dt().display_date();
						std::cout << " - ";
						item.get_trip()->get_est_arrival_dt().display_date();
						std::cout << "\n** Total of " << item.get_route()->get_distance() << " miles." << std::endl;
						std::cout << "** Price: $" << item.get_cost() << std::endl;
						std::cout << "** Bus type: " << item.get_trip()->get_bus()->get_type() << std::endl;
						std::cout << "** Bus Id: " << item.get_trip()->get_bus()->get_id_no() << std::endl;
						std::cout << "** Bus Hire: " << item.get_bus_hire_status() << std::endl;
						std::cout << "** Seat number: " << item.get_seat_number() << std::endl;
						std::cout << "** Ticket cost: $" << item.get_cost() << std::endl;
						std::cout << "******************************************************" << std::endl;
					}
				}
			}
		}
		// Edit reservation (change passenger’s name, modify charge)
		if (choice_int == 3)
		{
			int index = 1;
			std::cout << "Current users: " << std::endl;
			// Displays all users.
			for (auto& acc : AcctRep->get_accts())
			{
				std::cout << "Number: " << index << " " << acc.get_customer().get_first_name() << " " << acc.get_customer().get_last_name() << std::endl;
				index++;
			}
			// Proms the user to select which user to edit.
			while (true) {
				std::cout << "Choose an account number. Enter 0 to exit.\n";
				if (std::cin >> accountID) {
					break;
				}
				else {
					std::cout << "Enter a valid integer value!\n";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}
			
			if (accountID < 0 || accountID >= acctRep->get_accts().size()) {
				std::cout << "The account does not exist.\n";
				return 0;
			}
			if(accountID == 0)
			{
				return 0;
			}
			// Asking user what he/she wants to do with the selected user.
			int edit_customer_choice;
			account = acctRep->get_acc_by_index(accountID - 1);
			std::cout << "************************" << std::endl;
			std::cout << account->get_customer().get_first_name() << " " << account->get_customer().get_last_name() << " selected." << std::endl;
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
			// Edits customer.
			if (edit_customer_choice == 1) {
				std::cout << "Edit passenger's name and charges:\n";
				std::cout << "Change first name.\n";
				std::cin >> nameEdit;
				account->get_customer_reference()->set_first_name(nameEdit);
				std::cout << "Change last name.\n";
				std::cin >> nameEdit;
				account->get_customer_reference()->set_last_name(nameEdit);
			}
			// Edits the customer ticket cost.
			if (edit_customer_choice == 2) {
				int ticket_choice;
				int ticket_index = 1;
				double total_tickets_cost = 0;
				double new_ticket_cost = 0;
				for (auto& ticket : account->get_tickets()) {
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
				while (ticket_choice < 0 || ticket_choice > ticket_index-1) {
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
				std::string selected_ticket_id = account->get_tickets().at(ticket_choice - 1).get_ticket_id();
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
				// Calculates what to be added to the company revenue.
				double old_cost = selected_ticket->get_cost();
				selected_ticket->set_cost(new_ticket_cost);
				double difference_cost = old_cost - new_ticket_cost;
				if (old_cost > new_ticket_cost)
				{
					this->revenue_->withdrawal_income_by_date(selected_ticket->get_trip()->get_departure_dt().to_string(false), difference_cost);
					this->revenue_->withdrawal_income_by_vehicle(selected_ticket->get_trip()->get_bus()->get_id_no(), difference_cost);
					this->revenue_->set_total_amount(this->revenue_->get_total_amount() + difference_cost);
				}
				if (old_cost < new_ticket_cost)
				{
					difference_cost = new_ticket_cost - old_cost;
					this->revenue_->add_income_by_date(selected_ticket->get_trip()->get_departure_dt().to_string(false), difference_cost);
					this->revenue_->add_income_by_vehicle(selected_ticket->get_trip()->get_bus()->get_id_no(), difference_cost);
					this->revenue_->set_total_amount(this->revenue_->get_total_amount() + difference_cost);
				}
				
				std::cout << "New ticket cost of $" << new_ticket_cost << " was set." << std::endl;
			}
		}
		// Change reservation charge, hire charge.
		if (choice_int == 4)
		{
			
			return 0;
		}
		// View income by date and by vehicle.
		if (choice_int == 5)
		{
			std::cout << "*************************" << std::endl;
			std::cout << "****** INCOME PAGE ******" << std::endl;
			std::cout << "*************************" << std::endl;
			std::cout << "\nTotal income: $" << this->revenue_->get_total_amount() << std::endl;
			std::cout << "\nIncome by date:" << std::endl;
			for(auto &item: this->revenue_->get_income_by_date())
			{
				std::cout << "Date: " <<item.first << " : $" << item.second << std::endl;
			}
			std::cout << "\nIncome by vehicle:" << std::endl;
			for (auto& item : this->revenue_->get_income_by_vehicle())
			{
				std::cout << "Bus: " << item.first << " : $" << item.second << std::endl;
			}
			system("PAUSE");
		}
		else //exit
		{
			return 0;
		}
	}
	return 0;
}
