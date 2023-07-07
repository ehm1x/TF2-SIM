#pragma once
#include <Windows.h>
#include <iostream>
#include "Classes.h"
#include <vector>

enum console_color {
	BLACK,
	DARKRED,
	DARKGREEN,
	DARKYELLOW,
	DARKBLUE,
	DARKMAGENTA,
	DARKCYAN,
	DARKWHITE,
	DARKBLACK,
	BLUE,
	GREEN,
	LIGHTBLUE,
	RED,
	MAGENTA,
	YELLOW,
	WHITE,
};

void textColor(int c) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (unsigned short)c);
}

bool isDead(int team, int tmin, int tmax, const std::vector<Player*>& players) {
	for (int i = tmin; i <= tmax; i++) {
		if (players[i]->hp > 0) {
			return false;
		}
	}

	if (team == 1) {
		textColor(RED);
		std::cout << R"(
//    _____ ___   _   __  __   _   _  _   _   ___                        
//   |_   _| __| /_\ |  \/  | / | | || | /_\ / __|                       
//     | | | _| / _ \| |\/| | | | | __ |/ _ \\__ \                       
//    _|_|_|___/_/_\_\_| _|_|_|_| |_||_/_/_\_\___/  _   _ _____ ___ ___  
//   | _ ) __| __| \| | | __| |  |_ _|  \/  |_ _| \| | /_\_   _| __|   \ 
//   | _ \ _|| _|| .` | | _|| |__ | || |\/| || || .` |/ _ \| | | _|| |) |
//   |___/___|___|_|\_| |___|____|___|_|  |_|___|_|\_/_/ \_\_| |___|___/ 
//                                                                                                                                                                                   
)" << std::endl;
	}
	if (team == 2) {
		textColor(RED);
		std::cout << R"(
//    _____ ___   _   __  __   ___   _  _   _   ___                      
//   |_   _| __| /_\ |  \/  | |_  ) | || | /_\ / __|                     
//     | | | _| / _ \| |\/| |  / /  | __ |/ _ \\__ \                     
//    _|_|_|___/_/_\_\_| _|_|_/___|_|_||_/_/ \_\___/_   _ _____ ___ ___  
//   | _ ) __| __| \| | | __| |  |_ _|  \/  |_ _| \| | /_\_   _| __|   \ 
//   | _ \ _|| _|| .` | | _|| |__ | || |\/| || || .` |/ _ \| | | _|| |) |
//   |___/___|___|_|\_| |___|____|___|_|  |_|___|_|\_/_/ \_\_| |___|___/ 
//                                                                                                                                                                                        
)" << std::endl;
	}
	return true;

}

void attackAni(int team, Player* attacker, Player* victim) {
	if (team == 1) {
		std::string space;
		if (attacker->name == "Heavy" || attacker->name == "Light") {
			space = "                      ";
		}
		if (attacker->name == "Medium") {
			space = "                     ";
		}
		system("cls");
		std::cout << "Team 1                     Team 2" << std::endl;
		std::cout << attacker->name << space << victim->name;
		Sleep(200);
		system("cls");
		std::cout << "Team 1 ->                  Team 2" << std::endl;
		std::cout << attacker->name << space << victim->name << std::endl;
		Sleep(200);
		system("cls");
		std::cout << "Team 1    ->               Team 2" << std::endl;
		std::cout << attacker->name << space << victim->name << std::endl;
		Sleep(200);
		system("cls");
		std::cout << "Team 1        ->           Team 2" << std::endl;
		std::cout << attacker->name << space << victim->name << std::endl;
		Sleep(200);
		system("cls");
		std::cout << "Team 1           ->        Team 2" << std::endl;
		std::cout << attacker->name << space << victim->name << std::endl;
		Sleep(200);
		system("cls");
		std::cout << "Team 1               ->    Team 2" << std::endl;
		std::cout << attacker->name << space << victim->name << std::endl;
		Sleep(200);
		system("cls");
		std::cout << "Team 1                   ->Team 2" << std::endl;
		std::cout << attacker->name << space << victim->name << std::endl;
		Sleep(200);
		system("cls");
		std::cout << "Team 1                     ";
		textColor(RED);
		std::cout << "Team 2" << std::endl;
		textColor(WHITE);
		std::cout << attacker->name << space << victim->name << std::endl;
		Sleep(600);
		system("cls");
		textColor(WHITE);
		std::cout << "Team 1                     Team 2" << std::endl;
		std::cout << attacker->name << space << victim->name << std::endl;
		Sleep(600);
		system("cls");
		std::cout << "Team 1                     ";
		textColor(RED);
		std::cout << "Team 2" << std::endl;
		textColor(WHITE);
		std::cout << attacker->name << space << victim->name << std::endl;
		Sleep(600);
		system("cls");
		textColor(WHITE);
		std::cout << "Team 1                     Team 2" << std::endl;
		std::cout << attacker->name << space << victim->name << std::endl;
		Sleep(600);


	}
	if (team == 2) {
		std::string space;
		if (attacker->name == "Heavy" || attacker->name == "Light") {
			space = "                      ";
		}
		if (attacker->name == "Medium") {
			space = "                     ";
		}
		system("cls");
		std::cout << "Team 2                     Team 1" << std::endl;
		std::cout << attacker->name << space << victim->name;
		Sleep(250);
		system("cls");
		std::cout << "Team 2 ->                  Team 1" << std::endl;
		std::cout << attacker->name << space << victim->name << std::endl;
		Sleep(200);
		system("cls");
		std::cout << "Team 2    ->               Team 1" << std::endl;
		std::cout << attacker->name << space << victim->name << std::endl;
		Sleep(200);
		system("cls");
		std::cout << "Team 2        ->           Team 1" << std::endl;
		std::cout << attacker->name << space << victim->name << std::endl;
		Sleep(200);
		system("cls");
		std::cout << "Team 2           ->        Team 1" << std::endl;
		std::cout << attacker->name << space << victim->name << std::endl;
		Sleep(200);
		system("cls");
		std::cout << "Team 2               ->    Team 1" << std::endl;
		std::cout << attacker->name << space << victim->name << std::endl;
		Sleep(200);
		system("cls");
		std::cout << "Team 2                   ->Team 1" << std::endl;
		std::cout << attacker->name << space << victim->name << std::endl;
		Sleep(200);
		system("cls");
		std::cout << "Team 2                     ";
		textColor(RED);
		std::cout << "Team 1" << std::endl;
		textColor(WHITE);
		std::cout << attacker->name << space << victim->name << std::endl;
		Sleep(600);
		system("cls");
		textColor(WHITE);
		std::cout << "Team 2                     Team 1" << std::endl;
		std::cout << attacker->name << space << victim->name << std::endl;
		Sleep(600);
		system("cls");
		std::cout << "Team 2                     ";
		textColor(RED);
		std::cout << "Team 1" << std::endl;
		textColor(WHITE);
		std::cout << attacker->name << space << victim->name << std::endl;
		Sleep(600);
		system("cls");
		textColor(WHITE);
		std::cout << "Team 2                     Team 1" << std::endl;
		std::cout << attacker->name << space << victim->name << std::endl;
		Sleep(600);


	}
}
