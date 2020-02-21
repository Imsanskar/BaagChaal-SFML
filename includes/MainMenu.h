//
// Created by imsanskar on 2019-11-30.
//
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>

class MainMenu
{
private:
    unsigned width,height;
    sf::Font font;
    sf::Text menu[3];
    sf::Texture menuTexture;
    sf::RectangleShape menuImage;
    sf::Text myMenu[3];
    int selectedItem=0;
    bool isPressedUp, isPressedDown, isPressedReturn, enterAbout=false;
    sf::Text aboutText;
    std::string aboutTextString;

private:
    void LoadMenu();
    void processEvents();
    void handlePlayerInput(sf::Keyboard::Key &key, bool isPressed);
    void update();
    void MoveUp(bool goUp);
    void onPressEnter();
    void about();



public:
    void run();
    MainMenu(unsigned , unsigned );

protected:
    sf::RenderWindow window;

};


