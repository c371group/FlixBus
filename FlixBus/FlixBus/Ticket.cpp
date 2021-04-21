#include "Ticket.h"
#include "DateTime.h"

ticket::ticket()
{
	this->route_ = nullptr;
	this->bus_ = nullptr;
	this->cost_ = 0; //route_.get_distance() * bus_->get_rate_per_mile();
	//TODO add actual methods for travel date later on, with trip class
}

ticket::ticket(route* val1, luxuryBus* val2)
{
	this->route_ = val1;
	this->bus_ = val2;
}

void ticket::set_active(bool val)
{
	this->active_ = val;
}

void ticket::set_route(route* val)
{
	this->route_ = val;
	this->cost_ = 0; //route_.get_distance() * bus_->get_rate_per_mile();
}

void ticket::set_cost(double val)
{
	this->cost_ = val;
}

void ticket::set_ticket_id(std::string val)
{
	this->ticket_id_ = val;
}

/*void ticket::set_bus(vehicle* val)
{
	this->bus_ = val;
}*/

void ticket::set_travel_date(DateTime date)
{
	this->travel_date = date;
}

// Reserves a seat on a bus. If the seat is successfully reserved, reserveSeat() returns true, 
// Then we calculate the cost, based on the seat. Else we print messege.
void ticket::add_seat(int row, char column)
{	
	double seatRate;
	if (this->bus_->reserveSeat(row, column)) {
		seatRate = this->bus_->getSeatRate(row, column);
		this->set_cost(this->route_->get_distance() * seatRate);
	}
	else {
		std::cout << "Seat can't be reserved. Try again!" << std::endl;
	}
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
