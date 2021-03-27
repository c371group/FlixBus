//implementation file
#include "Customer.h"

Customer::Customer(string user_id, string f_name, string l_name, string address, string email, string contact_number)
{
	this->user_id_ = user_id;
	this->f_name_ = f_name;
	this->l_name_ = l_name;
	this->address_ = address;
	this->email_ = email;
	this->contact_number_ = contact_number;
}

void Customer::setUserID(string val)
{
	user_id_ = val;
}

void Customer::setFirstName(std::string f_nam) { f_name_ = f_nam; }

void Customer::setLastName(std::string val)
{
	l_name_ = val;
}

void Customer::setAddress(std::string val)
{
	address_ = val;
}

void Customer::setEmail(std::string val)
{
	email_ = val;
}

void Customer::setContactNumber(std::string val)
{
	contact_number_ = val;
}

void Customer::addTicket(ticket ticket)
{
	tickets_.push_back(ticket);
}

void Customer::removeTicket(int ticket_id)
{
	//TODO: come back to this
}

std::string Customer::getFirstName() const { return f_name_; }

std::string Customer::getLastName() const
{
	return l_name_;
}

std::string Customer::getAddress() const
{
	return address_;
}

std::string Customer::getEmail() const
{
	return email_;
}

std::string Customer::getContactNumber() const
{
	return contact_number_;
}

vector<ticket> Customer::getTickets() {
	return vector<ticket>();
}