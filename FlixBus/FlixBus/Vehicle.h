#pragma once
#include <string>
#include <map>
#include <iostream>


/**
 * \brief vehicle class is base class for all types of vehicles used in our bus company.
 */
class vehicle
{
private:
	// Unique id to be assigned to every vehicle object.
	std::string id_no_;
	// Type of vehicle
	const std::string type_ = "Base";
	// Seat capacity of the vehicle
	int capacity_ = 0;
	/**
	 * \brief map<std::pair<int, char>, std::pair<int, double>> seats representation.
	 * pair<int, char> represents int - row, char - column.
	 * pair<int, double> represents int - seat occupation (0-free, 1-taken), double - rate for the seat.
	 */
	std::map<std::pair<int, char>, std::pair<int, double>> seats{};
public:
	// Vehicle destructor
	virtual ~vehicle();
	// Base vehicle constructor
	vehicle();
	// Constructor that takes string and assigns it as id_no attribute.
	explicit vehicle(std::string);
	// Sets string value to id_no attribute.
	void set_id_no(std::string);
	// Sets int value to capacity attribute.
	void set_capacity(int);
	// Returns string id_no value
	virtual std::string get_id_no();
	// Returns type value
	virtual std::string get_type();
	// Returns capacity value
	virtual int get_capacity();
	// Returns seat count
	int get_all_seats_count();
	// Returns count of seats_ that are not reserved.
	int get_free_seats_count();
	// Displaying all seats_
	void display_seats();
	// Displaying taken seats_ as 'X'.
	void display_free_seats();
	// Reserve all seats_
	void reserve_all_seats();
	// Takes Int and Char, combines them to a seat id and reserves that seat. ( sets the second <int> to 1).
	bool reserve_seat(int row, char column);
	// Check if available for hire.
	virtual bool can_hire();
	// Takes Int and Char, combines them to a seat id and cancels the reservation (sets the second <int> to 0).
	bool cancel_seat(int row, char column);
	// Returns rate for a given seat (pair<int,chat>)
	double get_seat_rate(int row, char column);
	// Returns seat map.
	virtual std::map<std::pair<int, char>, std::pair<int, double>>* get_seats() = 0;
};

