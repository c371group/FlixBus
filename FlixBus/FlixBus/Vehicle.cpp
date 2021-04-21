//implementation file
#include "Vehicle.h"

vehicle::vehicle()
= default;

vehicle::vehicle(int val1)
{
	this->id_no = val1;
}

void vehicle::set_id_no(int val)
{
	this->id_no = val;
}

void vehicle::set_capacity(int val)
{
	this->capacity = val;
}

/*
void vehicle::set_rate_per_mile(int val)
{
	this->rate_per_mile = val;
}
*/

/*int vehicle::set_values_from_type(std::string val) //TODO: go back and make this an enum
{
	std::string types[] = {"Luxury Bus", "Mini Bus", "MiniVan"};
	int capacities[] = {52, 36, 12}; // we'll have to figure out stuff with the seats later
	int rates_per_mile_regular[] = {75, 65, 50}; // this is just an array for the regular travel, NOT RENTAL,
	//we'll have to create something for the luxury bus (remember that window and aisle seats are
	//different prices) but this is just for testing

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
*/

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
// Returns True only if the seat was reserved and not taken before. Else it will return False.
bool vehicle::reserveSeat(int row, char column)
{
	auto seats = *get_seats();
	std::pair<int, char> seat{row, column};
	if ((seats).count(seat) > 0)
	{
		for (auto& p : seats)
		{
			if (p.first.first == row && p.first.second == column)
			{
				if (p.second.first != 1) {
					p.second.first = 1;
					std::cout << std::endl << p.first.first << p.first.second << " seat was reserved!" << std::endl;
					return true;
				}
				else {
					std::cout << std::endl << p.first.first << p.first.second << " seat was taken!" << std::endl;
					return false;
				}
			}
		}
	}
	else
	{
		std::cout << std::endl << row << column << " seat was not found." << std::endl;
		return false;
	}
	return false;
}

// Takes Int and Char, combines them to a seat id and cancels the reservation (sets the second <int> to 0).
// Returns True only if the seat was cancelled. Else it will return False.
bool vehicle::cancelSeat(int row, char column)
{
	auto seats = get_seats();
	std::pair<int, char> seat{row, column};
	if ((*seats).count(seat) > 0)
	{
		for (auto& p : *seats)
		{
			if (p.first.first == row && p.first.second == column)
			{
				if (p.second.first != 0)
				{
					p.second.first = 0;
					std::cout << std::endl << p.first.first << p.first.second << " seat was cancelled!" << std::endl;
					return true;
				}
				else {
					std::cout << std::endl << p.first.first << p.first.second << " seat was not reserved. No need of cancellation." << std::endl;
					return false;
				}
			}
		}
	}
	else
	{
		std::cout << std::endl << row << column << " seat was not found." << std::endl;
		return false;
	}
	return false;
}

// Returns seat's rate, if it doesn't find the seat, returns 0
double vehicle::getSeatRate(int row, char column)
{
	auto seats = get_seats();
	std::pair<int, char> seat{ row, column };
	if ((*seats).count(seat) > 0)
	{
		for (auto& p : *seats)
		{
			if (p.first.first == row && p.first.second == column)
			{
				return p.second.second;
			}
		}
	}
	return 0;
}

int vehicle::get_all_seats_count()
{
	auto seats = *get_seats();
	int seatsCount = 0;
	for (const auto& p : seats)
	{
		seatsCount++;
	}
	return seatsCount;
}

int vehicle::get_free_seats_count()
{
	auto seats = *get_seats();
	int seatsCount = 0;
	for (const auto& p : seats)
	{

		if (p.second.first == 0)
		{
			seatsCount++;
		}
	}
	return seatsCount;
}

// Returns a refrence of the seats map
std::map<std::pair<int, char>, std::pair<int, double>>* luxaryBus::get_seats()
{
	return &this->seats;
}

luxaryBus::luxaryBus()
= default;

luxaryBus::luxaryBus(int id)
{
	this->id_no = id;
}

std::string luxaryBus::get_type()
{
	return this->type;
}

int luxaryBus::get_id_no()
{
	return this->id_no;
}

// Returns a refrence of the seats map
std::map<std::pair<int, char>, std::pair<int, double>>* miniBus::get_seats()
{
	return &this->seats;
}

miniBus::miniBus()
= default;

miniBus::miniBus(int id)
{
	this->id_no = id;
}

std::string miniBus::get_type()
{
	return this->type;
}

int miniBus::get_id_no()
{
	return this->id_no;
}

// Returns a refrence of the seats map
std::map<std::pair<int, char>, std::pair<int, double>>* miniVan::get_seats()
{
	return &this->seats;
}

miniVan::miniVan()
= default;

miniVan::miniVan(int id)
{
	this->id_no = id;
}

std::string miniVan::get_type()
{
	return this->type;
}

int miniVan::get_id_no()
{
	return this->id_no;
}
