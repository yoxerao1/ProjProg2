//T07_G06
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <algorithm>
#include <cmath>
using namespace std;

void menu()
{
	unsigned short answer;
	bool error = false;
	cout << ">======>                >=>                   >=>          >=>       >=>                                " << endl;
	cout << ">=>    >=>              >=>                   >=>          >> >=>   >>=>                                " << endl;
	cout << ">=>    >=>      >=>     >=>         >=>     >=>>==>        >=> >=> > >=>    >=> >=>  >====>>=>   >==>   " << endl;
	cout << ">> >==>       >=>  >=>  >=>>==>   >=>  >=>    >=>          >=>  >=>  >=>  >=>   >=>       >=>  >>   >=> " << endl;
	cout << ">=>  >=>     >=>    >=> >=>  >=> >=>    >=>   >=>          >=>   >>  >=> >=>    >=>     >=>    >>===>>=>" << endl;
	cout << ">=>    >=>    >=>  >=>  >=>  >=>  >=>  >=>    >=>          >=>       >=>  >=>   >=>    >=>     >>       " << endl;
	cout << ">=>      >=>    >=>     >=>>==>     >=>        >=>         >=>       >=>   >==>>>==> >=======>  >====>  " << endl;
	do
	{
		cout <<
			"--------------------" << endl <<
			"|choose :          |" << endl <<
			"|1 for Rules       |" << endl <<
			"|2 for Play        |" << endl <<
			"|3 for Leader Board|" << endl <<
			"|0 for Exit        |" << endl <<
			"--------------------" << endl;
		cin >> answer;
		if (cin.eof())
		{
			return;
		}
		if (!cin.good())
		{
			cout << "this is not a valid choice, please try again." << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			error = true;
		}
		else if (answer == 1)
		{
			cout << "----------------------------------------------------------------------------------------------------------" << endl <<
				"|                                                RULES                                                   |" << endl <<
				"----------------------------------------------------------------------------------------------------------" << endl <<
				"|You will be placed in a maze made up of high-voltage fences.                                            |" << endl <<
				"|There are robots that will try to destroy you.                                                          |" << endl <<
				"|The only way you have to destroy them (and win the game)                                                |" << endl <<
				"|is to make them crash with each other or make them crash                                                |" << endl <<
				"|with the eletric fences (sorry, you can not punch them).                                                |" << endl <<
				"|If you are the one hiting the robots or colliding with the fences you die.                              |" << endl <<
				"|Every time you make a move the robots will also make a move going to your direction by the shortest path|" << endl <<
				"|(thats how you trick them). The robots have no vision sensors but                                       |" << endl <<
				"|they have an accurate odour sensor that allows them to follow the player!                               |" << endl <<
				"|                                                                                                        |" << endl <<
				"|                                                                                                        |" << endl <<
				"|you can only move to one of the 8 neighbour cells of your current cell.                                 |" << endl <<
				"|these are the letters you can use to move :                                                             |" << endl <<
				"|                                     Q           W            E                                         |" << endl <<
				"|                                                                                                        |" << endl <<
				"|                                     A          you           D                                         |" << endl <<
				"|                                                                                                        |" << endl <<
				"|                                     Z           X            C                                         |" << endl <<
				"|                                                                                                        |" << endl <<
				"|you can also stay in the same place by choosing 'S'.                                                    |" << endl <<
				"----------------------------------------------------------------------------------------------------------" << endl;
			menu();
			error = false;
		}
		else if (answer == 2)
		{
			maze_selection();
			error = false;
		}
		else if (answer == 3)
		{
			bool check = True;
			int num
			string line, file;
			ifstream leaderboard;
			while (check)
			{
				cout << "choose the leader board number (01 to 99): ";
				do
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cin >> number;
					if (cin.eof())
					{
						return;
					}
					if (!cin.good())
					{
						cout << "not a valid maze number, please try again." << endl;
					}
				} while (!cin.good());
				if (number >= 0 && number < 10) //this is to make inputs like 1 and 01 to be accepted
				{
					file = "MAZE_0" + to_string(number) + "_WINNERS.TXT";
				}
				else
				{
					file = "MAZE_" + to_string(number) + "_WINNERS.TXT";
				}
				leaderboard.open(file);
				if (leaderboard.is_open())
				{
					ofstream create(file, ios::app); // check if the file exists without altering it, if it doesnt, create one
					create.close();
					ifstream screen(file);
					while (getline(screen, line))
					{
						cout << line << endl;
					}
				}
				else
				{
					cout << "can't access leader board" << endl;
					menu()
				}
			}
		}
		else if (answer == 0)
		{
			error = false;
			return;
		}
		else
		{
			cout << "this is not a valid choice, please try again." << endl;
			error = true;
		}
	} while (error);
}

int main()
{
	menu();
	return 0
}