#include <iostream>
#include <string>
#include "trip.h"
#include "Account.h"
#include "registration.h"
#include "Fleet.h"
#include "Customer.h"
#include "DateTime.h"
#include "customerInterface.h"
#include "fullTripListView.h"
#include "interfaceView.h"
#include "userTypeMenuView.h"
#include "routeRepo.h"
using namespace std;

int test_basic()
{
	////////////////////////////
	// TESTING CLASS RELATION //
	///////////////////////////

	Customer testCustomer("Jon", "Doe", "123 Road St", "JD@uwgb.edu", "(435) 534-2345");
	Account acct(testCustomer);
	luxuryBus lux_bus("L201");
    fleet testFleet;
	testFleet.addLuxuryBus(lux_bus);
	// Adding test ticket.
	DateTime departure(2021,5,1,12,0,0);
	DateTime arrival(2021, 5, 1, 15, 0, 0);
	route testRout("Green Bay", "Madison", 135.6, &testFleet);
	Trip test_trip(departure, arrival, &lux_bus);
	tripRepo trip_repo_test;
	trip_repo_test.add_trip(&test_trip);
	ticket testTicket(&testRout, &test_trip);
    testTicket.reserve_seat(1, 'C');
	testTicket.set_cost(testTicket.get_trip()->get_bus()->getSeatRate(1, 'A') * testRout.get_distance());
	acct.addTicket(testTicket);
	
	
	
	//testTicket.set_route(&testRout);
	//testTicket.set_cost(5500); // TODO: This will have to be calculated based on type of bus chosen for ticket;

	// Adding second ticket
	route test_route("Madison", "Green Bay", 135.6, &testFleet);
	DateTime departure_(2021, 5, 2, 9, 0, 0);
	DateTime arrival_(2021, 5, 2, 12, 0, 0);
	luxuryBus lux_bus_("L202");
	Trip test_trip_2(departure_, arrival_, &lux_bus_);
	trip_repo_test.add_trip(&test_trip_2);
	ticket testTicket2(&test_route, &test_trip_2);
    testTicket2.reserve_seat(3, 'C');
	testTicket2.set_cost(testTicket2.get_trip()->get_bus()->getSeatRate(3, 'C') * testRout.get_distance());
	acct.addTicket(testTicket2);

	//testCustomer.getTickets().at(1).set_travel_date("1/1/2021 12:00:00PM");

	cout << "Customer: " << acct.get_customer().getFirstName() << " " << acct.get_customer().getLastName() << endl;
	for (ticket item : acct.getTickets())
	{
		cout << "Ticket: From " << item.get_route()->get_source() << " To " << item.get_route()->get_destination() <<
			endl;
		item.get_trip()->getDepartureDT().displayDate();
		cout << " - ";
		item.get_trip()->getEstArrivalDT().displayDate();
		cout << "\nTotal of " << testRout.get_distance() << " miles." << endl;
		cout << "Price: $" << item.get_cost() << endl;
	}

	return 0;
}

void busSeatTesting()
{
	/*
	////////////////////////
	// TESTING BUS SEATS //
	/////////////////////// */
	// Testing luxury bus seats
	cout << "\nTesting luxury bus seats" << endl;
	luxuryBus testLuxBus;
	testLuxBus.displaySeats();
	testLuxBus.reserveSeat(1, 'B');
	testLuxBus.reserveSeat(11, 'B');
	testLuxBus.reserveSeat(33, 'B');
	testLuxBus.displayFreeSeats();
	testLuxBus.cancelSeat(11, 'B');
	testLuxBus.displayFreeSeats();

	// Testing small bus seats
	cout << "\nTesting mini bus seats" << endl;
	miniBus testMiniBus;
	testMiniBus.displaySeats();
	testMiniBus.reserveSeat(1, 'A');
	testMiniBus.reserveSeat(11, 'A');
	testMiniBus.reserveSeat(42, 'A');
	testMiniBus.displayFreeSeats();
	testMiniBus.cancelSeat(1, 'A');
	testMiniBus.displayFreeSeats();

	// Testing mini bus seats
	cout << "\nTesting minivan seats" << endl;
	miniVan testMiniVan;
	testMiniVan.displaySeats();
	testMiniVan.reserveSeat(1, 'C');
	testMiniVan.reserveSeat(3, 'C');
	testMiniVan.reserveSeat(12, 'B');
	testMiniVan.displayFreeSeats();
	testMiniVan.cancelSeat(1, 'C');
	testMiniVan.displayFreeSeats();
}

