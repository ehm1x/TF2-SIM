#pragma once
#include <iostream> 
#include <vector>
#include <Windows.h>

class Player {
public:
    int hp;
    int dmg;
    int team; 
    std::string name;

    Player(const std::string& playerName, int playerHP, int playerDMG, int playerTeam)
        : hp(playerHP), dmg(playerDMG), name(playerName), team(playerTeam)
    {
    }
    virtual void PrintInfo() {
        std::cout << "Player Info:" << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "HP: " << hp << std::endl;
        std::cout << "Damage: " << dmg << std::endl;
        std::cout << "Team: " << team << std::endl;
    }
    void Attack(Player* attacker, Player* victim) {
        victim->hp -= attacker->dmg;
        std::cout <<"Player " << attacker->team << "'s " << attacker->name << " troop has dealt " << attacker->dmg << " to Player " << victim->team << "'s " << victim->name << " troop!" << std::endl;
        Sleep(2500);
        if (victim->hp <= 0) {
            std::cout << "Player " << victim->team << "'s " << victim->name << " troop has been killed!\n";
            Sleep(2500);
            system("cls"); 
        }
      
    }
};


class Heavy : public Player {
public: 
    Heavy(int playerTeam)
        : Player("Heavy", 100, 15, playerTeam)

    {
    }
};

class Light : public Player {
public:
    Light(int playerTeam)
        : Player("Light", 20, 50, playerTeam)

    {
    }
};

class Medium : public Player {
public:
    Medium(int playerTeam)
        : Player("Medium", 50, 25, playerTeam)

    {
    }
};