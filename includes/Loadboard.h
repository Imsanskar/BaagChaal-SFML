//
// Created by imsanskar on 2020-01-04.
//

#ifndef BAAGCHAAL_LOARDBOARD_H
#define BAAGCHAAL_LOARDBOARD_H

#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "tigers.h"
#include "goats.h"
#include <map>
#include "const.h"


class Board
{
public:
    const int MAX_GRID_X = 5;
    const int MAX_GRID_Y = 5;
    sf::Font font;
    Cell initCell,finalCell;
    sf::Texture boardTexture;
    sf::RectangleShape boardImage;
    sf::Text goatsAtt[2];
    bool isMove,isReleased,moveCompleted,isTigerPressed,isGoatReleased,isGoatPressed,goatEatenMove;
    Tiger tiger[4];
    int tigerChosen,goatChosen;
    sf::Vector2i newPos,oldPos;
    sf::Text tigerText,goatText,goatWinText;
    sf::SoundBuffer normalMoveBuffer,goatEatenMoveBuffer;
    sf::Sound normalMoveSound,goatEatenMoveSound;
    int position;
    std::vector<Cell> possibleMoves;
    std::vector<Cell> goatEatenMoves;
    int goatEaten = 0;
    int numberOfGoatPlaced = 0;


    Cell cells[25] = {
        Cell((0 % 5) * 187.5 + 75, (0 / 5) * 147.5 + 30),
        Cell((1 % 5) * 187.5 + 75, (1 / 5) * 147.5 + 30),
        Cell((2 % 5) * 187.5 + 75, (2 / 5) * 147.5 + 30),
        Cell((3 % 5) * 187.5 + 75, (3 / 5) * 147.5 + 30),
        Cell((4 % 5) * 187.5 + 75, (4 / 5) * 147.5 + 30),
        Cell((5 % 5) * 187.5 + 75, (5 / 5) * 147.5 + 30),
        Cell((6 % 5) * 187.5 + 75, (6 / 5) * 147.5 + 30),
        Cell((7 % 5) * 187.5 + 75, (7 / 5) * 147.5 + 30),
        Cell((8 % 5) * 187.5 + 75, (8 / 5) * 147.5 + 30),
        Cell((9 % 5) * 187.5 + 75, (9 / 5) * 147.5 + 30),
        Cell((10 % 5) * 187.5 + 75, (10 / 5) * 147.5 + 30),
        Cell((11 % 5) * 187.5 + 75, (11 / 5) * 147.5 + 30),
        Cell((12 % 5) * 187.5 + 75, (12 / 5) * 147.5 + 30),
        Cell((13 % 5) * 187.5 + 75, (13 / 5) * 147.5 + 30),
        Cell((14 % 5) * 187.5 + 75, (14 / 5) * 147.5 + 30),
        Cell((15 % 5) * 187.5 + 75, (15 / 5) * 147.5 + 30),
        Cell((16 % 5) * 187.5 + 75, (16 / 5) * 147.5 + 30),
        Cell((17 % 5) * 187.5 + 75, (17 / 5) * 147.5 + 30),
        Cell((18 % 5) * 187.5 + 75, (18 / 5) * 147.5 + 30),
        Cell((19 % 5) * 187.5 + 75, (19 / 5) * 147.5 + 30),
        Cell((20 % 5) * 187.5 + 75, (20 / 5) * 147.5 + 30),
        Cell((21 % 5) * 187.5 + 75, (21 / 5) * 147.5 + 30),
        Cell((22 % 5) * 187.5 + 75, (22 / 5) * 147.5 + 30),
        Cell((23 % 5) * 187.5 + 75, (23 / 5) * 147.5 + 30),
        Cell((24 % 5) * 187.5 + 75, (24 / 5) * 147.5 + 30)
    };

public:
    void render(sf::RenderWindow &,Goat *,const bool *, bool ,bool,int ,int );//renders the goat into ths screen
    void tigerMove(sf::Event &,sf::RenderWindow &);//for the movement of the tiger
    void placements(sf::Event &,sf::RenderWindow &,Goat *);//for the placement of the goat
    Board();//constructor
    bool getState();//returns boolean if the move is completed or not
    void setState(bool );
    bool goatWin();//checks for the goat win case
    bool eatGoat(Goat *);//for killing the goats
    std::vector<Cell> getGoatEatenMoves();//returns the goat eaten moves
    void goatMove(sf::Event & ,sf::Vector2i &,Goat *goat);//for the movement  of the goats
    bool isClosed(Cell &_cell);//checks if the cell is closed
    int noOfClosedCell();//return the number of closed cell

    std::vector <std::pair<int, std::vector<Cell>>> getTigerMoves();
    std::vector <std::pair<int, std::vector<Cell>>> getGoatMoves(Goat goats[20]);
    void moveTiger(int tigerIndex, const Cell& dest);
    std::vector <Cell> getEmptyCells();
    void placeGoat(const Cell& cell, Goat& goat);
    void moveGoat(Goat &goat, const Cell& dest);
    uint64_t getBoardEncoding();
    void decodeBoard(uint64_t value);
    bool isGameOver();
    bool tigerWin();

private:
    int getCellIndex(const Cell &cell);//returns the index of the cell
    bool checkMove();//checks if the move is valid
    bool checkMove(Tiger &tiger);
    sf::Vector2i toPosition(Tiger &tiger,sf::Vector2i &);//function not used
    bool checkMove(Goat &goat,bool);//checks if the move of goat is valid
    sf::Vector2i toPosition(Goat &goat);//function not used
    void setEmpty();//sets the state of the cell to empty after the move is completed
    int findCell();//return the initial index of final cell
    std::vector<Cell> getPossibleMoves(const Cell &);//returns possible moves of the tiger
    void getGoatEatenMoves(int direction);//creates the goat eating moves of the tiger

};

#endif