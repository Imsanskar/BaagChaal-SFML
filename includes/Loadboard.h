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
    const int MAX_GRID_X = 5;
    const int MAX_GRID_Y = 5;
    sf::Font font;
    Cell cell[25];
    Cell initCell,finalCell;
    sf::Texture boardTexture;
    sf::RectangleShape boardImage;
    bool isMove,isReleased,moveCompleted,isTigerPressed,isGoatReleased,isGoatPressed;
    Tiger tiger[4];
    int tigerChosen;
    sf::Vector2i newPos,oldPos;
    sf::Text tigerText,goatText;
    int position;
    std::vector<Cell> possibleMoves;
    std::vector<Cell> goatEatenMoves;

public:
    void LoadBoard(sf::RenderWindow &,Goat *,bool *);
    void tigerMove(sf::Event &,sf::RenderWindow &);
    void placements(sf::Event &,sf::RenderWindow &,Goat *);
    Board();
    bool getState();
    void setState(bool );
private:
    bool checkMove();
    sf::Vector2i toPosition(Tiger &tiger,sf::Vector2i &);
    bool checkMove(Goat &goat);
    sf::Vector2i toPosition(Goat &goat);
    void setEmpty();
    int findCell();
    std::vector<Cell> getPossibleMoves();
    void getGoatEatenMoves(int direction);
};