
#include <iostream>
#include "Loadboard.h"
#include "MainMenu.h"

bool search(std::vector<Cell> list,Cell cell)
{
    int len=list.size();
    for(int i=0;i<len;i++)
    {
        if(list[i].getCoord().x==cell.getCoord().x && list[i].getCoord().y==cell.getCoord().y)
        {
            return true;
        }
    }
    return false;
}




Board::Board() //Constructor
{
    position=0;
    font.loadFromFile("../Media/Fonts/Arial.ttf");//font for text
    tigerText.setFont(font);
    goatText.setFont(font);
    tigerText.setStyle(sf::Text::Bold);
    tigerText.setString("TIGER'S TURN");
    goatText.setString("GOAT'S TURN");
    tigerText.setPosition(900,300);
    goatText.setPosition(900,300);
    isReleased=false;
    isMove=false;
    isTigerPressed= false;
    moveCompleted=false;//Checks  if the move is completed or not
    tigerChosen=0;
    newPos=sf::Vector2i(0,0);
    oldPos=sf::Vector2i (75,30);
    for(int i=0;i<25;i++)
    {
            (cell+i)->setCoord(i);
    }
    boardTexture.loadFromFile("../Media/Images/board.jpg");
    boardImage.setTexture(&boardTexture);
    boardImage.setPosition(0, 0);
    boardImage.setSize(sf::Vector2f(1377, 720));


    //Tiger initialization
    int j=0;
    for(int i=0;i<25;i++)
    {
        if (i==0 or i==4 or i==20 or i==24)
        {
            tiger[j].setPosition((cell+i)->getCoord().x,(cell+i)->getCoord().y);//Sets co ordinates
            tiger[j].setPosition(cell+i);
            (cell+i)->setState(TIGER);
            j++;
        }
    }
}



void Board::LoadBoard(sf::RenderWindow &mWindow,Goat *goat,bool *tigerFlag)//Renders on the screen
{
//    *tigerFlag=false;
    mWindow.draw(boardImage);
    for (int i=0;i<4;i++)
    {
        tiger[i].render(mWindow);
    }
    for(int i=0;i<20;i++)
    {
        if((goat+i)->getState() or true)
        {
            if ((goat + i)->getState() == Alive)
            {
                (goat + i)->render(mWindow);
            }

        }
    }
    if(*tigerFlag)
    {
        mWindow.draw(tigerText);
    }
    else {
        mWindow.draw(goatText);
    }

}


bool Board::getState()
{
    return moveCompleted;
}

void Board::setState(bool flag )
{
    moveCompleted=flag;
}

void Board::tigerMove(sf::Event &event,sf::RenderWindow &mWindow)
{
    sf::Vector2i pos = sf::Mouse::getPosition(mWindow);
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            isReleased=false;
            for(int i=0;i<4;i++)
            {
                if (tiger[i].getGlobalBounds().contains(pos.x, pos.y)) {
                    initCell=tiger[i].getSpot();
                    position=findCell();
                    isTigerPressed=true;
                    isMove = true;
                    tigerChosen = i;
                    oldPos.x=tiger[tigerChosen].getPosition().x;
                    oldPos.y=tiger[tigerChosen].getPosition().y;
                }
            }
        }
    }
    if (event.type == sf::Event::MouseButtonReleased)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            isReleased=true;
            isMove= false;
            newPos.x=tiger[tigerChosen].getPosition().x;
            newPos.y=tiger[tigerChosen].getPosition().y;
        }
    }
    if(isMove)
    {
        tiger[tigerChosen].setPosition(pos.x-25,pos.y-25);
    }
    if (isReleased and isTigerPressed)
    {
        isMove=false;
        if(checkMove())
        {
            tiger[tigerChosen].setPosition(toPosition(tiger[tigerChosen],newPos).x,toPosition(tiger[tigerChosen],newPos).y);
            isReleased=false;
            moveCompleted=true;
            isTigerPressed=false;
        }
        else
        {
            tiger[tigerChosen].setPosition(oldPos.x,oldPos.y);
            isReleased=false;
            moveCompleted=false;
            isTigerPressed=false;
        }
    }
}

bool Board::checkMove()
{
    goatEatenMoves.clear();//clears goat eaten moves for every new operation
    sf::FloatRect bounds;
    bounds=tiger[tigerChosen].getGlobalBounds();
    bounds.left=bounds.left-20;
    possibleMoves=getPossibleMoves();
    for(int i=0;i<25;i++)
    {
        if((bounds.contains((cell+i)->getCoord().x+10,(cell+i)->getCoord().y+10)) && (cell+i)->getState()==EMPTY && (search(possibleMoves,cell[i]) or search(goatEatenMoves,cell[i])))
        {
            setEmpty();
            (cell+i)->setState(TIGER);
            return true;
        }
    }
    return false;
}



sf::Vector2i Board::toPosition(Tiger &tiger,sf::Vector2i &pos)
{
    sf::FloatRect bounds;
    bounds=tiger.getGlobalBounds();
    for(int i=0;i<25;i++)
    {
        if((bounds.contains((cell+i)->getCoord().x+10,(cell+i)->getCoord().y+10)))
        {
            tiger.setPosition(cell+i);
            return (cell+i)->getCoord();
        }
    }
}

void Board::setEmpty()
{
    for(int i=0;i<25;i++)
    {
        if(oldPos==(cell+i)->getCoord())
        {
            cell[i].setState(EMPTY);
        }
    }
}


