#pragma once
#include <string>

class DateTime
{
private:
	int year;
	int month;
	int day;
	int hours;
	int minutes;
	int seconds;
public:
	DateTime();
	DateTime(int year, int month, int day, int hours, int minutes, int seconds);
	int differenceDays(DateTime dt);
	void displayDate();
	void getCurrentTime();
	std::string to_string(bool include_time);
};

