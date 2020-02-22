
#include "../includes/Loadboard.h"
#include "../includes/MainMenu.h"
#include<iostream>

//linear search of vector
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
    font.loadFromFile("../Media/Fonts/font.ttf");//font for text
    tigerText.setFont(font);
    goatText.setFont(font);
    tigerText.setStyle(sf::Text::Bold);
    tigerText.setString("TIGER'S TURN");
    goatText.setString("GOAT'S TURN");
    tigerText.setFillColor(sf::Color::Red);
    goatText.setFillColor(sf::Color::Red);
    goatWinText.setString("Goat wins!");
    tigerText.setPosition(1000,300);
    goatText.setPosition(1000,300);
    goatWinText.setPosition(1000,400);
    isReleased=false;
    isMove=false;
    isTigerPressed= false;
    goatEatenMove=false;//checks if the  move is goat eating move or nor
    moveCompleted=false;//Checks  if the move is completed or not
    tigerChosen=0;
    newPos=sf::Vector2i(0,0);
    oldPos=sf::Vector2i (75,30);
    for(int i=0;i<25;i++)
    {
        (cell+i)->setCoord(i);//sets the co ordinates
        goatEatenMoves.push_back(cell[i]);//just because the vector wont be empty  at the beginning
    }
    boardTexture.loadFromFile("../Media/Images/board.jpg");
    boardImage.setTexture(&boardTexture);
    boardImage.setPosition(0, 0);
    boardImage.setSize(sf::Vector2f(1377, 720));


    //Tiger initialization
    int j=0;//used for tiger array
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



void Board::render(sf::RenderWindow &mWindow,Goat *goat,const bool *tigerFlag,bool goatWin,bool tigerWin)//Renders on the screen
{
//    *tigerFlag=false;
    mWindow.draw(boardImage);//renders the board image
    for (auto & _tiger : tiger)
    {
        _tiger.render(mWindow);//renders the tiger
    }
    for(int i=0;i<20;i++)
    {
        if ((goat + i)->getState() == Alive)//checks if the goat is alive or dead
        {
            (goat + i)->render(mWindow);//renders the goat
        }
    }
    if(*tigerFlag)
    {
        mWindow.draw(tigerText);//for tiger turn
    }
    else {
        mWindow.draw(goatText);//for goat turn
    }
    if(goatWin)
    {
        mWindow.draw(goatWinText);
    }
}


bool Board::getState()//return boolean if the move is completed or not

{
    return moveCompleted;
}

void Board::setState(bool flag )
{
    moveCompleted=flag;
}


