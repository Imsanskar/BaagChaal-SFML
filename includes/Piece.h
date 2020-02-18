//
// Created by imsanskar on 2020-02-18.
//

#ifndef BAAGCHAAL_SFML_PIECE_H
#define BAAGCHAAL_SFML_PIECE_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics.hpp>
#include "Cell.h"

class Piece
{
protected:
    sf::Texture texture;
    sf::CircleShape shape;
    sf::Vector2f position;
    Cell *spot;

public:
    virtual void render(sf::RenderWindow &);
    sf::Rect<float> getGlobalBounds();
    sf::Vector2f getPosition();
    void setPosition(float x,float y);
    void setPosition(Cell *);
    Cell getSpot();
};


#endif //BAAGCHAAL_SFML_PIECE_H
