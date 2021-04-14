#include <iostream>
#include <string>
#include "registration.h"
#include "Fleet.h"
#include "Customer.h"
using namespace std;

bool validateInt(std::string, int, int);
int customer_interface();

//TODO: Rewrite this with classes, also find way to use validateInt here without writing twice??
//Just want to have something "down on paper"
int customer_interface()
{
	std::string user_input_string;
	std::cout << "1) Login \n2) Register" << std::endl;
	std::cout << "Enter desired choice: ";
	getline(std::cin, user_input_string);

	while (!validateInt(user_input_string, 1, 2)) {
		std::cout << "ERROR-- A valid choice must be entered: ";
		getline(std::cin, user_input_string);
	}
	const auto choice_int = stoi(user_input_string);
	//TODO: Change to allow going back to menu
	if (choice_int == 1) {
		return 0;
	}
	else {
		registration reg = registration(true);
		return 0;
	}

	return 0;
}

bool validateInt(std::string input, int min_num, int max_num)
{
	/* Description: the validInt function (overloaded) takes string input (returning false if empty) and attempts to convert to an integer, returning false if not. After successful conversion, the integer version of the string (intInput) is checked to make sure it does not exceed max_num and that min_num is not greater than intInput. If either of these two conditions are violated, return false. Otherwise, return true.
Pre: min_num cannot be greater than max_num.
Post: Returns true if string satisifies conditions established by min_num and/or max_num. */

	int int_input;

	if (input.length() == 0) {
		return false;
	}
	else {
		try {
			int_input = stoi(input);
		}
		catch (std::exception a) {
			return false;
		}

		if (int_input < min_num || int_input > max_num) {
			return false;
		}
	}
	return true;
}
int test_basic()
{
////////////////////////////
// TESTING CLASS RELATION //
///////////////////////////

	Customer testCustomer("3435225", "Jon", "Doe", "123 Road St", "JD@uwgb.edu", "(435) 534-2345");

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

	testCustomer.addTicket(testTicket);
	testCustomer.addTicket(testTicket2);

	//testCustomer.datesOfTravel.push_back("1/1/2021 12:00:00PM"); // FIXME: Maybe we should put datetime object here?
	//i'm gonna be honest, I have no idea what you were trying to do here?

	//testCustomer.getTickets().at(1).set_travel_date("1/1/2021 12:00:00PM");

	cout << "Customer: " << testCustomer.getFirstName() << " " << testCustomer.getLastName() << endl;
	for (ticket item : testCustomer.getTickets()) {
		cout << "Ticket: From " << item.get_route().get_source() << " To " << item.get_route().get_destination() << endl;
		cout << "Total of " << item.get_route().get_distance() << " miles." << endl;
		cout << "Price: $" << item.get_cost() << endl;
  }
	testCustomer.getTickets()[1].set_travel_date("1/1/2021 12:00:00PM");
	
	cout << "Customer: " << testCustomer.getFirstName() << " " << testCustomer.getLastName()<< endl;
	for (ticket item : testCustomer.getTickets()) {
		cout << "Ticket: From " << item.get_route().get_source() << " To " << item.get_route().get_destination() << endl;
		cout << "Total of " << item.get_route().get_distance()<< " miles." << endl;
		cout << "Price: $" << item.get_cost()<< endl;
	}

	return 0;
}

int main()
{

	interfaceControl int_con = interfaceControl();
	
	try {
		customer_interface();
	} catch (std::exception e)
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
