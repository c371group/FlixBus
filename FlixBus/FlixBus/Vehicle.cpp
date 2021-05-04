//implementation file
#include "Vehicle.h"


// Destructor
vehicle::~vehicle() = default;
// Base constructor
vehicle::vehicle() = default;

// Constructor, takes string and assigns it as id_no_ attribute.
vehicle::vehicle(std::string val)
{
	this->id_no_ = val;
}

// Sets string value to id_no_ attribute.
void vehicle::set_id_no(std::string val)
{
	this->id_no_ = val;
}

// Sets int value to capacity attribute.
void vehicle::set_capacity(int val)
{
	this->capacity_ = val;
}

// Returns id_no_ attribute.
std::string vehicle::get_id_no()
{
	return this->id_no_;
}

// Returns capacity_ attribute.
int vehicle::get_capacity()
{
	return this->capacity_;
}

// Returns type_ attribute.
std::string vehicle::get_type()
{
	return this->type_;
}

// Loops through seats_ map and displays all seats_.
void vehicle::display_seats()
{
	// Returns seats attribute for derived classes.
	auto seats = *get_seats();
	std::pair<int, char> seat{ 1, 'E' };
	int columns = seats.count(seat) > 0 ? 5 : 3;

	int displayRow = 0;
	for (const auto& p : seats)
	{
		// This is done so we  can see only 5 columns for luxury bus.
		if (displayRow == columns)
		{
			std::cout << std::endl;
			displayRow = 0;
		}
		displayRow++;
		std::cout << p.first.first << p.first.second << "\t ";
	}
}

