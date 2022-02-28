/*AKATON C++ munhe atzamim. names: Shaked Asido, 315853150. Shmuel malikov, 313530537 . */
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Artist;
class Craft
{
protected:
	char* nameCraft;
	int yearCreated;
	char* movement;
	float height;
	Artist* ptrArtist;	

public:
	Craft();
	virtual ~Craft();
	Craft(char* nameCraft, int yearCreated, char* movement, float height, Artist* ptrArtist);
	const char* getName()const { return nameCraft; }
	virtual const char* get_craft()const { return "Craft"; }
	virtual void print()const;
	const char* get_movement()const { return movement; }
};
