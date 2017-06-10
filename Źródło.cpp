#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <time.h>
#include <conio.h>
#include "stdafx.h"
#include "Nag³ówek.h"

using namespace std;


void Fighter_Interface::change_health(int difference)
{
	Boxer_parameters.health = Boxer_parameters.health + difference;
}

void Fighter_Interface::health_max()
{
	Boxer_parameters.health = 1000;
}

void Fighter_Interface::change_strength(int difference)
{
	Boxer_parameters.strength = Boxer_parameters.strength + difference;
}

int Fighter_Interface::return_defence()
{
	return Boxer_parameters.defense;
}

int Fighter_Interface::return_health()
{
	return Boxer_parameters.health;
}

string Fighter_Interface::return_name()
{
	return Boxer_parameters.name;
}

void Fighter_Interface::change_name(string newname)
{
	Boxer_parameters.name = newname;
}

int Fighter_Interface::return_power()
{
	return Boxer_parameters.knockout_power;
}

void Fighter_Interface::max_strengh()
{
	Boxer_parameters.strength = 1000;
}

int Fighter_Interface::return_strength()
{
	return Boxer_parameters.strength;
}
int Fighter_Interface::show_dmg()
{
	return Boxer_parameters.dmg;
}

int Fighter_Interface::return_points()
{
	return Boxer_parameters.points;
}

void Fighter_Interface::change_power(int var)
{
	Boxer_parameters.knockout_power += var;
}

void Fighter_Interface::change_score(bool newvar)
{
	Boxer_parameters.won = newvar;
}

bool Fighter_Interface::return_score()
{
	return Boxer_parameters.won;
}

void Boxer::Jab(Fighter_Interface *opponent)
{
	int precision;
	precision = rand() % 5 + 5;

	int damage;

	damage = (Boxer_parameters.knockout_power - precision) - opponent->return_defence();
	if (Boxer_parameters.strength >= 60)
	{
		Boxer_parameters.points += damage;
		opponent->change_health(-damage);
		Boxer_parameters.dmg = -damage;
		change_strength(-60);
	}
	else
		Clinching();
}

void Boxer::Hook(Fighter_Interface *opponent)
{
	int precision;
	precision = rand() % 5 + 1;

	int damage;

	damage = (Boxer_parameters.knockout_power - precision) - opponent->return_defence();
	if (Boxer_parameters.strength >= 90)
	{
		Boxer_parameters.points += damage;
		opponent->change_health(-damage);
		Boxer_parameters.dmg = -damage;
		change_strength(-90);
	}
	else
		Clinching();
}

void Boxer::Uppercut(Fighter_Interface *opponent)
{
	int precision;
	precision = rand() % 5 + 5;

	int damage;

	damage = (Boxer_parameters.knockout_power - precision) - opponent->return_defence();
	if (Boxer_parameters.strength >= 130)
	{
		Boxer_parameters.points += damage;
		opponent->change_health(-damage);
		Boxer_parameters.dmg = -damage;
		change_strength(-130);
	}
	else
		Clinching();
}

void Boxer::Clinching()
{
	change_health(40);
	change_strength(170);
	Boxer_parameters.dmg = 170;
}

void Swarmer::Jab(Fighter_Interface *opponent)
{
	int precision;
	precision = rand() % 5 + 1;

	int damage;

	damage = (Boxer_parameters.knockout_power - precision) - opponent->return_defence();
	if (Boxer_parameters.strength >= 50)
	{
		Boxer_parameters.points += damage;
		opponent->change_health(-damage);
		Boxer_parameters.dmg = -damage;
		change_strength(-50);
	}
	else
		Clinching();
}

void Swarmer::Hook(Fighter_Interface *opponent)
{
	int precision;
	precision = rand() % 5 + 5;

	int damage;

	damage = (Boxer_parameters.knockout_power - precision) - opponent->return_defence();
	if (Boxer_parameters.strength >= 100)
	{
		Boxer_parameters.points += damage;
		opponent->change_health(-damage);
		Boxer_parameters.dmg = -damage;
		change_strength(-100);
	}
	else
		Clinching();
}

