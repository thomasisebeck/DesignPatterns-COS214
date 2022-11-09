#include <iostream>
#include "PlayerFactory.h"
#include "Player.h"
#include "Goodie.h"
#include "Terrorist.h"
using namespace std;

int main() {

    PlayerFactory factory;

    for (int i = 0; i < 100; i++) {
        factory.getPlayer(rand() % 10)->mission();
    }

    return 0;
}