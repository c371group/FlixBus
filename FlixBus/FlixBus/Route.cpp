#include "Route.h"

route::route()
= default;

route::route(std::string source, std::string destination, double distance, fleet * busFleet)
{
	this->source_ = source;
	this->destination_ = destination;
	this->distance_ = distance;
	this->busFleet = busFleet;
}


void route::set_source(std::string val)
{
	this->source_ = val;
}

void route::set_destination(std::string val)
{
	this->destination_ = val;
}

void route::set_distance(int val)
{
	this->distance_ = val;
}

void route::set_fleet(fleet* busFleet)
{
	this->busFleet = busFleet;
}

std::string route::get_source()
{
	return this->source_;
}

std::string route::get_destination()
{
	return this->destination_;
}

double route::get_distance()
{
	return this->distance_;
}

fleet* route::get_fleet()
{
	return this->busFleet;
}