void Swarmer::Uppercut(Fighter_Interface *opponent)
{
	int precision;
	precision = rand() % 5 + 10;

	int damage;

	damage = (Boxer_parameters.knockout_power - precision) - opponent->return_defence();
	if (Boxer_parameters.strength >= 150)
	{
		Boxer_parameters.points += damage;
		opponent->change_health(-damage);
		Boxer_parameters.dmg = -damage;
		change_strength(-150);
	}
	else
		Clinching();
}

void Swarmer::Clinching()
{
	change_health(50);
	change_strength(150);
	Boxer_parameters.dmg = 150;
}

void Brawler::Jab(Fighter_Interface *opponent)
{
	int precision;
	precision = rand() % 5 + 10;

	int damage;

	damage = (Boxer_parameters.knockout_power - precision) - opponent->return_defence();
	if (Boxer_parameters.strength >= 70)
	{
		Boxer_parameters.points += damage;
		opponent->change_health(-damage);
		Boxer_parameters.dmg = -damage;
		change_strength(-70);
	}
	else
		Clinching();
}

void Brawler::Hook(Fighter_Interface *opponent)
{
	int precision;
	precision = rand() % 5 + 5;

	int damage;

	damage = (Boxer_parameters.knockout_power - precision) - opponent->return_defence();
	if (Boxer_parameters.strength >= 100)
	{
		Boxer_parameters.points += damage;
		opponent->change_health(-damage);
		Boxer_parameters.dmg = -damage;
		change_strength(-100);
	}
	else
		Clinching();
}

void Brawler::Uppercut(Fighter_Interface *opponent)
{
	int precision;
	precision = rand() % 5 + 1;

	int damage;

	damage = (Boxer_parameters.knockout_power - precision) - opponent->return_defence();
	if (Boxer_parameters.strength >= 110)
	{
		Boxer_parameters.points += damage;
		opponent->change_health(-damage);
		Boxer_parameters.dmg = -damage;
		change_strength(-110);
	}
	else
		Clinching();
}

void Brawler::Clinching()
{
	change_health(40);
	change_strength(170);
	Boxer_parameters.dmg = 170;
}


Boxer::Boxer()
{
	Boxer_parameters.points = 0;
	Boxer_parameters.dmg = 0;
	Boxer_parameters.won = false;
	Boxer_parameters.strength = 1000;
	Boxer_parameters.health = 1000;

		file1.open("fighternames.txt", ios::in);

		if (file1.good() == false)
		{
			cout << "File doesn't exist!" << endl;
			exit(0);
		}
		if (Brawler::objectCount == 0 && Boxer::objectCount == 0 && Swarmer::objectCount == 0)
	srand(time(NULL));


	Boxer_parameters.knockout_power = rand() % 40 + 120;
	Boxer_parameters.defense = rand() % 20 + 20;


	int iterator = 0;
	int number_of_name;
	string boxer_name;
	string buffor;
	number_of_name = rand() % 110 + 1;

	for (int i = 0; i < number_of_name; i++)
	{
		getline(file1, boxer_name);
		buffor = boxer_name;
	}


	Boxer_parameters.name = buffor;

	objectCount++;
}

Boxer::~Boxer()
{
	
	file1.close();
}

Swarmer::Swarmer()
{
	Boxer_parameters.points = 0;
	Boxer_parameters.dmg = 0;
	Boxer_parameters.won = false;
	Boxer_parameters.strength = 1000;
	Boxer_parameters.health = 1000;

		file1.open("fighternames.txt", ios::in);

		if (file1.good() == false)
		{
			cout << "File doesn't exist!" << endl;
			exit(0);
		}
		if (Brawler::objectCount == 0 && Boxer::objectCount == 0 && Swarmer::objectCount == 0)
	srand(time(NULL));


	Boxer_parameters.knockout_power = rand() % 50 + 100;
	Boxer_parameters.defense = rand() % 20 + 30;


	int iterator = 0;
	int number_of_name;
	string boxer_name;
	string buffor;
	number_of_name = rand() % 110 + 1;

	for (int i = 0; i < number_of_name; i++)
	{
		getline(file1, boxer_name);
		buffor = boxer_name;
	}

	Boxer_parameters.name = buffor;
	objectCount++;
}