void fleetTesting()
{
	/*
	////////////////////////
	//     TEST FLEET    //
	/////////////////////// */

	fleet busFleet;
	luxuryBus luxBus;
	miniVan miniVan;
	luxuryBus luxBus1;
	miniBus miniBus;
	cout << "\nTesting fleet class." << endl;
	busFleet.displayLuxuryBusFleet();
	busFleet.displayMiniBusFleet();
	busFleet.displayMiniVanFleet();

	cout << "\nAdding Luxury bus" << endl;
	busFleet.addLuxuryBus(luxBus);
	cout << "Adding Luxury bus" << endl;
	busFleet.addLuxuryBus(luxBus1);
	cout << "Adding Minivan" << endl;
	busFleet.addMiniVan(miniVan);
	cout << "Adding Mini bus" << endl;
	busFleet.addMiniBus(miniBus);

	busFleet.displayLuxuryBusFleet();
	busFleet.displayMiniBusFleet();
	busFleet.displayMiniVanFleet();

	vehicle* testSeats = busFleet.getLuxuryBus("0");
	cout << "\nTesting accessing seats from the fleet class:" << endl;
	testSeats->displaySeats();
	cout << "\nTesting reserving a seat from the fleet class:" << endl;
	testSeats->reserveSeat(1, 'A');
	testSeats->reserveSeat(1, 'B');
	testSeats->displayFreeSeats();
}

void dateTesting() {
	DateTime currentDate;
	DateTime testTicketDate(2021, 6, 20, 12,0,0);
	std::cout << "Current date: " << std::endl;
	currentDate.displayDate();
	std::cout << "\nTicket date: " << std::endl;
	testTicketDate.displayDate();
	std::cout << "\nDifference in days: " << std::endl;
	std::cout << currentDate.differenceDays(testTicketDate) << std::endl;
	
	// Needs sleep if we want the 2 times to be different.
	std::cout << "Get updated current date: " << std::endl;
	currentDate.getCurrentTime();
}

