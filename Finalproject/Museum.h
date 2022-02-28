/*AKATON C++ munhe atzamim. names: Shaked Asido, 315853150. Shmuel malikov, 313530537 . */
#pragma once
#include <iostream>
using namespace std;
#include "Artist.h"
#include "Hangstatue.h"
#include "Craft.h"

class Museum
{
private:
	Artist** artists;
	Craft** crafts;
	int number_of_artist;
	int number_of_crafts;

public:
	virtual ~Museum();
	Museum();
	void menu();
	void add_artist();
	void add_craft();
	void remove_craft(int index);
	void print_leastOne_craft();
	void print_crafts();
	void print_pictures();
	void print_statue();
	void print_by_artist();
	void print_by_movement();
	void print_by_amonutPic();
	void print_by_amountStat();
	void print_by_weight();
	int find_artist(const char* name);
	bool check_artist(char aname[20])const; 

};
