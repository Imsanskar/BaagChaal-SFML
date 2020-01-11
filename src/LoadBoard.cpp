//
// Created by imsanskar on 2020-01-04.
//

#include "Loadboard.h"
#include "MainMenu.h"
#include <iostream>


void Board::LoadBoard(sf::RenderWindow &mWindow)
{
    mWindow.clear();
    mWindow.draw(boardImage);
    for (int i=0;i<4;i++)
    {
        tiger[i].render(mWindow);
    }
    mWindow.display();
}
Board::Board() {
    isReleased=false;
    tigerChosen=0;
    goatChosen=0;
    newPos=sf::Vector2i(0,0);
    oldPos=sf::Vector2i (75,30);
    for(int i=0;i<25;i++)
    {
        coordinates[i].x=(i%5)*187.5+75;
        coordinates[i].y=(int(i/5))*147.5+30;
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





void Board::move(sf::Event &event,sf::RenderWindow &mWindow)
{
    sf::Vector2i pos = sf::Mouse::getPosition(mWindow);
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            isReleased=false;
            if (tiger[0].getGlobalBounds().contains(pos.x, pos.y)) {
                isMove = true;
                tigerChosen = 0;
                oldPos.x=tiger[tigerChosen].getPosition().x;
                oldPos.y=tiger[tigerChosen].getPosition().y;
            }
            if (tiger[1].getGlobalBounds().contains(pos.x, pos.y)) {
                isMove = true;
                tigerChosen = 1;
                oldPos.x=tiger[tigerChosen].getPosition().x;
                oldPos.y=tiger[tigerChosen].getPosition().y;
            }
            if (tiger[2].getGlobalBounds().contains(pos.x, pos.y)) {
                isMove = true;
                tigerChosen = 2;
                oldPos.x=tiger[tigerChosen].getPosition().x;
                oldPos.y=tiger[tigerChosen].getPosition().y;
            }
            if (tiger[3].getGlobalBounds().contains(pos.x, pos.y)) {
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
    if (isReleased)
    {
        isMove=false;
        if(checkMove(tiger[tigerChosen]))
        {
            std::cout<<newPos.x<<"     "<<newPos.y<<"\n";
            tiger[tigerChosen].setPosition(toPosition(tiger[tigerChosen],newPos).x,toPosition(tiger[tigerChosen],newPos).y);
            isReleased=false;
        }
        else
        {
            tiger[tigerChosen].setPosition(oldPos.x,oldPos.y);
            isReleased=false;
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

void Board::placements(sf::Event &event , sf::RenderWindow &mWindow )
{
    sf::Vector2i pos = sf::Mouse::getPosition(mWindow);
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if(goatChosen<20)
        {
            goat[goatChosen].setPosition(pos.x, pos.y);
            goatChosen++;
        }
    }
}
