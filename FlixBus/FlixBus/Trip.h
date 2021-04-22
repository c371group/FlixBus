#include "Route.h"
#include "Vehicle.h"
#include "DateTime.h"

#pragma once
class Trip
{
private:
	bool bookable;
	route route_;
	fleet* busFleet = nullptr;
	DateTime departure;
	DateTime estimatedArrival;
public:
	Trip();
	Trip(route);
	
	void set_Bookable(bool);
	void set_route_(route);
	void set_departureDT(DateTime);
	void set_estArrivalDT(DateTime);
	void set_fleet(fleet*);

	bool getBookable();
	route getRoute();
	DateTime getDepartureDT();
	DateTime getEstArrivalDT();
	fleet* get_fleet();
};

