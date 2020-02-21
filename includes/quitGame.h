#include <SFML/Graphics.hpp>

class quitGame
{
private:
    sf::RenderWindow window;
    sf::Event event;
    sf::Text text[3];
    sf::Font font;


public:
     quitGame();
     void gameExit(sf::RenderWindow &);

};