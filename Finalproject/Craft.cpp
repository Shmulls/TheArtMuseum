/*AKATON C++ munhe atzamim. names: Shaked Asido, 315853150. Shmuel malikov, 313530537 . */
#include "Craft.h"

Craft::~Craft()
{
	delete[]nameCraft;
	delete[]movement;
}

Craft::Craft(char* nameCraft, int yearCreated, char* movement, float height, Artist* ptrArtist)
{
	this->nameCraft = new char[strlen(nameCraft) + 1];
	if (this->nameCraft == NULL)
	{
		exit(1);
	}
	strcpy(this->nameCraft, nameCraft);
	this->yearCreated = yearCreated;
	this->movement = new char[strlen(movement) + 1];
	if (this->movement == NULL)
	{
		exit(1);
	}
	strcpy(this->movement, movement);
	this->height = height;

	this->ptrArtist = ptrArtist;
}
void Craft::print()const
{
	cout << "Name: " << nameCraft << endl << "Year: " << yearCreated << endl << "Movement: " << movement << endl << "Height: " << height << endl;
}

