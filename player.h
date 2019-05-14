//
// Created on 2019-05-13.
//

#ifndef FARKLE_PLAYER_H
#define FARKLE_PLAYER_H

#include <iostream>
#include "dice.h"

using namespace std;

class player {

private:
    int m_score;
    int m_score_in_turn;
    const char *m_name;
    dice **m_dices;
    bool rolled = false;
public:

    player(int index);

    ~player();

    void start();

    void print_dices();

    bool farkle();

    void choose();

    int score();

    int choose_score();

    int get_score(int select);

    int active_dice_count();

    void print_win();
};


#endif //FARKLE_PLAYER_H