// Derived class, used for representing Luxury bus type.
class luxury_bus : public vehicle
{
private:
	// Bus type
	const std::string type_ = "Luxury Bus";
	// Identification number for the bus
	std::string id_no_ = "0"; //unique identifier for bus
	// Rate for window seats_.
	double window_seat_rate_ = 0.95;
	// Rate for isle seats_.
	double aisle_seat_rate_ = 0.75;
	// Rate for bus hire.
	double bus_hire_rate_ = 1500;
	// Rate for bus hire per mile.
	double bus_hire_rate_per_mile_ = 0.25;
	// Rate for security deposit.
	double security_deposit_ = 5000;
	// Constant capacity for a luxury bus.
	const int capacity_ = 52;
public:
	// Base luxury bus constructor.
	luxury_bus();
	// Base constructor that assigns id_no.
	explicit luxury_bus(std::string);
	// Seats map. <int, char> represents seats_ id(1A 1B 1C) the <int> will be either 0 or 1, representing if the seat is taken(1) or free(0).
	std::map<std::pair<int, char>, std::pair<int, double>> seats{
		{{1, 'A'}, {0, window_seat_rate_}}, {{1, 'B'}, {0, aisle_seat_rate_}}, {{1, 'C'}, {0, aisle_seat_rate_}},
		{{1, 'D'}, {0, aisle_seat_rate_}}, {{1, 'E'}, {0, window_seat_rate_}},
		{{2, 'A'}, {0, window_seat_rate_}}, {{2, 'B'}, {0, aisle_seat_rate_}}, {{2, 'C'}, {0, aisle_seat_rate_}},
		{{2, 'D'}, {0, aisle_seat_rate_}}, {{2, 'E'}, {0, window_seat_rate_}},
		{{3, 'A'}, {0, window_seat_rate_}}, {{3, 'B'}, {0, aisle_seat_rate_}}, {{3, 'C'}, {0, aisle_seat_rate_}},
		{{3, 'D'}, {0, aisle_seat_rate_}}, {{3, 'E'}, {0, window_seat_rate_}},
		{{4, 'A'}, {0, window_seat_rate_}}, {{4, 'B'}, {0, aisle_seat_rate_}}, {{4, 'C'}, {0, aisle_seat_rate_}},
		{{4, 'D'}, {0, aisle_seat_rate_}}, {{4, 'E'}, {0, window_seat_rate_}},
		{{5, 'A'}, {0, window_seat_rate_}}, {{5, 'B'}, {0, aisle_seat_rate_}}, {{5, 'C'}, {0, aisle_seat_rate_}},
		{{5, 'D'}, {0, aisle_seat_rate_}}, {{5, 'E'}, {0, window_seat_rate_}},
		{{6, 'A'}, {0, window_seat_rate_}}, {{6, 'B'}, {0, aisle_seat_rate_}}, {{6, 'C'}, {0, aisle_seat_rate_}},
		{{6, 'D'}, {0, aisle_seat_rate_}}, {{6, 'E'}, {0, window_seat_rate_}},
		{{7, 'A'}, {0, window_seat_rate_}}, {{7, 'B'}, {0, aisle_seat_rate_}}, {{7, 'C'}, {0, aisle_seat_rate_}},
		{{7, 'D'}, {0, aisle_seat_rate_}}, {{7, 'E'}, {0, window_seat_rate_}},
		{{8, 'A'}, {0, window_seat_rate_}}, {{8, 'B'}, {0, aisle_seat_rate_}}, {{8, 'C'}, {0, aisle_seat_rate_}},
		{{8, 'D'}, {0, aisle_seat_rate_}}, {{8, 'E'}, {0, window_seat_rate_}},
		{{9, 'A'}, {0, window_seat_rate_}}, {{9, 'B'}, {0, aisle_seat_rate_}}, {{9, 'C'}, {0, aisle_seat_rate_}},
		{{9, 'D'}, {0, aisle_seat_rate_}}, {{9, 'E'}, {0, window_seat_rate_}},
		{{10, 'A'}, {0, window_seat_rate_}}, {{10, 'B'}, {0, aisle_seat_rate_}}, {{10, 'C'}, {0, aisle_seat_rate_}},
		{{10, 'D'}, {0, aisle_seat_rate_}}, {{10, 'E'}, {0, window_seat_rate_}},
		{{11, 'A'}, {0, window_seat_rate_}}, {{11, 'B'}, {0, aisle_seat_rate_}}
	};
	// Overrides base class virtual function, returns pointer to seats_ attribute.
	std::map<std::pair<int, char>, std::pair<int, double>>* get_seats() override;
	// Returns type attribute.
	std::string get_type() override;
	// Returns id_no attribute.
	std::string get_id_no() override;
	// Takes double and assigns it to bus_hire_rate attribute.
	void set_bus_hire_rate(double);
	// Takes double and assigns it to bus_hire_rate_per_mile attribute.
	void set_bus_hire_rate_per_mile(double);
	// Takes double and assigns it to security_deposit.
	void set_security_deposit(double);
	// Returns bus_hire_rate attribute.
	double get_bus_hire_rate() const;
	// Returns bus_hire_rate_per_mile attribute.
	double get_bus_hire_rate_per_mile() const;
	// Returns security_deposit.
	double get_security_deposit() const;
	// Returns capacity.
	int get_capacity() override;
};

class mini_bus : public vehicle
{
private:
	// Bus type
	const std::string type_ = "Mini Bus";
	// Identification number for the bus
	std::string id_no_ = "0";
	// Rate for window seats_.
	double window_seat_price_ = 0.65;
	// Rate for isle seats_.
	double aisle_seat_price_ = 0.65;
	// Rate for bus hire.
	double bus_hire_rate_ = 1300;
	// Rate for bus hire per mile.
	double bus_hire_rate_per_mile_ = 0.2;
	// Rate for security deposit.
	double security_deposit_ = 3000;
	// Constant capacity for a luxury bus.
	const int capacity_ = 36;
public:
	// Base mini bus constructor.
	mini_bus();
	// Base constructor that assigns id_no.
	mini_bus(std::string);
	// Seats map. <int, char> represents seats_ id(1A 1B 1C) the <int> will be either 0 or 1, representing if the seat is taken(1) or free(0).
	std::map<std::pair<int, char>, std::pair<int, double>> seats{
		{{1, 'A'}, {0, window_seat_price_}}, {{1, 'B'}, {0, aisle_seat_price_}}, {{1, 'C'}, {0, window_seat_price_}},
		{{2, 'A'}, {0, window_seat_price_}}, {{2, 'B'}, {0, aisle_seat_price_}}, {{2, 'C'}, {0, window_seat_price_}},
		{{3, 'A'}, {0, window_seat_price_}}, {{3, 'B'}, {0, aisle_seat_price_}}, {{3, 'C'}, {0, window_seat_price_}},
		{{4, 'A'}, {0, window_seat_price_}}, {{4, 'B'}, {0, aisle_seat_price_}}, {{4, 'C'}, {0, window_seat_price_}},
		{{5, 'A'}, {0, window_seat_price_}}, {{5, 'B'}, {0, aisle_seat_price_}}, {{5, 'C'}, {0, window_seat_price_}},
		{{6, 'A'}, {0, window_seat_price_}}, {{6, 'B'}, {0, aisle_seat_price_}}, {{6, 'C'}, {0, window_seat_price_}},
		{{7, 'A'}, {0, window_seat_price_}}, {{7, 'B'}, {0, aisle_seat_price_}}, {{7, 'C'}, {0, window_seat_price_}},
		{{8, 'A'}, {0, window_seat_price_}}, {{8, 'B'}, {0, aisle_seat_price_}}, {{8, 'C'}, {0, window_seat_price_}},
		{{9, 'A'}, {0, window_seat_price_}}, {{9, 'B'}, {0, aisle_seat_price_}}, {{9, 'C'}, {0, window_seat_price_}},
		{{10, 'A'}, {0, window_seat_price_}}, {{10, 'B'}, {0, aisle_seat_price_}}, {{10, 'C'}, {0, window_seat_price_}},
		{{11, 'A'}, {0, window_seat_price_}}, {{11, 'B'}, {0, aisle_seat_price_}}, {{11, 'C'}, {0, window_seat_price_}},
		{{12, 'A'}, {0, window_seat_price_}}, {{12, 'B'}, {0, aisle_seat_price_}}, {{12, 'C'}, {0, window_seat_price_}}
	};
	// Overrides base class virtual function, returns pointer to seats_ attribute.
	std::map<std::pair<int, char>, std::pair<int, double>>* get_seats() override;
	// Returns type attribute.
	std::string get_type() override;
	// Returns id_no attribute.
	std::string get_id_no() override;
	// Takes double and assigns it to bus_hire_rate attribute.
	void set_bus_hire_rate(double);
	// Takes double and assigns it to bus_hire_rate_per_mile attribute.
	void set_bus_hire_rate_per_mile(double);
	// Takes double and assigns it to security_deposit.
	void set_security_deposit(double);
	// Returns bus_hire_rate attribute.
	double get_bus_hire_rate() const;
	// Returns bus_hire_rate_per_mile attribute.
	double get_bus_hire_rate_per_mile() const;
	// Returns security_deposit attribute.
	double get_security_deposit() const;
	// Returns capacity attribute.
	int get_capacity() override;
};

