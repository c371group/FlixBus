#include <string>
#include <vector>
#include "Ticket.h"

using namespace std;

class Customer {
private:
	string userID;
	string fName, lName, address, email;
	int contactNumber;
	vector<Ticket> tickets;
public:
	Customer(string id, string fName, string lName, string address, string email, int contactNumber);
	void setUserID(string id);
	void setFirstName(string fName);
	void setLastName(string lName);
	void setAddress(string address);
	void setEmail(string email);
	void setContactNumber(int contactNumber);
	void addTicket(Ticket ticket);
	void removeTicket(int ticketId);

	string getFirstName() const;
	string getLastName() const;
	string getAddress() const;
	string getEmail() const;
	int getContactNumber() const;
	vector<Ticket> getTickets() const;
};