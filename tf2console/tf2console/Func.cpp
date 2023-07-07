#include <iostream> 
#include "Classes.h"

void isdead (int team){
	for (int i = t2min; i <= t2max; i++) {
		if (players[i]->hp > 0) {
			team2dead = false;
			break;
		}
		else {
			team2dead = true;
			std::cout << "Team 1 has been eliminated! ";
			system("pause");
		}
	}