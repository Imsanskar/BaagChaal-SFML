//
// Created by imsanskar on 2020-02-18.
//

#include <Piece.h>


void Piece::render(sf::RenderWindow &window)
{
    shape.setPosition(position.x,position.y);
    window.draw(shape);
}

sf::Rect<float> Piece::getGlobalBounds()
{
    return shape.getGlobalBounds();
}

sf::Vector2f Piece::getPosition() {
    return shape.getPosition();
}

void Piece::setPosition(float x, float y) {
    position.x=x;
    position.y=y;
}

void Piece::setPosition(Cell *_cell) {
    spot=_cell;
}

Cell Piece::getSpot()
{
    return *spot;
}
