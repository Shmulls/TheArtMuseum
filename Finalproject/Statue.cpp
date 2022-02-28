/*AKATON C++ munhe atzamim. names: Shaked Asido, 315853150. Shmuel malikov, 313530537 . */
#include "Statue.h"

Statue::~Statue() {}
Statue::Statue(char* nameCraft, int yearCreated, char* movement, float height, Artist* ptrArtist, float Area, float Weight) : Craft(nameCraft, yearCreated, movement, height, ptrArtist)
{
	this->Area = Area;
	this->Weight = Weight;
}

void Statue::print()const
{
	Craft::print();
	cout << "Area: " << Area << endl << "Weight: " << Weight << endl;
}
