#include "Revenue.h"

#include <iostream>

revenue::revenue()
{
	this->total_amount = 0;
	this->income_by_date = {};
	this->income_by_vehicle = {};
}

void revenue::set_total_amount(double amount)
{
	this->total_amount = amount;
}

void revenue::add_income_by_date(std::string date, double amount)
{
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

void revenue::add_income_by_vehicle(std::string vehicle_id, double amount)
{
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

void revenue::withdrawal_income_by_date(std::string date, double amount)
{
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

void revenue::withdrawal_income_by_vehicle(std::string vehicle_id, double amount)
{
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

double revenue::get_total_amount() const
{
	return this->total_amount;
}

std::map<std::string, double> revenue::get_income_by_date() const
{
	return this->income_by_date;
}

std::map<std::string, double> revenue::get_income_by_vehicle() const
{
	return this->income_by_vehicle;
}