Swarmer::~Swarmer()
{
	file1.close();
}




void Fighter_Interface::show_parameters()
{
	cout << "=== " << Boxer_parameters.name <<" ==="<< endl;
	cout << "Knockout power: " << Boxer_parameters.knockout_power << endl;
	cout << "Defense: " << Boxer_parameters.defense << endl;
	cout << "Health: " << Boxer_parameters.health << endl;
	cout << "Strength: " << Boxer_parameters.strength << endl;
}


Brawler::Brawler()
{
	Boxer_parameters.points = 0;
	Boxer_parameters.dmg = 0;
	Boxer_parameters.won = false;
	Boxer_parameters.strength = 1000;
	Boxer_parameters.health = 1000;
	
		file1.open("fighternames.txt", ios::in);

		if (file1.good() == false)
		{
			cout << "File doesn't exist!" << endl;
			exit(0);
		}
		if (Brawler::objectCount == 0 && Boxer::objectCount == 0 && Swarmer::objectCount == 0)
	srand(time(NULL));


	Boxer_parameters.knockout_power = rand() % 50 + 150;
	Boxer_parameters.defense = rand() % 20 + 10;


	int iterator = 0;
	int number_of_name;
	string boxer_name;
	string buffor;
	number_of_name = rand() % 110 + 1;

	for (int i = 0; i < number_of_name; i++)
	{
		getline(file1, boxer_name);
		buffor = boxer_name;
	}

	Boxer_parameters.name = buffor;
	objectCount++;
}

Brawler::~Brawler()
{
	
		file1.close();
}

///////////////////////////////////////////////////////////

void Board::change_stage(stage newst)
{
	stt = newst;
}

void Board::instruction()
{
	system("cls");
	cout << "Boxing is a combat sport which two people wearing protective gloves throw punches "<<endl;
	cout << "at each other for a predetermined set of time in a boxing ring." << endl;
	cout << "\nYou will find here some words that could be obscure for person " << endl;
		cout<<"who does't know the boxing." << endl;
		cout << "Most of them can be checked on wikipedia." << endl;
		cout << "I didn't predict that someone would read this." << endl;
		cout << "Thanks for your time. Catch ya's later." << endl;
		getchar();
}

void Board::auto_fight(Fighter_Interface *Red_Corner, Fighter_Interface *Blue_Corner)
{
	bool Red_Corner_Won = false;
	int order[100], iterator=0;

	for(int i =0; i<100; i++)
	order[i] = rand() % 100 + 1;

	Red_Corner->change_score(false);
	Blue_Corner->change_score(false);

	Red_Corner->health_max();
	Blue_Corner->health_max();

	Red_Corner->max_strengh();
	Blue_Corner->max_strengh();

	while (Red_Corner->return_health() > 0 && Blue_Corner->return_health() > 0)
	{
		if (iterator == 99) iterator = 0;

		select_punch(order[iterator],Red_Corner, Blue_Corner);

		select_punch(order[iterator + 1], Blue_Corner, Red_Corner);
		
		iterator++;
	}

	if (Red_Corner->return_health() > 0)
		Red_Corner->change_score(true);
	else if (Blue_Corner->return_health() > 0)
		Blue_Corner->change_score(true);

}

void Board::select_name(Fighter_Interface*ptr)
{
	system("cls");
	string new_name;
	cout << "Enter your name:";
	cin >> new_name;
	ptr->change_name(new_name);
}

