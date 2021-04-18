#include "Route.h"

route::route()
= default;

route::route(std::string source, std::string destination, int distance)
{
	this->source_ = source;
	this->destination_ = destination;
	this->distance_ = distance;
}

void route::set_source(std::string val)
{
	source_ = val;
}

void route::set_destination(std::string val)
{
	destination_ = val;
}

void route::set_distance(int val)
{
	distance_ = val;
}

std::string route::get_source()
{
	return source_;
}

std::string route::get_destination()
{
	return destination_;
}

int route::get_distance()
{
	return distance_;
}
