#pragma once
#include <string>
#include "Customer.h"
#include "uniqueID.h"


/**
 * \brief account object, holds customer object and vector of ticket objects.
 */
class account
{
private:
	// uniqueID account ID
	UniqueID acct_id_;
	// Username and password attributes.
	std::string username_, password_;
	// Customer object attribute.
	customer customer_;
	// Vector of ticket objects attribute.
	std::vector<ticket> tickets_;
public:
	// Base constructor.
	account();
	// Base constructor takes Customer object.
	account(customer);
	// Base constructor takes Customer object and int.
	account(customer cust, int person);
	// Base constructor takes Customer object, username and password.
	account(customer, std::string, std::string);
	// Takes uniqueID object and assigns it to acct_id.
	void set_acct_id(UniqueID acctID);
	// Takes string and assigns it to username_ attribute.
	void set_username(std::string);
	// Takes string and assigns it to password_ attribute.
	void set_password(std::string);
	// Takes customer object and assigns it to customer_ attribute.
	void set_customer(customer);
	// Takes ticket object and adds it to a vector of ticket objects.
	void add_ticket(ticket ticket);
	// Takes string id, searches for it in a vector and removes it.
	void remove_ticket(std::string ticket_id);
	// Saves ticket record to db.
	void save_ticket_to_db(ticket);
	// Returns acct_id_ attribute.
	UniqueID get_acct_id();
	// Returns username_ attribute.
	std::string get_username() const;
	// Returns password_ attribute.
	std::string get_password() const;
	// Returns customer object.
	customer get_customer() const;
	// Returns reference of a customer object.
	customer* get_customer_reference();
	// Returns vector of ticket objects.
	std::vector<ticket> get_tickets();
	// Returns reference to a ticket from a vector that matches the ticket_id.
	ticket* get_ticket_by_id(std::string ticket_id);
};

