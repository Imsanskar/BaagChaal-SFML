//
// Created by imsanskar on 2020-01-10.
//
#include <iostream>
#include "Game.h"
#include "MainMenu.h"

Game::Game(unsigned int width,unsigned int height)
{
    mWindow.create(sf::VideoMode(width, height), "Baagchaal", sf::Style::Default);
    goatChosen=0;
    tigerTurn=false;
    tigerWin=false;
    goatWin=false;
    goatChosen=0;
    goatEaten=0;
}


void Game::processEvents()
{
    while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            mWindow.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            handlePlayerInput(event.key.code);
        }
        if(tigerTurn) {
            board.tigerMove(event, mWindow);
            if(board.getState())
            {
                tigerTurn = false;
                if(board.eatGoat(&goat[0]))
                {
                    goatEaten++;
                }
                board.setState(false);
            }
        }
        else
        {
            board.placements(event,mWindow,&goat[goatChosen]);
            if(board.getState() and goatChosen<20)
            {
                tigerTurn = true;
                goatChosen++;
                board.setState(Dead);
                board.setState(false);
            }

        }
        if(board.goatWin())
        {
            goatWin=true;
        }
    }
}


void Game::handlePlayerInput(sf::Keyboard::Key & key)
{
    switch(key)
    {
        case sf::Keyboard::Escape:
            mWindow.close();
            MainMenu myMenu(1377,720);
            myMenu.run();
            break;

    }
}

void Game::run()
{
    while(mWindow.isOpen())
    {
        mWindow.clear();
        checkGameOver();
        processEvents();
        board.LoadBoard(mWindow,&goat[0],&tigerTurn,tigerWin,goatWin);
        mWindow.display();  
    }
}

void Game::checkGameOver() {
    if(goatEaten==5 )
    {
        std::cout<<"Tiger Win";
        mWindow.close();
    }
    if(board.goatWin())
    {
        std::cout<<"Goat win";
    }
}



