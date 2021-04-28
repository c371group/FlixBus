//implementation file
#include "Vehicle.h"

vehicle::vehicle()
= default;

vehicle::vehicle(std::string val1)
{
	this->id_no = val1;
}

void vehicle::set_id_no(std::string val)
{
	this->id_no = val;
}

void vehicle::set_capacity(int val)
{
	this->capacity = val;
}

std::string vehicle::get_id_no()
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
	std::pair<int, char> seat{ 1, 'E' };
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
	std::pair<int, char> seat{ 1, 'E' };
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

// Reserve all seats when the bus is hired.
void vehicle::reserveAllSeats()
{
	const auto seats = get_seats();
	for (auto& p : *seats)
	{
		p.second.first = 1;
	}
	
}

// Takes Int and Char, combines them to a seat id and reserves that seat. ( sets the second <int> to 1).
// Returns True only if the seat was reserved and not taken before. Else it will return False.
bool vehicle::reserveSeat(int row, char column)
{
	bool validate = false;
	auto seats = get_seats();
	std::pair<int, char> seat{ row, column };
	if ((*seats).count(seat) > 0)
	{
		for (auto& p : *seats)
		{
			if (p.first.first == row && p.first.second == column)
			{
				if (p.second.first != 1) {
					p.second.first = 1;
					std::cout << std::endl << p.first.first << p.first.second << " seat was reserved!" << std::endl;
					validate = true;
				}
				else
				{
					std::cout << std::endl << p.first.first << p.first.second << " seat was already reserved!" << std::endl;
					validate = true;
				}
			}
		}
	}
	else
	{
		std::cout << std::endl << row << column << " seat was not found." << std::endl;
	}
	return validate;
}

// Checks if half of the capacity is > than the free seats.
bool vehicle::can_hire()
{
	if(this->get_capacity()/2 > this->get_free_seats_count())
	{
		return false;
	}
	return true;
}

// Takes Int and Char, combines them to a seat id and cancels the reservation (sets the second <int> to 0).
// Returns True only if the seat was cancelled. Else it will return False.
bool vehicle::cancelSeat(int row, char column)
{
	bool validate = false;
	auto seats = get_seats();
	std::pair<int, char> seat{ row, column };
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
					validate = true;
				}
				else {
					std::cout << std::endl << p.first.first << p.first.second << " seat was not reserved. No need of cancellation." << std::endl;
				}
			}
		}
	}
	else
	{
		std::cout << std::endl << row << column << " seat was not found." << std::endl;
	}
	return validate;
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

// Returns a reference of the seats map
std::map<std::pair<int, char>, std::pair<int, double>>* luxuryBus::get_seats()
{
	return &this->seats;
}

luxuryBus::luxuryBus()
= default;

luxuryBus::luxuryBus(std::string id)
{
	this->id_no = id;
}

std::string luxuryBus::get_type()
{
	return this->type;
}
std::string luxuryBus::get_id_no()
{
	return this->id_no;
}

double luxuryBus::getBusHireRate() const
{
	return this->busHireRate;
}

double luxuryBus::getBusHireRatePerMile() const
{
	return this->busHireRatePerMile;
}

int luxuryBus::get_capacity()
{
	return this->capacity;
}

// Returns a reference of the seats map
std::map<std::pair<int, char>, std::pair<int, double>>* miniBus::get_seats()
{
	return &this->seats;
}

miniBus::miniBus()
= default;

/*miniBus::miniBus(const miniBus& mb)
{	x = sam.x;
	y = sam.y;
}*/
miniBus::miniBus(std::string id)
{
	this->id_no = id;
}

std::string miniBus::get_type()
{
	return this->type;
}

std::string miniBus::get_id_no()
{
	return this->id_no;
}

double miniBus::getBusHireRate() const
{
	return this->busHireRate;
}

double miniBus::getBusHireRatePerMile() const
{
	return this->busHireRatePerMile;
}

int miniBus::get_capacity()
{
	return this->capacity;
}

// Returns a reference of the seats map
std::map<std::pair<int, char>, std::pair<int, double>>* miniVan::get_seats()
{
	return &this->seats;
}

//for use by copies of the object, NOT original
void miniVan::set_seats(std::map<std::pair<int, char>, std::pair<int, double>> temp) {
	this->seats = temp;
}
miniVan::miniVan()
= default;

miniVan::miniVan(const miniVan & mv) //copy constructor for minivan
{
	id_no = mv.id_no;
	seats = mv.seats;
}
std::string miniVan::get_type()
{
	return this->type;
}
miniVan::miniVan(std::string id)
{
	this->id_no = id;
}

std::string miniVan::get_id_no()
{
	return this->id_no;
}

double miniVan::getBusHireRate() const
{
	return this->busHireRate;
}

double miniVan::getBusHireRatePerMile() const
{
	return this->busHireRatePerMile;
}

int miniVan::get_capacity()
{
	return this->capacity;
}
