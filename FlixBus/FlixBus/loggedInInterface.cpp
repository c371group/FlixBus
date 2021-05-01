#include "loggedInInterface.h"

loggedInInterface::loggedInInterface(Account& account)
{
	this->acct = account;
	preLoad();
	menuLogic();
}

loggedInInterface::loggedInInterface(Account& account, routeRepo* routeRepo)
{
	this->acct = account;
	this->routeRep = routeRepo;
	preLoad();
	menuLogic();
}

void loggedInInterface::preLoad()
{
	std::vector<std::string> menu = { "Account Info", "Your Upcoming Trips", "Browse Available Trips", "Book Trip", "Account Trip History", "Bus Rental", "Log Out" };
	std::vector<std::vector<std::string>> temp = { menu };
	set_vecMen(temp);
}

int loggedInInterface::menuLogic()
{
	accountInfoView aIV;
	fullTripListView fTLV;
	int choice_int = 0;
	while (choice_int != 7) {
		system("CLS");
		std::cout << "Welcome, " << acct.get_customer().getFirstName() << std::endl;
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
			switch (choice_int)
			{
			case 1: //acct info
				aIV = accountInfoView(acct);
				break;
			case 2: //upcoming trips the customer is scheduled to take/has ticket(s) for
			{
				if(this->acct.getTickets().empty())
				{
					std::cout <<"No trips scheduled!" << std::endl;
					system("PAUSE");
					break;
				}
				else
				{
					std::cout << "Travel Date\t\tSource\tDestination\tCost" << std::endl;
					int ticket_number = 1;
					int edit_ticket_choice;
					for (auto& item : this->acct.getTickets())
					{
						std::cout << "******************************************************" << std::endl;
						std::cout << "*************** Ticket: " << ticket_number << " *****************************" << std::endl;
						std::cout << "******************************************************" << std::endl;
						std::cout << "** From " << item.get_route()->get_source() << " To " << item.get_route()->get_destination() << std::endl;
						item.get_trip()->getDepartureDT().displayDate();
						std::cout << " - ";
						item.get_trip()->getEstArrivalDT().displayDate();
						std::cout << "\n** Total of " << item.get_route()->get_distance() << " miles." << std::endl;
						std::cout << "** Price: $" << item.get_cost() << std::endl;
						std::cout << "** Bus type: " << item.get_trip()->get_bus()->get_type() << std::endl;
						std::cout << "** Bus Hire: " << item.get_bus_hire_status() << std::endl;
						std::cout << "** Seat number: " << item.get_seat_number() << std::endl;
						std::cout << "** Ticket cost: $" << item.get_cost() << std::endl;
						ticket_number++;
					}
					
					while (true) {
						std::cout << "Enter ticket number to edit it or 0 for exit: ";
						if (std::cin >> edit_ticket_choice) {
							break;
						}
						else {
							std::cout << "Enter a valid integer value!\n";
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						}
					}
					
					while(edit_ticket_choice < 0 || edit_ticket_choice > static_cast<int>(this->acct.getTickets().size()))
					{
						std::cout << "Wrong choice! Please try again! Choose between 0 and " << static_cast<int>(this->acct.getTickets().size()) << std::endl;
						while (true) {
							std::cout << "Enter ticket number to edit it or 0 for exit: ";
							if (std::cin >> edit_ticket_choice) {
								break;
							}
							else {
								std::cout << "Enter a valid integer value!\n";
								std::cin.clear();
								std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							}
						}
					}
					if(edit_ticket_choice == 0)
					{
						break;
					}
					int ticket_edit_choice=0;
					std::vector<ticket> tickets_edit = this->acct.getTickets();
					ticket edit_ticket = tickets_edit.at(edit_ticket_choice-1);
					std::cout << "" << std::endl;
					std::cout << "** From " << edit_ticket.get_route()->get_source() << " To " << edit_ticket.get_route()->get_destination() << std::endl;
					edit_ticket.get_trip()->getDepartureDT().displayDate();
					std::cout << " - ";
					edit_ticket.get_trip()->getEstArrivalDT().displayDate();
					std::cout << "\n** Total of " << edit_ticket.get_route()->get_distance() << " miles." << std::endl;
					std::cout << "** Price: $" << edit_ticket.get_cost() << std::endl;
					std::cout << "** Bus type: " << edit_ticket.get_trip()->get_bus()->get_type() << std::endl;
					std::cout << "** Seat number: " << edit_ticket.get_seat_number() << std::endl;
					std::cout << "** Ticket cost: " << edit_ticket.get_cost() << std::endl;
					std::cout << "********************************************" << std::endl;
					if(edit_ticket.get_bus_hire_status())
					{
						std::cout << "1. Cancel ticket. (0 for exit)\n" << std::endl;
					}else
					{
						std::cout << "1. Cancel ticket.\n2. Change seat. (0 for exit)\n" << std::endl;
					}
					
					while (true) {
						std::cout << "Enter your choice: ";
						if (std::cin >> ticket_edit_choice) {
							break;
						}
						else {
							std::cout << "Enter a valid integer value!\n";
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						}
					}
					
					while (ticket_edit_choice < 0 || ticket_edit_choice > 2)
					{
						std::cout << "\nWrong choice! Please try again! Choose between 1 and 2." << std::endl;
						std::cout << "1. Cancel ticket.\n2. Change seat.\n" << std::endl;
						while (true) {
							std::cout << "Enter your choice: ";
							if (std::cin >> ticket_edit_choice) {
								break;
							}
							else {
								std::cout << "Enter a valid integer value!\n";
								std::cin.clear();
								std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							}
						}
					}
					if(ticket_edit_choice == 0)
					{
						break;
					}
					if (ticket_edit_choice == 1)
					{
						DateTime current_date;
						DateTime ticket_date = this->acct.getTickets().at(edit_ticket_choice - 1).get_travel_date();
						int days_difference = current_date.differenceDays(ticket_date);
						if(days_difference < 7)
						{
							std::cout << "Any cancellation shorter than a week will require 30%!" << std::endl;
							std::cout << this->acct.getTickets().at(edit_ticket_choice - 1).get_cost() * 0.3<< " will be hold from your account." << std::endl;
						}
						if (days_difference < 2)
						{
							std::cout << "Reservation cancellation one day before the travel including one minute before the travel will forfeit the entire cost of the ticket.!" << std::endl;
							std::cout << this->acct.getTickets().at(edit_ticket_choice - 1).get_cost() << " will be hold from your account." << std::endl;
						}
						this->acct.getTickets().at(edit_ticket_choice - 1).cancel_seat();
						this->acct.removeTicket(edit_ticket.get_ticket_id());
						if(edit_ticket.get_bus_hire_status())
						{
							//TODO: if bus is hired, we need to go and delete the trip from the trip repo.
						}
						std::cout << "Your ticket was canceled!" << std::endl;
					}
					if (ticket_edit_choice == 2 && !edit_ticket.get_bus_hire_status())
					{
						ticket* reference_to_edit_ticket = this->acct.get_ticket_by_id(edit_ticket.get_ticket_id());
						std::cout << "Free seats for ";
						edit_ticket.get_trip()->getDepartureDT();
						std::cout << " - ";
						edit_ticket.get_trip()->getEstArrivalDT();
						std::cout << " from " << edit_ticket.get_route()->get_source() << " to " << edit_ticket.get_route()->get_destination() << std::endl;
						edit_ticket.get_trip()->get_bus()->displayFreeSeats();
						int seat_row;
						char seat_column;
						std::cout << "\nPlease select a seat: " << std::endl;

						while (true) {
							std::cout << "\nEnter row (number): " << std::endl;
							if (std::cin >> seat_row) {
								break;
							}
							else {
								std::cout << "Enter a valid integer value!\n";
								std::cin.clear();
								std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							}
						}

						std::cout << "\nEnter column (char): " << std::endl;
						std::cin >> seat_column;
						while (!(seat_column == 'A' || seat_column == 'B' || seat_column == 'C' || seat_column == 'D' || seat_column == 'E'))
						{
							std::cout << "Please enter char value ('A', 'B', 'C', 'D' or 'E'" << std::endl;
							std::cout << "\nEnter column (char): " << std::endl;
							std::cin >> seat_column;
						}
						
						int old_seat_row = edit_ticket.get_seat_pair().first;
						char old_seat_column = edit_ticket.get_seat_pair().second;
						reference_to_edit_ticket->cancel_seat();
						int count_attempts = 0;
						while(!reference_to_edit_ticket->reserve_seat(seat_row, seat_column))
						{
							count_attempts++;
							std::cout << "\nAttempt: " << count_attempts << ". After 5 attempts seat change will be canceled." << std::endl;
							std::cout << "\nPlease select a seat: " << std::endl;
							while (true) {
								std::cout << "\nEnter row (number): " << std::endl;
								if (std::cin >> seat_row) {
									break;
								}
								else {
									std::cout << "Enter a valid integer value!\n";
									std::cin.clear();
									std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								}
							}

							std::cout << "\nEnter column (char): " << std::endl;
							std::cin >> seat_column;
							while (!(seat_column == 'A' || seat_column == 'B' || seat_column == 'C' || seat_column == 'D' || seat_column == 'E'))
							{
								std::cout << "Please enter char value ('A', 'B', 'C', 'D' or 'E'" << std::endl;
								std::cout << "\nEnter column (char): " << std::endl;
								std::cin >> seat_column;
							}
							if(count_attempts>4)
							{
								std::cout << "We couldn't reserve this seat." << std::endl;
								std::cout << "Restoring old seat reservation." << std::endl;
								reference_to_edit_ticket->reserve_seat(old_seat_row, old_seat_column);
								break;
							}
						}
					}
					system("PAUSE");
					break;
				}
			}
			case 3:
				/*see trips that the customer can book--
				 *not sure if we want to limit this to those that
				 *can be scheduled already (remember, 2 weeks) or all of them */
				fTLV = fullTripListView(true); //this currently shows all trips, regardless of if they can book them right now or not
				break;
			case 4: 
			{
				ticket new_ticket;
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
					std::cout << "\nWrong choice! Choose between 1 and " << route_index << std::endl;;
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
				}
				if (route_choice == 0)
				{
					break;
				}
				int choice_index = route_choice - 1;
				std::vector<route>* selected_vector = this->routeRep->getRoutes();
				route* selected_route = &selected_vector->at(choice_index);
				new_ticket.set_route(&selected_vector->at(choice_index));
				std::cout << "DEPARTURE\t\t" << "ARRIVAL\t\t\t" << "SOURCE\t\t" << "DESTINATION" << std::endl;
				int trip_choice = 0;
				int index = 0;
				for (auto item : *selected_route->get_trip_repo()->getAllTrips())
				{
					std::cout << index + 1 << ". ";
					item.getDepartureDT().displayDate();
					std::cout << "\t";
					item.getEstArrivalDT().displayDate();
					std::cout << "\t";
					std::cout << selected_route->get_source() << "\t" << selected_route->get_destination() << "\t" << std::endl;
					index++;
				}
				
				while (true) {
					std::cout << "\n\nPlease select a trip (or enter 0 to exit): ";
					if (std::cin >> trip_choice) {
						break;
					}
					else {
						std::cout << "Enter a valid integer value!\n";
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
				}
					
				while (trip_choice < 0 || trip_choice > index)
				{
					std::cout << "\nWrong choice! Choose between 1 and " << route_index << std::endl;;
					while (true) {
						std::cout << "\n\nPlease select a trip (or enter 0 to exit): ";
						if (std::cin >> trip_choice) {
							break;
						}
						else {
							std::cout << "Enter a valid integer value!\n";
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						}
					}
				}
				if (trip_choice == 0)
				{
					break;
				}
				else
				{
					std::vector<Trip>* list_of_trips = selected_route->get_trip_repo()->getAllTrips();
					Trip* selected_trip = &list_of_trips->at(trip_choice - 1); //&selected_route->get_trip_repo()->getAllTrips()[trip_choice - 1];
					new_ticket.set_trip(&list_of_trips->at(trip_choice - 1));
					std::cout << "\nAvailable bus seats." << std::endl;
					selected_trip->get_bus()->displayFreeSeats();

					int seat_row;
					char seat_column;
					std::cout << "\nPlease select a seat: " << std::endl;

					while (true) {
						std::cout << "\nEnter row (number): " << std::endl;
						if (std::cin >> seat_row) {
							break;
						}
						else {
							std::cout << "Enter a valid integer value!\n";
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						}
					}

					std::cout << "\nEnter column (char): " << std::endl;
					std::cin >> seat_column;
					while (!(seat_column == 'A' || seat_column == 'B' || seat_column == 'C' || seat_column == 'D' || seat_column == 'E'))
					{
						std::cout << "Please enter char value ('A', 'B', 'C', 'D' or 'E'" << std::endl;
						std::cout << "\nEnter column (char): " << std::endl;
						std::cin >> seat_column;
					}
					int count_attempts = 0;
					while (new_ticket.reserve_seat(seat_row, seat_column))
					{
						count_attempts++;
						std::cout << "\nAttempt: " << count_attempts << ". After 5 attempts seat change will be canceled." << std::endl;
						std::cout << "\nPlease select a seat: " << std::endl;
						while (true) {
							std::cout << "\nEnter row (number): " << std::endl;
							if (std::cin >> seat_row) {
								break;
							}
							else {
								std::cout << "Enter a valid integer value!\n";
								std::cin.clear();
								std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							}
						}

						std::cout << "\nEnter column (char): " << std::endl;
						std::cin >> seat_column;
						while (!(seat_column == 'A' || seat_column == 'B' || seat_column == 'C' || seat_column == 'D' || seat_column == 'E'))
						{
							std::cout << "Please enter char value ('A', 'B', 'C', 'D' or 'E'" << std::endl;
							std::cout << "\nEnter column (char): " << std::endl;
							std::cin >> seat_column;
						}
						if (count_attempts > 4)
						{
							std::cout << "We couldn't reserve this seat." << std::endl;
							break;
						}
					}

					new_ticket.set_cost(new_ticket.get_trip()->get_bus()->getSeatRate(seat_row, seat_column) * new_ticket.get_route()->get_distance());
					std::string compiled_id = this->acct.get_customer().getLastName() + "_" + new_ticket.get_route()->get_source() + "_" + new_ticket.get_route()->get_destination() + "_" + new_ticket.get_trip()->get_bus()->get_id_no();
					new_ticket.set_ticket_id(compiled_id);
					this->acct.addTicket(new_ticket);
					system("PAUSE");
					break;
				}
				
			}
			case 5:
				/*see history for account, including cancelled tickets and prior trips or rentals*/
				break;
			case 6:
				{
					std::cout << "AVAILABLE ROUTES FOR BUS HIRE: " << std::endl;
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
						std::cout << "\nWrong choice! Choose between 1 and " << route_index << std::endl;;
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
					}
					if (route_choice == 0)
					{
						break;
					}
					int choice_index = route_choice - 1;
					int choice_bus_hire = 0;
					std::vector<route>* selected_vector = this->routeRep->getRoutes();
					route* selected_route = &selected_vector->at(choice_index);

					std::cout << "Currently we have:" << std::endl;
					selected_route->get_fleet()->displayLuxuryBusFleet();
					selected_route->get_fleet()->displayMiniBusFleet();
					selected_route->get_fleet()->displayMiniVanFleet();
					std::cout << "\n********************************\n";
					if(selected_route->get_fleet()->get_luxury_bus_count() > 0)
					{
						std::cout << "1. Select from our luxury buses"<< std::endl;
					}
					if (selected_route->get_fleet()->get_mini_bus_count() > 0)
					{
						std::cout << "2. Select from our mini buses" << std::endl;
					}
					if (selected_route->get_fleet()->get_minivan_count() > 0)
					{
						std::cout << "3. Select from our minivans" << std::endl;
					}

					while (true) {
						std::cout << "\nEnter your choice: ";
						if (std::cin >> choice_bus_hire) {
							break;
						}
						else {
							std::cout << "Enter a valid integer value!\n";
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						}
					}
					while (choice_bus_hire < 1 || choice_bus_hire > 3)
					{
						while (true) {
							std::cout << "Enter your choice: ";
							if (std::cin >> choice_bus_hire) {
								break;
							}
							else {
								std::cout << "Enter a valid integer value!\n";
								std::cin.clear();
								std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							}
						}
					}
					std::string bus_id;
					if(choice_bus_hire == 1)
					{
						selected_route->get_fleet()->displayLuxuryBusFleet();
						while (true) {
							std::cout << "Enter luxury bus id to hire it: ";
							if (std::cin >> bus_id) {
								break;
							}
							else {
								std::cout << "Enter a valid id value!\n";
								std::cin.clear();
								std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							}
						}
						luxuryBus* hire_luxury_bus = selected_route->get_fleet()->getLuxuryBus(bus_id);
						if(!hire_luxury_bus)
						{
							std::cout << "The bus id you entered was not found. Please try again!";
							std::cout << "Here are the options: " << std::endl;
							selected_route->get_fleet()->displayLuxuryBusFleet();
							while (true) {
								std::cout << "\nEnter luxury bus id to hire it: ";
								if (std::cin >> bus_id) {
									break;
								}
								else {
									std::cout << "Enter a valid id value!\n";
									std::cin.clear();
									std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								}
							}
							hire_luxury_bus = selected_route->get_fleet()->getLuxuryBus(bus_id);
						}
						if(hire_luxury_bus->can_hire())
						{
							hire_luxury_bus->reserveAllSeats();
							ticket bus_hire_ticket;
							
							//TODO: Ask the user to enter date and time. Currently takes current date and time.
							DateTime bus_hire_dep(2021, 5, 1, 12, 0,0);
							DateTime bus_hire_arr(2021, 5,1,15,30,0);
							Trip bus_hire_trip(bus_hire_dep, bus_hire_arr, hire_luxury_bus);
							selected_route->get_trip_repo()->add_trip(bus_hire_trip);
							std::vector<Trip>* trip_repo = selected_route->get_trip_repo()->getAllTrips();
							bus_hire_ticket.set_trip(&trip_repo->back());
							bus_hire_ticket.set_route(selected_route);
							
							bus_hire_ticket.set_bus_hire(true);
							bus_hire_ticket.set_cost(hire_luxury_bus->getBusHireRate() + (hire_luxury_bus->getBusHireRatePerMile() * selected_route->get_distance()));
							std::cout << "There is a security deposit for the luxury bus hire: " << hire_luxury_bus->getSecurityDeposit() << std::endl;
							std::cout << "Current cost is: " << bus_hire_ticket.get_cost() << std::endl;
							std::cout << "Adding security deposit.." << std::endl;
							bus_hire_ticket.set_cost(bus_hire_ticket.get_cost() + hire_luxury_bus->getSecurityDeposit());
							std::cout << "Total cost for bus hire is: " << bus_hire_ticket.get_cost() << std::endl;
							this->acct.addTicket(bus_hire_ticket);
							system("PAUSE");
							break;
						}
						
					}
					else if(choice_bus_hire == 3)
					{
						selected_route->get_fleet()->displayMiniBusFleet();
						while (true) {
							std::cout << "Enter mini bus id to hire it: ";
							if (std::cin >> bus_id) {
								break;
							}
							else {
								std::cout << "Enter a valid id value!\n";
								std::cin.clear();
								std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							}
						}
						miniBus* hire_mini_bus = selected_route->get_fleet()->getMiniBus(bus_id);
						if (!hire_mini_bus)
						{
							std::cout << "The bus id you entered was not found. Please try again!";
							std::cout << "Here are the options: " << std::endl;
							selected_route->get_fleet()->displayMiniBusFleet();
							while (true) {
								std::cout << "\nEnter mini bus id to hire it: ";
								if (std::cin >> bus_id) {
									break;
								}
								else {
									std::cout << "Enter a valid id value!\n";
									std::cin.clear();
									std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								}
							}
							hire_mini_bus = selected_route->get_fleet()->getMiniBus(bus_id);
						}
						if (hire_mini_bus->can_hire())
						{
							hire_mini_bus->reserveAllSeats();
							ticket bus_hire_ticket;
							
							//TODO: Ask the user to enter date and time. Currently takes current date and time.
							DateTime bus_hire_dep(2021, 5, 1, 12, 0, 0);
							DateTime bus_hire_arr(2021, 5, 1, 15, 30, 0);
							Trip bus_hire_trip(bus_hire_dep, bus_hire_arr, hire_mini_bus);
							selected_route->get_trip_repo()->add_trip(bus_hire_trip);
							std::vector<Trip>* trip_repo = selected_route->get_trip_repo()->getAllTrips();
							bus_hire_ticket.set_trip(&trip_repo->back());
							bus_hire_ticket.set_route(selected_route);
							
							bus_hire_ticket.set_route(selected_route);
							bus_hire_ticket.set_bus_hire(true);
							bus_hire_ticket.set_cost(hire_mini_bus->getBusHireRate() + (hire_mini_bus->getBusHireRatePerMile() * selected_route->get_distance()));
							std::cout << "There is a security deposit for the luxury bus hire: " << hire_mini_bus->getSecurityDeposit() << std::endl;
							std::cout << "Current cost is: " << bus_hire_ticket.get_cost() << std::endl;
							std::cout << "Adding security deposit.." << std::endl;
							bus_hire_ticket.set_cost(bus_hire_ticket.get_cost() + hire_mini_bus->getSecurityDeposit());
							std::cout << "Total cost for bus hire is: " << bus_hire_ticket.get_cost() << std::endl;
							this->acct.addTicket(bus_hire_ticket);
							system("PAUSE");
							break;
						}
					}
					else
					{
						selected_route->get_fleet()->displayMiniVanFleet();
						while (true) {
							std::cout << "Enter minivan id to hire it: ";
							if (std::cin >> bus_id) {
								break;
							}
							else {
								std::cout << "Enter a valid id value!\n";
								std::cin.clear();
								std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							}
						}
						

						miniVan* hire_mini_van = selected_route->get_fleet()->getMiniVan(bus_id);
						if (!hire_mini_van)
						{
							std::cout << "The bus id you entered was not found. Please try again!";
							std::cout << "Here are the options: " << std::endl;
							selected_route->get_fleet()->displayMiniVanFleet();
							while (true) {
								std::cout << "\nEnter minivan id to hire it: ";
								if (std::cin >> bus_id) {
									break;
								}
								else {
									std::cout << "Enter a valid id value!\n";
									std::cin.clear();
									std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								}
							}
							hire_mini_van = selected_route->get_fleet()->getMiniVan(bus_id);
						}
						
						if (hire_mini_van->can_hire())
						{
							hire_mini_van->reserveAllSeats();
							ticket bus_hire_ticket;

							//TODO: Ask the user to enter date and time. Currently takes current date and time.
							DateTime bus_hire_dep(2021, 5, 1, 12, 0, 0);
							DateTime bus_hire_arr(2021, 5, 1, 15, 30, 0);
							Trip bus_hire_trip(bus_hire_dep, bus_hire_arr, hire_mini_van);
							selected_route->get_trip_repo()->add_trip(bus_hire_trip);
							std::vector<Trip>* trip_repo = selected_route->get_trip_repo()->getAllTrips();
							bus_hire_ticket.set_trip(&trip_repo->back());
							bus_hire_ticket.set_route(selected_route);
							
							bus_hire_ticket.set_route(selected_route);
							bus_hire_ticket.set_bus_hire(true);
							bus_hire_ticket.set_cost(hire_mini_van->getBusHireRate() + (hire_mini_van->getBusHireRatePerMile() * selected_route->get_distance()));
							std::cout << "There is a security deposit for the luxury bus hire: " << hire_mini_van->getSecurityDeposit() << std::endl;
							std::cout << "Current cost is: " << bus_hire_ticket.get_cost() << std::endl;
							std::cout << "Adding security deposit.." << std::endl;
							bus_hire_ticket.set_cost(bus_hire_ticket.get_cost() + hire_mini_van->getSecurityDeposit());
							std::cout << "Total cost for bus hire is: " << bus_hire_ticket.get_cost() << std::endl;
							this->acct.addTicket(bus_hire_ticket);
							system("PAUSE");
							break;
						}
					}
					break;
				}
			default:
				//log out
				std::cout << "Goodbye, " << acct.get_customer().getFirstName() << std::endl;
				break;
			}
		}
	}
	return 0;
}