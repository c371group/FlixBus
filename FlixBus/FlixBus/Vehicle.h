#pragma once
#include <string>


class vehicle {
private:
	int id_no_ = 666; //unique identifier for bus
	std::string type_ = "MiniVan";
	int capacity_= 0; //how many seats-- this is implicitly linked to type.
	
	int rate_per_mile_ = 0; /* again, implicitly linked to type. While it's in decimal numbers, it's best to put it in integers (i.e. 0.16 per mile
	being stored 16 pennies per mile so we can avoid double and float shenanigans */

	//potentially want to have an attribute of an array of bus drivers who drive said bus
public:
	vehicle();
	explicit vehicle(std::string val);
	vehicle(int, std::string);
	void set_id_no(int);
	void set_type(std::string);
	void set_capacity(int);
	void set_rate_per_mile(int);
	
	int set_values_from_type(std::string val);

	int get_id_no();
	std::string get_type();
	int get_capacity();
	int get_rate_per_mile();
	
};
