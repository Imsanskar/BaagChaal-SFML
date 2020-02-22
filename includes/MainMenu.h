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
    sf::Text menu[3],headline;
    sf::Texture menuTexture,aboutTexture,backButtonTexture;
    sf::RectangleShape menuImage,aboutImage,backButtonImage;
    bool enterAbout=false;
    sf::Text aboutText;
    std::string aboutTextString;

private:
    void LoadMenu();
    void processEvents();
    void about();




public:
    void run();
    MainMenu(unsigned , unsigned );


protected:
    sf::RenderWindow window;

};


