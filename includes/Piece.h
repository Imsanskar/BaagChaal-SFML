//
// Created by imsanskar on 2020-02-22.
//

#ifndef BAAGCHAAL_PIECE_H
#define BAAGCHAAL_PIECE_H

#include <SFML/Graphics.hpp>
#include "Cell.h"

class Piece
{
protected:
    sf::Texture texture;
    sf::CircleShape image;
    sf::Vector2f position;
    Cell *pos;

public:
    Piece();//constructor
    void render(sf::RenderWindow &);//renders the tiger
    sf::Rect<float> getGlobalBounds();//returns the boundary of the tiger
    sf::Vector2f getPosition();//getter of the position of the tiger
    void setPosition(float x,float y);//setter of the position of the  tiger
    void setPosition(Cell *);//setter of the cell of the tiger
    Cell getSpot();//getter of the cell of the tiger
};


#endif //BAAGCHAAL_PIECE_H
