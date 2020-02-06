//
// Created by imsanskar on 2020-01-04.
//
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include "tigers.h"
#include "goats.h"
#include "Cell.h"


class Board
{
private:
    sf::Font font;
    Cell cell[25];
    sf::Vector2i coordinates[25];
    sf::Texture boardTexture;
    sf::RectangleShape boardImage;
    bool isMove,isReleased,moveCompleted,isTigerPressed;
    Tiger tiger[4];
    int tigerChosen;
    sf::Vector2i newPos,oldPos;
    sf::Text tigerText,goatText;

public:
    void LoadBoard(sf::RenderWindow &,Goat *,bool *);
    void tigerMove(sf::Event &,sf::RenderWindow &);
    void placements(sf::Event &,sf::RenderWindow &,Goat &goat);
    Board();
    bool getState();
    void setState(bool );
private:
    bool checkMove(Tiger &tiger);
    sf::Vector2i toPosition(Tiger &tiger,sf::Vector2i &);
    bool checkMove(Goat &goat);
    sf::Vector2i toPosition(Goat &goat);
};