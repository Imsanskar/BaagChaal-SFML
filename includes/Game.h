//
// Created by imsanskar on 2020-01-10.
//

#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include "Loadboard.h"
#include "MainMenu.h"
#include "quitGame.h"
#include <unistd.h>
#include <unordered_map>


struct Game
{
public:
    sf::Texture goatWinTexture;
    sf::Texture tigerWinTexture;
    sf::RectangleShape goatWinImage;
    sf::RectangleShape tigerWinImage;
    sf::Texture backButtonTexture;
    sf::RectangleShape backButtonImage;
    sf::Event event{};
    Goat goat[20];
    Board board;
    int goatChosen,goatEaten;
    bool gameOver,tigerTurn=true;
    bool tigerWin,goatWin;
    sf::Vector2i pos;
    bool quit;

public:
    Game(unsigned int ,unsigned int );
    void run();
    void processEvents();
    void handlePlayerInput(sf::Keyboard::Key & );
    void checkGameOver();
    void goatWins();
    void tigerWins();
    float getBestMove();
protected:
    sf::RenderWindow mWindow;
};
