#include "Customer.h"

Customer::Customer()
{
	this->f_name_ = "John";
	this->l_name_ = "Doughey";
	this->address_ = "123 Backhand Lane";
	this->email_ = "johndoughey@yahoo.com";
	this->contact_number_ = "920-345-3536";
}
Customer::Customer(string f_name, string l_name, string address, string email, string contact_number)
{
	this->f_name_ = f_name;
	this->l_name_ = l_name;
	this->address_ = address;
	this->email_ = email;
	this->contact_number_ = contact_number;
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
