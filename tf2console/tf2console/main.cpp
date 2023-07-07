#include <Windows.h>
#include <iostream>
#include "Classes.h"
#include <vector>
#include "functions.h"


int main() {
	std::cout << R"(
//   __      _____ _    ___ ___  __  __ ___   _____ ___             
//   \ \    / / __| |  / __/ _ \|  \/  | __| |_   _/ _ \            
//    \ \/\/ /| _|| |_| (_| (_) | |\/| | _|    | || (_) |           
//    _\_/\_/_|___|____\___\___/|_|__|_|___|_  |_| \___/__ ___  ___ 
//   |_   _| __|_  )  / __|_ _|  \/  | | | | |    /_\_   _/ _ \| _ \
//     | | | _| / /   \__ \| || |\/| | |_| | |__ / _ \| || (_) |   /
//     |_| |_| /___|  |___/___|_|  |_|\___/|____/_/ \_\_| \___/|_|_\
//                      PRESS ENTER TO PLAY                                       

)" << '\n';


	while (!(GetAsyncKeyState(VK_RETURN))) {

	}
	for (int b = 0; b < 5; b++) {
		system("cls"); 
		std::cout << "loading...-";
		system("cls");
		std::cout << "loading...\\";
		system("cls");
		std::cout << "loading...|";
		system("cls");
		std::cout << "loading.../";
	}
	system("cls");
	int playerCount;
	int* playerCountptr = &playerCount;
	std::cout << "\nHow many players would you like on each team? : ";
	std::cin >> playerCount;
	std::vector<Player*> players;
	int t1min = 0;
	int t1max = playerCount - 1;
	int t2min = playerCount;
	int t2max = (playerCount * 2) - 1;
	

	bool team1dead = true;
	bool team2dead = true;

	for (int i = 0; i < playerCount * 2; i++) {
		system("cls");
		textColor(WHITE);
		int p2count = i - *playerCountptr +1;
		int t = 0; 
		int choice = 0; 
		if (i < *playerCountptr) {
			std::cout << std::endl << "----- PLAYER 1 (" << (i+1) << "/" << *playerCountptr << ")------" << std::endl;
			t = 1;
		}
		else {
			std::cout << std::endl << "----- PLAYER 2 (" << p2count << "/" << *playerCountptr << ")------" << std::endl;
			t = 2;
		}
		
		std::cout << "Please Select:\n";
		textColor(BLUE); 
		std::cout << "1. Light\n";
		textColor(YELLOW);
		std::cout << "2. Medium\n";
		textColor(RED);
		std::cout << "3. Heavy\n";
		textColor(WHITE); 
		std::cin >> choice;
		
		if (choice == 1) {
			Light* lightplayerptr = new Light(t);
			players.push_back(lightplayerptr);
			textColor(BLUE);
			std::cout << "LIGHT ADDED\n";
			textColor(WHITE);
			Sleep(1000); 
		}
		else if (choice == 2) {
			Medium* mediumplayerptr = new Medium(t);
			players.push_back(mediumplayerptr);
			textColor(YELLOW);
			std::cout << "MEDIUM ADDED\n";
			textColor(WHITE);
			Sleep(1000);
		}
		else if (choice == 3) {
			Heavy* heavyplayerptr = new Heavy(t);
			players.push_back(heavyplayerptr);
			textColor(RED);
			std::cout << "HEAVY ADDED\n";
			textColor(WHITE);
			Sleep(1000);
		}
		else {
			std::cout << "Invalid Number Recieved";
		}
	}
	system("cls"); 
	std::cout << "Let the battle begin! \n";
	Sleep(1000);
	int p1;
	int p2;
	while (true) {
		
		bool t1 = isDead(1, t1min, t1max, players);
		bool t2 = isDead(2, t2min, t2max, players);
		
		if (!t1 && !t2) {
			do {
				p1 = rand() % (t1max - t1min + 1) + t1min;
			} while (players[p1]->hp <= 0);
			system("cls");
			std::cout << "Player 1 has selected " << players[p1]->name << std::endl;
			Sleep(1500);
			do {
				p2 = rand() % (t2max - t2min + 1) + t2min;
			} while (players[p2]->hp <= 0);
			
			std::cout << "Player 1's " << players[p1]->name << " troop will attack Player 2's " << players[p2]->name << " troop!\n";
			Sleep(3000);

			attackAni(1,players[p1],players[p2]);
			players[p1]->Attack(players[p1], players[p2]);

		}
		t1 = isDead(2, t2min, t2max, players);

		if (!t1 && !t2) {
			do {
				p2 = rand() % (t2max - t2min + 1) + t2min;
			} while (players[p2]->hp <= 0);
			system("cls");
			std::cout << "Player 2 has selected " << players[p2]->name << std::endl;
			Sleep(1500);
			do {
				p1 = rand() % (t1max - t1min + 1) + t1min;
			} while (players[p1]->hp <= 0);
			std::cout << "Player 2's " << players[p2]->name <<" troop will attack Player 1's " << players[p1]->name << " troop!\n";
			Sleep(3000);
			attackAni(2,players[p2], players[p1]);
			players[p1]->Attack(players[p2], players[p1]);


		}
		t2 = isDead(1, t1min, t1max, players);
		Sleep(5000); 
		if (t1 || t2) {
			break;
		}
	}
	system("cls");
	textColor(BLUE);
	std::cout << R"(
//    _____ _   _    _    _   _ _  __ __   _____  _   _   _____ ___  ____    ____  _        _ __   _____ _   _  ____ 
//   |_   _| | | |  / \  | \ | | |/ / \ \ / / _ \| | | | |  ___/ _ \|  _ \  |  _ \| |      / \\ \ / /_ _| \ | |/ ___|
//     | | | |_| | / _ \ |  \| | ' /   \ V / | | | | | | | |_ | | | | |_) | | |_) | |     / _ \\ V / | ||  \| | |  _ 
//     | | |  _  |/ ___ \| |\  | . \    | || |_| | |_| | |  _|| |_| |  _ <  |  __/| |___ / ___ \| |  | || |\  | |_| |
//     |_| |_| |_/_/   \_\_| \_|_|\_\   |_| \___/ \___/  |_|   \___/|_| \_\ |_|   |_____/_/   \_\_| |___|_| \_|\____|
//                                                                                                                   

)" << std::endl; 
	Sleep(10000); 
	
	return 0;
}
	