int mainMenu()
{

    //Setting variables for choice, order, and sentinel. 
    int mainMenu = 0;
    int customerMenu = 0;
    int orderReservation = 0;
    int luxarySeating = 0;
    int miniBusSeating = 0;
    int miniVanSeating = 0;
    int adminPrivileges = 0;
    int sentinel = -1;

    while (mainMenu != sentinel) {
        //Creating the choice options of Order, Pay, Exit.
        cout << "1. Are you a customer? \n2. Are you an admin? \n3. Would you like to exit? \n";

        cin >> mainMenu;
        switch (mainMenu) {

            //Menu for Customer 
        case 1:

            while (customerMenu != sentinel) {
                //Creating the choice options for reservation and scheduling. 
                cout << "1. Would you like to make a reservation? \n2. Would you like to schedule? \n";

                cin >> customerMenu;
                switch (customerMenu) {

                case 1:

                    while (orderReservation != sentinel) {
                        //Showing the code for ordering each item possible. All 3 possible busses. 
                        cout << "Reserve your seats from the list of options:\n";
                        cout << "1. Luxary Bus \n2. Mini Bus \n3. Minivan \n";

                        cin >> orderReservation;
                        switch (orderReservation) {

                        case 1:

                            while (luxarySeating != sentinel) {
                                //Showing the code for ordering each item possible. All 3 possible seats. 
                                cout << "Seats for Luxary Bus Include: \n1. Aisle Seats \n2. Window Seats \n3. Other Seats \n";

                                cin >> luxarySeating;
                                switch (luxarySeating) {

                                case 1:
                                    cout << "How many Aisle seats would you like to order?\n";
                                    //****Insert Code Here****//
                                    break;

                                case 2:
                                    cout << "How many Window seats would you like to order?\n";
                                    //****Insert Code Here****//
                                    break;

                                case 3:
                                    cout << "How many Other seats would you like to order?\n";
                                    //****Insert Code Here****//
                                    break;

                                default:
                                    cout << "Please enter a valid option. \n";
                                    return orderReservation;
                                }
                            }

                        case 2:

                            while (miniBusSeating != sentinel) {
                                //Showing the code for ordering each item possible.
                                cout << "Seats for Mini Bus Include: \n1. Aisle Seats \n2. Window Seats \n";

                                cin >> miniBusSeating;
                                switch (miniBusSeating) {

                                case 1:
                                    cout << "How many Aisle seats would you like to order?\n";
                                    //****Insert Code Here****//
                                    break;

                                case 2:
                                    cout << "How many Window seats would you like to order?\n";
                                    //****Insert Code Here****//
                                    break;

                                default:
                                    cout << "Please enter a valid option. \n";
                                    return orderReservation;
                                }
                            }

                        case 3:

                            while (miniVanSeating != sentinel) {
                                //Showing the code for ordering each item possible.
                                cout << "The Minivan is a set Rent Value.\n";

                                cin >> miniVanSeating;
                                switch (miniVanSeating) {


                                case 1:
                                    cout << "Please order the amount of Minivans you desire.\n";
                                    //****Insert Code Here****//
                                    break;

                                default:
                                    cout << "Please enter a valid option. \n";
                                    return orderReservation;
                                }
                            }

                        default:
                            cout << "Please enter a valid option. \n";
                            return orderReservation;
                        }
                    }

                case 2:

                    //What do we need to do for scheduling?
                default:
                    cout << "Please enter a valid option. \n";
                    return orderReservation;
                }
            }

            //Menu for Admin 
        case 2:

            while (adminPrivileges != sentinel) {
                //Showing the code for ordering each item possible. All 3 possible busses. 
                cout << "1. Add a vehicle \n2. View reservations \n3. Edit passenger information \n4. Change reservation charges \n5. View income \n";

                cin >> orderReservation;
                switch (orderReservation) {

                case 1:
                    cout << "Add a vehicle to the fleet:\n";
                    //****Insert Code Here****//
                    break;

                case 2:
                    cout << "View reservation by bus and date:\n";
                    //****Insert Code Here****//
                    break;

                case 3:
                    cout << "Edit passenger's name and charges:\n";
                    //****Insert Code Here****//
                    break;

                case 4:
                    cout << "Change reservation charges:\n";
                    //****Insert Code Here****//
                    break;

                case 5:
                    cout << "View income:\n";
                    //****Insert Code Here****//
                    break;
                }
            }
        case 3:
            exit(0);
        }
        system("PAUSE");
    }
    return 0;
}

