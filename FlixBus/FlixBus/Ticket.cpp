#include "Ticket.h"
#include "DateTime.h"
#include <string>


ticket::ticket()
{
	this->route_ = nullptr;
	this->bus_ = nullptr;
}

ticket::ticket(route* route, luxuryBus* bus)
{
	this->route_ = route;
	this->bus_ = bus;
}

ticket::ticket(route* route, miniBus* bus)
{
	this->route_ = route;
	this->bus_ = bus;
}

ticket::ticket(route* route, miniVan* bus)
{
	this->route_ = route;
	this->bus_ = bus;
}

void ticket::set_active(bool val)
{
	this->active_ = val;
}

void ticket::set_route(route* val)
{
	this->route_ = val;
}

void ticket::set_cost(double val)
{
	this->cost_ = val;
}

void ticket::set_ticket_id(std::string val)
{
	this->ticket_id_ = val;
}


void ticket::set_travel_date(DateTime date)
{
	this->travel_date = date;
}

// Reserves a seat on a bus. If the seat is successfully reserved, reserveSeat() returns true, 
// Then we calculate the cost, based on the seat. Else we print message.
void ticket::add_seat(int row, char column)
{	
	double seatRate;
	if (this->bus_->reserveSeat(row, column)) {
		seatRate = this->bus_->getSeatRate(row, column);
		this->set_cost(this->route_->get_distance() * seatRate);
		this->seat_number_ = std::to_string(row) + column;
	}
	else {
		std::cout << "Seat can't be reserved. Try again!" << std::endl;
	}
}

void ticket::set_bus(vehicle* bus)
{
	this->bus_ = bus;
}

bool ticket::get_active()
{
	return this->active_;
}

route* ticket::get_route()
{
	return this->route_;
}

double ticket::get_cost()
{
	return this->cost_;
}

std::string ticket::get_ticket_id()
{
	return this->ticket_id_;
}

vehicle* ticket::get_bus()
{
	return this->bus_;
}

DateTime ticket::get_travel_date()
{
	return this->travel_date;
}

std::string ticket::get_seat_number()
{
	return this->seat_number_;
}
