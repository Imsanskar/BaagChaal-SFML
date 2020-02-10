//
// Created bx imsanskar on 2020-01-05.
//
#include"tigers.h"


void Tiger::render(sf::RenderWindow &mWindow)
{
    tigerImage.setPosition(tigerPos.x,tigerPos.y);
    mWindow.draw(tigerImage);
//    tigerImage.setPosition(pos.getCoord().x,pos.getCoord().y);
}

Tiger::Tiger()
{
    tigerTexture.loadFromFile("../Media/Images/tiger.png");
    tigerImage.setTexture(&tigerTexture);
    tigerImage.setRadius(35);
}

sf::Rect<float> Tiger::getGlobalBounds()
{
    return tigerImage.getGlobalBounds();
}

sf::Vector2f Tiger::getPosition()
{
    return tigerImage.getPosition();
}

void Tiger::setPosition(float x, float y)
{
    tigerPos.x=x;
    tigerPos.y=y;
}

void Tiger::setPosition(Cell *cell)
{
    pos=cell;
}

Cell* Tiger::getSpot()
{
    return pos;
}