void functionalityTesting() {

    std::cout << "Creating buses" << std::endl;
    luxuryBus luxBus("LB002");
    luxuryBus luxBus1("LB003");
    miniVan miniVan_("MV202");
    miniBus miniBus("MB204");
    std::cout << "Creating fleet object" << std::endl;
    fleet GBMadisonFleet;
    std::cout << "Adding buses to fleet object" << std::endl;
    GBMadisonFleet.addLuxuryBus(luxBus);
    GBMadisonFleet.addLuxuryBus(luxBus1);
    GBMadisonFleet.addMiniVan(miniVan_);
    GBMadisonFleet.addMiniBus(miniBus);
    std::cout << "Creating route object" << std::endl;
    route GreenBayMadison("Green Bay", "Madison", 135.6, &GBMadisonFleet);
    std::cout << "Creating customer." << std::endl;
    Customer testCustomer("Jon", "Doe", "123 Road St", "JD@uwgb.edu", "(435) 534-2345");
    Account acct(testCustomer);
    luxuryBus* testBussPtr = GBMadisonFleet.getLuxuryBus("LB002");
    DateTime dep_(2021, 5, 1, 20, 05, 00);
    DateTime arr_(2021, 5, 1, 23, 00, 00);
    Trip customer_trip(dep_, arr_, testBussPtr);
    ticket customerTicket(&GreenBayMadison, &customer_trip);
    DateTime ticketDate(2021, 5, 5, 12, 0, 0);
    customerTicket.set_travel_date(ticketDate);
    customerTicket.set_active(true);
    customerTicket.reserve_seat(4, 'B');
    acct.addTicket(customerTicket);

    std::cout << "Customer: " << std::endl;
    std::cout << "\tName: " << acct.get_customer().getFirstName() << " " << acct.get_customer().getLastName() << std::endl;
    std::cout << "\tContact number: " << acct.get_customer().getContactNumber() << std::endl;

    for (ticket item : acct.getTickets())
    {
        cout << "Ticket: From " << item.get_route()->get_source() << " To " << item.get_route()->get_destination() <<
            endl;
        item.get_trip()->getDepartureDT().displayDate();
        cout << " - ";
        item.get_trip()->getEstArrivalDT().displayDate();
        cout << "\nTotal of " << item.get_route()->get_distance() << " miles." << endl;
        cout << "\tPrice: $" << item.get_cost() << endl;
        cout << "\tBus type: " << item.get_trip()->get_bus()->get_type() << endl;
        cout << "\tSeat number: " << item.get_seat_number() << endl;
        cout << "\tTicket cost: " << item.get_cost() << endl;
        cout << "\tAll seats count on the bus: " << item.get_trip()->get_bus()->get_all_seats_count() << endl;
        cout << "\tAll free seats count on the bus: " << item.get_trip()->get_bus()->get_free_seats_count() << endl;
    }
	

    std::cout << "\nTesting 2nd Customer" << std::endl;
    route GreenBayMilwaukee("Green Bay", "Milwaukee", 118.7, &GBMadisonFleet);
    Customer testCustomer2("Poo", "Moo", "852 Road St", "PM@uwgb.edu", "(920) 123-4567");
    Account acct2(testCustomer2);
    miniVan* testMinivanPtr = GBMadisonFleet.getMiniVan("MV202");
    DateTime dep_2(2021, 5, 11, 11, 5, 00);
    DateTime arr_2(2021, 5, 11, 14, 45, 00);
    Trip customer_2_trip(dep_2, arr_2, testMinivanPtr);
    ticket customerTicket2(&GreenBayMilwaukee, &customer_2_trip);
    customerTicket2.reserve_seat(4, 'C');
    acct2.addTicket(customerTicket2);

    for (ticket item : acct2.getTickets())
    {
        cout << "Ticket: From " << item.get_route()->get_source() << " To " << item.get_route()->get_destination() <<
            endl;
        item.get_trip()->getDepartureDT().displayDate();
        cout << " - ";
        item.get_trip()->getEstArrivalDT().displayDate();
        cout << "\nTotal of " << item.get_route()->get_distance() << " miles." << endl;
        cout << "\tPrice: $" << item.get_cost() << endl;
        cout << "\tBus type: " << item.get_trip()->get_bus()->get_type() << endl;
        cout << "\tSeat number: " << item.get_seat_number() << endl;
        cout << "\tTicket cost: " << item.get_cost() << endl;
        cout << "\tAll seats count on the bus: " << item.get_trip()->get_bus()->get_all_seats_count() << endl;
        cout << "\tAll free seats count on the bus: " << item.get_trip()->get_bus()->get_free_seats_count() << endl;
    }

}

