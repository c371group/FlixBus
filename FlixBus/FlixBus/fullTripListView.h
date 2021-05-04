#pragma once
#include "interfaceView.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>


/**
 * \brief fullTripListView fullTripListView displays all trips from a csv file.
 */
class fullTripListView :
	public interfaceView //not sure if it actually NEEDS to be interfaceView right now, but prepping just in case for future.
{
public:
	// Base constructor.
	fullTripListView();
	fullTripListView(bool);
	int read_full_list();
};
