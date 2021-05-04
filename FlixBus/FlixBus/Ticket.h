#pragma once
#include <string>
#include "Route.h"
#include "DateTime.h"
#include "Trip.h"


/**
 * \brief ticket class holds information about the route, the trio and which seat was reserved.
 * It has functionality to reserve and cancel seats. Hold the cost of the ticket based on the seat.
 */
class ticket
{
private:
	// Unique ticket ID.
	std::string ticket_id_ = "DEFAULT";
	// Pair<int, char> represents seat number for a given vehicle.
	std::pair<int, char> seat_number_;
	// Boolean attribute, default value false.
	bool active_ = false;
	// Boolean attribute, default value false. Set to true if customer is hiring the bus.
	bool bus_hire_ = false;
	// Reference to a route object.
	route* route_;
	// Reference to a trip object.
	trip * trip_;
	// Ticket cost.
	double cost_ = 0;
	// Date of travel.
	date_time travel_date;

public:
	// Base constructor.
	ticket();
	// Constructor that takes references to a trip and route object. Assigns them to trip_ and route_.
	ticket(route*,trip*);
	// Takes boolean value and assigns it to active_ attribute.
	void set_active(bool);
	// Takes reference to a route object and assigns it to route_ attribute.
	void set_route(route*);
	// Takes double value and assigns it to cost_ attribute.
	void set_cost(double);
	// Takes reference to a trip object and assigns it to trip_ attribute.
	void set_trip(trip*);
	// Takes string value and assigns it to ticket_id attribute.
	void set_ticket_id(std::string);
	// Takes date time object and assigns it to travel_date attribute.
	void set_travel_date(date_time);
	// Takes int and char values, creates pair structure and assigns it to seat_ attribute.
	void set_seat(int row, char column);
	// Takes boolean value and assigns it to bus_hire attribute.
	void set_bus_hire(bool);
	// Takes int and char values, creates pair structure and reserves a seat on a given bus.
	bool reserve_seat(int row, char column);
	// Cancels a seat reservation on a given bus.
	bool cancel_seat() const;
	// Returns active_ attribute.
	bool get_active() const;
	// Returns bus_hire attribute.
	bool get_bus_hire_status() const;
	// Returns reference to a route object.
	route* get_route() const;
	// Returns ticket cost.
	double get_cost() const;
	// Returns reference to a trip object.
	trip* get_trip() const;
	// Returns ticket_id attribute.
	std::string get_ticket_id() const;
	// Returns travel date attribute.
	date_time get_travel_date() const;
	// Returns string representation of the seat number.
	std::string get_seat_number() const;
	// Returns seat_number_ attribute.
	std::pair<int, char> get_seat_pair() const;
};
