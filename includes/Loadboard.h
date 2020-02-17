//
// Created by imsanskar on 2020-01-04.
//
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include "tigers.h"

enum GameState
{
    goatWin,
    tigerWin,
    Progress,
};


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
    bool isMove,isReleased,moveCompleted,isTigerPressed,isGoatReleased,isGoatPressed,goatEatenMove;
    Tiger tiger[4];
    int tigerChosen,goatChosen;
    sf::Vector2i newPos,oldPos;
    sf::Text tigerText,goatText,goatWinText;
    int position;
    std::vector<Cell> possibleMoves;
    std::vector<Cell> goatEatenMoves;

public:
    void render(sf::RenderWindow &,Goat *,const bool *, bool ,bool);
    void tigerMove(sf::Event &,sf::RenderWindow &);
    void placements(sf::Event &,sf::RenderWindow &,Goat *);
    Board();
    bool getState();
    void setState(bool );
    bool goatWin();
    bool eatGoat(Goat *);
    void goatMove(sf::Event & ,sf::Vector2i &,Goat *goat);
private:
    int getCellIndex(Cell &cell);
    bool checkMove();
    sf::Vector2i toPosition(Tiger &tiger,sf::Vector2i &);
    bool checkMove(Goat &goat,bool);
    sf::Vector2i toPosition(Goat &goat);
    void setEmpty();
    int findCell();
    std::vector<Cell> getPossibleMoves();
    void getGoatEatenMoves(int direction);
};