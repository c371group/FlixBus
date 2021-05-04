#include "Fleet.h"
#include <fstream>
#include <sstream>


// Base constructor.
fleet::fleet() {
	read_bus_details();
}

// Takes luxury bus object and adds it to a vector.
void fleet::add_luxury_bus(luxury_bus luxury)
{
	this->luxury_buses.push_back(luxury);
}

// Takes mini bus object and adds it to a vector.
void fleet::add_mini_bus(mini_bus small)
{
	this->mini_buses.push_back(small);
}

// Takes mini van object and adds it to a vector.
void fleet::add_mini_van(mini_van mini)
{
	this->mini_vans.push_back(mini);
}

// Returns a reference to a specific object in luxury bus vector, where the object has the same id as the one provided.
luxury_bus* fleet::get_luxury_bus(std::string id)
{
	int index = 0;
	for (auto item : this->luxury_buses) {
		if (item.get_id_no() == id) {
			// Returns address of the specific luxury bus object from the vector.
			return &this->luxury_buses.at(index);
		}
		index++;
	}
	return nullptr;
}

// Returns a reference to a specific object in mini bus vector, where the object has the same id as the one provided.
mini_bus* fleet::get_mini_bus(std::string id)
{
	int index = 0;
	for (auto item : this->mini_buses) {
		if (item.get_id_no() == id) {
			return &this->mini_buses.at(index);
		}
		index++;
	}
	return nullptr;
}

// Returns a reference to a specific object in mini van vector, where the object has the same id as the one provided.
mini_van* fleet::get_mini_van(std::string id)
{
	int index = 0;
	for (auto item : this->mini_vans) {
		if (item.get_id_no() == id) {
			return &this->mini_vans.at(index);
		}
		index++;
	}
	return nullptr;
}

// Returns a count of luxury buses in the vector.
size_t fleet::get_luxury_bus_count()
{
	return this->luxury_buses.size();
}

// Returns a count of mini buses in the vector.
size_t fleet::get_mini_bus_count()
{
	return this->mini_buses.size();
}

// Returns a count of mini vans in the vector.
size_t fleet::get_minivan_count()
{
	return this->mini_vans.size();
}

// Displays luxury buses that are in the vector.
void fleet::display_luxury_bus_fleet()
{
	// Checks if vector is not empty.
	if (!this->luxury_buses.empty())
	{
		std::cout << "Luxury buses:" << std::endl;
		int index = 0;
		for (auto& elem : this->luxury_buses)
		{
			index++;
			std::cout << index << ". " << elem.get_id_no() << " " << elem.get_type() << std::endl;
		}
	}
	else
	{
		std::cout << "Currently we have no Luxury buses in our fleet." << std::endl;
	}
}

// Displays mini buses that are in the vector.
void fleet::display_mini_bus_fleet()
{
	// Checks if vector is not empty.
	if (!this->mini_buses.empty())
	{
		std::cout << "Mini buses:" << std::endl;
		int index = 0;
		for (auto& elem : this->mini_buses)
		{
			index++;
			std::cout << index << ". " << elem.get_id_no() << " " << elem.get_type() << std::endl;
		}
	}
	else
	{
		std::cout << "Currently we have no Mini buses in our fleet." << std::endl;
	}
}

// Displays mini vans that are in the vector.
void fleet::display_mini_van_fleet()
{
	// Checks if vector is not empty.
	if (!this->mini_vans.empty())
	{
		std::cout << "Minivans:" << std::endl;
		int index = 0;
		for (auto& elem : this->mini_vans)
		{
			index++;
			std::cout << index << ". " << elem.get_id_no() << " " << elem.get_type() << std::endl;
		}
	}
	else
	{
		std::cout << "Currently we have no Minivans in our fleet." << std::endl;
	}
}

// Loads vehicle data from a csv file.
void fleet::read_bus_details() {
	//right now this does not read all of the registration details, as they might not be needed
	//thinking of having it read the list of bus drivers as well and making it a vector
	std::ifstream input_from_file("busdetails.csv");
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
			std::string idAsString = rowelements[0];
			// declaring character array
			char char_array[6];
			strcpy_s(char_array, idAsString.c_str());
			char letter1 = char_array[0];
			char letter2 = char_array[1];
			if (letter1 == 'L') {
				luxury_bus lbtemp = luxury_bus(rowelements[0]);
				add_luxury_bus(lbtemp);
			}
			if (letter1 == 'M') {
				if (letter2 == 'V') {
					mini_van mvtemp = mini_van(rowelements[0]);
					add_mini_van(mvtemp);
				}
				if (letter2 == 'B') {
					mini_bus mbtemp = mini_bus(rowelements[0]);
					add_mini_bus(mbtemp);
				}
			}
		}
	}
}