void busHireTesting()
{
    cout << "\nTesting luxury bus hire:" << endl;
    cout << "Creating luxury bus object and reserving seats." << endl;
    luxuryBus lux_bus;
    lux_bus.reserveSeat(1, 'A');
    lux_bus.reserveSeat(2, 'A');
    lux_bus.reserveSeat(3, 'A');
    lux_bus.reserveSeat(4, 'A');
    lux_bus.reserveSeat(5, 'A');
    lux_bus.reserveSeat(6, 'A');
    cout << "Check bus seats:" << endl;
    lux_bus.displayFreeSeats();
    cout << "\nTrying to hire bus." << endl;
    std::cout << std::boolalpha;
    cout << "Bus hire status: " << lux_bus.can_hire() << endl;
    cout << "Hire the bus." << endl;
    lux_bus.reserveAllSeats();
    lux_bus.displayFreeSeats();
    cout << "\nFlat fee for " << lux_bus.get_type() << " hire is: " << lux_bus.getBusHireRate() << endl;
    cout << "Additionally there is a fee of " << lux_bus.getBusHireRatePerMile() << " per mile." << endl;
	
    cout << "\nTesting minivan hire:" << endl;
    miniVan mini_van;
    mini_van.reserveSeat(1, 'A');
    mini_van.reserveSeat(2, 'A');
    mini_van.reserveSeat(3, 'A');
    mini_van.reserveSeat(4, 'A');
    mini_van.reserveSeat(1, 'B');
    mini_van.reserveSeat(2, 'B');
    mini_van.reserveSeat(3, 'B');
    mini_van.reserveSeat(4, 'B');
    cout << "Check bus seats:" << endl;
    mini_van.displayFreeSeats();
    cout << "\nTrying to hire minivan." << endl;
    std::cout << std::boolalpha;
    cout << "Minivan hire status: " << mini_van.can_hire() << endl;
}

void print_customer_info(Account* account)
{
    cout << "\n##########################" << endl;
    cout << "## Customer Information ##" << endl;
    cout << "##########################" << endl;
    cout << "# Name: " << account->get_customer().getFirstName() << " " << account->get_customer().getLastName() << endl;
    cout << "# Address: " << account->get_customer().getAddress() << endl;
    cout << "# Contact Number: " << account->get_customer().getContactNumber() << endl;
    cout << "# Email Address: " << account->get_customer().getEmail() << endl;
    system("pause");
}

void manage_customer_trips(Account* account)
{
    cout << "Manage trips" << endl;
    cout << "Travel Date\t\tSource\tDestination\tCost" << endl;
    for (auto& item : account->getTickets())
    {
        cout << "******************************************************" << endl;
        cout << "Ticket: From " << item.get_route()->get_source() << " To " << item.get_route()->get_destination() <<
            endl;
        item.get_trip()->getDepartureDT().displayDate();
        cout << " - ";
        item.get_trip()->getEstArrivalDT().displayDate();
        cout << "\nTotal of " << item.get_route()->get_distance() << " miles." << endl;
        cout << "\tPrice: $" << item.get_cost() << endl;
        cout << "\tBus type: " << item.get_trip()->get_bus()->get_type() << endl;
        cout << "\tSeat number: " << item.get_seat_number() << endl;
        cout << "\tTicket cost: " << item.get_cost() << endl;
        cout << "******************************************************" << endl;
    }
}

