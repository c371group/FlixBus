#include "loggedInInterface.h"

loggedInInterface::loggedInInterface(account* account)
{
	this->acct = account;
	preLoad();
	menuLogic();
}

loggedInInterface::loggedInInterface(account* account, route_repo* routeRepo, revenue* revenue)
{
	this->acct = account;
	this->routeRep = routeRepo;
	this->revenue_ = revenue;
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
		std::cout << "Welcome, " << acct->get_customer().get_first_name() << std::endl;
		int max = display_menu_items(0);
		choice_int = enterChoice(max);
		bool confirm = confirm_Menu_Choice(0, choice_int - 1);

		if (!confirm)
		{
			menuLogic();
		}
		else
		{
			switch (choice_int)
			{
			case 1: //acct info
				aIV = accountInfoView(*acct);
				break;
			case 2: //upcoming trips the customer is scheduled to take/has ticket(s) for
			{
				if(this->acct->get_tickets().empty())
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
					for (auto& item : this->acct->get_tickets())
					{
						std::cout << "******************************************************" << std::endl;
						std::cout << "*************** Ticket: " << ticket_number << " *****************************" << std::endl;
						std::cout << "******************************************************" << std::endl;
						std::cout << "** From " << item.get_route()->get_source() << " To " << item.get_route()->get_destination() << std::endl;
						item.get_trip()->get_departure_dt().display_date();
						std::cout << " - ";
						item.get_trip()->get_est_arrival_dt().display_date();
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
					
					while(edit_ticket_choice < 0 || edit_ticket_choice > static_cast<int>(this->acct->get_tickets().size()))
					{
						std::cout << "Wrong choice! Please try again! Choose between 0 and " << static_cast<int>(this->acct->get_tickets().size()) << std::endl;
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
					std::vector<ticket> tickets_edit = this->acct->get_tickets();
					ticket edit_ticket = tickets_edit.at(edit_ticket_choice-1);
					std::cout << "" << std::endl;
					std::cout << "** From " << edit_ticket.get_route()->get_source() << " To " << edit_ticket.get_route()->get_destination() << std::endl;
					edit_ticket.get_trip()->get_departure_dt().display_date();
					std::cout << " - ";
					edit_ticket.get_trip()->get_est_arrival_dt().display_date();
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
						date_time current_date;
						date_time ticket_date = this->acct->get_tickets().at(edit_ticket_choice - 1).get_travel_date();
						int days_difference = current_date.difference_days(ticket_date);
						if(days_difference < 7 && days_difference > 2)
						{
							double cost_ = this->acct->get_tickets().at(edit_ticket_choice - 1).get_cost();
							double amount_ = this->acct->get_tickets().at(edit_ticket_choice - 1).get_cost() * 0.3;
							std::cout << "Any cancellation shorter than a week will require 30%!" << std::endl;
							std::cout << amount_ << " will be hold from your account." << std::endl;
							this->revenue_->withdrawal_income_by_date(edit_ticket.get_trip()->get_departure_dt().to_string(false), cost_);
							this->revenue_->withdrawal_income_by_vehicle(edit_ticket.get_trip()->get_bus()->get_id_no(), cost_);
							this->revenue_->set_total_amount(this->revenue_->get_total_amount() - (cost_ + amount_));
						}
						if (days_difference < 2)
						{
							std::cout << "Reservation cancellation one day before the travel including one minute before the travel will forfeit the entire cost of the ticket.!" << std::endl;
							std::cout << this->acct->get_tickets().at(edit_ticket_choice - 1).get_cost() << " will be hold from your account." << std::endl;
						}
						this->acct->get_tickets().at(edit_ticket_choice - 1).cancel_seat();
						this->acct->remove_ticket(edit_ticket.get_ticket_id());
						if(edit_ticket.get_bus_hire_status())
						{
							//TODO: if bus is hired, we need to go and delete the trip from the trip repo.
						}
						std::cout << "Your ticket was canceled!" << std::endl;
					}
					if (ticket_edit_choice == 2 && !edit_ticket.get_bus_hire_status())
					{
						ticket* reference_to_edit_ticket = this->acct->get_ticket_by_id(edit_ticket.get_ticket_id());
						std::cout << "Free seats for ";
						edit_ticket.get_trip()->get_departure_dt();
						std::cout << " - ";
						edit_ticket.get_trip()->get_est_arrival_dt();
						std::cout << " from " << edit_ticket.get_route()->get_source() << " to " << edit_ticket.get_route()->get_destination() << std::endl;
						edit_ticket.get_trip()->get_bus()->display_free_seats();
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
						double old_cost_of_seat = edit_ticket.get_cost();
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
						
						double cost_of_new_seat = reference_to_edit_ticket->get_cost();
						if(old_cost_of_seat < cost_of_new_seat)
						{
							double difference = cost_of_new_seat - old_cost_of_seat;
							std::cout << "Your new seat is more expensive than your last one." << std::endl;
							this->revenue_->add_income_by_date(reference_to_edit_ticket->get_trip()->get_departure_dt().to_string(false), difference);
							this->revenue_->add_income_by_date_to_db(reference_to_edit_ticket->get_trip()->get_departure_dt().to_string(false), difference);
							this->revenue_->add_income_by_vehicle(reference_to_edit_ticket->get_trip()->get_bus()->get_id_no(), difference);
							this->revenue_->add_income_by_vehicle_to_db(reference_to_edit_ticket->get_trip()->get_bus()->get_id_no(), difference);
							this->revenue_->set_total_amount(this->revenue_->get_total_amount() + (difference + difference));
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
				for (auto item : *this->routeRep->get_routes())
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
				std::vector<route>* selected_vector = this->routeRep->get_routes();
				route* selected_route = &selected_vector->at(choice_index);
				new_ticket.set_route(&selected_vector->at(choice_index));
				std::cout << "DEPARTURE\t\t" << "ARRIVAL\t\t\t" << "SOURCE\t\t" << "DESTINATION" << std::endl;
				int trip_choice = 0;
				int index = 0;
				for (auto item : *selected_route->get_trip_repo()->get_all_trips())
				{
					std::cout << index + 1 << ". ";
					item.get_departure_dt().display_date();
					std::cout << "\t";
					item.get_est_arrival_dt().display_date();
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
					std::cout << "\nWrong choice! Choose between 1 and " << index << std::endl;;
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
					std::vector<trip>* list_of_trips = selected_route->get_trip_repo()->get_all_trips();
					trip* selected_trip = &list_of_trips->at(trip_choice - 1); //&selected_route->get_trip_repo()->getAllTrips()[trip_choice - 1];
					date_time current_date_time;
					if(current_date_time.difference_days(selected_trip->get_departure_dt())>14)
					{
						std::cout << "\nPassengers can reserve seats 2 weeks in advance.\nPlease try again later or select another trip!" << std::endl;
						system("PAUSE");
						break;
					}
					new_ticket.set_trip(&list_of_trips->at(trip_choice - 1));
					std::cout << "\nAvailable bus seats." << std::endl;
					selected_trip->get_bus()->display_free_seats();

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
					while (!new_ticket.reserve_seat(seat_row, seat_column))
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
					new_ticket.set_cost(new_ticket.get_trip()->get_bus()->get_seat_rate(seat_row, seat_column) * new_ticket.get_route()->get_distance());
					std::string compiled_id = this->acct->get_customer().get_last_name() + "_" + new_ticket.get_route()->get_source() + "_" + new_ticket.get_route()->get_destination() + "_" + new_ticket.get_trip()->get_bus()->get_id_no();
					new_ticket.set_ticket_id(compiled_id);
					new_ticket.set_travel_date(selected_trip->get_departure_dt());
					this->revenue_->add_income_by_date(new_ticket.get_trip()->get_departure_dt().to_string(false), new_ticket.get_cost());
					this->revenue_->add_income_by_date_to_db(new_ticket.get_trip()->get_departure_dt().to_string(false), new_ticket.get_cost());
					this->revenue_->add_income_by_vehicle(new_ticket.get_trip()->get_bus()->get_id_no(), new_ticket.get_cost());
					this->revenue_->add_income_by_vehicle_to_db(new_ticket.get_trip()->get_bus()->get_id_no(), new_ticket.get_cost());
					this->revenue_->set_total_amount(this->revenue_->get_total_amount() + new_ticket.get_cost());
					this->acct->add_ticket(new_ticket);
					this->acct->save_ticket_to_db(new_ticket);
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
					for (auto item : *this->routeRep->get_routes())
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
					std::vector<route>* selected_vector = this->routeRep->get_routes();
					route* selected_route = &selected_vector->at(choice_index);

					std::cout << "Currently we have:" << std::endl;
					selected_route->get_fleet()->display_luxury_bus_fleet();
					selected_route->get_fleet()->display_mini_bus_fleet();
					selected_route->get_fleet()->display_mini_van_fleet();
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
						selected_route->get_fleet()->display_luxury_bus_fleet();
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
						luxury_bus* hire_luxury_bus = selected_route->get_fleet()->get_luxury_bus(bus_id);
						if(!hire_luxury_bus)
						{
							std::cout << "The bus id you entered was not found. Please try again!";
							std::cout << "Here are the options: " << std::endl;
							selected_route->get_fleet()->display_luxury_bus_fleet();
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
							hire_luxury_bus = selected_route->get_fleet()->get_luxury_bus(bus_id);
						}
						if(hire_luxury_bus->can_hire())
						{
							hire_luxury_bus->reserve_all_seats();
							ticket bus_hire_ticket;
							
							int choice_year;
							int choice_month;
							int choice_day;

							while (true) {
								std::cout << "Enter year for your bus hire: ";
								if (std::cin >> choice_year) {
									break;
								}
								else {
									std::cout << "Enter a valid id value!\n";
									std::cin.clear();
									std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								}
							}

							while (true) {
								std::cout << "Enter moth for your bus hire: ";
								if (std::cin >> choice_month) {
									break;
								}
								else {
									std::cout << "Enter a valid id value!\n";
									std::cin.clear();
									std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								}
							}

							while (true) {
								std::cout << "Enter day for your bus hire: ";
								if (std::cin >> choice_day) {
									break;
								}
								else {
									std::cout << "Enter a valid id value!\n";
									std::cin.clear();
									std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								}
							}

							date_time bus_hire_dep(choice_year, choice_month, choice_day, 9, 0, 0);
							date_time bus_hire_arr(choice_year, choice_month, choice_day, 15, 30, 0);
							trip bus_hire_trip(bus_hire_dep, bus_hire_arr, hire_luxury_bus);
							selected_route->get_trip_repo()->add_trip(bus_hire_trip);
							std::vector<trip>* trip_repo = selected_route->get_trip_repo()->get_all_trips();
							bus_hire_ticket.set_trip(&trip_repo->back());
							bus_hire_ticket.set_route(selected_route);
							
							bus_hire_ticket.set_bus_hire(true);
							bus_hire_ticket.set_cost(hire_luxury_bus->get_bus_hire_rate() + (hire_luxury_bus->get_bus_hire_rate_per_mile() * selected_route->get_distance()));
							std::cout << "There is a security deposit for the luxury bus hire: " << hire_luxury_bus->get_security_deposit() << std::endl;
							std::cout << "Current cost is: " << bus_hire_ticket.get_cost() << std::endl;
							std::cout << "Adding security deposit.." << std::endl;
							bus_hire_ticket.set_cost(bus_hire_ticket.get_cost() + hire_luxury_bus->get_security_deposit());
							std::cout << "Total cost for bus hire is: " << bus_hire_ticket.get_cost() << std::endl;
							this->revenue_->add_income_by_date(bus_hire_ticket.get_trip()->get_departure_dt().to_string(false), bus_hire_ticket.get_cost());
							this->revenue_->add_income_by_date_to_db(bus_hire_ticket.get_trip()->get_departure_dt().to_string(false), bus_hire_ticket.get_cost());
							this->revenue_->add_income_by_vehicle(bus_hire_ticket.get_trip()->get_bus()->get_id_no(), bus_hire_ticket.get_cost());
							this->revenue_->add_income_by_vehicle_to_db(bus_hire_ticket.get_trip()->get_bus()->get_id_no(), bus_hire_ticket.get_cost());
							this->revenue_->set_total_amount(this->revenue_->get_total_amount() + bus_hire_ticket.get_cost());
							this->acct->add_ticket(bus_hire_ticket);
							this->acct->save_ticket_to_db(bus_hire_ticket);
							system("PAUSE");
							break;
						}
						
					}
					else if(choice_bus_hire == 3)
					{
						selected_route->get_fleet()->display_mini_bus_fleet();
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
						mini_bus* hire_mini_bus = selected_route->get_fleet()->get_mini_bus(bus_id);
						if (!hire_mini_bus)
						{
							std::cout << "The bus id you entered was not found. Please try again!";
							std::cout << "Here are the options: " << std::endl;
							selected_route->get_fleet()->display_mini_bus_fleet();
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
							hire_mini_bus = selected_route->get_fleet()->get_mini_bus(bus_id);
						}
						if (hire_mini_bus->can_hire())
						{
							hire_mini_bus->reserve_all_seats();
							ticket bus_hire_ticket;

							int choice_year;
							int choice_month;
							int choice_day;

							while (true) {
								std::cout << "Enter year for your bus hire: ";
								if (std::cin >> choice_year) {
									break;
								}
								else {
									std::cout << "Enter a valid id value!\n";
									std::cin.clear();
									std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								}
							}

							while (true) {
								std::cout << "Enter moth for your bus hire: ";
								if (std::cin >> choice_month) {
									break;
								}
								else {
									std::cout << "Enter a valid id value!\n";
									std::cin.clear();
									std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								}
							}

							while (true) {
								std::cout << "Enter day for your bus hire: ";
								if (std::cin >> choice_day) {
									break;
								}
								else {
									std::cout << "Enter a valid id value!\n";
									std::cin.clear();
									std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								}
							}

							date_time bus_hire_dep(choice_year, choice_month, choice_day, 9, 0, 0);
							date_time bus_hire_arr(choice_year, choice_month, choice_day, 15, 30, 0);
							
							
							trip bus_hire_trip(bus_hire_dep, bus_hire_arr, hire_mini_bus);
							selected_route->get_trip_repo()->add_trip(bus_hire_trip);
							std::vector<trip>* trip_repo = selected_route->get_trip_repo()->get_all_trips();
							bus_hire_ticket.set_trip(&trip_repo->back());
							bus_hire_ticket.set_route(selected_route);
							
							bus_hire_ticket.set_route(selected_route);
							bus_hire_ticket.set_bus_hire(true);
							bus_hire_ticket.set_cost(hire_mini_bus->get_bus_hire_rate() + (hire_mini_bus->get_bus_hire_rate_per_mile() * selected_route->get_distance()));
							std::cout << "There is a security deposit for the luxury bus hire: " << hire_mini_bus->get_security_deposit() << std::endl;
							std::cout << "Current cost is: " << bus_hire_ticket.get_cost() << std::endl;
							std::cout << "Adding security deposit.." << std::endl;
							bus_hire_ticket.set_cost(bus_hire_ticket.get_cost() + hire_mini_bus->get_security_deposit());
							std::cout << "Total cost for bus hire is: " << bus_hire_ticket.get_cost() << std::endl;
							this->revenue_->add_income_by_date(bus_hire_ticket.get_trip()->get_departure_dt().to_string(false), bus_hire_ticket.get_cost());
							this->revenue_->add_income_by_date_to_db(bus_hire_ticket.get_trip()->get_departure_dt().to_string(false), bus_hire_ticket.get_cost());
							this->revenue_->add_income_by_vehicle(bus_hire_ticket.get_trip()->get_bus()->get_id_no(), bus_hire_ticket.get_cost());
							this->revenue_->add_income_by_vehicle_to_db(bus_hire_ticket.get_trip()->get_bus()->get_id_no(), bus_hire_ticket.get_cost());
							this->revenue_->set_total_amount(this->revenue_->get_total_amount() + bus_hire_ticket.get_cost());
							this->acct->add_ticket(bus_hire_ticket);
							this->acct->save_ticket_to_db(bus_hire_ticket);
							system("PAUSE");
							break;
						}
					}
					else
					{
						selected_route->get_fleet()->display_mini_van_fleet();
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
						

						mini_van* hire_mini_van = selected_route->get_fleet()->get_mini_van(bus_id);
						if (!hire_mini_van)
						{
							std::cout << "The bus id you entered was not found. Please try again!";
							std::cout << "Here are the options: " << std::endl;
							selected_route->get_fleet()->display_mini_van_fleet();
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
							hire_mini_van = selected_route->get_fleet()->get_mini_van(bus_id);
						}
						
						if (hire_mini_van->can_hire())
						{
							hire_mini_van->reserve_all_seats();
							ticket bus_hire_ticket;

							int choice_year;
							int choice_month;
							int choice_day;

							while (true) {
								std::cout << "Enter year for your bus hire: ";
								if (std::cin >> choice_year) {
									break;
								}
								else {
									std::cout << "Enter a valid id value!\n";
									std::cin.clear();
									std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								}
							}

							while (true) {
								std::cout << "Enter moth for your bus hire: ";
								if (std::cin >> choice_month) {
									break;
								}
								else {
									std::cout << "Enter a valid id value!\n";
									std::cin.clear();
									std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								}
							}

							while (true) {
								std::cout << "Enter day for your bus hire: ";
								if (std::cin >> choice_day) {
									break;
								}
								else {
									std::cout << "Enter a valid id value!\n";
									std::cin.clear();
									std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								}
							}

							date_time bus_hire_dep(choice_year, choice_month, choice_day, 9, 0, 0);
							date_time bus_hire_arr(choice_year, choice_month, choice_day, 15, 30, 0);
							trip bus_hire_trip(bus_hire_dep, bus_hire_arr, hire_mini_van);
							selected_route->get_trip_repo()->add_trip(bus_hire_trip);
							std::vector<trip>* trip_repo = selected_route->get_trip_repo()->get_all_trips();
							bus_hire_ticket.set_trip(&trip_repo->back());
							bus_hire_ticket.set_route(selected_route);
							
							bus_hire_ticket.set_route(selected_route);
							bus_hire_ticket.set_bus_hire(true);
							bus_hire_ticket.set_cost(hire_mini_van->get_bus_hire_rate() + (hire_mini_van->get_bus_hire_rate_per_mile() * selected_route->get_distance()));
							std::cout << "There is a security deposit for the luxury bus hire: " << hire_mini_van->get_security_deposit() << std::endl;
							std::cout << "Current cost is: " << bus_hire_ticket.get_cost() << std::endl;
							std::cout << "Adding security deposit.." << std::endl;
							bus_hire_ticket.set_cost(bus_hire_ticket.get_cost() + hire_mini_van->get_security_deposit());
							std::cout << "Total cost for bus hire is: " << bus_hire_ticket.get_cost() << std::endl;
							this->revenue_->add_income_by_date(bus_hire_ticket.get_trip()->get_departure_dt().to_string(false), bus_hire_ticket.get_cost());
							this->revenue_->add_income_by_date_to_db(bus_hire_ticket.get_trip()->get_departure_dt().to_string(false), bus_hire_ticket.get_cost());
							this->revenue_->add_income_by_vehicle(bus_hire_ticket.get_trip()->get_bus()->get_id_no(), bus_hire_ticket.get_cost());
							this->revenue_->add_income_by_vehicle_to_db(bus_hire_ticket.get_trip()->get_bus()->get_id_no(), bus_hire_ticket.get_cost());
							this->revenue_->set_total_amount(this->revenue_->get_total_amount() + bus_hire_ticket.get_cost());
							this->acct->add_ticket(bus_hire_ticket);
							this->acct->save_ticket_to_db(bus_hire_ticket);
							system("PAUSE");
							break;
						}
					}
					break;
				}
			default:
				//log out
				std::cout << "Goodbye, " << acct->get_customer().get_first_name() << std::endl;
				break;
			}
		}
	}
	return 0;
}