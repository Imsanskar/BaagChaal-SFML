
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
    void setCoord(int i);
    inline STATE getState() const;
    void setState(STATE );

};