//
// Created by imsanskar on 2020-02-06.
//

#include <Cell.h>

Cell::Cell()
{

}
void Cell ::setCoord(int i)
{
    coord.x=(i%5)*187.5+75;
    coord.y=(int(i/5))*147.5+30;
}
inline STATE Cell::getState() const
{
    return state;
}

void Cell::setState(STATE _state)
{
    state=_state;
}