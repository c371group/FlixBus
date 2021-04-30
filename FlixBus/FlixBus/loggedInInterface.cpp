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
				std::cout << "Travel Date\t\tSource\tDestination\tCost" << std::endl;
				for (auto& item : this->acct.getTickets())
				{
					std::cout << "******************************************************" << std::endl;
					std::cout << "Ticket: From " << item.get_route()->get_source() << " To " << item.get_route()->get_destination() << std::endl;
					item.get_trip()->getDepartureDT().displayDate();
					std::cout << " - ";
					item.get_trip()->getEstArrivalDT().displayDate();
					std::cout << "\nTotal of " << item.get_route()->get_distance() << " miles." << std::endl;
					std::cout << "Price: $" << item.get_cost() << std::endl;
					std::cout << "Bus type: " << item.get_trip()->get_bus()->get_type() << std::endl;
					std::cout << "Seat number: " << item.get_seat_number() << std::endl;
					std::cout << "Ticket cost: " << item.get_cost() << std::endl;
					std::cout << "******************************************************" << std::endl;
				}
				system("PAUSE");
				break;
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
				std::cout << "\nPlease select a route for your trip (or enter 0 to exit): ";
				std::cin >> route_choice;
				while (route_choice < 0 || route_choice > route_index)
				{
					std::cout << "\nWrong choice! Please select a route for your trip (or enter 0 to exit): ";
					std::cin >> route_choice;
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
				std::cout << "\n\nPlease select a trip (or enter 0 to exit): ";
				std::cin >> trip_choice;
				while (trip_choice < 0 || trip_choice > index)
				{
					std::cout << "\n\nPlease select a trip (1-" << index << ") or (enter 0 to exit): ";
					std::cin >> trip_choice;
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
					std::cout << "\nEnter row (number): " << std::endl;
					std::cin >> seat_row;
					std::cout << "\nEnter column (char): " << std::endl;
					std::cin >> seat_column;
					if (new_ticket.reserve_seat(seat_row, seat_column))
					{
						std::cout << "Seat " << new_ticket.get_seat_number() << "reserved" << std::endl;
					}
					else
					{
						std::cout << "We couldn't reserve this seat." << std::endl;
					}
					new_ticket.set_cost(new_ticket.get_trip()->get_bus()->getSeatRate(seat_row, seat_column) * new_ticket.get_route()->get_distance());
					this->acct.addTicket(new_ticket);
					break;
				}
				
			}
			case 5:
				/*see history for account, including cancelled tickets and prior trips or rentals*/
				break;
			case 6:
				//bus rental
				break;
			default:
				//log out
				std::cout << "Goodbye, " << acct.get_customer().getFirstName() << std::endl;
				break;
			}
		}
	}
	return 0;
}