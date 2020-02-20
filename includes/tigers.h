//
// Created by imsanskar on 2020-01-05.
//
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "goats.h"


class Tiger
{
private:
    sf::Font font;
    sf::Texture tigerTexture;
    sf::CircleShape tigerImage;
    sf::Vector2f tigerPos;
    bool isPressed;
    Cell *pos;

public:
    Tiger();//constructor
    void render(sf::RenderWindow &);//renders the tiger
    sf::Rect<float> getGlobalBounds();//returns the boundary of the tiger
    sf::Vector2f getPosition();//getter of the position of the tiger
    void setPosition(float x,float y);//setter of the position of the  tiger
    void setPosition(Cell *);//setter of the cell of the tiger
    Cell getSpot();//getter of the cell of the tiger
};