int reserve_customer_ticket(Account* account, routeRepo* route_repo)
{
    route selected_route;
    cout << "AVAILABLE ROUTES: " << endl;
    int route_choice = 0;
    int route_index = 0;
    for (auto item : route_repo->getRoutes())
    {
        cout << route_index + 1 << ". " << item.get_source() << " - " << item.get_destination() << endl;
        route_index++;
    }
    cout << "\nPlease select a route for your trip (or enter 0 to exit): ";
    cin >> route_choice;
    while (route_choice < 0 || route_choice > route_index)
    {
        cout << "\nWrong choice! Please select a route for your trip (or enter 0 to exit): ";
        cin >> route_choice;
    }
    if (route_choice == 0)
    {
        return 0;
    }
    selected_route = route_repo->getRoutes()[route_choice - 1];
    cout << "DEPARTURE\t\t" << "ARRIVAL\t\t\t" << "SOURCE\t\t" << "DESTINATION" << endl;
    int trip_choice = 0;
    int index = 0;
    for (auto item : selected_route.get_trip_repo()->getAllTrips())
    {
        cout << index + 1 << ". ";
        item->getDepartureDT().displayDate();
        cout << "\t";
        item->getEstArrivalDT().displayDate();
        cout << "\t";
        cout << selected_route.get_source() << "\t" << selected_route.get_destination() << "\t" << endl;
        index++;
    }
    cout << "\n\nPlease select a trip (or enter 0 to exit): ";
    cin >> trip_choice;
    while (trip_choice < 0 || trip_choice > index)
    {
        cout << "\n\nPlease select a trip (1-" << index << ") or (enter 0 to exit): ";
        cin >> trip_choice;
    }
    if (trip_choice == 0)
    {
        return 0;
    }
    else
    {
	    Trip * selected_trip = selected_route.get_trip_repo()->getAllTrips()[trip_choice-1];
        cout << "\nAvailable bus seats." << endl;
        selected_trip->get_bus()->displayFreeSeats();
    	
        //vector<route>::iterator it;
        //it = std::find(route_repo->getRoutes().begin(), route_repo->getRoutes().end(), selected_route);

        //tripRepo* test_ = route_repo->getRoutes()[it - route_repo->getRoutes().begin()].get_trip_repo();
    	
        //vector<Trip*>::iterator it_;
        //it_ = std::find(test_->getAllTrips().begin(), test_->getAllTrips().end(), selected_trip);
        //route_repo->getRoutes()[it - route_repo->getRoutes().begin()].get_trip_repo()->getAllTrips()[it_ - test_->getAllTrips().end()];
        //
    	
        //ticket new_ticket(&route_repo->getRoutes()[it - route_repo->getRoutes().begin()], route_repo->getRoutes()[it - route_repo->getRoutes().begin()].get_trip_repo()->getAllTrips()[it_ - test_->getAllTrips().end()]);
        ticket new_ticket(&selected_route, selected_trip);
    	int seat_row;
        char seat_column;
        cout << "\nPlease select a seat: " << endl;
        cout << "\nEnter row (number): " << endl;
        cin >> seat_row;
        cout << "\nEnter column (char): " << endl;
        cin >> seat_column;
        if (new_ticket.reserve_seat(seat_row, seat_column))
        {
            cout << "Seat " << new_ticket.get_seat_number() << "reserved" << endl;
        }
        else
        {
            cout << "We couldn't reserve this seat." << endl;
        }
        account->addTicket(new_ticket);

    }
    return 0;
}

int customer_menu(Account* account, routeRepo* route_repo)
{
    int customer_choice = 0;

    //Creating the choice options for reservation and scheduling.
    cout << "*******************" << endl;
    cout << "*  Customer Menu  *" << endl;
    cout << "*******************" << endl;
    cout << "1. Customer Information\n2. Manage trips\n3. Book a trip\n4. Bus hire\n0. Exit\n";
    cout << "Enter your choice: ";
    cin >> customer_choice;
    switch (customer_choice) {
    case 1:
        //customer info
        print_customer_info(account);
        customer_menu(account, route_repo);
        break;
    case 2:
        //manage trips
        manage_customer_trips(account);
        customer_menu(account, route_repo);
        break;
    case 3:
        //available trips that the customer can book
        reserve_customer_ticket(account, route_repo);
        customer_menu(account, route_repo);
        break;

    case 4:
        //bus hire
        cout << "Bus hire" << endl;
        customer_menu(account, route_repo);
        break;
    case 0:
        break;
    default:
        cout << "Please enter a valid option. \n";
        customer_menu(account, route_repo);
    }

    return 0;
}

