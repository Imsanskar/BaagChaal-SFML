//
// Created by imsanskar on 2020-01-04.
//
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include "tigers.h"
#include "goats.h"

typedef std::vector<Cell> vectorCell;
class Board
{
private:
    sf::Font font;
    Cell cell[25];
    Cell *initCell,finalCell;
    sf::Texture boardTexture;
    sf::RectangleShape boardImage;
    bool isMove,isReleased,moveCompleted,isTigerPressed,isGoatReleased,isGoatPressed;
    Tiger tiger[4];
    int tigerChosen;
    sf::Vector2i newPos,oldPos;
    sf::Text tigerText,goatText;
    sf::Rect<float> initBound;
    std::map<Cell,vectorCell> moveMap;

public:
    void LoadBoard(sf::RenderWindow &,Goat *,bool *);
    void tigerMove(sf::Event &,sf::RenderWindow &);
    void placements(sf::Event &,sf::RenderWindow &,Goat *);
    Board();
    bool getState();
    void setState(bool );
private:
    bool checkMove(Tiger &);
    sf::Vector2i toPosition(Tiger &tiger,sf::Vector2i &);
    bool checkMove(Goat &goat);
    sf::Vector2i toPosition(Goat &goat);
    void setEmpty();
    void setMoveMap();
};