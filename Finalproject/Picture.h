/*AKATON C++ munhe atzamim. names: Shaked Asido, 315853150. Shmuel malikov, 313530537 . */
#pragma once
#include "Craft.h"

class Picture : virtual public Craft
{
protected:
	float length;
public:
	virtual ~Picture();
	virtual const char* get_craft()const { return "Picture"; }
	Picture(char* nameCraft, int yearCreated, char* movement, float height, Artist* ptrArtist, float length);
	virtual void print()const;
};
