#include "routeRepo.h"
#include <fstream>
#include <sstream>


// Base constructor.
route_repo::route_repo()
{
	// TODO: routes lack fleet and trip reference.
	this->read_routes_db();
}

// Returns vector of references of route objects.
std::vector<route>* route_repo::get_routes()
{
	return &this->routes_;
}

// Takes route object and adds it to vector.
void route_repo::add_route(route rt)
{
	routes_.push_back(rt);
}

// Reads data from csv.
void route_repo::read_routes_db() {
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