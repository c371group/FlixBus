#include <iostream>
#include <string>
#include "Customer.h"
using namespace std;

int main() {
	////////////////////////////
	// TESTING CLASS RELATION //
	///////////////////////////

	Customer testCustomer;
	testCustomer.setFirstName = "Jon";
	testCustomer.lName = "Doe";
	testCustomer.address = "123 Road St";
	testCustomer.email = "JD@uwgb.edu";

	// Adding test ticket.
	Ticket testTicket;
	Route testRout;
	testRout.source = "Green Bay";
	testRout.destination = "Madison";
	testRout.distance = 135.6;
	testTicket.route = testRout;
	testTicket.cost = 55; // FIXME: This will have to be calculated based on seats.

	// Adding second ticket
	Ticket testTicket2;
	Route testRout2;
	testRout2.source = "Green Bay";
	testRout2.destination = "Oshkosh";
	testRout2.distance = 50.4;
	testTicket2.route = testRout2;
	testTicket2.cost = 25;

	testCustomer.tickets.push_back(testTicket);
	testCustomer.tickets.push_back(testTicket2);

	testCustomer.datesOfTravel.push_back("1/1/2021 12:00:00PM"); // FIXME: Maybe we should put datetime object here?

	cout << "Cusomter: " << testCustomer.fName << " " << testCustomer.lName << endl;
	for (Ticket item : testCustomer.tickets) {
		cout << "Ticket: From " << item.route.source << " To " << item.route.destination << endl;
		cout << "Total of " << item.route.distance << " miles." << endl;
		cout << "Price: $" << item.cost << endl;
	}

	return 0;
}