#include "Revenue.h"
#include <iostream>


// Base constructor. Initialize total amout to 0 and creates empy map objects.
revenue::revenue()
{
	this->total_amount = 0;
	this->income_by_date = {};
	this->income_by_vehicle = {};
}

// Takes double value and assigns it to total amount attribute.
void revenue::set_total_amount(double amount)
{
	this->total_amount = amount;
}

// Takes string and double. Checks if string(date) already exists, if yes it adds the amount, if no it creates new pair and adds it to the map.
void revenue::add_income_by_date(std::string date, double amount)
{
	// Creates iterator.
    std::map<std::string, double>::iterator it;
    it = this->income_by_date.find(date);
    // Check if element exists in map or not
    if (it != this->income_by_date.end()) {
        // Access the value from iterator
        it->second = it->second + amount;
        
        std::cout << "\n$" << amount << " added to the revenue." << std::endl;
    }
    else {
        std::cout << "Adding amount of $" << amount << " for date " << date <<std::endl;
        this->income_by_date.insert(std::pair<std::string, double>(date, amount));
    }
}

// Takes string and double. Checks if string(vehicle id) already exists, if yes it adds the amount, if no it creates new pair and adds it to the map.
void revenue::add_income_by_vehicle(std::string vehicle_id, double amount)
{
    // Creates iterator.
    std::map<std::string, double>::iterator it;
    it = this->income_by_vehicle.find(vehicle_id);
    // Check if element exists in map or not
    if (it != this->income_by_vehicle.end()) {
        // Access the value from iterator
        it->second = it->second + amount;

        std::cout << "\n$" << amount << " added to the revenue." << std::endl;
    }
    else {
        std::cout << "Adding amount of $" << amount << " for vehicle " << vehicle_id << std::endl;
        this->income_by_vehicle.insert(std::pair<std::string, double>(vehicle_id, amount));
    }
}

// Takes string and double. Checks if string(date) already exists, if yes it subtracts the amount, if no it displays message that the date was not found in the records.
void revenue::withdrawal_income_by_date(std::string date, double amount)
{
    // Creates iterator.
    std::map<std::string, double>::iterator it;
    it = this->income_by_date.find(date);
    // Check if element exists in map or not
    if (it != this->income_by_date.end()) {
        // Access the value from iterator
        it->second = it->second - amount;

        std::cout << "\n$" << amount << " withdrawal from the revenue." << std::endl;
    }
    else {
        std::cout << "Revenue for date " << date << "was not found!" << std::endl;
    }
}

// Takes string and double. Checks if string(vehicle id) already exists, if yes it subtracts the amount, if no it displays message that the vehicle was not found in the records.
void revenue::withdrawal_income_by_vehicle(std::string vehicle_id, double amount)
{
    // Creates iterator.
    std::map<std::string, double>::iterator it;
    it = this->income_by_vehicle.find(vehicle_id);
    // Check if element exists in map or not
    if (it != this->income_by_vehicle.end()) {
        // Access the value from iterator
        it->second = it->second - amount;

        std::cout << "\n$" << amount << " withdrawal from the revenue." << std::endl;
    }
    else {
        std::cout << "Revenue for vehicle " << vehicle_id << "was not found!" << std::endl;
    }
}

// Returns total_amount attribute.
double revenue::get_total_amount() const
{
	return this->total_amount;
}

// Returns map<std::string, double> income by date attribute.
std::map<std::string, double> revenue::get_income_by_date() const
{
	return this->income_by_date;
}

// Returns map<std::string, double> income by vehicle attribute.
std::map<std::string, double> revenue::get_income_by_vehicle() const
{
	return this->income_by_vehicle;
}