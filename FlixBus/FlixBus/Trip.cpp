#include "Trip.h"

Trip::Trip()
{
	this->bookable = true;
	this->bus_ = nullptr;
}

Trip::Trip(DateTime leave, DateTime arrive, vehicle* fleet)
{
	//set_route_(rt);
	//this->route_ = route;
	this->bookable = true;
	this->departure = leave;
	this->estimatedArrival = arrive;
	this->bus_ = fleet;
	set_Bookable(false);
}

void Trip::set_Bookable(bool bookable)
{
	this->bookable = bookable;
}

//void Trip::set_route_(route* route_)
//{
//	this->route_ = route_;
//}

void Trip::set_departureDT(DateTime dt)
{
	this->departure = dt;
}

void Trip::set_estArrivalDT(DateTime dt)
{
	this->estimatedArrival = dt;
}

void Trip::set_bus(vehicle* bus)
{
	this->bus_ = bus;
}

//void Trip::set_fleet(fleet* busFleet) //not sure if we need the pointer for this or not here, as a singular trip would only use one bus
//{
//	this->busFleet = busFleet;
//}

void Trip::set_busType(std::string type)
{
	this->busType = type;
}

bool Trip::getBookable()
{
	return this->bookable;
}

vehicle* Trip::get_bus()
{
	return this->bus_;
}

//route* Trip::getRoute()
//{
//	return this->route_;
//}

DateTime Trip::getDepartureDT()
{
	return this->departure;
}

DateTime Trip::getEstArrivalDT()
{
	return this->estimatedArrival;
}
//fleet* Trip::get_fleet()
//{
//	return this->busFleet;
//}

std::string Trip::get_type()
{
	return this->busType;
}
