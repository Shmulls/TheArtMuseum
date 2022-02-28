/*AKATON C++ munhe atzamim. names: Shaked Asido, 315853150. Shmuel malikov, 313530537 . */
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Date.h"
#include <string.h>
 
class Craft;
class Artist
{
private:
	char* nameArtist;
	const Date dateBirth;
	Date dateDeath;
	int amount_crafts;
	Craft** crafts;

public:
	Artist();
	virtual ~Artist();
	Artist(char* nameArtist, const Date& dateBirth, Date& dateDeath, int amount_crafts);
	const Date& getDateBirth()const { return dateBirth; }
	const Date& getDateDeath()const { return dateDeath; }
	const char* get_name()const { return nameArtist; }
	const int amount_craft()const { return amount_crafts; }
	friend ostream& operator<<(ostream& os, const Artist& ar);
	void Add_craft(Craft *ptrCraft);
	void printCrafts()const;
	bool check_pic()const;
	bool check_statue()const;
};
