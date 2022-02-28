/*AKATON C++ munhe atzamim. names: Shaked Asido, 315853150. Shmuel malikov, 313530537 . */
#include "Picture.h"

Picture::~Picture() {}
Picture::Picture(char* nameCraft, int yearCreated, char* movement, float height, Artist* ptrArtist, float length) : Craft(nameCraft, yearCreated, movement, height, ptrArtist)
{
	this->length = length;
}

void Picture::print()const
{
	Craft::print();
	cout << "The length of the picture: " << length << endl;
 }

