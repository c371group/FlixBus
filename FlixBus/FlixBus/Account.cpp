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
	return this->acctID;
}

std::string Account::get_username() const
{
	return this->username_;
}

std::string Account::get_password() const
{
	return this->password_;
}

Customer Account::get_customer() const
{
	return this->customer;
}

Customer* Account::get_customer_reference()
{
	return &this->customer;
}

std::vector<ticket> Account::getTickets()
{
	return this->tickets_;
}

ticket* Account::get_ticket_by_id(std::string ticket_id)
{
	int index = 0;
	for (auto& item : this->tickets_)
	{
		if (item.get_ticket_id() == ticket_id)
		{
			break;
		}
		index++;
	}
	return &this->tickets_.at(index);
}

void Account::addTicket(ticket ticket)
{
	tickets_.push_back(ticket);
}

void Account::removeTicket(std::string ticket_id)
{
	int index = 0;
	for(auto &item: this->tickets_)
	{
		if(item.get_ticket_id() == ticket_id)
		{
			break;
		}
		index++;
	}
	this->tickets_.erase(this->tickets_.begin() + index);
}
