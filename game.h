//
// Created on 2019-05-14.
//

#ifndef FARKLE_GAME_H
#define FARKLE_GAME_H

#include <iostream>
#include "player.h"

using namespace std;

#define MAX_PLAYER_COUNT 4

class game {

private:
    int m_player_count;
    player** m_players;

public:
    game();

    void game_loop();

    void start();
};


#endif //FARKLE_GAME_H
