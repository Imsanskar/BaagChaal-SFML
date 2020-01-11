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
    Board board;
public:
    Game(unsigned int ,unsigned int );
    void run();
    void processEvents();
    void handlePlayerInput(sf::Keyboard::Key & );


protected:
    sf::RenderWindow mWindow;
};
