#pragma once
#include <string>


/**
 * \brief date time class used to determine time for tickets and trips.
 */
class date_time
{
private:
	// Year attribute.
	int year_;
	// Month attribute.
	int month_;
	// Day attribute.
	int day_;
	// Hours attribute.
	int hours_;
	// Minutes attribute.
	int minutes_;
	// Seconds attribute.
	int seconds_;
public:
	// Base constructor.
	date_time();
	// Constructor, takes six integer values and assigns them as year, month, day, hours, minutes, seconds
	date_time(int year, int month, int day, int hours, int minutes, int seconds);
	// Compares current object with a given date_time object. Returns difference in dates as integer.
	int difference_days(date_time dt) const;
	// Displaying date
	void display_date();
	// Updates all attributes, assign them to current time and displays the time.
	void get_current_time();
	// Returns year attribute.
	int get_year();
	// Returns month attribute.
	int get_month();
	// Returns day attribute.
	int get_day();
	// Returns hours attribute.
	int get_hour();
	// Returns minutes attribute.
	int get_minute();
	// Returns seconds attribute.
	int get_seconds();
	// Returns string representation of the date. Takes boolean, if set to false it will only display the date, without the time.
	std::string to_string(bool include_time) const;
	// Compare two dates and returns true or false if they are the same date.
	bool compare_to_date(date_time);
};