void customerMenuTest()
{
    Customer test_customer("Jon", "Doe", "JD@uwgb.edu", "123 Road St", "(435) 534-2345");
    Account test_account(test_customer);

    // Creating test bus fleet. This should come from a file.
    fleet bus_fleet;
    luxuryBus lux_bus_1("LB201");
    luxuryBus lux_bus_2("LB202");
    luxuryBus lux_bus_3("LB203");
    luxuryBus lux_bus_4("LB204");
    luxuryBus lux_bus_5("LB205");
    luxuryBus lux_bus_6("LB206");
    miniVan mini_van_1("MV401");
    miniVan mini_van_2("MV402");
    miniVan mini_van_3("MV403");
    miniVan mini_van_4("MV404");
    miniBus mini_bus_1("MB301");
    miniBus mini_bus_2("MB302");
    miniBus mini_bus_3("MB303");
    miniBus mini_bus_4("MB304");

    // Add them in a loop.
    bus_fleet.addLuxuryBus(lux_bus_1);
    bus_fleet.addLuxuryBus(lux_bus_2);
    bus_fleet.addLuxuryBus(lux_bus_3);
    bus_fleet.addLuxuryBus(lux_bus_4);
    bus_fleet.addLuxuryBus(lux_bus_5);
    bus_fleet.addLuxuryBus(lux_bus_6);

    bus_fleet.addMiniVan(mini_van_1);
    bus_fleet.addMiniVan(mini_van_2);
    bus_fleet.addMiniVan(mini_van_3);
    bus_fleet.addMiniVan(mini_van_4);

    bus_fleet.addMiniBus(mini_bus_1);
    bus_fleet.addMiniBus(mini_bus_2);
    bus_fleet.addMiniBus(mini_bus_3);
    bus_fleet.addMiniBus(mini_bus_4);

    // Adding trips
    Trip GBToMadisonTrip_1(DateTime(2021, 5, 1, 12, 00, 00), DateTime(2021, 5, 1, 15, 00, 00), &lux_bus_1);
    Trip GBToMadisonTrip_2(DateTime(2021, 5, 2, 12, 00, 00), DateTime(2021, 5, 2, 15, 00, 00), &lux_bus_2);
    Trip GBToMadisonTrip_3(DateTime(2021, 5, 3, 12, 00, 00), DateTime(2021, 5, 3, 15, 00, 00), &lux_bus_3);
    Trip GBToMadisonTrip_4(DateTime(2021, 5, 4, 12, 00, 00), DateTime(2021, 5, 4, 15, 00, 00), &lux_bus_4);

    Trip GBToMilwaukeeTrip_1(DateTime(2021, 5, 1, 18, 30, 00), DateTime(2021, 5, 1, 22, 00, 00), &lux_bus_5);
    Trip GBToMilwaukeeTrip_2(DateTime(2021, 5, 4, 18, 30, 00), DateTime(2021, 5, 4, 22, 00, 00), &lux_bus_6);
    Trip GBToMilwaukeeTrip_3(DateTime(2021, 5, 7, 18, 30, 00), DateTime(2021, 5, 7, 22, 00, 00), &mini_van_1);

    Trip GBToWhitewaterTrip_1(DateTime(2021, 5, 1, 10, 45, 00), DateTime(2021, 5, 1, 12, 45, 00), &mini_van_2);
    Trip GBToWhitewaterTrip_2(DateTime(2021, 5, 2, 10, 45, 00), DateTime(2021, 5, 2, 12, 45, 00), &mini_van_3);

    Trip GBToOshkoshTrip_1(DateTime(2021, 5, 1, 9, 00, 00), DateTime(2021, 5, 1, 9, 45, 00), &mini_van_4);
    Trip GBToOshkoshTrip_2(DateTime(2021, 5, 1, 12, 00, 00), DateTime(2021, 5, 1, 12, 45, 00), &mini_bus_1);
    Trip GBToOshkoshTrip_3(DateTime(2021, 5, 1, 15, 00, 00), DateTime(2021, 5, 1, 15, 45, 00), &mini_bus_2);
    Trip GBToOshkoshTrip_4(DateTime(2021, 5, 1, 18, 00, 00), DateTime(2021, 5, 1, 18, 45, 00), &mini_bus_3);

    Trip GBToEauClairTrip_1(DateTime(2021, 5, 1, 10, 00, 00), DateTime(2021, 5, 1, 13, 00, 00), &mini_bus_4);

    tripRepo trip_repoGBMs;
    trip_repoGBMs.add_trip(&GBToMadisonTrip_1);
    trip_repoGBMs.add_trip(&GBToMadisonTrip_2);
    trip_repoGBMs.add_trip(&GBToMadisonTrip_3);
    trip_repoGBMs.add_trip(&GBToMadisonTrip_4);

    tripRepo trip_repoGBMl;
    trip_repoGBMl.add_trip(&GBToMilwaukeeTrip_1);
    trip_repoGBMl.add_trip(&GBToMilwaukeeTrip_2);
    trip_repoGBMl.add_trip(&GBToMilwaukeeTrip_3);

    tripRepo trip_repoGBWw;
    trip_repoGBWw.add_trip(&GBToWhitewaterTrip_1);
    trip_repoGBWw.add_trip(&GBToWhitewaterTrip_2);

    tripRepo trip_repoGBOs;
    trip_repoGBOs.add_trip(&GBToOshkoshTrip_1);
    trip_repoGBOs.add_trip(&GBToOshkoshTrip_2);
    trip_repoGBOs.add_trip(&GBToOshkoshTrip_3);
    trip_repoGBOs.add_trip(&GBToOshkoshTrip_4);

    tripRepo trip_repoGBEc;
    trip_repoGBEc.add_trip(&GBToEauClairTrip_1);
	
    // Adding routes
    route GreenBayMadison("Green Bay", "Madison", 135.6, &bus_fleet, &trip_repoGBMs);
    route GreenBayMilwaukee("Green Bay", "Milwaukee", 118.7, &bus_fleet, &trip_repoGBMl);
    route GreenBayWhitewater("Green Bay", "Whitewater", 142.2, &bus_fleet, &trip_repoGBWw);
    route GreenBayOshkosh("Green Bay", "Oshkosh", 50.4, &bus_fleet, &trip_repoGBOs);
    route GreenBayEauClaire("Green Bay", "Eau Claire", 194.4, &bus_fleet, &trip_repoGBEc);

    routeRepo route_repo;
    route_repo.add_route(GreenBayMadison);
    route_repo.add_route(GreenBayMilwaukee);
    route_repo.add_route(GreenBayWhitewater);
    route_repo.add_route(GreenBayOshkosh);
    route_repo.add_route(GreenBayEauClaire);

    
    Customer customer_("Jon", "Doe", "123 Road St", "JD@uwgb.edu", "(435) 534-2345");
    Account acct(customer_);
    customer_menu(&acct, &route_repo);
}

int main()
{
	accountRepo acctRepo = accountRepo();
    routeRepo rteRepo = routeRepo();
	//test_basic();
    //busSeatTesting();
    //fleetTesting();
	//dateTesting();
    //functionalityTesting();
    //busHireTesting();
    customerMenuTest();
	
 //   try
	//{
	//	userTypeMenuView usertypemenuview = userTypeMenuView(acctRepo);
	//}
	//catch (std::exception e)
	//{
	//	std::cout << "ERROR: COULD NOT LOAD PROGRAM." << std::endl;
 //       exit(0);
	//}
}