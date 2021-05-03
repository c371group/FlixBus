#pragma once
#include <map>
#include <string>

#include "DateTime.h"

class revenue
{
private:
	double total_amount;
	std::map<std::string, double> income_by_date;
	std::map<std::string, double> income_by_vehicle;
public:
	revenue();
	void set_total_amount(double);
	void add_income_by_date(std::string, double);
	void add_income_by_vehicle(std::string, double);
	void withdrawal_income_by_date(std::string, double);
	void withdrawal_income_by_vehicle(std::string, double);

	double get_total_amount() const;
	std::map<std::string, double> get_income_by_date() const;
	std::map<std::string, double> get_income_by_vehicle() const;
	
};

