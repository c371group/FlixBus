#include <string>
#include <vector>
#include "Ticket.h"

using namespace std;


class Customer {
public:
	string firstName, lastName, address, email;
	int number;
	vector<Ticket> tickets;
	vector<string> datesOfTravel;
};