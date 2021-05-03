#include "DateTime.h"
#include <ctime>
#include <iostream>
#include <string>

DateTime::DateTime()
{
	// current date/time based on current system
	struct tm newtime;
	__time64_t long_time;
	// Get time as 64-bit integer.
	_time64(&long_time);
	// Convert to local time.
	_localtime64_s(&newtime, &long_time);	

	this->year = 1900 + newtime.tm_year;
	this->month = 1 + newtime.tm_mon;
	this->day = newtime.tm_mday;
	this->hours = newtime.tm_hour;
	this->minutes = newtime.tm_min;
	this->seconds = newtime.tm_sec;
}

DateTime::DateTime(int year, int month, int day, int hours, int minutes, int seconds)
{
	if (year > 1000 && year < 3000)
	{
		if (day > 31 || month > 12 || day <= 0 || month <= 0 || year < 0)
		{
			std::cout << month << "/" << day << "/" << year << ": is not valid date!" << std::endl;

		}
		if (this->day == 31 && (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11))
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
		this->year = year;
		this->month = month;
		this->day = day;
		this->hours = hours;
		this->minutes = minutes;
		this->seconds = seconds;
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

int DateTime::differenceDays(DateTime dt)
{
	int differenceInDays = (days_from_civil(this->year, this->month, this->day) - days_from_civil(dt.year, dt.month, dt.day));
	return abs(differenceInDays);
}

void DateTime::displayDate()
{
	std::string month_ = this->month < 10 ? "0" + std::to_string(this->month) : std::to_string(this->month);
	std::string day_ = this->day < 10 ? "0" + std::to_string(this->day) : std::to_string(this->day);
	std::string hour_ = this->hours < 10 ? "0" + std::to_string(this->hours) : std::to_string(this->hours);
	std::string minute_ = this->minutes < 10 ? "0" + std::to_string(this->minutes) : std::to_string(this->minutes);
	std::string second_ = this->seconds < 10 ? "0" + std::to_string(this->seconds) : std::to_string(this->seconds);

	std::cout << this->year << "/" << month_ << "/" << day_ << " ";
	std::cout << hour_ << ":" << minute_ << ":" << second_;
}

void DateTime::getCurrentTime()
{
	// current date/time based on current system
	struct tm newtime;
	__time64_t long_time;
	// Get time as 64-bit integer.
	_time64(&long_time);
	// Convert to local time.
	_localtime64_s(&newtime, &long_time);

	this->year = 1900 + newtime.tm_year;
	this->month = 1 + newtime.tm_mon;
	this->day = newtime.tm_mday;
	this->hours = newtime.tm_hour;
	this->minutes = newtime.tm_min;
	this->seconds = newtime.tm_sec;
	this->displayDate();
}

std::string DateTime::to_string(bool include_time)
{
	std::string string_date;
	std::string month_ = this->month < 10 ? "0" + std::to_string(this->month) : std::to_string(this->month);
	std::string day_ = this->day < 10 ? "0" + std::to_string(this->day) : std::to_string(this->day);
	std::string hour_ = this->hours < 10 ? "0" + std::to_string(this->hours) : std::to_string(this->hours);
	std::string minute_ = this->minutes < 10 ? "0" + std::to_string(this->minutes) : std::to_string(this->minutes);
	std::string second_ = this->seconds < 10 ? "0" + std::to_string(this->seconds) : std::to_string(this->seconds);
	
	if(include_time)
	{
		string_date = std::to_string(this->year) + "/" + month_ + "/" + day_ + " " + hour_ + ":" + minute_ + ":" + second_;
	}
	else
	{
		string_date = std::to_string(this->year) + "/" + month_ + "/" + day_;
	}
	
	return string_date;
}
