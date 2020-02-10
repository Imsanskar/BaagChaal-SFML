//
// Created by imsanskar on 2020-02-06.
//

#include <Cell.h>

Cell::Cell()
{
    state=EMPTY;
}
void Cell ::setCoord(int i) {
    coord.x=(i%5)*187.5+75;
    coord.y=(i/5)*147.5+30;
}
STATE Cell::getState()
{
    return state;
}

sf::Vector2i Cell::getCoord() const
{
    return coord;
}

void Cell::setState(STATE _state) {
    state=_state;
}

bool Cell::operator==(Cell _cell)
{
    return coord.x == _cell.getCoord().x and coord.y == _cell.getCoord().y;
}

bool Cell::operator <(const Cell &_cell) const
{
    return _cell.coord.x < this -> coord.x && _cell.coord.y < this -> coord.y;
}