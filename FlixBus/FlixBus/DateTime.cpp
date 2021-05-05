#include "DateTime.h"
#include <ctime>
#include <iostream>
#include <string>


// Base constructor.
date_time::date_time()
{
	// current date/time based on current system
	struct tm newtime;
	__time64_t long_time;
	// Get time as 64-bit integer.
	_time64(&long_time);
	// Convert to local time.
	_localtime64_s(&newtime, &long_time);	

	this->year_ = 1900 + newtime.tm_year;
	this->month_ = 1 + newtime.tm_mon;
	this->day_ = newtime.tm_mday;
	this->hours_ = newtime.tm_hour;
	this->minutes_ = newtime.tm_min;
	this->seconds_ = newtime.tm_sec;
}

// Constructor, takes six integer values and assigns them as year, month, day, hours, minutes, seconds
date_time::date_time(int year, int month, int day, int hours, int minutes, int seconds)
{
	if (year > 1000 && year < 3000)
	{
		if (day > 31 || month > 12 || day <= 0 || month <= 0 || year < 0)
		{
			std::cout << month << "/" << day << "/" << year << ": is not valid date!" << std::endl;

		}
		if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
		{
			std::cout << month << "/" << day << "/" << year << ": Feb, April, June, Sep and Nov do not have 31 days!" << std::endl;
			return;
		}
		if (month == 2)
		{
			if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0)
			{
				if (day > 28)
				{
					std::cout << month << "/" << day << "/" << year << ": is a leap year, so FEB can't have more than 28 days!!!" << std::endl;
					return;
				}
			}
			if (day > 29)
			{
				std::cout << month << "/" << day << "/" << year << ": FEB has no more than 29 days!!" << std::endl;
				return;
			}
		}
		this->year_ = year;
		this->month_ = month;
		this->day_ = day;
		this->hours_ = hours;
		this->minutes_ = minutes;
		this->seconds_ = seconds;
	}
	else {
		std::cout << "It is Invalid";
	}
}

// days_from_civil from Chrono
// Returns number of days since civil 1970-01-01.  Negative values indicate
//    days prior to 1970-01-01.
// Preconditions:  y-m-d represents a date in the civil (Gregorian) calendar
//                 m is in [1, 12]
//                 d is in [1, last_day_of_month(y, m)]
//                 y is "approximately" in
//                   [numeric_limits<Int>::min()/366, numeric_limits<Int>::max()/366]
//                 Exact range of validity is:
//                 [civil_from_days(numeric_limits<Int>::min()),
//                  civil_from_days(numeric_limits<Int>::max()-719468)]
template <class Int> constexpr Int days_from_civil(Int y, unsigned m, unsigned d) noexcept
{
	static_assert(std::numeric_limits<unsigned>::digits >= 18,
		"This algorithm has not been ported to a 16 bit unsigned integer");
	static_assert(std::numeric_limits<Int>::digits >= 20,
		"This algorithm has not been ported to a 16 bit signed integer");
	y -= m <= 2;
	const Int era = (y >= 0 ? y : y - 399) / 400;
	const unsigned yoe = static_cast<unsigned>(y - era * 400);      // [0, 399]
	const unsigned doy = (153 * (m + (m > 2 ? -3 : 9)) + 2) / 5 + d - 1;  // [0, 365]
	const unsigned doe = yoe * 365 + yoe / 4 - yoe / 100 + doy;         // [0, 146096]
	return era * 146097 + static_cast<Int>(doe) - 719468;
}

// Compares current object with a given date_time object. Returns difference in dates as integer.
int date_time::difference_days(date_time dt) const
{
	const int difference_in_days = (days_from_civil(this->year_, this->month_, this->day_) - days_from_civil(dt.year_, dt.month_, dt.day_));
	return abs(difference_in_days);
}

// Displaying date
void date_time::display_date()
{
	// If the month, day, hour, minute or second is single digit, it adds 0 in front of it.
	std::string month_ = this->month_ < 10 ? "0" + std::to_string(this->month_) : std::to_string(this->month_);
	std::string day_ = this->day_ < 10 ? "0" + std::to_string(this->day_) : std::to_string(this->day_);
	std::string hour_ = this->hours_ < 10 ? "0" + std::to_string(this->hours_) : std::to_string(this->hours_);
	std::string minute_ = this->minutes_ < 10 ? "0" + std::to_string(this->minutes_) : std::to_string(this->minutes_);
	std::string second_ = this->seconds_ < 10 ? "0" + std::to_string(this->seconds_) : std::to_string(this->seconds_);

	
	std::cout << hour_ << ":" << minute_ << ":" << second_ << " ";
	std::cout << month_ << "/" << day_ <<"/" <<  this->year_ ;
}

// Updates all attributes, assign them to current time and displays the time.
void date_time::get_current_time()
{
	// current date/time based on current system
	struct tm newtime;
	__time64_t long_time;
	// Get time as 64-bit integer.
	_time64(&long_time);
	// Convert to local time.
	_localtime64_s(&newtime, &long_time);

	this->year_ = 1900 + newtime.tm_year;
	this->month_ = 1 + newtime.tm_mon;
	this->day_ = newtime.tm_mday;
	this->hours_ = newtime.tm_hour;
	this->minutes_ = newtime.tm_min;
	this->seconds_ = newtime.tm_sec;
	this->display_date();
}

// Returns year attribute.
int date_time::get_year()
{
	return this->year_;
}

// Returns month attribute.
int date_time::get_month()
{
	return this->month_;
}

// Returns day attribute.
int date_time::get_day()
{
	return this->day_;
}

// Returns hours attribute.
int date_time::get_hour()
{
	return this->hours_;
}

// Returns minutes attribute.
int date_time::get_minute()
{
	return this->minutes_;
}

// Returns seconds attribute.
int date_time::get_seconds()
{
	return this->seconds_;
}

// Returns string representation of the date. Takes boolean, if set to false it will only display the date, without the time.
std::string date_time::to_string(bool include_time) const
{
	std::string string_date;
	std::string month_ = this->month_ < 10 ? "0" + std::to_string(this->month_) : std::to_string(this->month_);
	std::string day_ = this->day_ < 10 ? "0" + std::to_string(this->day_) : std::to_string(this->day_);
	std::string hour_ = this->hours_ < 10 ? "0" + std::to_string(this->hours_) : std::to_string(this->hours_);
	std::string minute_ = this->minutes_ < 10 ? "0" + std::to_string(this->minutes_) : std::to_string(this->minutes_);
	std::string second_ = this->seconds_ < 10 ? "0" + std::to_string(this->seconds_) : std::to_string(this->seconds_);
	
	if(include_time)
	{
		string_date = hour_ + ":" + minute_ + ":" + second_ + " " + month_ + "/" + day_ + "/" + std::to_string(this->year_);
	}
	else
	{
		string_date = month_ + "/" + day_ + "/" + std::to_string(this->year_);
	}
	
	return string_date;
}

// Comares given date_time object to the current one.
bool date_time::compare_to_date(date_time dt)
{
	if (this->year_ == dt.get_year() && this->month_ == dt.get_month() && this->day_ == dt.get_day() && this->hours_ ==
		dt.get_hour() && this->minutes_ == dt.get_minute() && this->seconds_ == dt.get_seconds())
	{
		return true;
	}
	return false;
}