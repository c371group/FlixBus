#include <iostream>
#include "Fleet.h"


void fleet::addLuxaryBus(vehicle* luxary)
{
	this->luxury_buses.push_back(luxary);
}

void fleet::addMiniBus(vehicle* small)
{
	this->mini_buses.push_back(small);
}

void fleet::addMiniVan(vehicle* mini)
{
	this->mini_vans.push_back(mini);
}

vehicle* fleet::getLuxaryBus(int index)
{
	return this->luxury_buses[index];
}

vehicle* fleet::getMiniBus(int index)
{
	return this->mini_buses[index];
}

vehicle* fleet::getMiniVan(int index)
{
	return this->mini_vans[index];
}

void fleet::displayLuxaryBusFleet()
{
	if (!this->luxury_buses.empty())
	{
		std::cout << "Luxary buses:" << std::endl;
		int index = 0;
		for (auto& elem : this->luxury_buses)
		{
			index++;
			std::cout << index << ". " << elem->get_type() << std::endl;
		}
	}
	else
	{
		std::cout << "Currently we have no Luxary buses in our fleet." << std::endl;
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
			std::cout << index << ". " << elem->get_type() << std::endl;
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
			std::cout << index << ". " << elem->get_type() << std::endl;
		}
	}
	else
	{
		std::cout << "Currently we have no Minivans in our fleet." << std::endl;
	}
}
