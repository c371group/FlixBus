#include "Fleet.h"

void fleet::addLuxaryBus(luxaryBus* luxary)
{
	this->luxury_buses.push_back(luxary);
}

void fleet::addMiniBus(miniBus* small)
{
	this->mini_buses.push_back(small);
}

void fleet::addMiniVan(miniVan* mini)
{
	this->mini_vans.push_back(mini);
}

luxaryBus* fleet::getLuxaryBus(int index)
{
	for (auto item : this->luxury_buses) {
		if (item->get_id_no() == index) {
			return item;
		}
	}
}

miniBus* fleet::getMiniBus(int index)
{
	for (auto item : this->mini_buses) {
		if (item->get_id_no() == index) {
			return item;
		}
	}
	return nullptr;
}

miniVan* fleet::getMiniVan(int index)
{
	for (auto item : this->mini_vans) {
		if (item->get_id_no() == index) {
			return item;
		}
	}
	return nullptr;
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
