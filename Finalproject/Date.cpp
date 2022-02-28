/*AKATON C++ munhe atzamim. names: Shaked Asido, 315853150. Shmuel malikov, 313530537 . */
#include "Date.h"

bool Date::setDay(int day)
{
	if (day < 1 || day>amountDays())
	{
		return false;
	}
	return true;
}
bool Date::setMonth(int month)
{
	if (month < 1 || month>12)
	{
		return false;
	}
	return true;
}
bool Date::setYear(int year)
{
	if (year < 1 || year>2021)
	{
		return false;
	}
	return true;
}
Date::Date()
{
	today();
}
void Date::today()
{
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	day = timeinfo.tm_mday;
	month = timeinfo.tm_mon + 1;
	year = timeinfo.tm_year + 2000;
}
Date::Date(int day, int month, int year)
{
	if (year == 0)
	{
		if (month != 0 || day != 0)
		{
			cout << "Ivalid date";
		}
		this->year = 0;
		this->month = 0;
		this->day = 0;
		return;
	}
	else if (setYear(year))
	{
		this->year = year;
		if (setMonth(month))
		{
			this->month = month;

			if (setDay(day))
			{
				this->day = day;
			}
		}
	}
}
int Date::amountDays()
{
	if (month < 1 || month > 12)
	{
		cout << "Not a month" << endl;
		return 0;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else if (month == 2)
	{
		if (leapYear())
		{
			return 29;
		}
		else
		{
			return 28;
		}
	}
	else
		return 31;
}
bool Date::leapYear()
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return true;
	}
	return false;
}

Date::~Date()
{
}

ostream& operator<<(ostream& os, const Date& ar)
{
	os << ar.day << "." << ar.month << "." << ar.year << endl;
	return os;
}
