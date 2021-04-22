#pragma once
#include <vector>
#include "Route.h"

class routeRepo
{
private:
	std::vector<route> routes;
public:
	routeRepo();
	std::vector<route> getRoutes();
	void add_route(route rt);
};
