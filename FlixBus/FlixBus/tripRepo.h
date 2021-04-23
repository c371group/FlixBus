#pragma once
#include <vector>
#include "Trip.h"
#include "routeRepo.h"

class tripRepo
{
private:
	std::vector<Trip> trips;
public:
	tripRepo();
	std::vector<Trip> getAllTrips();
	std::vector<Trip> getBookableTrips(DateTime); //returns all Trips that are able to be booked at the time specified by the DateTime parameter passed (ideally current time at time of calling)-- ie, within two weeks of the parameter
	void add_trip(Trip);
};