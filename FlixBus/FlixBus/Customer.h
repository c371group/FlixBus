#pragma once
#include <string>
#include <vector>
#include "Ticket.h"

//using namespace std;

class Customer
{
private:
	std::string f_name_, l_name_, address_, email_;
	std::string contact_number_;
	ticket* ticket_;
	
public:
	Customer();
	Customer(std::string f_name, std::string l_name, std::string address, std::string email, std::string contact_number);
	
	void setFirstName(std::string f_nam);
	void setLastName(std::string l_name);
	void setAddress(std::string address);
	void setEmail(std::string email);
	void setContactNumber(std::string contact_number);
	void setTicket(ticket*);
	

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getAddress() const;
	std::string getEmail() const;
	std::string getContactNumber() const;
	ticket* get_ticket();
	
};
