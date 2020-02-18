//
// Created by imsanskar on 2020-01-05.
//
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Cell.h"

enum goatState
{
    Alive,
    Dead,
};


class Goat
{
private:
    sf::Texture goatTexture;
    sf::CircleShape goatImage;
    sf::Vector2f goatPos;
    bool isAlive;
    goatState state;
    Cell *pos;

public:
    Goat();
    void render(sf::RenderWindow &);
    sf::Rect<float> getGlobalBounds();
    sf::Vector2f getPosition();
    void setPosition(float x,float y);
    void setPosition(Cell *);
    Cell getSpot();
    goatState getState();
    void setState(goatState );
};