void Board::fight(Fighter_Interface *Red_Corner, Fighter_Interface *Blue_Corner)
{
	char punch;

	bool over = true;

	Red_Corner->change_score(false);
	Blue_Corner->change_score(false);

	Red_Corner->health_max();
	Blue_Corner->health_max();

	Red_Corner->max_strengh();
	Blue_Corner->max_strengh();

	while (over)
	{
		system("cls");
		cout << "\t\t\t\tScore: " << Red_Corner->return_points() << endl << endl;
		cout << "\t\t\t" << Red_Corner->return_name() << "\t\t" << Blue_Corner->return_name() << endl;
		cout << "Knockout power:\t\t" << Red_Corner->return_power() << "\t\t" << Blue_Corner->return_power() << endl;
		cout << "Defence:\t\t" << Red_Corner->return_defence() << "\t\t" << Blue_Corner->return_defence() << endl;
		cout << "Strenght:\t\t" << Red_Corner->return_strength() << "\t\t" << Blue_Corner->return_strength() << endl;
		cout << "Health:\t\t\t" << Red_Corner->return_health() << "\t\t" << Blue_Corner->return_health() << endl;
		cout << endl;
		cout << "\t\t\tDamage:\t\tDamage:" << endl;
		cout << "\t\t\t" << Red_Corner->show_dmg() << "\t\t" << Blue_Corner->show_dmg() << endl;
		cout << '\n';
		cout << "Select punch:" << endl;
		cout << "1. Jab" << endl;
		cout << "2. Hook" << endl;
		cout << "3. Uppercut" << endl;
		cout << "4. Clinch" << endl;
		punch = getche();
		player_fight(punch, Red_Corner, Blue_Corner);
		if (Red_Corner->return_health() < 0 || Blue_Corner->return_health() < 0)
			over = false;
	}

	if (Red_Corner->return_health() > 0)
		Red_Corner->change_score(true);
	else if (Blue_Corner->return_health() > 0)
		Blue_Corner->change_score(true);
}

void Board::player_fight(char choice ,Fighter_Interface *Red_Corner, Fighter_Interface *Blue_Corner)
{
	int order[100], j = 0;

	for (int i = 0; i<100; i++)
		order[i] = rand() % 100 + 1;

	switch (choice)
	{
	case '1':
		Red_Corner->Jab(Blue_Corner);
		if(Red_Corner->return_health()>0 && Blue_Corner->return_health()>0)
		select_punch(order[j], Blue_Corner, Red_Corner);
		j++;
		break;
	case '2':
		Red_Corner->Hook(Blue_Corner);
		if (Red_Corner->return_health()>0 && Blue_Corner->return_health()>0)
		select_punch(order[j], Blue_Corner, Red_Corner);
		j++;
		break;
	case '3':
		Red_Corner->Uppercut(Blue_Corner);
		if (Red_Corner->return_health()>0 && Blue_Corner->return_health()>0)
		select_punch(order[j], Blue_Corner, Red_Corner);
		j++;
		break;
	case '4':
		Red_Corner->Clinching();
		if (Red_Corner->return_health()>0 && Blue_Corner->return_health()>0)
		select_punch(order[j], Blue_Corner, Red_Corner);
		j++;
		break;
	default:
		cout << "ERROR!!!" << endl;
		exit(0);
		break;
	}

}

void Board::select_punch(int rand_number, Fighter_Interface* Attacks, Fighter_Interface* Defends)
{
	if (rand_number < 100 && rand_number>80)
	{
		if(Attacks->return_health()>0 && Defends->return_health()>0)
		Attacks->Jab(Defends);
	}
	else if (rand_number <= 80 && rand_number > 60)
	{
		if (Attacks->return_health() > 0 && Defends->return_health() > 0)
			Attacks->Hook(Defends);
	}
	else if (rand_number <= 60 && rand_number > 40)
	{
		if (Attacks->return_health() > 0 && Defends->return_health() > 0)
			Attacks->Uppercut(Defends);
	}
	else if (rand_number <= 40 && rand_number > 20)
	{
		if (Attacks->return_health() > 0 && Defends->return_health() > 0)
			Attacks->Clinching();
	}
	else if (rand_number <= 20 && rand_number > 0)
	{
		if (Attacks->return_health() > 0 && Defends->return_health() > 0)
			Defends->Hook(Attacks);
	}
}