//function for movement of the tigers
void Board::tigerMove(sf::Event &event,sf::RenderWindow &mWindow)
{
    sf::Vector2i pos = sf::Mouse::getPosition(mWindow);
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            isReleased=false;
            if (tiger[0].getGlobalBounds().contains(pos.x, pos.y)) {
                initCell=tiger[0].getSpot();
                position=getCellIndex(initCell);
                isTigerPressed=true;
                isMove = true;
                tigerChosen = 0;
                oldPos.x=tiger[tigerChosen].getPosition().x;
                oldPos.y=tiger[tigerChosen].getPosition().y;
            }
            else if (tiger[1].getGlobalBounds().contains(pos.x, pos.y)) {
                initCell=tiger[1].getSpot();
                tigerChosen = 1;
                isTigerPressed=true ;
                position=getCellIndex(initCell);
                isMove = true;
                oldPos.x=tiger[tigerChosen].getPosition().x;
                oldPos.y=tiger[tigerChosen].getPosition().y;
            }
            else if (tiger[2].getGlobalBounds().contains(pos.x, pos.y)) {
                initCell=tiger[2].getSpot();
                tigerChosen = 2;
                isTigerPressed=true;
                position=getCellIndex(initCell);
                isMove = true;
                oldPos.x=tiger[tigerChosen].getPosition().x;
                oldPos.y=tiger[tigerChosen].getPosition().y;
            }
            else if (tiger[3].getGlobalBounds().contains(pos.x, pos.y)) {
                tigerChosen = 3;
                initCell=tiger[3].getSpot();
                isTigerPressed=true;
                position=getCellIndex(initCell);
                isMove = true;
                oldPos.x=tiger[tigerChosen].getPosition().x;
                oldPos.y=tiger[tigerChosen].getPosition().y;
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
    if(isMove)//moves the tiger according to th position of the mouse
    {
        tiger[tigerChosen].setPosition(pos.x-25,pos.y-25);
    }
    if (isReleased and isTigerPressed)
    {
        isMove=false;
        if(checkMove())
        {
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
    sf::Vector2i temp;
    temp.x=0;
    temp.y=0;
    int num=0;
    bool flag=false;
    goatEatenMoves.clear();//clears goat eaten moves for every new operation
    sf::FloatRect bounds;
    bounds=tiger[tigerChosen].getGlobalBounds();
    bounds.left=bounds.left-20;
    Cell _cell=tiger[tigerChosen].getSpot();
    possibleMoves=getPossibleMoves(_cell);
    for(int i=0;i<25;i++)
    {
        if( (cell+i)->getState()==EMPTY and (bounds.contains((cell+i)->getCoord().x+10,(cell+i)->getCoord().y+10)))
        {
                if (search(possibleMoves, cell[i]))
                {
                    flag=true;
                    finalCell = cell[i];
                    num=i;
                    temp.x=cell[i].getCoord().x;
                    temp.y=cell[i].getCoord().y;
                    tiger[tigerChosen].setPosition(&finalCell);
                    tiger[tigerChosen].setPosition(&cell[i]);
                    setEmpty();
                    (cell + i)->setState(TIGER);
                    break;
                }
                else if (search(goatEatenMoves, cell[i]))
                {
                    flag=true;
                    temp.x=cell[i].getCoord().x;
                    temp.y=cell[i].getCoord().y;
                    finalCell = cell[i];
                    tiger[tigerChosen].setPosition(&cell[i]);
                    setEmpty();
                    (cell + i)->setState(TIGER);
                    break;
                }
        }
    }
    if(flag )
    {
        tiger[tigerChosen].setPosition(temp.x,temp.y);
        return true;
    }
    else
    {
        return false;
    }
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


//sets the state of the cell to empty after the tiger has been moved to new position
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

//generates the moves for goat eating condition
void Board::getGoatEatenMoves(int direction)
{
    if((position+direction)>=0 && (position+direction)<25)//checks the overflow  of cell array
    {

        goatEatenMoves.push_back(cell[position+direction]);
    }
}



//returns the possible moves for the current position of tiger
std::vector<Cell> Board::getPossibleMoves(Cell &_cell)
{
    position=getCellIndex(_cell);
    std::vector<Cell> results;
    // Check for left-corner case
    if (position % MAX_GRID_X != 0)
    {
        if(cell[position-1].getState()==EMPTY)
            results.push_back(cell[position - 1]);
        if(cell[position-1].getState()==GOAT)//checks for goat eaten moves
        {
            getGoatEatenMoves(-2);
        }
    }
    //Check for diagonal  movement
    if(position%2==0)
    {
        //check for downward right downward diagonal movement
        if(position<MAX_GRID_Y*(MAX_GRID_X-1) and position%MAX_GRID_X!=(MAX_GRID_X-1))
        {
            if(cell[position+6].getState()==EMPTY)
                results.push_back(cell[position + 6]);
            if(cell[position+6].getState()==GOAT)//checks for goar eaten moves
            {
                getGoatEatenMoves(12);
            }
        }
        //check for downward left downward diagonal movement
        if(position % MAX_GRID_X != 0 and position<MAX_GRID_Y*(MAX_GRID_X-1) )
        {
            if(cell[position+4].getState()==EMPTY)
                results.push_back(cell[position + 4]);
            if(cell[position+4].getState()==GOAT)
            {
                getGoatEatenMoves(8);
            }
        }
        //check for upward right upward diagonal movement
        if((position>MAX_GRID_X-1) and (position % MAX_GRID_X)!=(MAX_GRID_X-1) )
        {
            if(cell[position-4].getState()==EMPTY)
                results.push_back(cell[position - 4]);
            if(cell[position-4].getState()==GOAT)
            {
                getGoatEatenMoves(-8);
            }
        }
        //check for upward left upward diagonal movement
        if((position)%MAX_GRID_X!=0 and position>MAX_GRID_X)//checks for goat eaten moves
        {
            if(cell[position-6].getState()==EMPTY)
                results.push_back(cell[position-6]);
            if(cell[position-6].getState()==GOAT )
            {
                getGoatEatenMoves(-12);
            }
        }
    }
    // Check for right-corner case
    if ((position + 1) % MAX_GRID_X != 0)
    {
        if(cell[position+1].getState()==EMPTY)
            results.push_back(cell[position + 1]);
        if(cell[position+1].getState()==GOAT )//checks for goat eaten moves
        {
            getGoatEatenMoves(2);
        }
    }
    // Check for upper-corner case
    if (position / MAX_GRID_Y != 0)
    {
        if(cell[position-5].getState()==EMPTY)
            results.push_back(cell[position - 5]);
        if(cell[position-MAX_GRID_X].getState()==GOAT )//checks for goat eaten moves
        {
            getGoatEatenMoves(-(MAX_GRID_X*2));
        }
    }
    // Check for lower-corner case
    if (position < MAX_GRID_X*(MAX_GRID_Y-1))//checks for goat eaten moves
    {
        if(cell[position+5].getState()==EMPTY)
            results.push_back(cell[position + 5]);
        if(cell[position+MAX_GRID_X].getState()==GOAT )
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
        if(checkMove(*goat,false))
        {
//            (goat)->setPosition(toPosition(*goat).x, toPosition(*goat).y);
            isGoatPressed=false;
            isGoatReleased=false;
            moveCompleted=true;
        }
        else
        {
            goat->setState(Dead);
            moveCompleted=false;
            isGoatPressed=false;
            isGoatReleased=false;
        }
    }

}

bool Board::checkMove(Goat &goat,bool flag=false)
{
    bool moveFlag=false;
    sf::Vector2i temp;
    sf::FloatRect bounds;
    bounds=goat.getGlobalBounds();
    bounds.left=bounds.left-20;
    if(!flag)//checks move for  placement part
    {
        for (int i = 0; i < 25; i++) {
            if ((bounds.contains((cell + i)->getCoord().x + 10, (cell + i)->getCoord().y + 10)) and (cell + i)->getState() == EMPTY)
            {
                goat.setPosition(cell[i].getCoord().x,cell[i].getCoord().y);//gets the co ordinate  of the goat
                goat.setPosition(&cell[i]);//sets the cell to goat
                (cell + i)->setState(GOAT);//sets the state of the the final cell to GOAT
                return true;
            }
        }
    }
    if(flag)//checks move for movement part
    {
        Cell _cell=goat.getSpot();
        possibleMoves=getPossibleMoves(_cell);

        for (int i = 0; i < 25; i++)
        {
            if ((bounds.contains((cell + i)->getCoord().x + 10, (cell + i)->getCoord().y + 10)) and (cell + i)->getState() == EMPTY)
            {;
                if(search(possibleMoves,cell[i]))
                {
                    goat.setPosition(cell[i].getCoord().x,cell[i].getCoord().y);
                    goat.setPosition(&cell[i]);
                    finalCell=cell[i];
                    setEmpty();
                    cell[i].setState(GOAT);
                    return true;
                }
            }
        }
    }
    return false;
}

sf::Vector2i Board::toPosition(Goat &goat)
{
    sf::FloatRect bounds;
    bounds=goat.getGlobalBounds();
    bounds.left=bounds.left;
    for(int i=0;i<25;i++)
    {
        if((bounds.contains((cell+i)->getCoord().x+10,(cell+i)->getCoord().y+10)))
        {
            goat.setPosition(cell+i);
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



int Board::getCellIndex(Cell &_cell)
{
    for(int i=0;i<25;i++)
    {
        if (cell[i]==_cell)
        {
            return i;
        }
    }
}



bool Board::eatGoat(Goat *goat)
{
    Cell deadGoatCell;
    Cell tempCell;
    int initIndex=getCellIndex(initCell);
    int finalIndex=getCellIndex(finalCell);
    sf::Vector2i tempPos=sf::Vector2i(0,0);
    if((getCellIndex(initCell)+getCellIndex(finalCell))%2==0)
    {
        if((initIndex/5-finalIndex/5)!=1 and (-initIndex/5+finalIndex/5)!=1)
        {
            int index = (getCellIndex(initCell) + getCellIndex(finalCell)) / 2;
            deadGoatCell = cell[index];
            cell[index].setState(EMPTY);
            for (int i = 0; i < 20; i++) {
                if (goat[i].getState() == Dead) {
                    continue;
                }
//                tempPos.x = goat[i].getPosition().x;
//                tempPos.y = goat[i].getPosition().y;
                tempCell=goat[i].getSpot();
                std::cout<<getCellIndex(tempCell)<<"     "<<getCellIndex(deadGoatCell)<<"\n";
                if (tempCell== deadGoatCell)
                {
                    std::cout<<"Hello\n";
                    goat[i].setState(Dead);
                    return true;
                }
            }
        }
    }
    return false;

}



bool Board::goatWin()
{
    std::vector<Cell> move;
    int direction = 0;
    move.clear();

    for(auto & i : tiger)
    {
        Cell _cell=i.getSpot();
        int currentPosition=getCellIndex(_cell);
        // Check for left-corner case
        if (currentPosition % MAX_GRID_X != 0)
        {
            direction=-1;
            if(cell[currentPosition-1].getState()==GOAT and cell[currentPosition-2].getState()==EMPTY and (currentPosition/5-(currentPosition-2)/5!=1))
            {
                if((currentPosition+direction*2)>=0 && (currentPosition+direction*2)<25 )//checks the overflow  of cell array
                {
                    move.push_back(cell[currentPosition+direction*2]);
                }
            }
            if(cell[currentPosition-1].getState()==EMPTY)
            {
                move.push_back(cell[currentPosition + direction]);
            }
        }
        //Check for diagonal  movement
        if(currentPosition%2==0)
        {
            //check for downward right downward diagonal movement
            if(currentPosition<MAX_GRID_Y*(MAX_GRID_X-1) and currentPosition%MAX_GRID_X!=(MAX_GRID_X-1))
            {
                direction=6;
                if(cell[currentPosition+6].getState()==GOAT and cell[currentPosition+6*2].getState()==EMPTY)
                {
                    if((currentPosition+6*2)>=0 && (currentPosition+6*2)<25)//checks the overflow  of cell array
                    {
                        move.push_back(cell[currentPosition+6*2]);
                    }
                }
                if(cell[currentPosition+6].getState()==EMPTY)
                {
                    move.push_back(cell[currentPosition + 6]);
                }
            }
            //check for downward left downward diagonal movement
            if(currentPosition % MAX_GRID_X != 0 && currentPosition<MAX_GRID_Y*(MAX_GRID_X-1))
            {
                direction = 4;
                if(cell[currentPosition+4].getState()==GOAT and cell[currentPosition+4*2].getState()==EMPTY and (-currentPosition/5+(currentPosition+8)/5!=1))
                {
                    if((currentPosition+4*2)>=0 && (currentPosition+4*2)<25)//checks the overflow  of cell array
                    {
                        move.push_back(cell[currentPosition+4*2]);
                    }
                }
                if(cell[currentPosition+4].getState()==EMPTY)
                {
                    move.push_back(cell[currentPosition + 4]);
                }
            }
            //check for upward right upward diagonal movement
            if(currentPosition>MAX_GRID_X-1 and (currentPosition % MAX_GRID_X)!=(MAX_GRID_X-1))
            {
                direction=-4;
                if(cell[currentPosition-4].getState()==GOAT and cell[currentPosition-4*2].getState()==EMPTY and (currentPosition/5-(currentPosition-8)/5!=1))
                {
                    if((currentPosition-4*2)>=0 && (currentPosition-4*2)<25)//checks the overflow  of cell array
                    {
                        move.push_back(cell[currentPosition-4*2]);
                    }
                }
                if(cell[currentPosition-4].getState()==EMPTY and currentPosition-4>=0 )
                {
                    move.push_back(cell[currentPosition -4]);
                }
            }
            //check for upward left upward diagonal movement
            if((currentPosition)%MAX_GRID_X!=0 && currentPosition>MAX_GRID_X-1)
            {
                direction=-6;
                if(cell[currentPosition-6*2].getState()==GOAT and cell[currentPosition-6*2].getState()==EMPTY )
                {
                    if((currentPosition+-6*2)>=0 && (currentPosition+-6*2)<25)//checks the overflow  of cell array
                    {
                        move.push_back(cell[currentPosition-12]);
                    }
                }
                if(cell[currentPosition-6].getState()==EMPTY and currentPosition-6>=0)
                {
                    move.push_back(cell[currentPosition  -6]);
                }
            }
        }
        // Check for right-corner case
        if ((currentPosition + 1) % MAX_GRID_X != 0)
        {
            direction = 1;
            if(cell[currentPosition+1].getState()==GOAT and cell[currentPosition+1*2].getState()==EMPTY and (-currentPosition/5+(currentPosition+2)/5!=1))//checks for goar eaten moves
            {
                if((currentPosition+1*2)>=0 && (currentPosition+2)<25)//checks the overflow  of cell array
                {
                    move.push_back(cell[currentPosition+1*2]);
                }
            }
            if(cell[currentPosition+1].getState()==EMPTY and currentPosition+1>=0 and currentPosition+1<25)
            {
                move.push_back(cell[currentPosition + 1]);
            }
        }
        // Check for upper-corner case
        if (currentPosition / MAX_GRID_Y != 0)
        {
            direction=-MAX_GRID_X;
            if(cell[currentPosition-5].getState()==GOAT and cell[currentPosition-5*2].getState()==EMPTY and (currentPosition/5-(currentPosition-10)/5!=1))
            {
                if((currentPosition-10)>=0)//checks the overflow  of cell array
                {
                    move.push_back(cell[currentPosition-5*2]);
                }
            }
            if(cell[currentPosition-5].getState()==EMPTY and currentPosition-5>=0 )
            {
                move.push_back(cell[currentPosition + direction]);
            }
        }
        // Check for lower-corner case
        if (currentPosition < MAX_GRID_X*(MAX_GRID_Y-1))
        {
            direction = MAX_GRID_X;
            if(cell[currentPosition+5].getState()==GOAT and cell[currentPosition+5*2].getState()==EMPTY and (-currentPosition/5+(currentPosition+10)/5!=1))
            {
                if((currentPosition+5*2)>=0 && (currentPosition+5*2)<25)//checks the overflow  of cell array
                {
                    move.push_back(cell[currentPosition+5*2]);
                }
            }
            if(cell[currentPosition+5].getState()==EMPTY)
            {
                move.push_back(cell[currentPosition + direction]);
            }
        }
    }
    return move.empty();
}

void Board::goatMove(sf::Event &event, sf::Vector2i &pos,Goat *goat)
{
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            isReleased=false;
            for(int i=0;i<20;i++)
            {
                if((goat+i)->getState()==Dead)
                {
                    continue;//reject the dead goad
                }
                (goat+i)->setState(Alive);
                if((goat+i)->getGlobalBounds().contains(pos.x,pos.y))
                {
                    goatChosen=i;
                    initCell=(goat+i)->getSpot();
                    position=findCell();
                    isGoatPressed=true;
                    isMove=true;
                    goatChosen=i;
                    oldPos.x=(goat+i)->getPosition().x;
                    oldPos.y=(goat+i)->getPosition().y;
                }
            }
        }
    }
    if(event.type==sf::Event::MouseButtonReleased)
    {
        if(event.mouseButton.button==sf::Mouse::Left)
        {
            isReleased=true;
            isMove=false;
            newPos.x=(goat+goatChosen)->getPosition().x;
            newPos.y=(goat+goatChosen)->getPosition().y;
        }
    }
    if(isMove)
    {
        (goat+goatChosen)->setPosition(pos.x-25,pos.y-25);
    }
    if(isReleased and isGoatPressed)
    {
        isMove=false;
        if(checkMove(*(goat+goatChosen),true))
        {
            isReleased=false;
            moveCompleted=true;
            isGoatPressed=false;
        }
        else
        {
            (goat+goatChosen)->setPosition(oldPos.x,oldPos.y);
            isReleased=false;
            moveCompleted=false;
            isGoatPressed=false;
        }
    }
}