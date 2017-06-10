// ConsoleApplication21.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

// PROJEKT SEMESTRALNY Z PROGRAMOWANIA OBIEKTOWEGO

#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <time.h>
#include <fstream>
#include "stdafx.h"
#include "Nag³ówek.h"

using namespace std;

void intro();

int Brawler::objectCount = 0;
int Swarmer::objectCount = 0;
int Boxer::objectCount = 0;

int main()
{
	intro();
	
	bool EXIT = false;
	Boxer contender1[3];
	Swarmer contender2[3];
	Brawler contender3[2];

	Fighter_Interface*pointer[9];

	pointer[0] = &contender1[0];
	pointer[1] = &contender1[1];
	pointer[2] = &contender1[2];
	pointer[3] = &contender2[0];
	pointer[4] = &contender2[1];
	pointer[5] = &contender2[2];
	pointer[6] = &contender3[0];
	pointer[7] = &contender3[1];

	Board obj2;

		obj2.panel(pointer);


    return 0;
}

void intro()
{
	HANDLE hOut1;
	hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 2; i < 16; i++)
	{
		system("cls");
		SetConsoleTextAttribute(hOut1, i);
		cout << "\n";
		cout << "   =========================" << endl;
		cout << "   ===ART OF THE KNOCKOUT===" << endl;
		cout << "   =========================" << endl;
		Sleep(1000);
	}
	system("cls");
}

