#pragma once
#include <string>
#include "Route.h"
#include "DateTime.h"
#include "trip.h"

class ticket
{
private:
	//should have attribute for date and time booked to potentially compare to time and date of route departure versus cancellation date and time
	std::string ticket_id_ = "DEFAULT";
	std::pair<int, char> seat_number_;
	bool active_ = false; //active or cancelled ticket
	route* route_;
	//vehicle* bus_;
	Trip * trip_;
	//TODO: CREATE TRIP CLASS TO IMPLEMENT IT HERE
	double cost_ = 0; //cost of ticket-- want to do this as int!
	DateTime travel_date;

public:
	ticket();
	ticket(route*,Trip*);
	void set_active(bool);
	void set_route(route*);
	void set_cost(double);
	void set_trip(Trip*);
	void set_ticket_id(std::string);
	void set_travel_date(DateTime);
	void set_seat(int row, char column);
	bool reserve_seat(int row, char column);
	bool cancel_seat();
	//void set_bus(vehicle*);
	bool get_active();
	route* get_route();
	double get_cost();
	Trip* get_trip();
	std::string get_ticket_id();
	//vehicle* get_bus();
	DateTime get_travel_date();
	std::string get_seat_number();
};