// Loops through seats_ map and displays reserved seats_ as 'X'.
void vehicle::display_free_seats()
{
	// Returns seats attribute for derived classes.
	auto seats = *get_seats();
	std::pair<int, char> seat{ 1, 'E' };
	int columns = seats.count(seat) > 0 ? 5 : 3;
	int displayRow = 0;
	for (const auto& p : seats)
	{
		// This is done so we  can see only 5 columns for luxury bus.
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

// Reserve all seats_ when the bus is hired.
void vehicle::reserve_all_seats()
{
	const auto seats = get_seats();
	for (auto& p : *seats)
	{
		p.second.first = 1;
	}
	
}

// Takes Int and Char, combines them to a seat id and reserves that seat. ( sets the second <int> to 1).
// Returns True only if the seat was reserved and not taken before. Else it will return False.
bool vehicle::reserve_seat(int row, char column)
{
	bool validate = false;
	// Returns seats attribute for derived classes.
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

// Checks if half of the capacity is > than the free seats_.
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
bool vehicle::cancel_seat(int row, char column)
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
double vehicle::get_seat_rate(int row, char column)
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

// Counts how many seats there are and returns the value.
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

// Counts how many free (not reserved) seats there are and returns the value.
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

// Returns a reference of the seats_ map
std::map<std::pair<int, char>, std::pair<int, double>>* luxury_bus::get_seats()
{
	return &this->seats;
}

// Luxury bus default constructor.
luxury_bus::luxury_bus()
= default;

// Constructor that takes string and assigns it to id_no_ attribute.
luxury_bus::luxury_bus(std::string id)
{
	this->id_no_ = id;
}

// Returns type_ attribute.
std::string luxury_bus::get_type()
{
	return this->type_;
}

// Returns id_no_ attribute.
std::string luxury_bus::get_id_no()
{
	return this->id_no_;
}

// Takes double and assigns it to bus_hire_rate attribute.
void luxury_bus::set_bus_hire_rate(double value)
{
	this->bus_hire_rate_ = value;
}

// Takes double and assigns it to bus_hire_rate_per_mile attribute.
void luxury_bus::set_bus_hire_rate_per_mile(double value)
{
	this->bus_hire_rate_per_mile_ = value;
}

// Takes double and assigns it to security_deposit.
void luxury_bus::set_security_deposit(double value)
{
	this->security_deposit_ = value;
}

// Returns bus_hire_rate attribute.
double luxury_bus::get_bus_hire_rate() const
{
	return this->bus_hire_rate_;
}

// Returns bus_hire_rate_per_mile attribute.
double luxury_bus::get_bus_hire_rate_per_mile() const
{
	return this->bus_hire_rate_per_mile_;
}

// Returns security deposit attribute.
double luxury_bus::get_security_deposit() const
{
	return this->security_deposit_;
}

// Returns capacity attribute.
int luxury_bus::get_capacity()
{
	return this->capacity_;
}

// Returns a reference of the seats_ map
std::map<std::pair<int, char>, std::pair<int, double>>* mini_bus::get_seats()
{
	return &this->seats;
}

mini_bus::mini_bus()
= default;

// Constructor takes string and sets its value to id_no_ attribute.
mini_bus::mini_bus(std::string id)
{
	this->id_no_ = id;
}

// Returns type_ attribute.
std::string mini_bus::get_type()
{
	return this->type_;
}

// Returns id_no_ attribute.
std::string mini_bus::get_id_no()
{
	return this->id_no_;
}

// Takes double and assigns it to bus_hire_rate attribute.
void mini_bus::set_bus_hire_rate(double value)
{
	this->bus_hire_rate_ = value;
}

// Takes double and assigns it to bus_hire_rate_per_mile attribute.
void mini_bus::set_bus_hire_rate_per_mile(double value)
{
	this->bus_hire_rate_per_mile_ = value;
}

// Takes double and assigns it to security_deposit.
void mini_bus::set_security_deposit(double value)
{
	this->security_deposit_ = value;
}

// Returns bus_hire_rate attribute.
double mini_bus::get_bus_hire_rate() const
{
	return this->bus_hire_rate_;
}

// Returns bus_hire_rate_per_mile attribute.
double mini_bus::get_bus_hire_rate_per_mile() const
{
	return this->bus_hire_rate_per_mile_;
}

// Returns security deposit attribute.
double mini_bus::get_security_deposit() const
{
	return this->security_deposit_;
}

// Returns capacity.
int mini_bus::get_capacity()
{
	return this->capacity_;
}

// Returns a reference of the seats_ map
std::map<std::pair<int, char>, std::pair<int, double>>* mini_van::get_seats()
{
	return &this->seats;
}

// Used by copies of the object, NOT original
void mini_van::set_seats(std::map<std::pair<int, char>, std::pair<int, double>> temp) {
	this->seats = temp;
}

// Base mini van constructor.
mini_van::mini_van()
= default;

// Copy constructor for minivan
mini_van::mini_van(const mini_van & mv)
{
	id_no_ = mv.id_no_;
	seats = mv.seats;
}

// Returns type_ attribute.
std::string mini_van::get_type()
{
	return this->type_;
}

// Constructor that takes string value and assigns it to id_no_ attribute.
mini_van::mini_van(std::string id)
{
	this->id_no_ = id;
}

// returns id_no_ attribute.
std::string mini_van::get_id_no()
{
	return this->id_no_;
}

// Takes double and assigns it to bus_hire_rate attribute.
void mini_van::set_bus_hire_rate(double value)
{
	this->bus_hire_rate_ = value;
}

// Takes double and assigns it to bus_hire_rate_per_mile attribute.
void mini_van::set_bus_hire_rate_per_mile(double value)
{
	this->bus_hire_rate_per_mile_ = value;
}

// Takes double and assigns it to security_deposit.
void mini_van::set_security_deposit(double value)
{
	this->security_deposit_ = value;
}

// Returns bus_hire_rate attribute.
double mini_van::get_bus_hire_rate() const
{
	return this->bus_hire_rate_;
}

// Returns bus_hire_rate_per_mile attribute.
double mini_van::get_bus_hire_rate_per_mile() const
{
	return this->bus_hire_rate_per_mile_;
}

// Returns security_deposit attribute.
double mini_van::get_security_deposit() const
{
	return this->security_deposit_;
}

// Returns capacity attribute.
int mini_van::get_capacity()
{
	return this->capacity_;
}
