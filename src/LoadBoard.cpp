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
    if(goatChosen<20)
    {
        goat[goatChosen].render(mWindow);
    }
    mWindow.display();
}
Board::Board() {
    goatChosen=0;
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
    float dx,dy;
    sf::Vector2i pos = sf::Mouse::getPosition(mWindow);
    sf::Vector2i init;
    sf::Vector2f final;
    if (event.type == sf::Event::MouseButtonPressed) {
        init.x = pos.x;
        init.y=pos.y;
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (tiger[0].getGlobalBounds().contains(pos.x, pos.y)) {
                isMove = true;
                tigerChosen = 0;
            }
            if (tiger[1].getGlobalBounds().contains(pos.x, pos.y)) {
                isMove = true;
                tigerChosen = 1;
            }
            if (tiger[2].getGlobalBounds().contains(pos.x, pos.y)) {
                isMove = true;
                tigerChosen = 2;
            }
            if (tiger[3].getGlobalBounds().contains(pos.x, pos.y)) {
                isMove = true;
                tigerChosen = 3;
            }
            dx = pos.x - tiger[tigerChosen].getPosition().x;
            dy = pos.y - tiger[tigerChosen].getPosition().y;
        }
    }
    if (event.type == sf::Event::MouseButtonReleased)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            std::cout<<"hello"<<std::endl;
            isMove= false;
            final.x=sf::Mouse::getPosition(mWindow).x;
            final.y=sf::Mouse::getPosition(mWindow).y;
        }
    }
    if(isMove)
    {
        std::cout<<final.x<<"     "<<final.y<<"\n";
        if (checkMove(pos))
        {
            tiger[tigerChosen].setPosition(final.x, final.y);
        }
        else
        {
            tiger[tigerChosen].setPosition(pos.x,pos.y);
        }
    }
}

bool Board::checkMove(sf::Vector2i pos)
{
    for(int i=0;i<25;i++)
    {
        if((coordinates[i]==pos))
        {
            return true;
        }
    }
    return false;
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
