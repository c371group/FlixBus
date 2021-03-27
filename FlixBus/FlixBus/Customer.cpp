//implementation file
#include "Customer.h"

Customer::Customer(string userID, string fName, string lName, string address, string email, int contactNumber)
{
	this->userID = userID;
	this->fName = fName;
	this->lName = lName;
	this->address = address;
	this->email = email;
	this->contactNumber = contactNumber;

}

void Customer::setUserID(string userID)
{
}


void Customer::setFirstName(std::string val) { fName = val; }

void Customer::setLastName(string lName)
{
}

void Customer::setAddress(string address)
{
}

void Customer::setEmail(string email)
{
}

void Customer::setContactNumber(int contactNumber)
{
}

void Customer::addTicket(Ticket ticket)
{
}

void Customer::removeTicket(int ticketId)
{
}

std::string Customer::getFirstName() const { return fName; }

std::string Customer::getLastName() const
{
}

std::string Customer::getAddress() const
{
	return string();
}

std::string Customer::getEmail() const
{
	return string();
}

int Customer::getContactNumber() const
{
	return 0;
}

vector<Ticket> Customer::getTickets() const
{
	return vector<Ticket>();
}