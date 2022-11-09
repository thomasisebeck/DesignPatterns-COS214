#pragma once
#include "Player.h"
#include "Goodie.h"
#include "Terrorist.h"

class PlayerFactory {
private:
    Player** players;
    int getRandomType() {
        return rand() % 2;
    }
public:
    PlayerFactory() {
        players = new Player *[10];
        for (int i = 0; i < 10; i++)
            players[i] = nullptr;
    }
    Player* getPlayer(int index) {
        if (index > 9 || index < 0) {
            std::cout << "Invalid index " << std::endl;
            return nullptr;
        }

        if (players[index] != nullptr)
            return players[index];

        if (getRandomType() == 0)  //create a goodie
            players[index] = new Goodie("Knife", "Kill bad guys");
        else
            players[index] = new Terrorist("Gun", "Plant a bomb");

        return players[index];
    }
    ~PlayerFactory() {
        for (int i = 0; i < 10; i++) {
            if (players[i] != nullptr)
                delete players[i];
        }
        delete [] players;
    }
};