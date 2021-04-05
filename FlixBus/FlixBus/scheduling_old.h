#pragma once

#include <iostream>

#ifndef SCHEDULING_H
#define SCHEDULING_H

class trip_old {
private:
	int tripID_ = 751;
	std::string busType_ = "MiniVan";
	int routeNo_ = 137;
	std::string departureDate_ = "4/1/2021";
	int departureTime_ = 163000;
public:
	void setBusType(std::string newType);


};

#endif