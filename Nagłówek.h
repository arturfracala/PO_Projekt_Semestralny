#pragma once
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <time.h>
#include <fstream>
#include "stdafx.h"

using namespace std;

struct parameters
{
	int knockout_power;
	int defense;
	int strength;
	int health;
	string name;
	////////
	int dmg; 
	bool won;
	int points; 
};




class Fighter_Interface
{
public:
    void show_parameters();
    void change_health(int);
    void change_strength(int);
	void health_max();
	void change_name(string);
	void change_power(int);
	bool return_score();
	void change_score(bool);
	int return_power();
	string return_name();
	int return_defence();
	void max_strengh();
	int  return_health();
	int return_points();
	int return_strength();
	int show_dmg();
	virtual void Jab(Fighter_Interface *)=0;
	virtual void Hook(Fighter_Interface *)=0;
	virtual void Uppercut(Fighter_Interface *)=0;
	virtual void Clinching()=0;
protected:
	fstream file1;
	parameters Boxer_parameters;
};

class Boxer: public Fighter_Interface
{
public:
	static int objectCount;
	Boxer();
	~Boxer();
	virtual void Jab(Fighter_Interface *);
	virtual void Hook(Fighter_Interface *);
	virtual void Uppercut(Fighter_Interface *);
	virtual void Clinching();
};

class Swarmer:public Fighter_Interface
{
public:
	static int objectCount;
	Swarmer();
	~Swarmer();
	virtual void Jab(Fighter_Interface *);
	virtual void Hook(Fighter_Interface *);
	virtual void Uppercut(Fighter_Interface *);
	virtual void Clinching();
};

class Brawler :public Fighter_Interface
{
public:
	static int objectCount;
	Brawler();
	~Brawler();
	virtual void Jab(Fighter_Interface *);
	virtual void Hook(Fighter_Interface *);
	virtual void Uppercut(Fighter_Interface *);
	virtual void Clinching();
};

class Board
{
	enum stage
	{
		opening = 0, quarterfinal = 1, semifinal = 2, finall = 3
	} stt;
public:
	Board();
	void change_stage(stage);
	void panel(Fighter_Interface*[8]);
	void replacing(Fighter_Interface*,Fighter_Interface*);
	void auto_fight(Fighter_Interface *, Fighter_Interface *);
	void select_punch(int,Fighter_Interface*,Fighter_Interface*);
	void select_name(Fighter_Interface*);
	void player_fight(char ,Fighter_Interface *, Fighter_Interface *);
	void fight(Fighter_Interface *, Fighter_Interface *);
	void game(Fighter_Interface*[8]);
	bool quick_menu(Fighter_Interface*[8]);
	void players_game(Fighter_Interface*[8]);
	void display_players(Fighter_Interface*[8]);
	void tournament_ladder(Fighter_Interface*[8]);
	void instruction();
	void save_points(Fighter_Interface*);
	void app_points();
};

