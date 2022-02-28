/*AKATON C++ munhe atzamim. names: Shaked Asido, 315853150. Shmuel malikov, 313530537 . */
#include "Artist.h"
#include <typeinfo>
#include "Hangstatue.h"


Artist::Artist(char* nameArtist, const Date& dateBirth, Date& dateDeath, int amount_crafts) : dateBirth(dateBirth), dateDeath(dateDeath)
{
	this->nameArtist = new char[strlen(nameArtist) + 1];
	if (this->nameArtist == NULL)
	{
		nameArtist = NULL;
		exit(1);
	}
	this->amount_crafts = 0;
	strcpy(this->nameArtist, nameArtist);
	crafts = new Craft * [amount_crafts];
}

Artist::Artist()
{
	nameArtist = NULL;
	amount_crafts = 0;
    crafts = NULL;
}

Artist::~Artist()
{
	for (int i = 0; i < amount_crafts; i++)
	{
		delete crafts[i];
	}
	delete[]crafts;
	delete[]nameArtist;
	cout << "Destruction crafts" << endl;
	cout << "Destruction artists" << endl;
}

void Artist::Add_craft(Craft *ptrCraft)
{
	Craft** TempCraft = new Craft * [amount_crafts + 1];
	if (TempCraft == NULL)
	{
		cout << "TempCraft error" << endl;
		exit(1);
	}
	for (int i = 0; i < amount_crafts; i++)
	{
		TempCraft[i] = crafts[i];
	}
	TempCraft[amount_crafts] = ptrCraft;
	amount_crafts++;
	delete crafts;
	crafts = TempCraft;
	cout << ">Craft added!" << endl;
}

ostream& operator<<(ostream& os, const Artist& ar)
{
	os << " ~~~~~Artist~~~~~ " << endl << "Name of artist: " << ar.nameArtist << endl << "Date of birth: " << ar.dateBirth << "Date of death: " << ar.dateDeath << "Crafts: " << endl;
	for (int i = 0; i < ar.amount_crafts; i++)
	{
		os << ar.crafts[i]->getName();
		if (i < ar.amount_crafts - 1)
			cout << ", ";
	}
	cout << endl;
	if (!ar.amount_crafts)
	{
		os << "No crafts exists.";
	}
	return os;
}
void Artist::printCrafts()const
{

	for (int i = 0; i < amount_crafts; i++)
	{
		crafts[i]->print();
		cout << endl;
	}
	cout << endl;

}

bool Artist::check_pic()const
{
	for (int i = 0; i < amount_crafts; i++)
	{
		if (strcmp("Picture", crafts[i]->get_craft()) == 0)
		{
			return true;
		}
	}
	return false;
}
bool Artist::check_statue()const 
{
	for (int i = 0; i < amount_crafts; i++)
	{
		if (strcmp("Statue", crafts[i]->get_craft()) == 0)
		{
			return true;
		}
	}
	return false;
}
