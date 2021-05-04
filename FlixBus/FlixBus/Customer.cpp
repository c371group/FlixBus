#include "Customer.h"


// Base constructor.
customer::customer()
{
	this->f_name_ = "John";
	this->l_name_ = "Doughey";
	this->address_ = "123 Backhand Lane";
	this->email_ = "johndoughey@yahoo.com";
	this->contact_number_ = "920-345-3536";
}

// Constructor takes name, address, email and contact number.
customer::customer(std::string f_name, std::string l_name, std::string email, std::string address, std::string contact_number)
{
	this->f_name_ = f_name;
	this->l_name_ = l_name;
	this->email_ = email;
	this->address_ = address;
	this->contact_number_ = contact_number;
}

// Takes string and assigns it to f_name_ attribute.
void customer::set_first_name(std::string val) 
{ 
	this->f_name_ = val; 
}

// Takes string and assigns it to l_name_ attribute.
void customer::set_last_name(std::string val)
{
	this->l_name_ = val;
}

// Takes string and assigns it to address_ attribute.
void customer::set_address(std::string val)
{
	this->address_ = val;
}

// Takes string and assigns it to email_ attribute.
void customer::set_email(std::string val)
{
	this->email_ = val;
}

// Takes st ring and assigns it to contact_number_.
void customer::set_contact_number(std::string val)
{
	this->contact_number_ = val;
}

// Returns f_name_ attribute.
std::string customer::get_first_name() const 
{ 
	return this->f_name_;
}

// Returns l_name_ attribute.
std::string customer::get_last_name() const
{
	return this->l_name_;
}

// Returns address_ attribute.
std::string customer::get_address() const
{
	return this->address_;
}

// Returns email_ attribute.
std::string customer::get_email() const
{
	return this->email_;
}

// Returns contact_number_ attribute.
std::string customer::get_contact_number() const
{
	return this->contact_number_;
}