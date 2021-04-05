#pragma once

#include <iostream>

class trip
{
private:
	int tripID_ = 751;
	int vehicleNo_ = 666;
	int routeNo_ = 137;
	std::string departureDate_ = "4/1/2021";
	int departureTime_ = 163000;
public:
	int getTripNo();
	int getRouteNo();
	int getDepartureTime();
	std::string getDepartureDate();
	std::string getBusType();
	bool isFull();
	float getPctFull();
};

