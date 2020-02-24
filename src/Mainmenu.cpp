//
// Created by imsanskar on 2019-12-07.
//
#include "../includes/Game.h"
#include "../includes/quitGame.h"
#include<fstream>
#include <iostream>

void MainMenu::LoadMenu()//Renders window
{
    if (!enterAbout)
    {
        window.clear(sf::Color::White);
        window.draw(menuImage);
        for(int i=0;i<3;i++)
        {
            window.draw(menu[i]);
        }
        window.display();
    }
}



MainMenu::MainMenu(unsigned int width,unsigned int height)
{
    window.create(sf::VideoMode(width,height),"Baagchaal",sf::Style::Default);
    enterAbout=false;
    width=width;
    height=height;
    font.loadFromFile("../Media/Fonts/font.ttf");//font for text
    for(int j=0;j<3;j++)
    {
        menu[j].setFont(font);//sets font for text
        menu[j].setStyle(sf::Text::Bold);//creates bold text
    }
    for(int i=0;i<3;i++)
    {
        menu[i].setCharacterSize(50);
        menu[i].setFillColor(sf::Color::Black);
    }
    //Sets co ordinates for menu text
    menu[0].setPosition(520, 240);
    menu[1].setPosition(590, 370);
    menu[2].setPosition(625, 500);


    //Sting values for menu text
    menu[0].setString("Play Game");
    menu[1].setString("About");
    menu[2].setString("Exit");
    menuTexture.loadFromFile("../Media/Images/baaghchaal.jpg");
    aboutTexture.loadFromFile("../Media/Images/about.jpg");
    backButtonTexture.loadFromFile("../Media/Images/backButton.png");
    menuImage.setTexture(&menuTexture);
    aboutImage.setTexture(&aboutTexture);
    backButtonImage.setTexture(&backButtonTexture);
    menuImage.setPosition(0,0);
    menuImage.setSize(sf::Vector2f(1377,720));//size of the image
    aboutImage.setSize(sf::Vector2f(1377,720));
    backButtonImage.setPosition(1190,25);
    backButtonImage.setSize(sf::Vector2f(150,70));


    std::string detail;
    std::fstream aboutFile;
    aboutFile.open(("../about.txt"));
    if(aboutFile)
    {
        while(getline(aboutFile, detail))
        {
            aboutTextString.append(detail + "\n");
        }
    }
    aboutText.setString(aboutTextString);
    aboutText.setFont(font);
    aboutText.setFillColor(sf::Color::Black);
    aboutText.setCharacterSize(24);
    aboutText.setPosition(250, 200);
}

void MainMenu::processEvents() {
    while (window.pollEvent(event)) {

        if (event.type == sf::Event::Closed) {
            window.close();
        }
        sf::Vector2i mouse;
        mouse = sf::Mouse::getPosition(window);
        if (menu[0].getGlobalBounds().contains(mouse.x,mouse.y))//checks if the mouse co-ordinates is in text boundary
        {
            menu[0].setFillColor(sf::Color::Red);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                window.close();
                Game game(1377, 720);
                game.run();
            }
        } else if (menu[1].getGlobalBounds().contains(mouse.x,mouse.y))//checks if the mouse co-ordinates is in text boundary
        {
            menu[1].setFillColor(sf::Color::Red);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                enterAbout = true;
                about();
            }
        } else if (menu[2].getGlobalBounds().contains(mouse.x,mouse.y))//checks if the mouse co-ordinates is in text boundary
        {
            menu[2].setFillColor(sf::Color::Red);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                window.close();
            }
        } else if (backButtonImage.getGlobalBounds().contains(mouse.x, mouse.y) and enterAbout)
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                enterAbout = false;
            }
        } else {
            menu[0].setFillColor(sf::Color::Black);
            menu[1].setFillColor(sf::Color::Black);
            menu[2].setFillColor(sf::Color::Black);
        }
    }

}

void MainMenu::run()
{
     while (window.isOpen())
     {
         processEvents();
         LoadMenu();
     }

 }
void MainMenu::about()
{
    if(enterAbout)
    {
        window.clear(sf::Color::White);
        window.draw(aboutImage);
        window.draw(aboutText);
        window.draw(backButtonImage);
        window.display();
    }
}