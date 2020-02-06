//
// Created by imsanskar on 2020-01-05.
//

#include "goats.h"

void Goat::render(sf::RenderWindow &mWindow )
{
    goatImage.setPosition(goatPos.x,goatPos.y);
    mWindow.draw(goatImage);
}
Goat::Goat() 
{
    state=Dead;
    isAlive=false;
    goatTexture.loadFromFile("../Media/Images/goat.jpg");
    goatImage.setTexture(&goatTexture);
    goatImage.setRadius(35);
}

sf::FloatRect Goat::getGlobalBounds()
{
    return goatImage.getGlobalBounds();
}

sf::Vector2f Goat::getPosition()
{
    return goatImage.getPosition();
}

void Goat::setPosition(float x, float y)
{
    goatPos.x=x;
    goatPos.y=y;
}


goatState Goat::getState() {
    return state;
}

void Goat::setState(goatState _state)
{
    state=_state;
}