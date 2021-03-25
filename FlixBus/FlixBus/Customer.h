#include <string>
#include <vector>
#include "Ticket.h"

using namespace std;

class Customer {
private:
	string userID;
	string firstName, lastName, address, email;
	int contactNumber;
	vector<Ticket> tickets;
public:
	Customer(string id, string fName, string lName, string address, string email, string number);
	void setUserID(string id);
	void setFirstName(string fName);
	void setLastName(string lName);
	void setAddress(string address);
	void setEmail(string email);
	void setNumber(int number);
	void addTicket(Ticket ticket);
	void removeTicket(int ticketId);

	string getFirstName();
	string getLastName();
	string getAddress();
	string getEmail();
	int getNumber();
	vector<Ticket> getTickets();
};