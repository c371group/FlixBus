#pragma once
#include <string>
#include <vector>
#include "Ticket.h"

using namespace std;

class Customer
{
private:
	string f_name_, l_name_, address_, email_;
	string contact_number_;
	ticket* ticket_;
	
public:
	Customer();
	Customer(string f_name, string l_name, string address, string email, string contact_number);
	
	void setFirstName(string f_nam);
	void setLastName(string l_name);
	void setAddress(string address);
	void setEmail(string email);
	void setContactNumber(string contact_number);
	void setTicket(ticket*);
	

	string getFirstName() const;
	string getLastName() const;
	string getAddress() const;
	string getEmail() const;
	string getContactNumber() const;
	ticket* get_ticket();
	
};
