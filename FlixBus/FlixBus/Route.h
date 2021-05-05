#pragma once
#include <string>
#include "Fleet.h"
#include "tripRepo.h"


/**
 * \brief route object represents route between two cities.
 * Have reference of fleet and reference of trip_repo.
 */
class route
{
private:
	// Source city.
	std::string source_;
	// Destination city.
	std::string destination_;
	// Distance between source and distance.
	double distance_;
	// Reference to a fleet object.
	fleet* bus_fleet_;
	// Reference to a trip repo object
	trip_repo* trip_repo_;

public:
	// Basic constructor.
	route();
	// Constructor takes source city and destination city.
	route(std::string source, std::string destination);
	// Constructor takes source city and destination city and distance.
	route(std::string source, std::string destination, double distance);
	// Constructor takes source city and destination city, distance and bus fleet.
	route(std::string source, std::string destination, double distance, fleet* busFleet);
	// Constructor takes source city and destination city, distance, bus fleet. and reference to a trip repo object.
	route(std::string source, std::string destination, double distance, fleet* busFleet, trip_repo* trip_repo);
	// Takes string and assigns it to source_ attribute.
	void set_source(std::string);
	// Takes string and assigns it to destination_ attribute.
	void set_destination(std::string);
	// Takes string and assigns it to distance_ attribute.
	void set_distance(int);
	// Takes fleet and assigns it to distance_ bus_fleet_.
	void set_fleet(fleet*);
	// Takes trip repo and assigns it to trip_repo_ attribute.
	void set_trip_repo(trip_repo*);
	// Returns source_ attribute.
	std::string get_source();
	// Returns destination_ attribute.
	std::string get_destination();
	// Returns distance_ attribute.
	double get_distance();
	// Returns reference to a fleet object.
	fleet* get_fleet();
	// Returns reference to a trip_repo object.
	trip_repo* get_trip_repo();
};