void Board::getGoatEatenMoves(int direction)
{
    if((position+direction)>=0 && (position+direction)<25)//checks the overflow  of cell array
    {
        goatEatenMoves.push_back(cell[position+direction]);
    }
}



//returns the possible moves for the current position of tiger
std::vector<Cell> Board::getPossibleMoves()
{
    std::vector<Cell> results;
    // Check for left-corner case
    if (position % MAX_GRID_X != 0)
    {
        results.push_back(cell[position - 1]);
        if(cell[position-1].getState()==GOAT)//checks for goar eaten moves
        {
            getGoatEatenMoves(-2);
        }
    }
    //Check for diagonal  movement
    if(position%2==0)
    {
        //check for downward right downward diagonal movement
        if(position<MAX_GRID_Y*(MAX_GRID_X-1))
        {
            results.push_back(cell[position+6]);
            if(cell[position+6].getState()==GOAT)//checks for goar eaten moves
            {
                getGoatEatenMoves(12);
            }
        }
        //check for downward left downward diagonal movement
        if(position % MAX_GRID_X != 0 && position<MAX_GRID_Y*(MAX_GRID_X-1))
        {
            results.push_back(cell[position+4]);
            if(cell[position+4].getState()==GOAT)//checks for goar eaten moves
            {
                getGoatEatenMoves(8);
            }
        }
        //check for upward right upward diagonal movement
        if(position>MAX_GRID_X-1)
        {
            results.push_back(cell[position-4]);
            if(cell[position-4].getState()==GOAT)//checks for goar eaten moves
            {
                getGoatEatenMoves(-8);
            }
        }
        //check for upward left upward diagonal movement
        if((position+1)%MAX_GRID_X!=0 && position>MAX_GRID_X-1)//checks for goar eaten moves
        {
            results.push_back(cell[position-6]);
            if(cell[position-6].getState()==GOAT)
            {
                getGoatEatenMoves(-12);
            }
        }
    }
    // Check for right-corner case
    if ((position + 1) % MAX_GRID_X != 0)
    {
        results.push_back(cell[position + 1]);
        if(cell[position+1].getState()==GOAT)//checks for goar eaten moves
        {
            getGoatEatenMoves(2);
        }
    }
    // Check for upper-corner case
    if (position / MAX_GRID_Y != 0)
    {
        results.push_back(cell[position - MAX_GRID_X]);
        if(cell[position-MAX_GRID_X].getState()==GOAT)//checks for goar eaten moves
        {
            getGoatEatenMoves(-(MAX_GRID_X*2));
        }
    }
    // Check for lower-corner case
    if (position < MAX_GRID_X*(MAX_GRID_Y-1))//checks for goar eaten moves
    {
        results.push_back(cell[position + MAX_GRID_X]);
        if(cell[position+MAX_GRID_X].getState()==GOAT)
        {
            getGoatEatenMoves(MAX_GRID_X*2);
        }
    }
    return results;
}





//GOAT SECTION
void Board::placements(sf::Event &event , sf::RenderWindow &mWindow,Goat *goat )
{
    sf::Vector2i pos = sf::Mouse::getPosition(mWindow);
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if(event.mouseButton.button == sf::Mouse::Left) {
            goat->setState(Alive);
            isMove=true;
            isGoatReleased=false;
            isGoatPressed=true;
            newPos=sf::Mouse::getPosition(mWindow);
        }
    }
    if (event.type == sf::Event::MouseButtonReleased)
    {
        if(event.mouseButton.button == sf::Mouse::Left)
        {
            isGoatReleased=true;
            isMove=false;
        }
    }
    if(isMove)
    {
        goat->setPosition(pos.x-25,pos.y-25);
    }
    if(isGoatReleased and isGoatPressed)
    {
        isMove=false;
        if(checkMove(*goat))
        {
            goat->setPosition(toPosition(*goat).x, toPosition(*goat).y);
            isGoatPressed=false;
            isGoatReleased=false;
            moveCompleted=true;
        } else{
            goat->setState(Dead);

            moveCompleted=false;
            isGoatPressed=false;
            isGoatReleased=false;
        }
    }

}

bool Board::checkMove(Goat &goat)
{
    sf::FloatRect bounds;
    bounds=goat.getGlobalBounds();
    bounds.left=bounds.left;
    for(int i=0;i<25;i++)
    {
        if((bounds.contains((cell+i)->getCoord().x+10,(cell+i)->getCoord().y+10)) and (cell+i)->getState()==EMPTY )
        {
            (cell+i)->setState(GOAT);
            return true;
        }
    }
    return false;
}

sf::Vector2i Board::toPosition(Goat &goat)
{
    sf::FloatRect bounds;
    bounds=goat.getGlobalBounds();
    bounds.left=bounds.left-20;
    for(int i=0;i<25;i++)
    {
        if((bounds.contains((cell+i)->getCoord().x+10,(cell+i)->getCoord().y+10)))
        {
            return (cell+i)->getCoord();
        }
    }
}


//finds the initial index of the cell tiger is in
int Board::findCell()
{
    for(int i=0;i<25;i++)
    {
        if(initCell.getCoord().x==cell[i].getCoord().x && initCell.getCoord().y==cell[i].getCoord().y)
        {
            return i;
        }
    }
}






