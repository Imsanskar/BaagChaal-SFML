

#ifndef BAAGCHAAL_CELL_H
#define BAAGCHAAL_CELL_H



#include <SFML/System.hpp>

//
// Created by imsanskar on 2020-02-06.
//

enum STATE
{
    EMPTY,
    GOAT,
    TIGER
};

class Cell
{
private:
    sf::Vector2i coord;
    STATE state;
public:
    Cell();
    void setCoord(int i) ;//sets the co ordinates of the cell object
    sf::Vector2i getCoord() const;//getter of the co-ordinates of the cell object
    STATE getState();//getter of the state of the cell
    void setState(STATE ) ;//setter of the state of the cell
    bool operator ==(Cell );//operator overloading
    bool operator <(const Cell &) const;
};


#endif