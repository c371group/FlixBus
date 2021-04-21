#pragma once
#include <vector>
#include <iostream>
#include "Vehicle.h"

class fleet
{
private:
	std::vector<luxaryBus*> luxury_buses;
	std::vector<miniBus*> mini_buses;
	std::vector<miniVan*> mini_vans;

public:
	void addLuxaryBus(luxaryBus*);
	void addMiniBus(miniBus*);
	void addMiniVan(miniVan*);

	luxaryBus* getLuxaryBus(int);
	miniBus* getMiniBus(int);
	miniVan* getMiniVan(int);
	void displayLuxaryBusFleet();
	void displayMiniBusFleet();
	void displayMiniVanFleet();
};
