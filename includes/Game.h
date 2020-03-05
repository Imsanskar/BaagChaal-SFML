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
#include "AI.h"

class Game
{
private:
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
    sf::SoundBuffer tigerWinBuffer,winBuffer;
    sf::Sound tigerWinSound,winSound;
    bool quit;

public:
    Game(unsigned int ,unsigned int );
    void run();
    void processEvents();
    void handlePlayerInput(sf::Keyboard::Key & );
    void checkGameOver();
    void goatWins();
    void tigerWins();
protected:
    sf::RenderWindow mWindow;
};
