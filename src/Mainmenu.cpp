//
// Created by imsanskar on 2019-12-07.
//
#include "MainMenu.h"
#include "Game.h"
#include<fstream>
#include <iostream>

void MainMenu::LoadMenu()//Renders window
{

    if (!enterAbout)
    {
        window.clear(sf::Color::White);
        window.draw(menuImage);
        for (int i = 0; i < 3; i++)
        {
            menu[i].setFillColor(i == selectedItem ? sf::Color::Red : sf::Color::Black);
            window.draw(menu[i]);
        }
        window.display();
    }

}



MainMenu::MainMenu(unsigned int width,unsigned int height)

{
    window.create(sf::VideoMode(width,height),"Baagchaal",sf::Style::Default);
    selectedItem=0,
    isPressedUp=false;
    isPressedDown=false;
    isPressedReturn=false;
    enterAbout=false;
    width=width;
    height=height;
    font.loadFromFile("../Media/Fonts/Arial.ttf");//font for text

    for(int j=0;j<3;j++)
    {
        menu[j].setFont(font);//sets font for text
        menu[j].setStyle(sf::Text::Bold);//creates bold text
    }
    for(int i=0;i<3;i++)
    {
        menu[i].setCharacterSize(40);
        menu[i].setFillColor(sf::Color::Black);
    }
    //Sets co ordinates for menu text
    menu[0].setPosition(630, 410);
    menu[1].setPosition(652, 520);
    menu[2].setPosition(670, 638);


    //Sting values for menu text
    menu[0].setString("Play Game");
    menu[1].setString("About");
    menu[2].setString("Exit");
    menuTexture.loadFromFile("../Media/Images/menu.png");
    menuImage.setTexture(&menuTexture);
    menuImage.setPosition(0,0);
    menuImage.setSize(sf::Vector2f(1377,720));//size of the image
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
    aboutText.setCharacterSize(18);
    aboutText.setPosition(300, 300);
}

void MainMenu::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code,true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                window.close();
                break;
        }
    }
}


void MainMenu::handlePlayerInput(sf::Keyboard::Key & key, bool isPressed)
{
    switch (key){
        case sf::Keyboard::Up:
            isPressedUp=isPressed;
            break;
        case sf::Keyboard::Down:
            isPressedDown=isPressed;
            break;
        case sf::Keyboard::Return:
            isPressedReturn=isPressed;
            break;
        case sf::Keyboard::Escape:
            enterAbout = false;
            break;
    }
    update();
}

void MainMenu::update()
{

    if(isPressedUp)
        MoveUp(true);
    if(isPressedDown)
        MoveUp(false);
     if(isPressedReturn)
          onPressEnter();
}

void MainMenu::MoveUp(bool goUp=true)
{
    if (goUp and selectedItem != 0)
        selectedItem--;
    else if(not goUp and selectedItem!=2)
        selectedItem++;
}
void MainMenu::onPressEnter()
{
    switch (selectedItem)
    {
        case(1) :
            enterAbout=true;
            about();
            break;
        case(2):
            exit(0);
        case(0):
            window.close();
            Game game(1377,720);
            game.run();
            break;

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
    window.clear(sf::Color::White);
    window.draw(aboutText);
    window.display();
}
