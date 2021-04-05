#include "trip.h"
#include <iostream>

using namespace std;

int trip::getTripNo() {
	return tripID_;
}

int trip::getRouteNo() {
	return routeNo_;
}

int trip::getDepartureTime() {
	return departureTime_;
}

std::string trip::getDepartureDate() {
	return departureDate_;
}

