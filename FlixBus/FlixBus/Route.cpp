#include "Route.h"


// Basic constructor.
route::route()
{
	this->bus_fleet_ = nullptr;
	this->trip_repo_ = nullptr;
}

// Constructor takes source city and destination city.
route::route(std::string source, std::string destination)
{
	//I feel like there's a better way to do this, I'm open to any suggestions
	if ((source == "Green Bay" && destination == "Milwaukee") || (source == "Milwaukee" && destination == "Green Bay"))
	{
		this->distance_ = 118.7;
	}
	else if ((source == "Green Bay" && destination == "Eau Claire") || (source == "Eau Claire" && destination == "Green Bay"))
	{
		this->distance_ = 194.4;
	}
	else if ((source == "Green Bay" && destination == "Whitewater") || (source == "Whitewater" && destination == "Green Bay"))
	{
		this->distance_ = 142.2;
	}
	else if ((source == "Green Bay" && destination == "Madison") || (source == "Madison" && destination == "Green Bay"))
	{
		this->distance_ = 135.6;
	}
	else if ((source == "Green Bay" && destination == "Oshkosh") || (source == "Oshkosh" && destination == "Green Bay"))
	{
		this->distance_ = 50.4;
	}
	else {
		std::cout << "ERROR: Distance could not be calculated between inputted values " << source << " and " << destination;
		std::cout << ". Please check for any misspellings in the loaded CSV file." << std::endl;
		this->distance_ = 0;
	}
	
	this->source_ = source;
	this->destination_ = destination;
	this->bus_fleet_ = bus_fleet_;
}

// Constructor takes source city and destination city and distance.
route::route(std::string source, std::string destination, double distance)
{

	this->source_ = source;
	this->destination_ = destination;
	this->distance_ = distance;
	this->bus_fleet_ = nullptr;
}

// Constructor takes source city and destination city, distance and bus fleet.
route::route(std::string source, std::string destination, double distance, fleet * busFleet)
{
	this->source_ = source;
	this->destination_ = destination;
	this->distance_ = distance;
	this->bus_fleet_ = busFleet;
}

// Constructor takes source city and destination city, distance, bus fleet. and reference to a trip repo object.
route::route(std::string source, std::string destination, double distance, fleet* busFleet, trip_repo* trip_repo)
{
	this->source_ = source;
	this->destination_ = destination;
	this->distance_ = distance;
	this->bus_fleet_ = busFleet;
	this->trip_repo_ = trip_repo;
}

// Takes string and assigns it to source_ attribute.
void route::set_source(std::string val)
{
	this->source_ = val;
}

// Takes string and assigns it to destination_ attribute.
void route::set_destination(std::string val)
{
	this->destination_ = val;
}

// Takes string and assigns it to distance_ attribute.
void route::set_distance(int val)
{
	this->distance_ = val;
}

// Takes fleet and assigns it to distance_ bus_fleet_.
void route::set_fleet(fleet* bus_fleet)
{
	this->bus_fleet_ = bus_fleet;
}

void route::set_trip_repo(trip_repo* trip_repo)
{
	this->trip_repo_ = trip_repo;
}

// Returns source_ attribute.
std::string route::get_source()
{
	return this->source_;
}

// Returns destination_ attribute.
std::string route::get_destination()
{
	return this->destination_;
}

// Returns distance_ attribute.
double route::get_distance()
{
	return this->distance_;
}

// Returns reference to a fleet object.
fleet* route::get_fleet()
{
	return this->bus_fleet_;
}

// Returns reference to a trip_repo object.
trip_repo* route::get_trip_repo()
{
	return this->trip_repo_;
}
