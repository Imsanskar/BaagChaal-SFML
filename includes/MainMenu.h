//
// Created by imsanskar on 2019-11-30.
//


#ifndef BAAGCHAAL_MAINMENU_H
#define BAAGCHAAL_MAINMENU_H

#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>

class MainMenu
{
private:
    unsigned width,height;
    sf::Font font;
    sf::Event event;
    sf::Text menu[3];
    sf::Texture menuTexture,aboutTexture,backButtonTexture;
    sf::RectangleShape menuImage,aboutImage,backButtonImage;
    bool enterAbout=false;
    sf::Text aboutText;
    std::string aboutTextString;

private:
    void LoadMenu();
    void processEvents();
    void about();
    void onExit();




public:
    void run();
    MainMenu(unsigned , unsigned );


protected:
    sf::RenderWindow window;

};


#endif