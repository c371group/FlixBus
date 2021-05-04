#pragma once
#include <vector>
#include <string>
#include <iomanip>
#include "Vehicle.h"


/**
 * \brief Repository class that holds three vector, one for luxury, mini bus and mini van.
 */
class fleet
{
private:
	// Vector holding luxury bus objects.
	std::vector<luxury_bus> luxury_buses;
	// Vector holding mini bus objects.
	std::vector<mini_bus> mini_buses;
	// Vector holding mini van objects.
	std::vector<mini_van> mini_vans;

public:
	// Base constructor.
	fleet();
	// Takes luxury bus object and adds it to a vector.
	void add_luxury_bus(luxury_bus);
	// Takes mini bus object and adds it to a vector.
	void add_mini_bus(mini_bus);
	// Takes mini van object and adds it to a vector.
	void add_mini_van(mini_van);
	// Returns a reference to a specific object in luxury bus vector, where the object has the same id as the one provided.
	luxury_bus* get_luxury_bus(std::string);
	// Returns a reference to a specific object in mini bus vector, where the object has the same id as the one provided.
	mini_bus* get_mini_bus(std::string);
	// Returns a reference to a specific object in mini van vector, where the object has the same id as the one provided.
	mini_van* get_mini_van(std::string);
	// Returns a count of luxury buses in the vector.
	size_t get_luxury_bus_count();
	// Returns a count of mini buses in the vector.
	size_t get_mini_bus_count();
	// Returns a count of mini vans in the vector.
	size_t get_minivan_count();
	// Displays luxury buses that are in the vector.
	void display_luxury_bus_fleet();
	// Displays mini buses that are in the vector.
	void display_mini_bus_fleet();
	// Displays mini vans that are in the vector.
	void display_mini_van_fleet();
	// Loads vehicle data from a csv file.
	void read_bus_details();
};