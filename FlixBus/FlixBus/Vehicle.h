#pragma once
#include <string>
#include <map>


class vehicle {
private:
	int id_no_ = 0; //unique identifier for bus
	std::string type_ = "Base";
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

class luxaryBus : public vehicle {
private:
	std::string type_ = "Luxary Bus";
public:
	std::map<std::pair<int, char>, int> seats{ {{1,'A'},0 }, {{1,'B'},0 }, {{ 1,'C' }, 0}, {{ 1,'D' }, 0 }, {{ 1,'E' }, 0 },
		{{2,'A'},0 }, {{2,'B'},0 }, {{ 2,'C' }, 0}, {{ 2,'D' }, 0 }, {{ 2,'E' }, 0 },
		{{3,'A'},0 }, {{3,'B'},0 }, {{ 3,'C' }, 0}, {{ 3,'D' }, 0 }, {{ 3,'E' }, 0 },
		{{4,'A'},0 }, {{4,'B'},0 }, {{ 4,'C' }, 0}, {{ 4,'D' }, 0 }, {{ 4,'E' }, 0 },
		{{5,'A'},0 }, {{5,'B'},0 }, {{ 5,'C' }, 0}, {{ 5,'D' }, 0 }, {{ 5,'E' }, 0 },
		{{6,'A'},0 }, {{6,'B'},0 }, {{ 6,'C' }, 0}, {{ 6,'D' }, 0 }, {{ 6,'E' }, 0 },
		{{7,'A'},0 }, {{7,'B'},0 }, {{ 7,'C' }, 0}, {{ 7,'D' }, 0 }, {{ 7,'E' }, 0 },
		{{8,'A'},0 }, {{8,'B'},0 }, {{ 8,'C' }, 0}, {{ 8,'D' }, 0 }, {{ 8,'E' }, 0 },
		{{9,'A'},0 }, {{9,'B'},0 }, {{ 9,'C' }, 0}, {{ 9,'D' }, 0 }, {{ 9,'E' }, 0 },
		{{10,'A'},0 }, {{10,'B'},0 }, {{ 10,'C' }, 0}, {{ 10,'D' }, 0 }, {{ 10,'E' }, 0 },
		{{11,'A'},0 }, {{11,'B'},0 }};

	void displaySeats();
	void displayFreeSeats();
	void reserveSeat(int row, char column);
	void cancelSeat(int row, char column);
};
class smallBus : public vehicle {
private:
	std::string type_ = "Small Bus";
public:
	//std::map<std::string, int> seats{ {"CPU", 10}, {"GPU", 15}, {"RAM", 20}, };
	
	void displaySeats();
};
class miniBus : public vehicle {
private:
	std::string type_ = "Minivan";
public:
	//std::map<std::string, int> seats{ {"CPU", 10}, {"GPU", 15}, {"RAM", 20}, };
	
	void displaySeats();
};