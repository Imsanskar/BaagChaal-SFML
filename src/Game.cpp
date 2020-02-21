//
// Created by imsanskar on 2020-01-10.
//
#include <iostream>
#include "../includes/Game.h"
#include "../includes/MainMenu.h"

Game::Game(unsigned int _width,unsigned int _height)
{
    mWindow.create(sf::VideoMode(_width, _height), "Baagchaal", sf::Style::Default);
    goatChosen=0;
    tigerTurn=false;
    tigerWin=false;
    goatWin=false;
    goatChosen=0;
    goatEaten=0;
    pos=sf::Mouse::getPosition(mWindow);
}

//handles the event of the game
void Game::processEvents()
{
    while (mWindow.pollEvent(event)) {
        pos=sf::Mouse::getPosition(mWindow);
        if (event.type == sf::Event::Closed) {
            mWindow.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            handlePlayerInput(event.key.code);
        }
        if(tigerTurn) {
            board.tigerMove(event, mWindow);//for the movement of goat
            if(board.getState())
            {
                tigerTurn = false;
                if(board.eatGoat(&goat[0]))//checks if the the move if goat eating move
                {
                    goatEaten++;
                }
                board.setState(false);
            }
        }
        else if(goatChosen<20)//placing the goat
        {
            board.placements(event,mWindow,&goat[goatChosen]);
            if(board.getState())
            {
                tigerTurn = true;
                goatChosen++;
                board.setState(false);
            }
        }
        else if(goatChosen>=20)
        {
            board.goatMove(event,pos,&goat[0]);//moving the goat after all the goats are pressed
            if(board.getState())
            {
                tigerTurn=true;
                board.setState(false);
            }
        }

    }
}


void Game::handlePlayerInput(sf::Keyboard::Key & key)
{
    switch(key)
    {
        case sf::Keyboard::Escape:
            mWindow.close();//for closing the window on key  press
            MainMenu myMenu(1377,720);
            myMenu.run();
            break;

    }
}

void Game::run()//main game loo[
{
    while(mWindow.isOpen())
    {
        mWindow.clear();
        processEvents();
        checkGameOver();
        board.render(mWindow,&goat[0],&tigerTurn,tigerWin,goatWin);
        mWindow.display();  
    }
}

void Game::checkGameOver()//checks if the game is over
{
    if(goatEaten>=5 )
    {
        std::cout<<"Tiger Win";
        mWindow.close();
    }
    if(board.goatWin())
    {
        std::cout<<"Goat win";
        mWindow.close();
    }
}



