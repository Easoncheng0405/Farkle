//
// Created on 2019-05-13.
//

#include "dice.h"

dice::dice() {
    m_active = true;
    m_point = 1;
}

int dice::roll() {
    m_point = rand() % 6 + 1;
    return m_point;
}

int dice::point() {
    return m_active ? m_point : -1;
}
