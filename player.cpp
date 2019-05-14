//
// Created on 2019-05-13.
//

#include "player.h"

#define DICE_COUNT 6

const char *PLAYER_NAMES[] = {"Odin", "Thor", "Loki", "Hela"};

player::player(int index) {
    m_score = m_score_in_turn = 0;
    m_name = PLAYER_NAMES[index];
    m_dices = new dice *[DICE_COUNT];
    for (int i = 0; i < DICE_COUNT; ++i) {
        m_dices[i] = new dice();
    }
}

player::~player() {
}

void player::start() {
    cout << endl << m_name << "'s turn" << endl;
    for (int i = 0; i < DICE_COUNT; ++i) {
        m_dices[i]->m_active = true;
    }
    choose();
}

void player::print_dices() {
    cout << endl;
    for (int i = 0; i < DICE_COUNT; ++i) {
        int point = m_dices[i]->point();
        char c = point < 0 ? 'x' : point + '0';
        cout << "[" << c << "]" << "\t";
    }
    cout << endl;
    for (int i = 0; i < DICE_COUNT; ++i) {
        cout << " " << i + 1 << " " << "\t";
    }
    cout << endl;
}

bool player::farkle() {
    bool has_1_5 = false;
    bool has3same = false;
    int count[] = {0, 0, 0, 0, 0, 0};
    for (int i = 0; i < DICE_COUNT; ++i) {
        if (m_dices[i]->point() < 0) continue;
        ++count[m_dices[i]->point() - 1];
        if (m_dices[i]->point() == 1 || m_dices[i]->point() == 5)
            has_1_5 = true;
    }
    for (int c : count) {
        if (c >= 3)
            has3same = true;
    }
    return !(has_1_5 || has3same);
}

void player::choose() {
    cout << endl << "**********************************************" << endl
         << m_name << " Total: " << m_score << " , Current: "
         << m_score_in_turn << " , Dices Left: " << active_dice_count() << endl
         << "**********************************************" << endl
         << endl << "Do you want to [q]uit, [r]oll or [s]core? ";
    char c;
    cin >> c;
    switch (c) {
        case 'q':
            m_score += m_score_in_turn;
            m_score_in_turn = 0;
            rolled = false;
            cout << endl << m_name << " quit this turn with score " << m_score << endl;
            break;
        case 'r':
            for (int i = 0; i < DICE_COUNT; ++i) {
                m_dices[i]->roll();
            }
            rolled = true;
            print_dices();
            if (farkle()) {
                m_score_in_turn = 0;
                cout << endl << m_name << " has a farkle with score: " << m_score << endl;
                rolled = false;
            } else {
                choose();
            }
            break;
        case 's':
            if (rolled) {
                cout << endl << "Please input the num of your score combine without space."
                     << endl << "You can only input a single score combine in one select." << endl;
                m_score_in_turn += choose_score();
            } else {
                cout << endl << "Please roll your dices first." << endl;
            }
            choose();
            break;
        default:
            choose();
    }
}

int player::score() {
    return m_score;
}

int player::choose_score() {
    int input;
    cout << "Your Input(Enter 0 to cancel score) : ";
    cin >> input;
    int score = get_score(input);
    if (score < 0) {
        cout << endl << "Please Input a correct score combine." << endl;
        return choose_score();
    }
    print_dices();
    return score;
}

int player::get_score(int select) {
    if (select == 0) return 0;
    if (select >= 1 && select <= 6) {
        if (m_dices[select - 1]->m_active) {
            if (m_dices[select - 1]->point() == 1) {
                m_dices[select - 1]->m_active = false;
                return 100;
            }
            if (m_dices[select - 1]->point() == 5) {
                m_dices[select - 1]->m_active = false;
                return 50;
            }
        }
    }
    if (select >= 123 && select <= 654) {
        int a = select % 10;
        select = select / 10;
        int b = select % 10;
        int c = select / 10;
        if (a != b && a != c && b != c) {
            if (m_dices[a - 1]->point() == m_dices[b - 1]->point() &&
                m_dices[b - 1]->point() == m_dices[c - 1]->point()
                && m_dices[a - 1]->point() != -1) {
                int score = 0;
                switch (m_dices[a - 1]->point()) {
                    case 1:
                        score = 1000;
                        break;
                    case 2:
                        score = 200;
                        break;
                    case 3:
                        score = 300;
                        break;
                    case 4:
                        score = 400;
                        break;
                    case 5:
                        score = 500;
                        break;
                    case 6:
                        score = 600;
                        break;
                }
                m_dices[a - 1]->m_active = m_dices[b - 1]->m_active = m_dices[c - 1]->m_active = false;
                return score;
            }
        }
    }
    return -1;
}

int player::active_dice_count() {
    int count = 0;
    for (int i = 0; i < DICE_COUNT; ++i) {
        if (m_dices[i]->m_active)
            ++count;
    }
    return count;
}

void player::print_win() {
    cout << endl << m_name << " has win this game with score: " << m_score << endl;
}
