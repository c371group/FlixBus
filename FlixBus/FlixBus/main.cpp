#include <iostream>
#include <string>

#include "Account.h"
#include "registration.h"
#include "Fleet.h"
#include "Customer.h"
#include "DateTime.h"
#include "customerInterface.h"
#include "interfaceView.h"
using namespace std;

int test_basic()
{
	////////////////////////////
	// TESTING CLASS RELATION //
	///////////////////////////

	Customer testCustomer("Jon", "Doe", "123 Road St", "JD@uwgb.edu", "(435) 534-2345");
	Account acct(testCustomer);
    fleet testFleet;
	// Adding test ticket.
	ticket testTicket;
	route testRout("Green Bay", "Madison", 1356, &testFleet);
	testTicket.set_route(&testRout);
	//testTicket.set_cost(5500); // TODO: This will have to be calculated based on type of bus chosen for ticket;

	// Adding second ticket
	ticket testTicket2;
	route testRout2("Green Bay", "Oshkosh", 504, &testFleet);
	testTicket2.set_route(&testRout2);
	testTicket2.set_cost(2500); //25 dollars, or 2500 pennies

	acct.addTicket(testTicket);
	acct.addTicket(testTicket2);

	//testCustomer.datesOfTravel.push_back("1/1/2021 12:00:00PM"); // FIXME: Maybe we should put datetime object here?
	//i'm gonna be honest, I have no idea what you were trying to do here?

	//testCustomer.getTickets().at(1).set_travel_date("1/1/2021 12:00:00PM");

	cout << "Customer: " << acct.get_customer().getFirstName() << " " << acct.get_customer().getLastName() << endl;
	for (ticket item : acct.getTickets())
	{
		cout << "Ticket: From " << item.get_route()->get_source() << " To " << item.get_route()->get_destination() <<
			endl;
		cout << "Total of " << item.get_route()->get_distance() << " miles." << endl;
		cout << "Price: $" << item.get_cost() << endl;
	}
    DateTime ticketDate(2021, 1, 1, 12, 0, 0);
	acct.getTickets()[1].set_travel_date(ticketDate);

	cout << "Customer: " << acct.get_customer().getFirstName() << " " << acct.get_customer().getLastName() << endl;
	for (ticket item : acct.getTickets())
	{
		cout << "Ticket: From " << item.get_route()->get_source() << " To " << item.get_route()->get_destination() <<
			endl;
		cout << "Total of " << item.get_route()->get_distance() << " miles." << endl;
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
	busFleet.displayLuxaryBusFleet();
	busFleet.displayMiniBusFleet();
	busFleet.displayMiniVanFleet();

	cout << "\nAdding Luxury buss" << endl;
	busFleet.addLuxaryBus(&luxBus);
	cout << "Adding Luxury buss" << endl;
	busFleet.addLuxaryBus(&luxBus1);
	cout << "Adding Minivan" << endl;
	busFleet.addMiniVan(&miniVan);
	cout << "Adding Mini bus" << endl;
	busFleet.addMiniBus(&miniBus);

	busFleet.displayLuxaryBusFleet();
	busFleet.displayMiniBusFleet();
	busFleet.displayMiniVanFleet();

	vehicle* testSeats = busFleet.getLuxaryBus(0);
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
    int adminPrivlages = 0;
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

            while (adminPrivlages != sentinel) {
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
    luxuryBus luxBus(201);
    luxuryBus luxBus1(203);
    miniVan miniVan_(202);
    miniBus miniBus(204);
    std::cout << "Creating fleet object" << std::endl;
    fleet GBMadisonFleet;
    std::cout << "Adding buses to fleet object" << std::endl;
    GBMadisonFleet.addLuxaryBus(&luxBus);
    GBMadisonFleet.addLuxaryBus(&luxBus1);
    GBMadisonFleet.addMiniVan(&miniVan_);
    GBMadisonFleet.addMiniBus(&miniBus);
    std::cout << "Creating route object" << std::endl;
    route GreenBayMadison("Green Bay", "Madison", 135.6, &GBMadisonFleet);
    std::cout << "Creating customer." << std::endl;
    Customer testCustomer("Jon", "Doe", "123 Road St", "JD@uwgb.edu", "(435) 534-2345");
    luxuryBus* testBussPtr = GBMadisonFleet.getLuxaryBus(203);
    ticket customerTicket(&GreenBayMadison, testBussPtr);
    DateTime ticketDate(2021, 5, 5, 12, 0, 0);
    customerTicket.set_travel_date(ticketDate);
    customerTicket.set_active(true);
    customerTicket.add_seat(1, 'A');
    testCustomer.setTicket(&customerTicket);
    std::cout << "Customer: " << std::endl;
    std::cout << "\tName: " << testCustomer.getFirstName() << " " << testCustomer.getLastName() << std::endl;
    std::cout << "\tContact number: " << testCustomer.getContactNumber() << std::endl;
    std::cout << "\tRoute: " << testCustomer.get_ticket()->get_route()->get_source() << " - " << testCustomer.get_ticket()->get_route()->get_destination() << std::endl;
    std::cout << "\tBus type: " << testCustomer.get_ticket()->get_bus()->get_type() << std::endl;
    std::cout << "\tSeat number: " << testCustomer.get_ticket()->get_seat_number()<< std::endl;
    std::cout << "\tTicket cost: " << testCustomer.get_ticket()->get_cost() << std::endl;
    std::cout << "All seats count on the bus: " << testCustomer.get_ticket()->get_bus()->get_all_seats_count() << std::endl;
    std::cout << "All free seats count on the bus: " << testCustomer.get_ticket()->get_bus()->get_free_seats_count() << std::endl;


    std::cout << "\nTesting 2nd Customer" << std::endl;
    route GreenBayMilwaukee("Green Bay", "Milwaukee", 118.7, &GBMadisonFleet);
    Customer testCustomer2("Poo", "Moo", "852 Road St", "PM@uwgb.edu", "(920) 123-4567");
    miniVan* testMinivanPtr = GBMadisonFleet.getMiniVan(202);
    ticket customerTicket2(&GreenBayMilwaukee, testMinivanPtr);
    DateTime newTicketDate(2021, 5, 1, 17, 45, 0);
    customerTicket2.set_travel_date(ticketDate);
    customerTicket2.set_active(true);
    customerTicket2.add_seat(4, 'B');
    testCustomer2.setTicket(&customerTicket2);
    std::cout << "Customer: " << std::endl;
    std::cout << "\tName: " << testCustomer2.getFirstName() << " " << testCustomer2.getLastName() << std::endl;
    std::cout << "\tContact number: " << testCustomer2.getContactNumber() << std::endl;
    std::cout << "\tRoute: " << customerTicket2.get_route()->get_source() << " - " << customerTicket2.get_route()->get_destination() << std::endl;
    std::cout << "\tBus type: " << customerTicket2.get_bus()->get_type() << std::endl;
    std::cout << "\tSeat number: " << customerTicket2.get_seat_number() << std::endl;
    std::cout << "\tTicket cost: " << customerTicket2.get_cost() << std::endl;
    std::cout << "All seats count on the bus: " << testCustomer2.get_ticket()->get_bus()->get_all_seats_count() << std::endl;
    std::cout << "All free seats count on the bus: " << testCustomer2.get_ticket()->get_bus()->get_free_seats_count() << std::endl;

}

int main()
{
	//TODO: sticking this here before we have capabilities to read from permanent file
	accountRepo acctRepo = accountRepo();
    //busSeatTesting();
    //fleetTesting();
	//dateTesting();
    //functionalityTesting();

    try
	{
		customerInterface custInterface = customerInterface(acctRepo);
	}
	catch (std::exception e)
	{
		std::cout << "epic fail" << std::endl;
	}
}