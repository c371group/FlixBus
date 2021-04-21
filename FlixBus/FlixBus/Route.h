#pragma once
#include <string>
#include "Fleet.h"


class route
{
private:
	std::string source_;
	std::string destination_;
	double distance_ = 0;
	fleet* busFleet = nullptr;
public:
	route();
	route(std::string source, std::string destination, double distance, fleet* busFleet);
	void set_source(std::string);
	void set_destination(std::string);
	void set_distance(int);
	void set_fleet(fleet*);

	std::string get_source();
	std::string get_destination();
	double get_distance();
	fleet* get_fleet();
};
