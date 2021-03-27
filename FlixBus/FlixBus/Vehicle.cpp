//implementation file
#include "Vehicle.h"

#include <iostream>

vehicle::vehicle()
= default;

vehicle::vehicle(std::string val)
{
	this->type_ = val;
	set_values_from_type(val);
}

vehicle::vehicle(int val1, std::string val2)
{
	this->id_no_ = val1;
	this->type_ = val2;
	set_values_from_type(val2);
}

void vehicle::set_id_no(int val)
{
	id_no_ = val;
}

void vehicle::set_capacity(int val)
{
	capacity_ = val;
}
void vehicle::set_type(std::string val)
{
	type_ = val;
}
void vehicle::set_rate_per_mile(int val)
{
	rate_per_mile_ = val;
}

int vehicle::set_values_from_type(std::string val) //TODO: go back and make this an enum
{
	std::string types[] = {"Luxury Bus", "Mini Bus", "MiniVan"};
	int capacities[] = {52, 36, 12}; // we'll have to figure out stuff with the seats later
	int rates_per_mile_regular[] = {75, 65, 50}; /* this is just an array for the regular travel, NOT RENTAL,
	we'll have to create something for the luxury bus (remember that window and aisle seats are
	different prices) but this is just for testing*/

	for (auto i = 0; i < 3; i++)
	{
		if (val == types[i])
		{
			set_rate_per_mile(rates_per_mile_regular[i]);
			set_capacity(capacities[i]);
			return 0;
		}
	}

	std::cout << "WARNING: BUS TYPE COULD NOT BE FOUND" << std::endl;
	return 0;
	
}


int vehicle::get_id_no()
{
	return id_no_;
}

int vehicle::get_capacity()
{
	return capacity_;
}


std::string vehicle::get_type()
{
	return type_;
}



int vehicle::get_rate_per_mile()
{
	return rate_per_mile_;
}
