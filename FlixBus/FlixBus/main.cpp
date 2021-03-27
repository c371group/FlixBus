#include <iostream>
#include <string>
#include "Customer.h"
using namespace std;

int main() {
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
	route testRout2("Green Bay", "Oshkosh",  504);
	testTicket2.set_route(testRout2);
	testTicket2.set_cost(2500); //25 dollars, or 2500 pennies

	testCustomer.addTicket(testTicket);
	testCustomer.addTicket(testTicket2);

	//testCustomer.datesOfTravel.push_back("1/1/2021 12:00:00PM"); // FIXME: Maybe we should put datetime object here?
	//i'm gonna be honest, I have no idea what you were trying to do here?

	testCustomer.getTickets()[1].set_travel_date("1/1/2021 12:00:00PM");
	
	cout << "Customer: " << testCustomer.getFirstName() << " " << testCustomer.getLastName()<< endl;
	for (ticket item : testCustomer.getTickets()) {
		cout << "Ticket: From " << item.get_route().get_source() << " To " << item.get_route().get_destination() << endl;
		cout << "Total of " << item.get_route().get_distance()<< " miles." << endl;
		cout << "Price: $" << item.get_cost()<< endl;
	}

	return 0;
}