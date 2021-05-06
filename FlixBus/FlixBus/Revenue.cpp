#include "Revenue.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>


// Base constructor. Initialize total amount to 0 and creates empty map objects.
revenue::revenue()
{
	this->total_amount = 0;
	this->income_by_date = {};
	this->income_by_vehicle = {};
    read_income_by_date();
    read_income_by_vehicle();
    calculate_income_from_map();
}

// Takes double value and assigns it to total amount attribute.
void revenue::set_total_amount(double amount)
{
	this->total_amount = amount;
}

// Takes string and double. Checks if string(date) already exists, if yes it adds the amount, if no it creates new pair and adds it to the map.
// Date format: month/day/year
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

// Loads data from csv.
int revenue::read_income_by_date() {
    std::ifstream input_from_file("revenueDate.csv");
    std::string line;
    int lineno = 0; //line number
    while (getline(input_from_file, line)) {
        lineno++;
        line += ",";

        std::stringstream ss(line);
        std::string line_;
        std::vector<std::string> lines_;

        while (getline(ss, line_, ','))
            lines_.push_back(line_);
        double amount = std::atof(lines_[1].c_str());
        add_income_by_date(lines_[0], amount);
    }
    return 0;
}

// Loads data from csv.
int revenue::read_income_by_vehicle() {
    std::ifstream input_from_file("revenueVehicle.csv");
    std::string line;
    int lineno = 0; //line number
    while (getline(input_from_file, line)) {
        lineno++;
        line += ",";

        std::stringstream ss(line);
        std::string line_;
        std::vector<std::string> lines_;

        while (getline(ss, line_, ','))
            lines_.push_back(line_);
        double amount = std::atof(lines_[1].c_str());
        add_income_by_vehicle(lines_[0], amount);
    }
    return 0;
}

// Checks if both income by date and vehicle are the same and assigns it to total_income.
void revenue::calculate_income_from_map()
{
    double total_income_by_date = 0;
    double total_income_by_vehicle = 0;
    for (auto const& by_date_ : this->income_by_date)
    {
        total_income_by_date = total_income_by_date + by_date_.second;
    }
    for (auto const& by_vehicle_ : this->income_by_vehicle)
    {
        total_income_by_vehicle = total_income_by_vehicle + by_vehicle_.second;
    }
	if(total_income_by_date == total_income_by_vehicle)
	{
        this->total_amount = total_income_by_date;
	}
}

// Saves income by date to csv.
void revenue::add_income_by_date_to_db(std::string date, double amount) {
    std::ofstream fout;
    fout << std::endl;
    fout.open("revenueDate.csv", std::ios::app);
    fout << date << "," << amount << std::endl;
    fout.close();
}

// Saves income by date to csv.
void revenue::add_income_by_vehicle_to_db(std::string vehicle, double amount) {
    std::ofstream fout;
    fout << std::endl;
    fout.open("revenueVehicle.csv", std::ios::app);
    fout << vehicle << "," << amount << std::endl;
    fout.close();
}