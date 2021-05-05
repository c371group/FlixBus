#include "Ticket.h"
#include "DateTime.h"
#include "Trip.h"
#include <string>


// Base constructor.
ticket::ticket()
{
	this->trip_ = nullptr;
}

// Constructor that takes references to a trip and route object. Assigns them to trip_ and route_.
ticket::ticket(route* route, trip* trip)
{
	this->route_ = route;
	this->trip_ = trip;
}

// Takes boolean value and assigns it to active_ attribute.
void ticket::set_active(bool val)
{
	this->active_ = val;
}

// Takes reference to a route object and assigns it to route_ attribute.
void ticket::set_route(route* val)
{
	this->route_ = val;
}

// Takes double value and assigns it to cost_ attribute.
void ticket::set_cost(double val)
{
	this->cost_ = val;
}

// Takes reference to a trip object and assigns it to trip_ attribute.
void ticket::set_trip(trip* trip)
{
	this->trip_ = trip;
}

// Takes string value and assigns it to ticket_id attribute.
void ticket::set_ticket_id(std::string val)
{
	this->ticket_id_ = val;
}

// Takes date time object and assigns it to travel_date attribute.
void ticket::set_travel_date(date_time date)
{
	this->travel_date = date;
}

// Takes int and char values, creates pair structure and assigns it to seat_ attribute.
void ticket::set_seat(int row, char column)
{
	std::pair<int, char> seat;
	seat.first = row;
	seat.second = column;
	this->seat_number_ = seat;
}

// Takes boolean value and assigns it to bus_hire attribute.
void ticket::set_bus_hire(bool hire)
{
	this->bus_hire_ = hire;
}

// Takes int and char values, creates pair structure and reserves a seat on a given bus.
bool ticket::reserve_seat(int row, char column)
{
	// Checks if trip_ is not a nullptr
	if(this->trip_)
	{
		// Tries to reserve a seat on a given vehicle. Returns true or false.
		if (this->trip_->get_bus()->reserve_seat(row, column)) {
			const double seat_rate = this->trip_->get_bus()->get_seat_rate(row, column);
			this->set_cost(this->route_->get_distance() * seat_rate);
			this->set_seat(row, column);
			this->active_ = true;
			return true;
		}
		else {
			std::cout << "Seat can't be reserved. Try again!" << std::endl;
			return false;
		}
	}
	return false;
}

// Cancels a seat reservation on a given bus.
bool ticket::cancel_seat() const
{
	// Checks if the ticket is active. In other words if we have a confirmed reservation in a bus.
	if(this->active_)
	{
		return this->trip_->get_bus()->cancel_seat(this->seat_number_.first, this->seat_number_.second);
	}
	return false;
}

// Returns active_ attribute.
bool ticket::get_active() const
{
	return this->active_;
}

// Returns bus_hire attribute.
bool ticket::get_bus_hire_status() const
{
	return this->bus_hire_;
}

// Returns reference to a route object.
route* ticket::get_route() const
{
	return this->route_;
}

// Returns ticket cost.
double ticket::get_cost() const
{
	return this->cost_;
}

// Returns reference to a trip object.
trip* ticket::get_trip() const
{
	return this->trip_;
}

// Returns ticket_id attribute.
std::string ticket::get_ticket_id() const
{
	return this->ticket_id_;
}

// Returns travel date attribute.
date_time ticket::get_travel_date() const
{
	return this->travel_date;
}

// Returns string representation of the seat number.
std::string ticket::get_seat_number() const
{
	return std::to_string(this->seat_number_.first) + this->seat_number_.second;
}

// Returns seat_number_ attribute.
std::pair<int, char> ticket::get_seat_pair() const
{
	return this->seat_number_;
}