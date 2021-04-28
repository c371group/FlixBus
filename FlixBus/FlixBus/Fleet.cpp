#include "Fleet.h"

fleet::fleet() {
	readBusDetails();
}

void fleet::addLuxuryBus(luxuryBus luxury)
{
	this->luxury_buses.push_back(luxury);
}

void fleet::addMiniBus(miniBus small)
{
	this->mini_buses.push_back(small);
}

void fleet::addMiniVan(miniVan mini)
{
	this->mini_vans.push_back(mini);
}
luxuryBus* fleet::getLuxuryBus(std::string id)
{
	for (auto item : this->luxury_buses) {
		if (item.get_id_no() == id) {
			luxuryBus* itemptr = &item;
			return itemptr;
		}
	}
	return nullptr;
}

miniBus* fleet::getMiniBus(std::string id)
{
	for (auto item : this->mini_buses) {
		if (item.get_id_no() == id) {
			miniBus* itemptr = &item;
			return itemptr;
		}
	}
	return nullptr;
}

miniVan* fleet::getMiniVan(std::string id)
{
	for (auto item : this->mini_vans) {
		if (item.get_id_no() == id) {
			miniVan* itemptr = &item;
			return itemptr;
		}
	}
	return nullptr;
}

void fleet::displayLuxuryBusFleet()
{
	if (!this->luxury_buses.empty())
	{
		std::cout << "Luxury buses:" << std::endl;
		int index = 0;
		for (auto& elem : this->luxury_buses)
		{
			index++;
			std::cout << index << ". " << elem.get_id_no() << std::endl;
		}
	}
	else
	{
		std::cout << "Currently we have no Luxury buses in our fleet." << std::endl;
	}
}

void fleet::displayMiniBusFleet()
{
	if (!this->mini_buses.empty())
	{
		std::cout << "Mini buses:" << std::endl;
		int index = 0;
		for (auto& elem : this->mini_buses)
		{
			index++;
			std::cout << index << ". " << elem.get_id_no() << std::endl;
		}
	}
	else
	{
		std::cout << "Currently we have no Mini buses in our fleet." << std::endl;
	}
}

void fleet::displayMiniVanFleet()
{
	if (!this->mini_vans.empty())
	{
		std::cout << "Minivans:" << std::endl;
		int index = 0;
		for (auto& elem : this->mini_vans)
		{
			index++;
			std::cout << index << ". " << elem.get_id_no() << std::endl;
		}
	}
	else
	{
		std::cout << "Currently we have no Minivans in our fleet." << std::endl;
	}
}

void fleet::readBusDetails() {
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
		/* DEBUGGING
		for (auto& part : rowelements) {
			std::cout << part << "  ";
		}
		std::cout << std::endl; */
		if (lineno != 1) {
			std::string idAsString = rowelements[0];

			// declaring character array
			char char_array[6];
			strcpy_s(char_array, idAsString.c_str());
			char letter1 = char_array[0];
			char letter2 = char_array[1];
			if (letter1 == 'L') {
				luxuryBus lbtemp = luxuryBus(rowelements[0]);
				addLuxuryBus(lbtemp);
			}
			if (letter1 == 'M') {
				if (letter2 == 'V') {
					miniVan mvtemp = miniVan(rowelements[0]);
					addMiniVan(mvtemp);
				}
				if (letter2 == 'B') {
					miniBus mbtemp = miniBus(rowelements[0]);
					addMiniBus(mbtemp);
				}
			}
		}
	}
}