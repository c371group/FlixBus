#pragma once
#include "Vehicle.h"
#include <vector>

class fleet
{
private:
	std::vector<vehicle*> luxury_buses;
	std::vector<vehicle*> mini_buses;
	std::vector<vehicle*> mini_vans;

public:
	void addLuxaryBus(vehicle* luxary);
	void addMiniBus(vehicle* small);
	void addMiniVan(vehicle* mini);

	vehicle* getLuxaryBus(int index);
	vehicle* getMiniBus(int index);
	vehicle* getMiniVan(int index);
	void displayLuxaryBusFleet();
	void displayMiniBusFleet();
	void displayMiniVanFleet();
};
