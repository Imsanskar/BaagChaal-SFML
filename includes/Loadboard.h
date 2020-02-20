//
// Created by imsanskar on 2020-01-04.
//
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include "tigers.h"



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
    void tigerMove(sf::Event &,sf::RenderWindow &);//for the movement of the tiger
    void placements(sf::Event &,sf::RenderWindow &,Goat *);//for the placement of the goat
    Board();//constructor
    bool getState();//returns boolean if the move is completed or not
    void setState(bool );
    bool goatWin();//checks for the goat win case
    bool eatGoat(Goat *);//for killing the goats
    void goatMove(sf::Event & ,sf::Vector2i &,Goat *goat);//for the movement  of the goats
private:
    int getCellIndex(Cell &cell);//returns the index of the cell
    bool checkMove();//checks if the move is valid
    sf::Vector2i toPosition(Tiger &tiger,sf::Vector2i &);//function not used
    bool checkMove(Goat &goat,bool);//checks if the move of goat is valid
    sf::Vector2i toPosition(Goat &goat);//function not used
    void setEmpty();//sets the state of the cell to empty after the move is completed
    int findCell();//return the initial index of final cell
    std::vector<Cell> getPossibleMoves(Cell &);//returns possible moves of the tiger
    void getGoatEatenMoves(int direction);//creates the goat eating moves of the tiger
};