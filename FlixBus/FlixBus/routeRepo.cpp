#include "routeRepo.h"

routeRepo::routeRepo()
{
	//readRoutesDB();
}

std::vector<route>* routeRepo::getRoutes()
{
	return &this->routes;
}

void routeRepo::add_route(route rt)
{
	routes.push_back(rt);
}

void routeRepo::readRoutesDB() {
	//right now this does not read all of the registration details, as they might not be needed
	//thinking of having it read the list of bus drivers as well and making it a vector
	std::ifstream input_from_file("RoutesDB.csv");
	std::string line;
	int lineno = 0;

	while (std::getline(input_from_file, line)) {
		lineno++;
		line += ",";

		std::stringstream ss(line);

		std::string part;
		std::vector<std::string> rowelements;

		while (getline(ss, part, ','))
			rowelements.push_back(part);
		if (lineno != 1) {
			//right now I'm not putting the distance from file storage until we have to, as it's a double, not a string
			std::string departs = rowelements[0];
			std::string destination = rowelements[1];
			route temp = route(departs, destination);
			add_route(temp);
		}
	}
}