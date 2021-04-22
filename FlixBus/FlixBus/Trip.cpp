#include "Trip.h"

Trip::Trip()
{
}

Trip::Trip(route rt)
{
	set_route_(rt);
	set_Bookable(false);
}

void Trip::set_Bookable(bool bookable)
{
	this->bookable = bookable;
}

void Trip::set_route_(route route_)
{
	this->route_ = route_;
}

void Trip::set_departureDT(DateTime dt)
{
	this->departure = dt;
}

void Trip::set_estArrivalDT(DateTime dt)
{
	this->estimatedArrival = dt;
}

void Trip::set_fleet(fleet* busFleet)
{
	this->busFleet = busFleet;
}

bool Trip::getBookable()
{
	return bookable;
}

route Trip::getRoute()
{
	return route_;
}

DateTime Trip::getDepartureDT()
{
	return departure;
}

DateTime Trip::getEstArrivalDT()
{
	return estimatedArrival;
}
fleet* Trip::get_fleet()
{
	return this->busFleet;
}
