#include "Route.h"
#include "Vehicle.h"
#include "DateTime.h"

#pragma once
class Trip
{
private:
	bool bookable;
	route* route_ = nullptr;
	fleet* busFleet = nullptr;
	DateTime departure;
	DateTime estimatedArrival;
	std::string busType; //just for testing
public:
	Trip();
	Trip(route*, DateTime, DateTime);
	
	void set_Bookable(bool);
	void set_route_(route*);
	void set_departureDT(DateTime);
	void set_estArrivalDT(DateTime);
	void set_fleet(fleet*);
	void set_busType(std::string);

	bool getBookable();
	route* getRoute();
	DateTime getDepartureDT();
	DateTime getEstArrivalDT();
	fleet* get_fleet();
	std::string get_type();
};

