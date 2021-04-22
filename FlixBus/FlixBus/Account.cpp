#include "Account.h"

Account::Account()
{
	uniqueID acctID; //TODO: this might give us difficulty once we do the permanent file storage, but don't worry about it for now
	set_acct_id(acctID);
	this->username_ = "Providence";
	this->password_ = "Provid3nce";
}

Account::Account(Customer cust) //Testing purposes
{;
	this->customer = cust;
}

Account::Account(Customer cust, int person) //Testing purposes, DELETE LATER
{
	std::vector<std::string> usernames = { "Sam1", "Abubakr2", "Charlotte3", "Tori4", "Rhodri5", "Kelsea6" };
	std::vector<std::string> passwords = { "Parry1", "Harper2", "Thornton3", "Mathews4", "Davey5", "Bonilla6" };
	this->customer = cust;
	this->username_ = usernames[person];
	this->password_ = passwords[person];
}

Account::Account(Customer cust, std::string username, std::string password)
{
	this->customer = cust;
	this->username_ = username;
	this->password_ = password;
}


void Account::set_acct_id(uniqueID acctID)
{
	this->acctID= acctID;
}

void Account::set_username(std::string username)
{
	username_ = username;
}

void Account::set_password(std::string password)
{
	password_ = password;
}

void Account::set_customer(Customer cust)
{
	customer = cust;
}

uniqueID Account::get_acct_id()
{
	return acctID;
}

std::string Account::get_username() const
{
	return username_;
}

std::string Account::get_password() const
{
	return password_;
}

Customer Account::get_customer() const
{
	return customer;
}

std::vector<ticket> Account::getTickets()
{
	return tickets_;
}

void Account::addTicket(ticket ticket)
{
	tickets_.push_back(ticket);
}

void Account::removeTicket(int ticket_id)
{
	//TODO: come back to this
}



