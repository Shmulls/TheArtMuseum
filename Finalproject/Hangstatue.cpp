/*AKATON C++ munhe atzamim. names: Shaked Asido, 315853150. Shmuel malikov, 313530537 . */
#include "Hangstatue.h"

Hangstatue::~Hangstatue() {}
Hangstatue::Hangstatue(char* nameCraft, int yearCreated, char* movement, float height, Artist* ptrArtist, float length, float Area, float Weight, int Amount_of_screws) : Craft(nameCraft, yearCreated, movement, height, ptrArtist), Picture(nameCraft, yearCreated, movement, height, ptrArtist, length), Statue(nameCraft, yearCreated, movement, height, ptrArtist, Area, Weight)
{
	this->Amount_of_screws = Amount_of_screws;
}
void Hangstatue::print()const
{
	Statue::print();
	cout << "The amount of screws is: " << Amount_of_screws << endl;
}
