#pragma once
#include <string>
#include <map>
#include <iostream>

class vehicle
{
private:
	std::string id_no;
	const std::string type = "Base";
	int capacity = 0; //how many seats-- this is implicitly linked to type.
	std::map<std::pair<int, char>, std::pair<int, double>> seats{};
public:
	virtual ~vehicle() = default;
	vehicle();
	explicit vehicle(std::string);
	void set_id_no(std::string);
	void set_capacity(int);

	virtual std::string get_id_no();
	virtual std::string get_type();
	virtual int get_capacity();
	int get_all_seats_count();
	int get_free_seats_count();

	// Displaying all seats
	void displaySeats();
	// Displaying taken seats as 'X'.
	void displayFreeSeats();
	// Reserve all seats
	void reserveAllSeats();
	// Takes Int and Char, combines them to a seat id and reserves that seat. ( sets the second <int> to 1).
	bool reserveSeat(int row, char column);
	// Check if available for hire.
	virtual bool can_hire();
	// Takes Int and Char, combines them to a seat id and cancels the reservation (sets the second <int> to 0).
	bool cancelSeat(int row, char column);
	double getSeatRate(int row, char column);
	virtual std::map<std::pair<int, char>, std::pair<int, double>>* get_seats() = 0;
};

class luxuryBus : public vehicle
{
private:
	const std::string type = "Luxury Bus";
	std::string id_no = "0"; //unique identifier for bus
	const double windowSeatRate = 0.95;
	const double aisleSeatRate = 0.75;
	const double busHireRate = 1500;
	const double busHireRatePerMile = 0.25;
	const double securityDeposit = 5000;
	const int capacity = 52;
public:
	luxuryBus();
	explicit luxuryBus(std::string);
	// Seats map. <int, char> represents seats id(1A 1B 1C) the <int> will be either 0 or 1, representing if the seat is taken(1) or free(0).
	std::map<std::pair<int, char>, std::pair<int, double>> seats{
		{{1, 'A'}, {0, windowSeatRate}}, {{1, 'B'}, {0, aisleSeatRate}}, {{1, 'C'}, {0, aisleSeatRate}},
		{{1, 'D'}, {0, aisleSeatRate}}, {{1, 'E'}, {0, windowSeatRate}},
		{{2, 'A'}, {0, windowSeatRate}}, {{2, 'B'}, {0, aisleSeatRate}}, {{2, 'C'}, {0, aisleSeatRate}},
		{{2, 'D'}, {0, aisleSeatRate}}, {{2, 'E'}, {0, windowSeatRate}},
		{{3, 'A'}, {0, windowSeatRate}}, {{3, 'B'}, {0, aisleSeatRate}}, {{3, 'C'}, {0, aisleSeatRate}},
		{{3, 'D'}, {0, aisleSeatRate}}, {{3, 'E'}, {0, windowSeatRate}},
		{{4, 'A'}, {0, windowSeatRate}}, {{4, 'B'}, {0, aisleSeatRate}}, {{4, 'C'}, {0, aisleSeatRate}},
		{{4, 'D'}, {0, aisleSeatRate}}, {{4, 'E'}, {0, windowSeatRate}},
		{{5, 'A'}, {0, windowSeatRate}}, {{5, 'B'}, {0, aisleSeatRate}}, {{5, 'C'}, {0, aisleSeatRate}},
		{{5, 'D'}, {0, aisleSeatRate}}, {{5, 'E'}, {0, windowSeatRate}},
		{{6, 'A'}, {0, windowSeatRate}}, {{6, 'B'}, {0, aisleSeatRate}}, {{6, 'C'}, {0, aisleSeatRate}},
		{{6, 'D'}, {0, aisleSeatRate}}, {{6, 'E'}, {0, windowSeatRate}},
		{{7, 'A'}, {0, windowSeatRate}}, {{7, 'B'}, {0, aisleSeatRate}}, {{7, 'C'}, {0, aisleSeatRate}},
		{{7, 'D'}, {0, aisleSeatRate}}, {{7, 'E'}, {0, windowSeatRate}},
		{{8, 'A'}, {0, windowSeatRate}}, {{8, 'B'}, {0, aisleSeatRate}}, {{8, 'C'}, {0, aisleSeatRate}},
		{{8, 'D'}, {0, aisleSeatRate}}, {{8, 'E'}, {0, windowSeatRate}},
		{{9, 'A'}, {0, windowSeatRate}}, {{9, 'B'}, {0, aisleSeatRate}}, {{9, 'C'}, {0, aisleSeatRate}},
		{{9, 'D'}, {0, aisleSeatRate}}, {{9, 'E'}, {0, windowSeatRate}},
		{{10, 'A'}, {0, windowSeatRate}}, {{10, 'B'}, {0, aisleSeatRate}}, {{10, 'C'}, {0, aisleSeatRate}},
		{{10, 'D'}, {0, aisleSeatRate}}, {{10, 'E'}, {0, windowSeatRate}},
		{{11, 'A'}, {0, windowSeatRate}}, {{11, 'B'}, {0, aisleSeatRate}}
	};

