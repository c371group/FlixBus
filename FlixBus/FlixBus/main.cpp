#include <iostream>
#include <string>

#include "Account.h"
#include "registration.h"
#include "Fleet.h"
#include "Customer.h"
#include "interfaceView.h"
using namespace std;

int customer_interface(accountRepo acctRep);

//TODO: Rewrite this with classes
int customer_interface(accountRepo acctRep)
{
	/*Display menu options of 1. login and 2. register. once selected, ask user to confirm.
	 * If they don't confirm, send them back to login and register menu. if they do confirm,
	 * send them to either register or login interface
	 */
	interfaceView interfaceview = interfaceView();
	interfaceControl intcon = interfaceControl();
	int i = 0;
	int max = interfaceview.display_menu_items(i);
	int choice_int = interfaceview.enterChoice(max, intcon);
	bool confirm = interfaceview.confirm_Menu_Choice(i, choice_int - 1, intcon);
	
	if (!confirm)
	{
		customer_interface(acctRep);
	}
	else
	{
		//TODO: Change to allow going back to menu
		if (choice_int == 1)
		{
			return 0;
		}
		else
		{
			registration reg = registration(acctRep);
			customer_interface(acctRep);
			return 0;
		}
	}
	return 0;
}

int test_basic()
{
	////////////////////////////
	// TESTING CLASS RELATION //
	///////////////////////////

	Customer testCustomer("Jon", "Doe", "123 Road St", "JD@uwgb.edu", "(435) 534-2345");
	Account acct(testCustomer);
	// Adding test ticket.
	ticket testTicket;
	route testRout("Green Bay", "Madison", 1356);
	testTicket.set_route(testRout);
	//testTicket.set_cost(5500); // TODO: This will have to be calculated based on type of bus chosen for ticket;

	// Adding second ticket
	ticket testTicket2;
	route testRout2("Green Bay", "Oshkosh", 504);
	testTicket2.set_route(testRout2);
	testTicket2.set_cost(2500); //25 dollars, or 2500 pennies

	acct.addTicket(testTicket);
	acct.addTicket(testTicket2);

	//testCustomer.datesOfTravel.push_back("1/1/2021 12:00:00PM"); // FIXME: Maybe we should put datetime object here?
	//i'm gonna be honest, I have no idea what you were trying to do here?

	//testCustomer.getTickets().at(1).set_travel_date("1/1/2021 12:00:00PM");

	cout << "Customer: " << acct.get_customer().getFirstName() << " " << acct.get_customer().getLastName() << endl;
	for (ticket item : acct.getTickets())
	{
		cout << "Ticket: From " << item.get_route().get_source() << " To " << item.get_route().get_destination() <<
			endl;
		cout << "Total of " << item.get_route().get_distance() << " miles." << endl;
		cout << "Price: $" << item.get_cost() << endl;
	}
	acct.getTickets()[1].set_travel_date("1/1/2021 12:00:00PM");

	cout << "Customer: " << acct.get_customer().getFirstName() << " " << acct.get_customer().getLastName() << endl;
	for (ticket item : acct.getTickets())
	{
		cout << "Ticket: From " << item.get_route().get_source() << " To " << item.get_route().get_destination() <<
			endl;
		cout << "Total of " << item.get_route().get_distance() << " miles." << endl;
		cout << "Price: $" << item.get_cost() << endl;
	}

	return 0;
}

int main()
{
	//TODO: sticking this here before we have capabilities to read from permanent file
	accountRepo acctRepo;

	try
	{
		customer_interface(acctRepo);
	}
	catch (std::exception e)
	{
		std::cout << "epic fail" << std::endl;
	}


	/*
	////////////////////////
	// TESTING BUS SEATS //
	///////////////////////
	// Testing luxary bus seats
	cout << "\nTesting luxary bus seats" << endl;
	luxaryBus testLuxBus;
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
	
	*/


	/*
	////////////////////////
	//     TEST FLEET    //
	///////////////////////

	fleet busFleet;
	luxaryBus luxBus;
	miniVan miniVan;
	luxaryBus luxBus1;
	miniBus miniBus;
	cout << "\nTesting fleet class." << endl;
	busFleet.displayLuxaryBusFleet();
	busFleet.displayMiniBusFleet();
	busFleet.displayMiniVanFleet();

	cout << "\nAdding Luxary buss" << endl;
	busFleet.addLuxaryBus(&luxBus);
	cout << "Adding Luxary buss" << endl;
	busFleet.addLuxaryBus(&luxBus1);
	cout << "Adding Minivan" << endl;
	busFleet.addMiniVan(&miniVan);
	cout << "Adding Mini buss" << endl;
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
	*/

	//test_basic();
	return 0;
}

