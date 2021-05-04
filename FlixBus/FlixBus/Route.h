#pragma once
#include <string>
#include "Fleet.h"
#include "tripRepo.h"


class route
{
private:
	std::string source_;
	std::string destination_;
	double distance_;
	fleet* busFleet;
	trip_repo* trip_repo_;

public:
	route();
	route(std::string source, std::string destination); //For testing
	route(std::string source, std::string destination, fleet* busFleet);
	route(std::string source, std::string destination, double distance, fleet* busFleet);
	route(std::string source, std::string destination, double distance, fleet* busFleet, trip_repo* trip_repo);
	void set_source(std::string);
	void set_destination(std::string);
	void set_distance(int);
	void set_fleet(fleet*);

	std::string get_source();
	std::string get_destination();
	double get_distance();
	fleet* get_fleet();
	trip_repo* get_trip_repo();

};
