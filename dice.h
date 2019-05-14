//
// Created on 2019-05-13.
//

#ifndef FARKLE_DICE_H
#define FARKLE_DICE_H

#include <stdlib.h>

class dice {

private:
    int m_point;

public:

    bool m_active;

    dice();

    int roll();

    int point();
};


#endif //FARKLE_DICE_H
