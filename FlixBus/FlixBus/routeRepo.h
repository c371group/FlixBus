#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include "Route.h"


/**
 * \brief Repository class, contains vector of route objects.
 */
class route_repo
{
private:
	// Vector of routes.
	std::vector<route> routes_;
public:
	// Base constructor.
	route_repo();
	// Returns vector of references of route objects.
	std::vector<route>* get_routes();
	// Takes route object and adds it to vector.
	void add_route(route rt);
	// Reads data from csv.
	void read_routes_db();
};