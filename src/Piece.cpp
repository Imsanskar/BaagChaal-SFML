//
// Created by imsanskar on 2020-02-22.
//

#include "../includes/Piece.h"

void Piece::render(sf::RenderWindow &mWindow)
{
    image.setPosition(position.x,position.y);
    mWindow.draw(image);
//    image.setPosition(pos.getCoord().x,pos.getCoord().y);
}


sf::Rect<float> Piece::getGlobalBounds()
{
    return image.getGlobalBounds();
}

sf::Vector2f Piece::getPosition()
{
    return image.getPosition();
}

void Piece::setPosition(float x, float y)
{
    position.x=x;
    position.y=y;
}

void Piece::setPosition(Cell *cell)
{
    pos=cell;
}

Cell Piece::getSpot()
{
    return *pos;
}

Piece::Piece() {

}
