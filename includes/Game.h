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
    Board board;
    Goat goat[20];
    int goatChosen=0;
    bool gameOver=false,tigerTurn=true,goatTurn;
public:
    Game(unsigned int ,unsigned int );
    void run();
    void processEvents();
    void handlePlayerInput(sf::Keyboard::Key & );
protected:
    sf::RenderWindow mWindow;
};
