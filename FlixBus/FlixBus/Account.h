#pragma once
#include <string>
#include "Customer.h"
#include "uniqueID.h"

class Account
{
private:
	uniqueID acctID;
	std::string username_, password_;
	Customer customer;
	std::vector<ticket> tickets_;
public:
	Account();
	Account(Customer);
	Account(Customer cust, int person); //TESTING ONLY
	Account(Customer, std::string, std::string);
	void set_acct_id(uniqueID acctID);
	void set_username(std::string);
	void set_password(std::string);
	void set_customer(Customer);
	void addTicket(ticket ticket);
	void removeTicket(std::string ticket_id);
	
	uniqueID get_acct_id();
	std::string get_username() const;
	std::string get_password() const;
	Customer get_customer() const;
	std::vector<ticket> getTickets();
	ticket* get_ticket_by_id(std::string ticket_id);
};

