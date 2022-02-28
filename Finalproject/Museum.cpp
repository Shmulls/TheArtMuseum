/*AKATON C++ munhe atzamim. names: Shaked Asido, 315853150. Shmuel malikov, 313530537 . */
#include "Museum.h"
#include <typeinfo>

Museum::~Museum()
{
	for (int i = 0; i < number_of_artist; i++)
	{
		delete artists[i];
	}
	delete[]artists;
}
Museum::Museum()
{
	artists = NULL;
	crafts = NULL;
	number_of_artist = 0;
	number_of_crafts = 0;
}
void Museum::menu()
{
	int number;
	do
	{
	cout << endl;
	cout << endl;
	cout << "##################################################" << endl;
	cout << "Choose type of operation" << endl 
		 << "1.Add artist" << endl 
	 	 << "2.Add craft" << endl 
		 << "3.Remove craft" << endl 
		 << "4.Print all artist that have one craft" << endl 
		 << "5.Print all crafts in museum" << endl
	  	 << "6.Print all pictures in museum" << endl
		 << "7.Print all statues in museum" << endl
		 << "8.Print crafts owned by artist" << endl
		 << "9.Print crafts by movement" << endl
		 << "10.Print all artists that have one picture or more" << endl
		 << "11.Print all artist that have one statue or more" << endl
		 << "12.Print all statue by weight" << endl
		 << "13.Exit" << endl;
	cout << "##################################################" << endl;

		cout << "Please enter your choice--->";
		cin >> number;
		cout << endl;

		switch (number)
		{
		case 1:
			add_artist();
			break;

		case 2:
			add_craft();
			break;

		case 3:
		{
			int index = 0;
			char cname[20];
			bool found = false;

			cout << "Please enter the name of craft: " << endl;
			cin >> cname;
			for (int i = 0; i < number_of_crafts; i++)
			{
				if ((strcmp(cname, crafts[i]->getName()) == 0))
				{
					index = i;
				}
				found = true;
			}
			if (!found)
			{
				cout << "There is no craft named that way in the museum." << endl;
				break;
			}
			remove_craft(index);
			break;
		}
		case 4:
			print_leastOne_craft();
			break;

		case 5:
			print_crafts();
			break;

		case 6:
			print_pictures();
			break;

		case 7:
			print_statue();
			break;

		case 8:
			print_by_artist();
			break;

		case 9:
			print_by_movement();
			break;

		case 10:
			print_by_amonutPic();
			break;

		case 11:
			print_by_amountStat();
			break;

		case 12:
			print_by_weight();
			break;

		case 13:
			number = 14;
			cout << "The museum is closed, starting destruction." << endl;
	
			break;
		}
	} while (number != 14);

}
void Museum::add_artist()
{
	char aname[20];
	Date birthDay;
	Date dayingDay;
	int amount_crafts;
	int day, month, year, dayd, monthd, yeard;

	cout << "Enter artist name:" << endl;
	cin >> aname;

	cout << "Enter artist birthday: " << endl;
	cin >> day >> month >> year;

	cout << "Enter artist daying day: " << endl;
	cin >> dayd >> monthd >> yeard;

	cout << "Enter amount of crafts that this artist has: " << endl;
	cin >> amount_crafts;

    birthDay = Date(day, month, year);
	dayingDay = Date(dayd, monthd, yeard);

	Artist* TempArtist_Build = new Artist(aname, birthDay, dayingDay, amount_crafts);
	Artist** TempArtist = new Artist* [number_of_artist + 1];
	if (TempArtist == NULL)
	{
		cout << "TempArtist error" << endl;
	}
	for (int i = 0; i < number_of_artist; i++)
	{
		TempArtist[i] = artists[i];
	}
	TempArtist[number_of_artist] = TempArtist_Build;
	number_of_artist++;
	delete[]artists;
	artists = TempArtist;
	cout << ">Artist added!<" << endl;
}
void Museum::add_craft()
{
	char aname[20], cname[20], movement[20];
	int  yearc, place, screws, menu;
	Craft* new_craft;
	float area, weight, length, height;

	cout << "Enter artist name: " << endl;
	cin >> aname;

	place = find_artist(aname);
	if (place == -1)
	{
		cout << "There is not artist" << endl;
		return;
	}
	cout << "Enter name of craft:" << endl;
	cin >> cname;

	cout << "Enter year created:" << endl;
	cin >> yearc;

	cout << "Enter movement:" << endl;
	cin >> movement;

	cout << "Enter height:" << endl;
	cin >> height;

	do
	{
		cout << "Please choose type of craft:" << endl << "1.Picture" << endl << "2.Statue" << endl << "3.Hanging statue" << endl;
		cin >> menu;

		switch (menu)
		{
			case 1:
			{
				cout << "Enter length: " << endl;
				cin >> length;
				new_craft = new Picture(cname, yearc, movement, height, artists[place], length);
				break;
			}
			case 2:
			{
				cout << "Enter area and weight: " << endl;
				cin >> area >> weight;

				new_craft = new Statue(cname, yearc, movement, height, artists[place], area, weight);
				break;
			}
			case 3:
			{
				cout << "Enter area and weight: " << endl;
				cin >> area >> weight;
				cout << "Enter length: " << endl;
				cin >> length;
				cout << "Enter amount of screws: " << endl;
				cin >> screws;
			}

			new_craft = new Hangstatue(cname, yearc, movement, height, artists[place], length, area, weight, screws);
			break;
			default:
			cout << "Selection not vaild!" << endl;
			return;
		}

	} while (menu > 3 || menu < 1);

	Craft** TempCraft = new Craft * [number_of_crafts + 1];
	if (TempCraft == NULL)
	{
		cout << "TempCraft error" << endl;
		number_of_crafts--;
		return;
	}
	for (int i = 0; i < number_of_crafts; i++)
	{
		TempCraft[i] = crafts[i];
	}
	TempCraft[number_of_crafts] = new_craft;
	number_of_crafts++;
	delete[]crafts;
	crafts = TempCraft;

	artists[place]->Add_craft(new_craft);
}
void Museum::remove_craft(int index)
{
	
	if (index >= number_of_crafts || index < 0) 
	{
		cout << "Index error" << endl;
		return;
	}
	Craft** TempCraft = new Craft * [number_of_crafts - 1];
	if (TempCraft == NULL)
	{
		cout << "TempCraft error" << endl;
		number_of_crafts++;
		return;
	}
	for (int i = 0; i <= number_of_crafts; i++)
	{
		if (i != index)
		TempCraft[i] = crafts[i];
	}
	number_of_crafts--;
	delete[]crafts;
	crafts = TempCraft;
	cout << ">Craft deleted!" << endl;

}
void Museum::print_leastOne_craft()
{
	bool found = false;

	for (int i = 0; i < number_of_artist; i++)
	{
		if ((artists[i]->amount_craft()) >= 1)
		{
			cout << *artists[i];
		}
		found = true;
	}
	if (!found)
	{
		cout << "There is no crafts in the museum." << endl;
	}
	cout << " ~~~~~~~~~~~~~~~~ " << endl;
	cout << endl;
}
void Museum::print_crafts()
{
	if (number_of_crafts == 0)
	{
		cout << "There is no crafts in the museum." << endl;
		return;
	}

	for (int i = 0; i < number_of_crafts; i++)
	{
		crafts[i]->print();
		cout << endl;
	}
}
void Museum::print_pictures()
{
	bool found = false;

	for (int i = 0; i < number_of_crafts; i++)
	{
		if (dynamic_cast<Picture*>(crafts[i]))
		{
			dynamic_cast<Picture*>(crafts[i])->print();
			cout << endl;
		}
		found = true;
	}
	if (!found)
	{
		cout << "There is no pictures in the museum." << endl;
	}
}
void Museum::print_statue()
{
	bool found = false;

	for (int i = 0; i < number_of_crafts; i++)
	{
		if (dynamic_cast<Statue*>(crafts[i]))
		{
			dynamic_cast<Statue*>(crafts[i])->print();
			cout << endl;
		}
		found = true;
	}
	if (!found)
	{
		cout << "There is no statues in the museum." << endl;
	}
}
void Museum::print_by_artist()
{
		char aname[20];
		bool found = false;

		cout << "Enter artist name: " << endl;
		cin >> aname;

		for (int i = 0; i < number_of_artist; i++)
		{
			if (strcmp(artists[i]->get_name(), aname) == 0)
			{
					artists[i]->printCrafts();
			}
			found = true;
		}
		if (!found)
		{
			cout << "There is no artist goes by this name." << endl;
		}
}
void Museum::print_by_movement()
{
	char movement[20];

	cout << "Enter movement:" << endl;
	cin >> movement;
	bool found = false;

	for (int i = 0; i < number_of_crafts; i++)
	{
		if ((strcmp(crafts[i]->get_movement(), movement) == 0))
		{
			crafts[i]->print();
		}
		found = true;
	}
	if (!found)
	{
		cout << "There is no movement by this name in the museum." << endl;
	}
}
void Museum::print_by_amonutPic()
{
	bool found = false;

	for (int i = 0; i < number_of_artist; i++)
	{
		if (artists[i]->check_pic())
		{
			cout << *artists[i];
		}
		found = true;
	}
	if (!found)
	{
		cout << "There is no artist with at leaset one picture in the museum." << endl;
	}
}
void Museum::print_by_amountStat()
{
	bool found = false;

	for (int i = 0; i < number_of_artist; i++)
	{
		if (artists[i]->check_statue())
		{
			cout << *artists[i];
		}
		found = true;
	}
	if (!found)
	{
		cout << "There is no artist with at leaset one statue in the museum." << endl;
	}
}
void Museum::print_by_weight()
{
	float Weight_s;
	bool found = false;

	cout << "Enter weight please:" << endl;
	cin >> Weight_s;

	for (int i = 0; i < number_of_crafts; i++)
	{
		if ((strcmp("Statue", crafts[i]->get_craft())==0) || (strcmp("Hangstatue", crafts[i]->get_craft()) == 0))
		{
			if (Weight_s < (dynamic_cast<Statue*>(crafts[i])->get_weight()))
			{
				crafts[i]->print();
				cout << endl;
			}
			found = true;
		}
	}
	if (!found)
	{
		cout << "There is no statue over that weight." << endl;
	}
}
int Museum::find_artist(const char* name)
{
	for (int i = 0; i < number_of_artist; i++)
	{
		if (strcmp(artists[i]->get_name(), name)==0)
		{
			return i;
		}
	}
	return -1;
}

