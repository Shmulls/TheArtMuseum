/*AKATON C++ munhe atzamim. names: Shaked Asido, 315853150. Shmuel malikov, 313530537 . */
#pragma once
#include "Craft.h"

class Statue : virtual public Craft
{
protected:
	float Area, Weight;
public:
	virtual ~Statue();
	Statue(char* nameCraft, int yearCreated, char* movement, float height, Artist* ptrArtist, float Area, float Weight);
	virtual void print()const;
	virtual const char* get_craft()const { return "Statue"; }
	float get_weight()const { return Weight; }
};