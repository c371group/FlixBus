#pragma once
#include <string>


class route {
private:
	int routeID_ = 137; // an identifier Nate can use to reference the route in scheduling
	std::string source_ = "Green Bay"; //default parameters
	std::string destination_ = "Green Bay"; // This should be loaded from a file.
	int distance_ = 0; //To tenth of a mile-- ex. 195.2 miles would be stored as 1952, then divided later
public:
	route();
	route(std::string source, std::string destination, int distance);
	void set_source(std::string);
	void set_destination(std::string);
	void set_distance(int);

	std::string get_source();
	std::string get_destination();
	int get_distance();
};
