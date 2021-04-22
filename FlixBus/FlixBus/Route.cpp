#include "Route.h"

route::route()
= default;

route::route(std::string source, std::string destination)
{
	if ((source == "Green Bay" && destination == "Milwaukee") || (source == "Milwaukee" && destination == "Green Bay"))
	{
		this->distance_ = 118.7;
	}
	if ((source == "Green Bay" && destination == "Eau Claire") || (source == "Eau Claire" && destination == "Green Bay"))
	{
		this->distance_ = 194.4;
	}
	if ((source == "Green Bay" && destination == "Whitewater") || (source == "Whitewater" && destination == "Green Bay"))
	{
		this->distance_ = 142.2;
	}
	if ((source == "Green Bay" && destination == "Madison") || (source == "Madison" && destination == "Green Bay"))
	{
		this->distance_ = 135.6;
	}
	if ((source == "Green Bay" && destination == "Oshkosh") || (source == "Oshkosh" && destination == "Green Bay"))
	{
		this->distance_ = 50.4;
	}

	this->source_ = source;
	this->destination_ = destination;
	this->busFleet = busFleet;
}
route::route(std::string source, std::string destination, fleet * busFleet)
{
	//I feel like there's a better way to do this, I'm open to any suggestions
	if ((source == "Green Bay" && destination == "Milwaukee") || (source == "Milwaukee" && destination == "Green Bay"))
	{
		this->distance_ = 118.7;
	}
	if ((source == "Green Bay" && destination == "Eau Claire") || (source == "Eau Claire" && destination == "Green Bay"))
	{
		this->distance_ = 194.4;
	}
	if ((source == "Green Bay" && destination == "Whitewater") || (source == "Whitewater" && destination == "Green Bay"))
	{
		this->distance_ = 142.2;
	}
	if ((source == "Green Bay" && destination == "Madison") || (source == "Madison" && destination == "Green Bay"))
	{
		this->distance_ = 135.6;
	}
	if ((source == "Green Bay" && destination == "Oshkosh") || (source == "Oshkosh" && destination == "Green Bay"))
	{
		this->distance_ = 50.4;
	}

	this->source_ = source;
	this->destination_ = destination;
	this->busFleet = busFleet;
}
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
