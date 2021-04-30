#include "Vehicle.h"
#include "DateTime.h"

#pragma once
class Trip
{
private:
	bool bookable;
	//route* route_ = nullptr;
	//fleet* busFleet;
	vehicle* bus_;
	DateTime departure;
	DateTime estimatedArrival;
	std::string busType; //just for testing
public:
	Trip();
	Trip(DateTime, DateTime, vehicle*);
	
	void set_Bookable(bool);
	//void set_route_(route*);
	void set_departureDT(DateTime);
	void set_estArrivalDT(DateTime);
	void set_bus(vehicle*);
	//void set_fleet(fleet*);
	void set_busType(std::string);

	bool getBookable();
	//route* getRoute();
	vehicle* get_bus();
	DateTime getDepartureDT();
	DateTime getEstArrivalDT();
	//fleet* get_fleet();
	std::string get_type();
};

