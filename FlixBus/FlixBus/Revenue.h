#pragma once
#include <map>
#include <string>


/**
 * \brief revenue class holds the revenue information about the bus company.
 * There is map that holds data for income by date and by vehicle.
 */
class revenue
{
private:
	// Total amount of income for the bus company.
	double total_amount;
	// Map object hols income by date. String - represents date and double represents the income.
	std::map<std::string, double> income_by_date;
	// Map object holds income by vehicle. String - represents vehicle id and double represents the income.
	std::map<std::string, double> income_by_vehicle;
public:
	// Base constructor.
	revenue();
	// Takes double value and assigns it to total amount attribute.
	void set_total_amount(double);
	// Takes string and double. Checks if string(date) already exists, if yes it adds the amount, if no it creates new pair and adds it to the map.
	void add_income_by_date(std::string, double);
	// Takes string and double. Checks if string(vehicle id) already exists, if yes it adds the amount, if no it creates new pair and adds it to the map.
	void add_income_by_vehicle(std::string, double);
	// Takes string and double. Checks if string(date) already exists, if yes it subtracts the amount, if no it displays message that the date was not found in the records.
	void withdrawal_income_by_date(std::string, double);
	// Takes string and double. Checks if string(vehicle id) already exists, if yes it subtracts the amount, if no it displays message that the vehicle was not found in the records.
	void withdrawal_income_by_vehicle(std::string, double);
	// Returns total_amount attribute.
	double get_total_amount() const;
	// Returns map<std::string, double> income by date attribute.
	std::map<std::string, double> get_income_by_date() const;
	// Returns map<std::string, double> income by vehicle attribute.
	std::map<std::string, double> get_income_by_vehicle() const;
	int read_income_by_date();
	int read_income_by_vehicle();
	void calculate_income_from_map();
	void add_income_by_date_to_db(std::string, double);
	void add_income_by_vehicle_to_db(std::string, double);
};

