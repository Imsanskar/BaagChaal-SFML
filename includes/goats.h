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
    goatState state;

public:
    Goat();//constructor
//    void render(sf::RenderWindow &);//renders to the screen
//    sf::Rect<float> getGlobalBounds();//returns the boundary of the goat
//    sf::Vector2f getPosition();//return the position the the goat
//    void setPosition(float x,float y);//sets the position of the goat
//    void setPosition(Cell *);//sets the cell of the goat
//    Cell getSpot();//returns the cell of the goat
    goatState getState();//getter of the state of the goat
    void setState(goatState );//setter of the goat state
};
