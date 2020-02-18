//
// Created by imsanskar on 2020-01-05.
//
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Piece.h"

enum goatState
{
    Alive,
    Dead,
};


class Goat:public Piece
{
private:
    bool isAlive;
    goatState state;

public:
    Goat();
    goatState getState();
    void setState(goatState );
};
