#include "Account.h"


// Base constructor.
account::account()
{
	uniqueID acctID; //TODO: this might give us difficulty once we do the permanent file storage, but don't worry about it for now
	set_acct_id(acctID);
	this->username_ = "Providence";
	this->password_ = "Provid3nce";
}

// Base constructor takes Customer object.
account::account(customer cust) //Testing purposes
{
	this->customer_ = cust;
}

// Base constructor takes Customer object, username and password.
account::account(customer cust, std::string username, std::string password)
{
	this->customer_ = cust;
	this->username_ = username;
	this->password_ = password;
}

// Takes uniqueID object and assigns it to acct_id.
void account::set_acct_id(uniqueID acctID)
{
	this->acct_id_= acctID;
}

// Takes string and assigns it to username_ attribute.
void account::set_username(std::string username)
{
	username_ = username;
}

// Takes string and assigns it to password_ attribute.
void account::set_password(std::string password)
{
	password_ = password;
}

// Takes customer object and assigns it to customer_ attribute.
void account::set_customer(customer cust)
{
	customer_ = cust;
}

// Returns acct_id_ attribute.
uniqueID account::get_acct_id()
{
	return this->acct_id_;
}

// Returns username_ attribute.
std::string account::get_username() const
{
	return this->username_;
}

// Returns password_ attribute.
std::string account::get_password() const
{
	return this->password_;
}

// Returns customer object.
customer account::get_customer() const
{
	return this->customer_;
}

// Returns reference of a customer object.
customer* account::get_customer_reference()
{
	return &this->customer_;
}

// Returns vector of ticket objects.
std::vector<ticket> account::get_tickets()
{
	return this->tickets_;
}

// Returns reference to a ticket from a vector that matches the ticket_id.
ticket* account::get_ticket_by_id(std::string ticket_id)
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

// Takes string id, searches for it in a vector and removes it.
void account::add_ticket(ticket ticket)
{
	tickets_.push_back(ticket);
}

// Takes string id, searches for it in a vector and removes it.
void account::remove_ticket(std::string ticket_id)
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