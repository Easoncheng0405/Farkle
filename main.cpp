#include <iostream>
#include "dice.h"
#include "player.h"
#include "game.h"

using namespace std;

int main() {
    srand((unsigned) time(nullptr)); // initialized random seed

    game game;
    game.start();
}