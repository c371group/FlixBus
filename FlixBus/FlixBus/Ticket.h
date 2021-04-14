#pragma once
#include <string>
#include <vector>
#include "Route.h"
#include "Vehicle.h"


class ticket {
private:
	//should have attribute for date and time booked to potentially compare to time and date of route departure versus cancellation date and time
	std::string ticket_id_ = "DEFAULT";
	bool active_ = true; //active or cancelled ticket
	route route_;
	vehicle* bus_; // might change this, but we'll want to still somehow associate the ticket with that particular bus
	//TODO: CREATE SEAT CLASS TO IMPLEMENT IT HERE
	std::vector<std::pair<int, char>> seats;
	//TODO: CREATE TRIP CLASS TO IMPLEMENT IT HERE
	int cost_; //cost of ticket-- want to do this as int! | Trifon: Why ????????
	std::string travel_date_; //TODO: might want to do this as a time struct object instead

public:
	ticket();
	ticket(route, vehicle*);
	void set_active(bool);
	void set_route(route);
	void set_cost(int);
	void set_ticket_id(std::string);
	void set_bus(vehicle*);
	void set_travel_date(std::string);
	void add_seat(int row, char column);

	bool get_active();
	route get_route();
	int get_cost();
	std::string get_ticket_id();
	vehicle* get_bus();
	std::string get_travel_date();
};
