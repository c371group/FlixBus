#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include "Route.h"

class routeRepo
{
private:
	std::vector<route> routes;
public:
	routeRepo();
	std::vector<route>* getRoutes();
	void add_route(route rt);
	void readRoutesDB();
};
