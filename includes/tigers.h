//
// Created by imsanskar on 2020-01-05.
//
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Cell.h"

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
    Tiger();
    void render(sf::RenderWindow &);
    sf::Rect<float> getGlobalBounds();
    sf::Vector2f getPosition();
    void setPosition(float x,float y);
    void setPosition(Cell *);
    Cell* getSpot();
};