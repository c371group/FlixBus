#include "tripRepo.h"
#include <fstream>
#include <sstream>

#include "Trip.h"


// Base trip_repo constructor.
trip_repo::trip_repo()
= default;

trip_repo::trip_repo(std::string source, std::string destination)
{
	this->read_trips_db(source, destination);
}

// Returns the memory address of trips_ attribute.
std::vector<trip>* trip_repo::get_all_trips()
{
	return &this->trips_;
}

// Takes Trip object and adds it to trips_ attribute (vector of Trips).
void trip_repo::add_trip(trip tp)
{
	trips_.push_back(tp);
}

// Splits string with a given delimiter and returns a vector of string elements;
std::vector<std::string> split_date_string(const std::string& s, char delim) {
	std::vector<std::string> result;
	std::stringstream ss(s);
	std::string item;

	while (getline(ss, item, delim)) {
		result.push_back(item);
	}

	return result;
}

// Reads data from csv.
void trip_repo::read_trips_db(std::string source, std::string destination) {
	//right now this does not read all of the registration details, as they might not be needed
	//thinking of having it read the list of bus drivers as well and making it a vector
	std::ifstream input_from_file("Trips502508.csv");
	std::string line;
	int lineno = 0;
	std::cout << "Loading trip data from file...." << std::endl;
	while (std::getline(input_from_file, line)) {
		lineno++;
		line += ",";

		std::stringstream ss(line);

		std::string part;
		std::vector<std::string> rowelements;

		while (getline(ss, part, ','))
			rowelements.push_back(part);
		if (lineno != 1) {
			std::string departs = rowelements[0];

			int dep_year = std::stoi(split_date_string(rowelements[1], '/')[2]);
			int dep_month = std::stoi(split_date_string(rowelements[1], '/')[0]);
			int dep_day = std::stoi(split_date_string(rowelements[1], '/')[1]);
			int dep_hour = std::stoi(split_date_string(rowelements[7], ':')[0]);
			int dep_min = std::stoi(split_date_string(rowelements[7], ':')[1]);
			int dep_sec = std::stoi(split_date_string(rowelements[7], ':')[2]);
			
			int arr_year = std::stoi(split_date_string(rowelements[1], '/')[2]);
			int arr_month = std::stoi(split_date_string(rowelements[1], '/')[0]);
			int arr_day = std::stoi(split_date_string(rowelements[1], '/')[1]);
			int arr_hour = std::stoi(split_date_string(rowelements[8], ':')[0]);
			int arr_min = std::stoi(split_date_string(rowelements[8], ':')[1]);
			int arr_sec = std::stoi(split_date_string(rowelements[8], ':')[2]);
			date_time departure(dep_year, dep_month, dep_day, dep_hour, dep_min, dep_sec);
			date_time arrival(arr_year, arr_month, arr_day, arr_hour, arr_min, arr_sec);
			trip temp = trip();
			temp.set_departure_dt(departure);
			temp.set_est_arrival_dt(arrival);
			temp.set_bus_id(rowelements[4]);
			temp.set_source(rowelements[5]);
			temp.set_destination(rowelements[6]);
			if(rowelements[5] == source && rowelements[6]== destination)
			{
				this->add_trip(temp);
			}
		}
	}
}