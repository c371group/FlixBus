//implementation file
#include "Ticket.h"
#include "Route.h"

ticket::ticket()
{
	route_ = route();
	bus_ = nullptr;
	cost_ = route_.get_distance() * bus_->get_rate_per_mile();
	//TODO add actual methods for travel date later on, with trip class
}

ticket::ticket(route val1, vehicle* val2)
{
	route_ = val1;
	bus_ = val2;
	cost_ = val1.get_distance() * val2->get_rate_per_mile(); 
	/*storing as is to make math easier,
	there's no payment requirement so all we have to really do is display in "regular" numbers for customer
	by dividing and setting precision. */
}

void ticket::set_active(bool val)
{
	active_ = val;
}

void ticket::set_route(route val)
{
	route_ = val;
	cost_ = route_.get_distance() * bus_->get_rate_per_mile();
}

void ticket::set_cost(int val)
{
	cost_ = val;
}

void ticket::set_ticket_id(std::string val)
{
	ticket_id_ = val;
}

void ticket::set_bus(vehicle* val)
{
	bus_ = val;
}

void ticket::set_travel_date(std::string val)
{
	travel_date_ = val;
}

void ticket::add_seat(int row, char column)
{
	std::pair<int, char> seat{ row, column };
	this->seats.push_back(seat);
}

bool ticket::get_active()
{
	return active_;
}

route ticket::get_route()
{
	return route_;
}

int ticket::get_cost()
{
	return cost_;
}

std::string ticket::get_ticket_id()
{
	return ticket_id_;
}

vehicle* ticket::get_bus()
{
	return bus_;
}

std::string ticket::get_travel_date()
{
	return travel_date_;
}
