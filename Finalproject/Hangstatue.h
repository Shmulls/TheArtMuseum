/*AKATON C++ munhe atzamim. names: Shaked Asido, 315853150. Shmuel malikov, 313530537 . */
#pragma once
#include "Statue.h"
#include "Picture.h"

class Hangstatue : public Picture, public Statue
{
private:
	int Amount_of_screws;
public:
	virtual const char* get_craft()const { return "Hangstatue"; }
	virtual ~Hangstatue();
	Hangstatue(char* nameCraft, int yearCreated, char* movement, float height, Artist* nameArtist, float length, float Area, float Weight, int Amount_of_screws);
	virtual void print()const;
};
