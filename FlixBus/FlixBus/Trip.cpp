#include "Trip.h"


// Default constructor. Sets bookable to true and bus_ to nullptr.
trip::trip()
{
	this->bookable_ = true;
	this->bus_ = nullptr;
}

// Constructor that takes two date time objects and assigns them for departure and arrival attributes.
// Also takes vehicle reference and assigns it to bus_ attribute.
trip::trip(date_time leave, date_time arrive, vehicle* fleet)
{
	this->bookable_ = true;
	this->departure_ = leave;
	this->estimated_arrival_ = arrive;
	this->bus_ = fleet;
	set_bookable(false);
}

// Sets bookable_ to be equal to a given boolean value.
void trip::set_bookable(bool bookable)
{
	this->bookable_ = bookable;
}

// Takes date time objects and assigns it to departure attribute.
void trip::set_departure_dt(date_time dt)
{
	this->departure_ = dt;
}

// Takes date time object and assigns it to arrival attribute.
void trip::set_est_arrival_dt(date_time dt)
{
	this->estimated_arrival_ = dt;
}

// Takes reference to a vehicle object and assigns it to bus_ attribute.
void trip::set_bus(vehicle* bus)
{
	this->bus_ = bus;
}

// Takes string and assigns it to source_ attribute.
void trip::set_source(std::string source)
{
	this->source_ = source;
}

// Takes string and assigns it to destination_ attribute.
void trip::set_destination(std::string dest)
{
	this->destination_ = dest;
}

// Returns boolean value of bookable_ attribute.
bool trip::get_bookable()
{
	return this->bookable_;
}

// Takes strings and assigns it to bus_id_ attribute
void trip::set_bus_id(std::string id)
{
	this->bus_id_ = id;
}

// Returns reference to a vehicle object.
vehicle* trip::get_bus()
{
	return this->bus_;
}

// Returns departure_ attribute.
date_time trip::get_departure_dt()
{
	return this->departure_;
}

// Returns arrival_ attribute.
date_time trip::get_est_arrival_dt()
{
	return this->estimated_arrival_;
}

// Returns bus_id attribute
std::string trip::get_bus_id()
{
	return this->bus_id_;
}

// Returns source_ attribute.
std::string trip::get_source()
{
	return this->source_;
}

// Returns destination_ attribute.
std::string trip::get_destination()
{
	return this->destination_;
}