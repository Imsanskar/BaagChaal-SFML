//
// Created by imsanskar on 2020-01-05.
//
#include "../includes/goats.h"

Goat::Goat()
{
    state=Dead;
    texture.loadFromFile("../Media/Images/goat.jpg");
    image.setTexture(&texture);
    image.setRadius(35);
}



goatState Goat::getState() {
    return state;
}

void Goat::setState(goatState _state)
{
    state=_state;
}




