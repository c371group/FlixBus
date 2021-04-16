//implementation file
#include "Vehicle.h"
#include <iostream>
#include <map>


vehicle::vehicle()
= default;

vehicle::vehicle(std::string val)
{
	this->type = val;
	set_values_from_type(val);
}

vehicle::vehicle(int val1, std::string val2)
{
	this->id_no = val1;
	this->type = val2;
	set_values_from_type(val2);
}

void vehicle::set_id_no(int val)
{
	this->id_no = val;
}

void vehicle::set_capacity(int val)
{
	this->capacity = val;
}

void vehicle::set_type(std::string val)
{
	this->type = val;
}

void vehicle::set_rate_per_mile(int val)
{
	this->rate_per_mile = val;
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
	return this->id_no;
}

int vehicle::get_capacity()
{
	return this->capacity;
}


std::string vehicle::get_type()
{
	return this->type;
}


int vehicle::get_rate_per_mile()
{
	return this->rate_per_mile;
}

// Loops through seats map and displays all seats.
void vehicle::displaySeats()
{
	auto seats = *get_seats();
	std::pair<int, char> seat{1, 'E'};
	int columns = seats.count(seat) > 0 ? 5 : 3;

	int displayRow = 0;
	for (const auto& p : seats)
	{
		// This is done so we  can see only 5 columns for luxary bus.
		if (displayRow == columns)
		{
			std::cout << std::endl;
			displayRow = 0;
		}
		displayRow++;
		std::cout << p.first.first << p.first.second << "\t ";
	}
}

// Loops through seats map and displays reserved seats as 'X'.
void vehicle::displayFreeSeats()
{
	auto seats = *get_seats();
	std::pair<int, char> seat{1, 'E'};
	int columns = seats.count(seat) > 0 ? 5 : 3;
	int displayRow = 0;
	for (const auto& p : seats)
	{
		// This is done so we  can see only 5 columns for luxary bus.
		if (displayRow == columns)
		{
			std::cout << std::endl;
			displayRow = 0;
		}
		if (p.second.first == 0)
		{
			std::cout << p.first.first << p.first.second << "\t ";
		}
		else
		{
			std::cout << "X" << "\t ";
		}
		displayRow++;
	}
}

// Takes Int and Char, combines them to a seat id and reserves that seat. ( sets the second <int> to 1).
void vehicle::reserveSeat(int row, char column)
{
	auto seats = get_seats();
	std::pair<int, char> seat{row, column};
	if ((*seats).count(seat) > 0)
	{
		for (auto& p : *seats)
		{
			if (p.first.first == row && p.first.second == column)
			{
				p.second.first = 1;
				std::cout << std::endl << p.first.first << p.first.second << " seat was reserved!" << std::endl;
			}
		}
	}
	else
	{
		std::cout << std::endl << row << column << " seat was not found." << std::endl;
	}
}

// Takes Int and Char, combines them to a seat id and cancels the reservation (sets the second <int> to 0).
void vehicle::cancelSeat(int row, char column)
{
	auto seats = get_seats();
	std::pair<int, char> seat{row, column};
	if ((*seats).count(seat) > 0)
	{
		for (auto& p : *seats)
		{
			if (p.first.first == row && p.first.second == column)
			{
				p.second.first = 0;
				std::cout << std::endl << p.first.first << p.first.second << " seat was cancelled!" << std::endl;
			}
		}
	}
	else
	{
		std::cout << std::endl << row << column << " seat was not found." << std::endl;
	}
}

// Returns a refrence of the seats map
std::map<std::pair<int, char>, std::pair<int, double>>* luxaryBus::get_seats()
{
	// TODO: insert return statement here
	return &this->seats;
}

std::string luxaryBus::get_type()
{
	return this->type;
}

// Returns a refrence of the seats map
std::map<std::pair<int, char>, std::pair<int, double>>* miniBus::get_seats()
{
	// TODO: insert return statement here
	return &this->seats;
}

std::string miniBus::get_type()
{
	return this->type;
}

// Returns a refrence of the seats map
std::map<std::pair<int, char>, std::pair<int, double>>* miniVan::get_seats()
{
	// TODO: insert return statement here
	return &this->seats;
}

std::string miniVan::get_type()
{
	return this->type;
}
