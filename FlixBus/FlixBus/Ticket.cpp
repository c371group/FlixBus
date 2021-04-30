#include "Ticket.h"
#include "DateTime.h"
#include "trip.h"
#include <string>

ticket::ticket()
{
	this->trip_ = nullptr;
}

ticket::ticket(route* route, Trip* trip)
{
	this->route_ = route;
	this->trip_ = trip;
}


//ticket::ticket()
//{
//	this->route_ = nullptr;
//	this->bus_ = nullptr;
//}
//
//ticket::ticket(route* route, luxuryBus* bus)
//{
//	this->route_ = route;
//	this->bus_ = bus;
//}
//
//ticket::ticket(route* route, miniBus* bus)
//{
//	this->route_ = route;
//	this->bus_ = bus;
//}
//
//ticket::ticket(route* route, miniVan* bus)
//{
//	this->route_ = route;
//	this->bus_ = bus;
//}

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

void ticket::set_trip(Trip* trip)
{
	this->trip_ = trip;
}

void ticket::set_ticket_id(std::string val)
{
	this->ticket_id_ = val;
}


void ticket::set_travel_date(DateTime date)
{
	this->travel_date = date;
}

void ticket::set_seat(int row, char column)
{
	std::pair<int, char> seat;
	seat.first = row;
	seat.second = column;
	this->seat_number_ = seat;
}

bool ticket::reserve_seat(int row, char column)
{
	double seatRate;
	if(this->trip_)
	{
		if (this->trip_->get_bus()->reserveSeat(row, column)) {
			seatRate = this->trip_->get_bus()->getSeatRate(row, column);
			this->set_cost(this->route_->get_distance() * seatRate);
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

bool ticket::cancel_seat()
{
	// Checks if the ticket is active. In other words if we have a confirmed reservation in a bus.
	if(this->active_)
	{
		return this->trip_->get_bus()->cancelSeat(this->seat_number_.first, this->seat_number_.second);
	}
	return false;
}

// Reserves a seat on a bus. If the seat is successfully reserved, reserveSeat() returns true, 
// Then we calculate the cost, based on the seat. Else we print message.
//void ticket::add_seat(int row, char column)
//{	
//	double seatRate;
//	if (this->bus_->reserveSeat(row, column)) {
//		seatRate = this->bus_->getSeatRate(row, column);
//		this->set_cost(this->route_->get_distance() * seatRate);
//		this->seat_number_ = std::to_string(row) + column;
//	}
//	else {
//		std::cout << "Seat can't be reserved. Try again!" << std::endl;
//	}
//}

//void ticket::set_bus(vehicle* bus)
//{
//	this->bus_ = bus;
//}

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

Trip* ticket::get_trip()
{
	return this->trip_;
}

std::string ticket::get_ticket_id()
{
	return this->ticket_id_;
}

//vehicle* ticket::get_bus()
//{
//	return this->bus_;
//}

DateTime ticket::get_travel_date()
{
	return this->travel_date;
}

std::string ticket::get_seat_number()
{
	return std::to_string(this->seat_number_.first) + this->seat_number_.second;
}
