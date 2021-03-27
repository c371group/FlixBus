#pragma once
#include <string>
#include <vector>
#include "Ticket.h"

using namespace std;

class Customer {
private:
	string user_id_;
	string f_name_, l_name_, address_, email_;
	string contact_number_;
	vector<ticket> tickets_;
public:
	Customer(string user_id, string f_name, string l_name, string address, string email, string contact_number);
	void setUserID(string user_id);
	void setFirstName(string f_nam);
	void setLastName(string l_name);
	void setAddress(string address);
	void setEmail(string email);
	void setContactNumber(string contact_number);
	void addTicket(ticket ticket);
	void removeTicket(int ticket_id);

	string getFirstName() const;
	string getLastName() const;
	string getAddress() const;
	string getEmail() const;
	string getContactNumber() const;
	vector<ticket> getTickets() ;
};