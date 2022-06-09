//
// Created by imsanskar on 2020-01-05.
//

#ifndef BAAGCHAAL_TIGER_H
#define BAAGCHAAL_TIGER_H


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Piece.h"


class Tiger:public Piece
{


public:
    Tiger();//constructor

    bool operator < (Tiger t) const {
        return pos < t.pos;
    } 
};

#endif