class mini_van : public vehicle
{
private:
	// Bus type
	const std::string type_ = "MiniVan";
	// Identification number for the bus
	std::string id_no_ = "0";
	// Rate for window seats_.
	double window_seat_price_ = 0.5;
	// Rate for isle seats_.
	double aisle_seat_price_ = 0.5;
	// Rate for bus hire.
	double bus_hire_rate_ = 1000;
	// Rate for bus hire per mile.
	double bus_hire_rate_per_mile_ = 0.15;
	// Rate for security deposit.
	double security_deposit_ = 1500;
	// Constant capacity for a luxury bus.
	const int capacity_ = 12;
public:
	// Base mini van constructor.
	mini_van();
	// Copy constructor for mini_van
	mini_van(const mini_van& mv);
	// Base constructor that assigns id_no.
	mini_van(std::string);
	// Seats map. <int, char> represents seats_ id(1A 1B 1C) the <int> will be either 0 or 1, representing if the seat is taken(1) or free(0).
	std::map<std::pair<int, char>, std::pair<int, double>> seats{
		{{1, 'A'}, {0, window_seat_price_}}, {{1, 'B'}, {0, aisle_seat_price_}}, {{1, 'C'}, {0, window_seat_price_}},
		{{2, 'A'}, {0, window_seat_price_}}, {{2, 'B'}, {0, aisle_seat_price_}}, {{2, 'C'}, {0, window_seat_price_}},
		{{3, 'A'}, {0, window_seat_price_}}, {{3, 'B'}, {0, aisle_seat_price_}}, {{3, 'C'}, {0, window_seat_price_}},
		{{4, 'A'}, {0, window_seat_price_}}, {{4, 'B'}, {0, aisle_seat_price_}}, {{4, 'C'}, {0, window_seat_price_}}
	};
	// For use by copies of the object, NOT original
	void set_seats(std::map<std::pair<int, char>, std::pair<int, double>> temp);
	// Overrides base class virtual function, returns pointer to seats_ attribute.
	std::map<std::pair<int, char>, std::pair<int, double>>* get_seats() override;
	// Returns type attribute.
	std::string get_type() override;
	// Returns id_no attribute.
	std::string get_id_no() override;
	// Takes double and assigns it to bus_hire_rate attribute.
	void set_bus_hire_rate(double);
	// Takes double and assigns it to bus_hire_rate_per_mile attribute.
	void set_bus_hire_rate_per_mile(double);
	// Takes double and assigns it to security_deposit.
	void set_security_deposit(double);
	// Returns bus_hire_rate attribute.
	double get_bus_hire_rate() const;
	// Returns bus_hire_rate_per_mile attribute.
	double get_bus_hire_rate_per_mile() const;
	// Returns deposit attribute.
	double get_security_deposit() const;
	// Returns capacity attribute.
	int get_capacity() override;
};
