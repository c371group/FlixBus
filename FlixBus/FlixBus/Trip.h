#pragma once
#include "Vehicle.h"
#include "DateTime.h"


/**
 * \brief trip class  contains data for individuals trips between two destinations.
 * It contains information about the bus that was hired.
 */
class trip
{
private:
	// Boolean attribute that indicates if the ticket is bookable.
	bool bookable_;
	// Reference to a vehicle object.
	vehicle* bus_;
	// DateTime object representing the departure time.
	date_time departure_;
	// DateTime object representing arrival time.
	date_time estimated_arrival_;
public:
	// Base constructor.
	trip();
	// Constructor that takes two date time objects and assigns them for departure and arrival attributes.
	// Also takes vehicle reference and assigns it to bus_ attribute.
	trip(date_time, date_time, vehicle*);
	// Sets bookable_ to be equal to a given boolean value.
	void set_bookable(bool);
	// Takes date time objects and assigns it to departure attribute.
	void set_departure_dt(date_time);
	// Takes date time object and assigns it to arrival attribute.
	void set_est_arrival_dt(date_time);
	// Takes reference to a vehicle object and assigns it to bus_ attribute.
	void set_bus(vehicle*);
	// Returns boolean value of bookable_ attribute.
	bool get_bookable();
	// Returns reference to a vehicle object.
	vehicle* get_bus();
	// Returns departure_ attribute.
	date_time get_departure_dt();
	// Returns arrival_ attribute.
	date_time get_est_arrival_dt();
};