void Board::display_players(Fighter_Interface* Boxrs[8])
{
	system("cls");
	for (int i = 1; i < 8; i++)
	{
		cout << " .... " << i << " ...." << endl;
		Boxrs[i]->show_parameters();
		cout << "......................" << endl;
		cout << endl;
	}
	
	getchar();
}

void Board::tournament_ladder(Fighter_Interface* Fighter[8])
{
	system("cls");

	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);


	SetConsoleTextAttribute(hOut, 15);
	if (stt >= quarterfinal)
		cout << "1. " << Fighter[0]->return_name() << " -  " << endl;
	else
		cout << "1. " << endl;
	if(stt>=quarterfinal)
	cout << "\t\t\t" << Fighter[0]->return_name()<< " -  "<< endl;
	cout << "2. " << Fighter[1]->return_name() <<" -  "<<endl;
	if(stt>=semifinal)
	cout << "\t\t\t\t\t  " << Fighter[0]->return_name() <<" -  "<< endl;
	cout << "3. " << Fighter[2]->return_name() <<" -  "<< endl;
	if (stt >= quarterfinal)
	cout << "\t\t\t" << Fighter[2]->return_name()<< " -  " << endl;
	cout << "4. " << Fighter[3]->return_name() << " -  " << endl;
	if (stt >= finall)
	cout << "\t\t\t\t\t\t\t    " << Fighter[0]->return_name() << endl;
	cout << "5. " << Fighter[4]->return_name() << " -  " << endl;
	if (stt >= quarterfinal)
	cout << "\t\t\t" << Fighter[4]->return_name() << " -  " << endl;
	cout << "6. " << Fighter[5]->return_name() << " -  " << endl;
	if (stt >= semifinal)
	cout << "\t\t\t\t\t  " << Fighter[4]->return_name() << " -  " << endl;
	cout << "7. " << Fighter[6]->return_name() << " -  " << endl;
	if (stt >= quarterfinal)
	cout << "\t\t\t" << Fighter[6]->return_name() << " -  " << endl;
	cout << "8. " << Fighter[7]->return_name() << " -  " << endl;

	getchar();
}

Board::Board()
{
	stt = opening;	
}


void Board::players_game(Fighter_Interface* Boxrs[8])
{
	bool way_out = true;

	char sign;
	while (way_out)
	{
		system("cls");

		cout << "1. Start the fight." << endl;
		cout << "2. Show tournament ladder." << endl;
		cout << "3. Show my opponents. " << endl;
		cout << "4. Quit the game. " << endl;

		sign = getche();

		switch (sign)
		{
		case '1':
			game(Boxrs);
			break;
		case '2':
			tournament_ladder(Boxrs);
				break;
		case '3':
			display_players(Boxrs);
			break;
		case '4':
			way_out = false;
			break;
		default:
			cout << "Wrong. Select 1, 2, 3 or 4." << endl;
			break;
		}
	}
}
bool Board::quick_menu(Fighter_Interface*Boxers[8])
{
	char sign;

	system("cls");

	cout << "1. Continue the tournament." << endl;
	cout << "2. Show tournament ladder." << endl;
	cout << "3. Show my opponents. " << endl;
	
	sign = getche();

	switch (sign)
	{
	case '1':
		return false;
		break;
	case '2':
		tournament_ladder(Boxers);
		break;
	case '3':
		display_players(Boxers);
		break;
	default:
		cout << "Wrong. Select 1, 2 or 3." << endl;
		getchar();
		break;
	}
}

void Board::panel(Fighter_Interface*Fighters[8])
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	bool microswitch = true;
	char sign;

	while (microswitch)
	{
		system("cls");
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);

		cout << "===ART OF THE KNOCKOUT===" << endl;

		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);

		cout << "1. New game." << endl;
		cout << "2. Show my results." << endl;
		cout << "3. Instruction." << endl;
		cout << "4. Quit." << endl;

		sign = getche();

		switch (sign)
		{
		case '1':
			players_game(Fighters);
			break;
		case '2':
			app_points();
			break;
		case '3':
			instruction();
			break;
		case '4':
			microswitch = false;
			break;
		default:
			cout << "Wrong. Select 1, 2, 3 or 4." << endl;
			getchar();
			break;


		}
	}
}

