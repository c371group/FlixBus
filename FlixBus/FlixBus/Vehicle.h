#pragma once
#include <string>
#include <map>


class vehicle
{
private:
	int id_no = 0; //unique identifier for bus
	std::string type = "Base";
	int capacity = 0; //how many seats-- this is implicitly linked to type.
	int rate_per_mile = 0;
	/* again, implicitly linked to type. While it's in decimal numbers, it's best to put it in integers (i.e. 0.16 per mile
	   being stored 16 pennies per mile so we can avoid double and float shenanigans */
	std::map<std::pair<int, char>, std::pair<int, double>> seats{};

	//potentially want to have an attribute of an array of bus drivers who drive said bus | ???????? what bus drivers?

public:
	vehicle();
	explicit vehicle(std::string val);
	vehicle(int, std::string);
	void set_id_no(int);
	void set_type(std::string);
	void set_capacity(int);
	void set_rate_per_mile(int);

	int set_values_from_type(std::string val);

	int get_id_no();
	virtual std::string get_type();
	int get_capacity();
	int get_rate_per_mile();

	// Displaying all seats
	void displaySeats();
	// Displaying taken seats as 'X'.
	void displayFreeSeats();
	// Takes Int and Char, combines them to a seat id and reserves that seat. ( sets the second <int> to 1).
	void reserveSeat(int row, char column);
	// Takes Int and Char, combines them to a seat id and cancels the reservation (sets the second <int> to 0).
	void cancelSeat(int row, char column);
	virtual std::map<std::pair<int, char>, std::pair<int, double>>* get_seats() = 0;
};


class luxaryBus : public vehicle
{
private:
	std::string type = "Luxary Bus";
	int id_no = 0; //unique identifier for bus
	const double windowSeatRate = 0.95;
	const double aisleSeatRate = 0.75;
public:
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

	std::map<std::pair<int, char>, std::pair<int, double>>* get_seats();
	std::string get_type();
};


class miniBus : public vehicle
{
private:
	std::string type = "Mini Bus";
	int id_no = 0; //unique identifier for bus
	const double windowSeatPrice = 0.65;
	const double aisleSeatPrice = 0.65;
public:
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

	std::map<std::pair<int, char>, std::pair<int, double>>* get_seats();
	std::string get_type();
};


class miniVan : public vehicle
{
private:
	std::string type = "MiniVan";
	int id_no = 0; //unique identifier for bus
	const double windowSeatPrice = 0.5;
	const double aisleSeatPrice = 0.5;
public:
	// Seats map. <int, char> represents seats id(1A 1B 1C) the <int> will be either 0 or 1, representing if the seat is taken(1) or free(0).
	std::map<std::pair<int, char>, std::pair<int, double>> seats{
		{{1, 'A'}, {0, windowSeatPrice}}, {{1, 'B'}, {0, aisleSeatPrice}}, {{1, 'C'}, {0, windowSeatPrice}},
		{{2, 'A'}, {0, windowSeatPrice}}, {{2, 'B'}, {0, aisleSeatPrice}}, {{2, 'C'}, {0, windowSeatPrice}},
		{{3, 'A'}, {0, windowSeatPrice}}, {{3, 'B'}, {0, aisleSeatPrice}}, {{3, 'C'}, {0, windowSeatPrice}},
		{{4, 'A'}, {0, windowSeatPrice}}, {{4, 'B'}, {0, aisleSeatPrice}}, {{4, 'C'}, {0, windowSeatPrice}}
	};

	std::map<std::pair<int, char>, std::pair<int, double>>* get_seats();
	std::string get_type();
};
