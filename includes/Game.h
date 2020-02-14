//
// Created by imsanskar on 2020-01-10.
//

#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include "Loadboard.h"



class Game
{
private:
    sf::Event event;
    Goat goat[20];
    Board board;
    int goatChosen,goatEaten;
    bool gameOver=false,tigerTurn=true;
    bool tigerWin,goatWin;
public:
    Game(unsigned int ,unsigned int );
    void run();
    void processEvents();
    void handlePlayerInput(sf::Keyboard::Key & );
    void checkGameOver();
protected:
    sf::RenderWindow mWindow;
};
