
#include <iostream>
#include "Loadboard.h"
#include "MainMenu.h"


Board::Board() //Constructor
{
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
        coordinates[i].x=(i%5)*187.5+75;
        coordinates[i].y=(int(i/5))*147.5+30;
    }
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
            tiger[j].setPosition((i%5)*187.5+75,(int(i/5))*147.5+30);//Sets co ordinates
            j++;
        }
    }
}





void Board::LoadBoard(sf::RenderWindow &mWindow,Goat *goat,bool *tigerFlag)//Renders on the screen
{
    mWindow.draw(boardImage);
    for (int i=0;i<4;i++)
    {
        tiger[i].render(mWindow);
    }
    for(int i=0;i<20;i++)
    {
        if((goat+i)->getState() or true)
        {

                (goat + i)->render(mWindow);

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
    bool isPressed;
    sf::Vector2i pos = sf::Mouse::getPosition(mWindow);
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            isReleased=false;
            if (tiger[0].getGlobalBounds().contains(pos.x, pos.y)) {
                isTigerPressed=true;
                isMove = true;
                tigerChosen = 0;
                oldPos.x=tiger[tigerChosen].getPosition().x;
                oldPos.y=tiger[tigerChosen].getPosition().y;
            }
            else if (tiger[1].getGlobalBounds().contains(pos.x, pos.y)) {
                isTigerPressed=true;
                isMove = true;
                tigerChosen = 1;
                oldPos.x=tiger[tigerChosen].getPosition().x;
                oldPos.y=tiger[tigerChosen].getPosition().y;
            }
            else if (tiger[2].getGlobalBounds().contains(pos.x, pos.y)) {
                isTigerPressed=true;
                isMove = true;
                tigerChosen = 2;
                oldPos.x=tiger[tigerChosen].getPosition().x;
                oldPos.y=tiger[tigerChosen].getPosition().y;
            }
            else if (tiger[3].getGlobalBounds().contains(pos.x, pos.y)) {
                isTigerPressed=true;
                isMove = true;
                tigerChosen = 3;
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
    if(isMove)
    {
        tiger[tigerChosen].setPosition(pos.x-25,pos.y-25);
    }
    if (isReleased and isTigerPressed)
    {
        isMove=false;
        if(checkMove(tiger[tigerChosen]))
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

bool Board::checkMove(Tiger &tiger)
{
    sf::FloatRect bounds;
    bounds=tiger.getGlobalBounds();
    bounds.left=bounds.left-20;
    for(int i=0;i<25;i++)
    {
        if((bounds.contains(coordinates[i].x+10,coordinates[i].y+10)))
        {
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
        if((bounds.contains(coordinates[i].x+10,coordinates[i].y+10)))
        {
            return coordinates[i];
        }
    }
}

void Board::placements(sf::Event &event , sf::RenderWindow &mWindow,Goat &goat )
{
    sf::Vector2i pos = sf::Mouse::getPosition(mWindow);
    if (event.type == sf::Event::MouseButtonPressed)
    {
        goat.setPosition(pos.x-25,pos.y-25);
        if(event.mouseButton.button == sf::Mouse::Left) {
            goat.setPosition(pos.x-25,pos.y-25);
            if(checkMove(goat))
            {
                std::cout<<"Hello\n";
                goat.setState(true);
                goat.setPosition(toPosition(goat).x, toPosition(goat).y);
                moveCompleted=true;
            }
            else {
                goat.setState(false);
            }

        }
    }
}

bool Board::checkMove(Goat &goat)
{
    sf::FloatRect bounds;
    bounds=goat.getGlobalBounds();
    bounds.left=bounds.left-20;
    for(int i=0;i<25;i++)
    {
        if((bounds.contains(coordinates[i].x+10,coordinates[i].y+10)))
        {
            return true;
        }
    }
    return false;
}

sf::Vector2i Board::toPosition(Goat &goat)
{
    sf::FloatRect bounds;
    bounds=goat.getGlobalBounds();
    for(int i=0;i<25;i++)
    {
        if((bounds.contains(coordinates[i].x+10,coordinates[i].y+10)))
        {
            return coordinates[i];
        }
    }
}
