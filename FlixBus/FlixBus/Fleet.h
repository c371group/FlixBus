#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Vehicle.h"

class fleet
{
private:
	std::vector<luxuryBus> luxury_buses;
	std::vector<miniBus> mini_buses;
	std::vector<miniVan> mini_vans;

public:
	fleet();
	void addLuxuryBus(luxuryBus);
	void addMiniBus(miniBus);
	void addMiniVan(miniVan);

	luxuryBus* getLuxuryBus(std::string);
	miniBus* getMiniBus(std::string);
	miniVan* getMiniVan(std::string);
	size_t get_luxury_bus_count();
	size_t get_mini_bus_count();
	size_t get_minivan_count();
	void displayLuxuryBusFleet();
	void displayMiniBusFleet();
	void displayMiniVanFleet();
	void readBusDetails();
};
