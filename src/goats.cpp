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
    goatImage.setPosition(goatPos.x,goatPos.y);
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
void Goat::render(sf::RenderWindow &mWindow,float x,float y)
{
    goatImage.setPosition(x,y);
    mWindow.draw(goatImage);
}