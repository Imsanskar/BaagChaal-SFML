#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "Game.h"

int main()
{
    MainMenu myMenu(1377,720);
    myMenu.run();
//    Game game(1377,720);
//    game.run();
    return 0;
}