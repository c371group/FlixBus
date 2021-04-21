#include "Route.h"
#include "Vehicle.h"
#include "DateTime.h"

#pragma once
class Trip
{
private:
	bool bookable;
	route route_;
	//vehicle bus;
	DateTime departure;
	DateTime estimatedArrival;
public:
	Trip();
	Trip(route);
	
	void set_Bookable(bool);
	void set_route_(route);
	void set_departureDT(DateTime);
	void set_estArrivalDT(DateTime);

	bool getBookable();
	route getRoute();
	DateTime getDepartureDT();
	DateTime getEstArrivalDT();
};

