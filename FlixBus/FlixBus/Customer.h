#pragma once
#include <string>
#include <vector>
#include "Ticket.h"


/**
 * \brief  Customer container class.
 */
class customer
{
private:
	// f_name_, l_name_, address_, email_ attributes.
	std::string f_name_, l_name_, address_, email_;
	// contct_number of the customer.
	std::string contact_number_;
public:
	// Base constructor.
	customer();
	// Constructor that takes int id.
	customer(int person);
	// Constructor takes name, address, email and contact number.
	customer(std::string f_name, std::string l_name, std::string address, std::string email, std::string contact_number);
	// Takes string and assigns it to f_name_ attribute.
	void set_first_name(std::string f_nam);
	// Takes string and assigns it to l_name_ attribute.
	void set_last_name(std::string l_name);
	// Takes string and assigns it to address_ attribute.
	void set_address(std::string address);
	// Takes string and assigns it to email_ attribute.
	void set_email(std::string email);
	// Takes st ring and assigns it to contact_number_.
	void set_contact_number(std::string contact_number);
	// Returns f_name_ attribute.
	std::string get_first_name() const;
	// Returns l_name_ attribute.
	std::string get_last_name() const;
	// Returns address_ attribute.
	std::string get_address() const;
	// Returns email_ attribute.
	std::string get_email() const;
	// Returns contact_number_ attribute.
	std::string get_contact_number() const;
};