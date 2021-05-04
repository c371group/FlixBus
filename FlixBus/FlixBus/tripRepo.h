#pragma once
#include <vector>
#include "Trip.h"


/**
 * \brief Repository class that contains vector of Trips classes.
 */
class trip_repo
{
private:
	// Vector of Trip objects.
	std::vector<trip> trips_;
public:
	// Base constructor.
	trip_repo();
	// Returns a reference to trips_ attribute.
	std::vector<trip>* get_all_trips();
	// Takes Trip object and adds it to trips_ attribute (vector of Trips).
	void add_trip(trip);
};