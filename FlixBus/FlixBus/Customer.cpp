#include "Customer.h"

Customer::Customer()
{
	this->f_name_ = "John";
	this->l_name_ = "Doughey";
	this->address_ = "123 Backhand Lane";
	this->email_ = "johndoughey@yahoo.com";
	this->contact_number_ = "920-345-3536";
}

//DELETE LATER, JUST FOR TESTING
Customer::Customer(int person)
{
	std::vector<std::string> fnames = { "Sam", "Abubakr", "Charlotte", "Tori", "Rhodri", "Kelsea" };
	std::vector<std::string> lnames = { "Parry", "Harper", "Thornton", "Mathews", "Davey", "Bonilla" };
	this->f_name_ = fnames[person];
	this->l_name_ = lnames[person];
	this->address_ = "123 Backhand Lane";
	this->email_ = "yolo@yahoo.com";
	this->contact_number_ = "920-345-3536";
}
Customer::Customer(std::string f_name, std::string l_name, std::string email, std::string address, std::string contact_number)
{
	this->f_name_ = f_name;
	this->l_name_ = l_name;
	this->email_ = email;
	this->address_ = address;
	this->contact_number_ = contact_number;
}


void Customer::setFirstName(std::string val) 
{ 
	this->f_name_ = val; 
}


void Customer::setLastName(std::string val)
{
	this->l_name_ = val;
}

void Customer::setAddress(std::string val)
{
	this->address_ = val;
}

void Customer::setEmail(std::string val)
{
	this->email_ = val;
}

void Customer::setContactNumber(std::string val)
{
	this->contact_number_ = val;
}

void Customer::setTicket(ticket* tckt)
{
	this->ticket_ = tckt;
}

std::string Customer::getFirstName() const 
{ 
	return this->f_name_;
}

std::string Customer::getLastName() const
{
	return this->l_name_;
}

std::string Customer::getAddress() const
{
	return this->address_;
}

std::string Customer::getEmail() const
{
	return this->email_;
}

std::string Customer::getContactNumber() const
{
	return this->contact_number_;
}

ticket* Customer::get_ticket()
{
	return this->ticket_;
}