void Board::replacing(Fighter_Interface *left, Fighter_Interface *right)
{
	Fighter_Interface *buffor;
	buffor = left;
	left = right;
	right = left;
}

void Board::game(Fighter_Interface *Boxers[8])
{
	select_name(Boxers[0]);
	Boxers[0]->change_power(40);


	fight(Boxers[0], Boxers[1]);

	auto_fight(Boxers[2], Boxers[3]);
	if (Boxers[3]->return_score())
		replacing(Boxers[2], Boxers[3]);

	auto_fight(Boxers[4], Boxers[5]);
	if (Boxers[5]->return_score())
		replacing(Boxers[5], Boxers[4]);

	auto_fight(Boxers[6], Boxers[7]);
	if (Boxers[7]->return_score())
		replacing(Boxers[6], Boxers[7]);



	change_stage(quarterfinal);
	
	while (quick_menu(Boxers));

	if (Boxers[0]->return_score())
	{
		fight(Boxers[0], Boxers[2]);

		auto_fight(Boxers[4], Boxers[6]);
		if (Boxers[6]->return_score())
			replacing(Boxers[4], Boxers[6]);

		change_stage(semifinal);
		while (quick_menu(Boxers));
		if (Boxers[0]->return_score())
		{
			fight(Boxers[0], Boxers[4]);
			if (Boxers[0]->return_score() != true)
				replacing(Boxers[4], Boxers[0]);

			change_stage(finall);
			save_points(Boxers[0]);
			while (quick_menu(Boxers));
		}
		else
		{
			save_points(Boxers[0]);
			replacing(Boxers[0], Boxers[4]);

			auto_fight(Boxers[0], Boxers[4]);
			if (Boxers[4]->return_score() != true)
				replacing(Boxers[0], Boxers[4]);

			change_stage(finall);
			while (quick_menu(Boxers));
		}
	}
	else
	{
		save_points(Boxers[0]);
		replacing(Boxers[0], Boxers[1]);
		
		if (Boxers[3]->return_score())
			replacing(Boxers[2], Boxers[3]);
		if (Boxers[5]->return_score())
			replacing(Boxers[4], Boxers[5]);
		if (Boxers[7]->return_score())
			replacing(Boxers[6], Boxers[7]);

		change_stage(quarterfinal);

		auto_fight(Boxers[0], Boxers[2]);
		if (Boxers[2]->return_score())
			replacing(Boxers[2], Boxers[0]);
		auto_fight(Boxers[4], Boxers[6]);
		if (Boxers[6]->return_score())
			replacing(Boxers[4], Boxers[6]);

		change_stage(semifinal);

		auto_fight(Boxers[0], Boxers[4]);
		if (Boxers[4]->return_score())
			replacing(Boxers[4], Boxers[0]);

		change_stage(finall);

	}

}

void Board::save_points(Fighter_Interface* Bxr)
{
	fstream file2;
	file2.open("points.txt", ios::out | ios::app);
	if (file2.good() == false)
	{
		system("cls");
		cout << "ERROR!!!" << endl;
		Sleep(3000);
		exit(0);
	}

	file2 << Bxr->return_name() << endl;
	file2 << Bxr->return_points() << endl;

	file2.close();
}

void Board::app_points()
{
	fstream file3;
	file3.open("points.txt", ios::in);
	int nr = 0, pts, iterator = 1;
	string name;

	while (getline(file3,name))
	{
		if (nr == 2) nr = 0;
		switch (nr)
		{
		case 0: 
			cout << iterator << ". " << name << endl;
			break;
		case 1:
			pts = atoi(name.c_str());
			cout << pts << endl;
			break;
		}
		nr++;
		iterator++;
	}
	getchar();

	file3.close();
}