	std::map<std::pair<int, char>, std::pair<int, double>>* get_seats() override;
	std::string get_type() override;
	std::string get_id_no() override;
	double getBusHireRate() const;
	double getBusHireRatePerMile() const;
	double getSecurityDeposit() const;
	int get_capacity() override;
};

class miniBus : public vehicle
{
private:
	const std::string type = "Mini Bus";
	std::string id_no = "0"; //unique identifier for bus
	const double windowSeatPrice = 0.65;
	const double aisleSeatPrice = 0.65;
	const double busHireRate = 1300;
	const double busHireRatePerMile = 0.2;
	const double securityDeposit = 3000;
	const int capacity = 36;
public:
	miniBus();
	miniBus(std::string);
	// Seats map. <int, char> represents seats id(1A 1B 1C) the <int> will be either 0 or 1, representing if the seat is taken(1) or free(0).
	std::map<std::pair<int, char>, std::pair<int, double>> seats{
		{{1, 'A'}, {0, windowSeatPrice}}, {{1, 'B'}, {0, aisleSeatPrice}}, {{1, 'C'}, {0, windowSeatPrice}},
		{{2, 'A'}, {0, windowSeatPrice}}, {{2, 'B'}, {0, aisleSeatPrice}}, {{2, 'C'}, {0, windowSeatPrice}},
		{{3, 'A'}, {0, windowSeatPrice}}, {{3, 'B'}, {0, aisleSeatPrice}}, {{3, 'C'}, {0, windowSeatPrice}},
		{{4, 'A'}, {0, windowSeatPrice}}, {{4, 'B'}, {0, aisleSeatPrice}}, {{4, 'C'}, {0, windowSeatPrice}},
		{{5, 'A'}, {0, windowSeatPrice}}, {{5, 'B'}, {0, aisleSeatPrice}}, {{5, 'C'}, {0, windowSeatPrice}},
		{{6, 'A'}, {0, windowSeatPrice}}, {{6, 'B'}, {0, aisleSeatPrice}}, {{6, 'C'}, {0, windowSeatPrice}},
		{{7, 'A'}, {0, windowSeatPrice}}, {{7, 'B'}, {0, aisleSeatPrice}}, {{7, 'C'}, {0, windowSeatPrice}},
		{{8, 'A'}, {0, windowSeatPrice}}, {{8, 'B'}, {0, aisleSeatPrice}}, {{8, 'C'}, {0, windowSeatPrice}},
		{{9, 'A'}, {0, windowSeatPrice}}, {{9, 'B'}, {0, aisleSeatPrice}}, {{9, 'C'}, {0, windowSeatPrice}},
		{{10, 'A'}, {0, windowSeatPrice}}, {{10, 'B'}, {0, aisleSeatPrice}}, {{10, 'C'}, {0, windowSeatPrice}},
		{{11, 'A'}, {0, windowSeatPrice}}, {{11, 'B'}, {0, aisleSeatPrice}}, {{11, 'C'}, {0, windowSeatPrice}},
		{{12, 'A'}, {0, windowSeatPrice}}, {{12, 'B'}, {0, aisleSeatPrice}}, {{12, 'C'}, {0, windowSeatPrice}}
	};
	std::map<std::pair<int, char>, std::pair<int, double>>* get_seats() override;
	std::string get_type() override;
	std::string get_id_no() override;
	double getBusHireRate() const;
	double getBusHireRatePerMile() const;
	double getSecurityDeposit() const;
	int get_capacity() override;
};

class miniVan : public vehicle
{
private:
	const std::string type = "MiniVan";
	std::string id_no = "0"; //unique identifier for bus -- ex. MV002
	const double windowSeatPrice = 0.5;
	const double aisleSeatPrice = 0.5;
	const double busHireRate = 1000;
	const double busHireRatePerMile = 0.15;
	const double securityDeposit = 1500;
	const int capacity = 12;
public:

	miniVan();
	miniVan(const miniVan& mv);
	miniVan(std::string);
	// Seats map. <int, char> represents seats id(1A 1B 1C) the <int> will be either 0 or 1, representing if the seat is taken(1) or free(0).
	std::map<std::pair<int, char>, std::pair<int, double>> seats{
		{{1, 'A'}, {0, windowSeatPrice}}, {{1, 'B'}, {0, aisleSeatPrice}}, {{1, 'C'}, {0, windowSeatPrice}},
		{{2, 'A'}, {0, windowSeatPrice}}, {{2, 'B'}, {0, aisleSeatPrice}}, {{2, 'C'}, {0, windowSeatPrice}},
		{{3, 'A'}, {0, windowSeatPrice}}, {{3, 'B'}, {0, aisleSeatPrice}}, {{3, 'C'}, {0, windowSeatPrice}},
		{{4, 'A'}, {0, windowSeatPrice}}, {{4, 'B'}, {0, aisleSeatPrice}}, {{4, 'C'}, {0, windowSeatPrice}}
	};
	void set_seats(std::map<std::pair<int, char>, std::pair<int, double>> temp);
	std::map<std::pair<int, char>, std::pair<int, double>>* get_seats() override;
	std::string get_type() override;
	std::string get_id_no() override;
	double getBusHireRate() const;
	double getBusHireRatePerMile() const;
	double getSecurityDeposit() const;
	int get_capacity() override;
};
