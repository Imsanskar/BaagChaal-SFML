//
// Created by imsanskar on 2020-01-10.
//


#include "../includes/Game.h"


void Game::getBestMove() {
    if (tigerTurn) {
        std::map<int, std::vector<Cell>> moves = board.getTigerMoves();
        
        board.moveTiger(0, moves[0][0]);
        tigerTurn = false;
    }
}


Game::Game(unsigned int _width, unsigned int _height)
{
    mWindow.create(sf::VideoMode(_width, _height), "Baagchaal", sf::Style::Default);
    goatChosen=0;
    tigerTurn=false;
    tigerWin=false;
    goatWin=false;
    gameOver=false;
    goatChosen=0;
    goatEaten=0;
    quit = false;
    pos=sf::Mouse::getPosition(mWindow);
    backButtonTexture.loadFromFile("Media/Images/backButton.png");
    backButtonImage.setTexture(&backButtonTexture);
    backButtonImage.setPosition(1190,25);
    backButtonImage.setSize(sf::Vector2f(150,70));
    tigerWinTexture.loadFromFile("Media/Images/tigerWins.jpg");
    tigerWinImage.setTexture(&tigerWinTexture);
    tigerWinImage.setPosition(0,0);
    tigerWinImage.setSize(sf::Vector2f(1377,720));
    goatWinTexture.loadFromFile("Media/Images/goatWins.jpg");
    goatWinImage.setTexture(&goatWinTexture);
    goatWinImage.setPosition(0,0);
    goatWinImage.setSize(sf::Vector2f(1377,720));
    
}

//handles the event of the game
void Game::processEvents()
{
    while (mWindow.pollEvent(event)) {
        pos=sf::Mouse::getPosition(mWindow);
        if (event.type == sf::Event::Closed) {
            quit= true;
        }
        if (event.type == sf::Event::KeyPressed) {
            handlePlayerInput(event.key.code);
        }
        if(tigerTurn) {
            // board.tigerMove(event, mWindow);//for the movement of goat
            getBestMove();
    
            tigerTurn = false;
            if(board.eatGoat(&goat[0]))//checks if the the move if goat eating move
            {
                goatEaten++;
                board.goatEatenMoveSound.play();
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
    if(gameOver and backButtonImage.getGlobalBounds().contains(pos.x,pos.y))
    {
        if(event.type==sf::Event::MouseButtonPressed) {
            mWindow.close();
            MainMenu menu(1377, 720);
            menu.run();
        }
    }
}


void Game::handlePlayerInput(sf::Keyboard::Key & key)
{
    switch(key)
    {
        case sf::Keyboard::Escape:
            MainMenu myMenu(1377,720);
            quit= true;
            break;

    }
}

void Game::run()//main game loo[
{
    while(mWindow.isOpen())
    {
        mWindow.clear();
        if(quit)
        {
            quitGame q;
            q.gameExit(mWindow);
            quit=false;
        }
        processEvents();
        if(!gameOver)
            board.render(mWindow,&goat[0],&tigerTurn,tigerWin,goatWin,20-goatChosen,goatEaten);
        checkGameOver();
        mWindow.display();  
    }
}

void Game::checkGameOver()//checks if the game is over
{
    if(goatEaten>=5 )
    {
        gameOver=true;
        tigerWins();
    }
    if(board.goatWin())
    {
        gameOver=true;
        goatWins();
    }
}



void Game::goatWins()
{
    mWindow.clear();
    mWindow.draw(goatWinImage);
    mWindow.draw(backButtonImage);
    mWindow.display();
}

void Game::tigerWins()
{
    mWindow.clear();
    mWindow.draw(tigerWinImage);
    mWindow.draw(backButtonImage);
    mWindow.display();
}



