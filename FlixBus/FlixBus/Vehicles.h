#include <string>

using namespace std;


class Vehicles{
public:
	int idNo; //unique identifier for bus
	string type;
	int capacity; //how many seats-- this is implicitly linked to type.
	int ratePerMile; /* again, implicitly linked to type. While it's in decimal numbers, it's best to put it in integers (i.e. 0.16 per mile
	being stored 16 pennies per mile so we can avoid double and float shenanigans */
	int count;
	int seats; // FIXME: maybe we can use arrays?
	//I don't think that will be necessary, I think we can potentially make a Seat class, assigning bus number, row and column, and boolean
	//saying if its currently booked or not
	//i think we CAN make an array of that object though


	//potentially want to have an attribute of an array of bus drivers who drive said bus
};
