#include "Trip.h"

Trip::Trip() = default;

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
	return this->bookable;
}

route Trip::getRoute()
{
	return this->route_;
}

DateTime Trip::getDepartureDT()
{
	return this->departure;
}

DateTime Trip::getEstArrivalDT()
{
	return this->estimatedArrival;
}
fleet* Trip::get_fleet()
{
	return this->busFleet;
}
