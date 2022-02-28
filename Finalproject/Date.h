/*AKATON C++ munhe atzamim. names: Shaked Asido, 315853150. Shmuel malikov, 313530537 . */
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<time.h>
#include<iostream>
using namespace std;


class Date
{
private:
	int day, month, year;
public:
	bool setDay(int day);
	bool setMonth(int month);
	bool setYear(int year);
	void today();
	Date();
	Date(int day, int month, int year);
	int amountDays();
	bool leapYear();
	friend ostream& operator<<(ostream& os, const Date& ar);
	virtual ~Date();
};

