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


class Board
{
public:
    const int MAX_GRID_X = 5;
    const int MAX_GRID_Y = 5;
    sf::Font font;
    Cell cell[25];
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


    std::map <int, std::vector<Cell>> getTigerMoves() {
        std::map<int, std::vector<Cell>> moves;
        for (int i = 0; i < 4; i++) {
            std::vector<Cell> possibleMoves;
            std::vector<Cell> normalMoves = getPossibleMoves(tiger[i].getSpot());
            possibleMoves.reserve(normalMoves.size() + goatEatenMoves.size());
            possibleMoves.insert(possibleMoves.end(), goatEatenMoves.begin(), goatEatenMoves.end());
            possibleMoves.insert(possibleMoves.end(), normalMoves.begin(), normalMoves.end());
            moves.insert(std::pair<int, std::vector<Cell>> (i, possibleMoves));
        }

        return moves;
    }

    void moveTiger(int tigerIndex, const Cell& dest) {
        initCell = tiger[tigerIndex].getSpot();
        finalCell = dest;
        cell[getCellIndex(tiger[tigerIndex].getSpot())].setState(EMPTY);
        tiger[tigerIndex].setPosition(dest.coord.x, dest.coord.y);
        tiger[tigerIndex].setPosition(dest);
        cell[getCellIndex(dest)].setState(TIGER);
    }

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