#pragma once
#include <vector>
#include <iostream>
#include "Vehicle.h"

class fleet
{
private:
	std::vector<luxuryBus*> luxury_buses;
	std::vector<miniBus*> mini_buses;
	std::vector<miniVan*> mini_vans;

public:
	void addLuxaryBus(luxuryBus*);
	void addMiniBus(miniBus*);
	void addMiniVan(miniVan*);

	luxuryBus* getLuxaryBus(int);
	miniBus* getMiniBus(int);
	miniVan* getMiniVan(int);
	void displayLuxaryBusFleet();
	void displayMiniBusFleet();
	void displayMiniVanFleet();
};
