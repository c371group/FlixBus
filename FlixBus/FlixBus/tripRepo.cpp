#include "tripRepo.h"
#include "trip.h"

tripRepo::tripRepo()
= default;

std::vector<Trip*> tripRepo::getAllTrips()
{
	return this->trips;
}

std::vector<Trip*> tripRepo::getBookableTrips(DateTime currentTime)
{
	//TODO: modify and make this work
	return this->trips;
}

void tripRepo::add_trip(Trip* tp)
{
	trips.push_back(tp);
}
