#include <string>
#include "Route.h"

using namespace std;


class Ticket{
public:
	//should have attribute for date and time booked to potentially compare to time and date of route departure versus cancellation date and time
	Customer customer;
	bool active; //active or cancelled ticket
	Route route;
	int cost; //cost of ticket-- want to do this as int!
};