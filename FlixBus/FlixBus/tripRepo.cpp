#include "tripRepo.h"
#include "Trip.h"


// Base trip_repo constructor.
trip_repo::trip_repo()
= default;

// Returns the memory address of trips_ attribute.
std::vector<trip>* trip_repo::get_all_trips()
{
	return &this->trips_;
}

// Takes Trip object and adds it to trips_ attribute (vector of Trips).
void trip_repo::add_trip(trip tp)
{
	trips_.push_back(tp);
}
