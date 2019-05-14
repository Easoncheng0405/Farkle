//
// Created on 2019-05-14.
//

#include "game.h"

#define SCORE_WIN 5000

game::game() {
    m_player_count = 0;
}

void game::game_loop() {
    player *p;
    while (true) {
        bool win = false;
        for (int i = 0; i < m_player_count; i++) {
            p = m_players[i];
            win = p->score() >= SCORE_WIN;
            if (win) break;
            p->start();
        }
        // player won
        if (win) break;
    }
    p->print_win();
}

void game::start() {
    while (m_player_count < 1 || m_player_count > MAX_PLAYER_COUNT) {
        cout << endl << "Input the player count [0<x<=4]: ";
        cin >> m_player_count;
    }
    m_players = new player *[m_player_count];
    int index = rand() % m_player_count; // random player first
    for (int i = 0; i < m_player_count; i++) {
        m_players[i] = new player((i + index) % m_player_count);
    }
    cout << endl << "Game start with " << m_player_count << " players." << endl;
    // start game loop
    game_loop();
}
