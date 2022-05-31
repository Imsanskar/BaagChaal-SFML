#include <iostream>
#include<SFML/Graphics.hpp>
#include "../includes/quitGame.h"
using namespace std;

quitGame::quitGame()
{
     window.create(sf::VideoMode(400,75),"Quit Game",sf::Style::Close);
    if(!font.loadFromFile("Media/Fonts/font.ttf"))
    {
        cout<<"Error in loading Font."<<endl;
    }

    for(int j=0;j<3;j++)
    {
        text[j].setFont(font);//sets font for text
        text[j].setStyle(sf::Text::Regular);//creates bold text
    }
    for(int i=0;i<3;i++)
    {
      text[i].setCharacterSize(20);
      text[i].setFillColor(sf::Color::Black);
    }
    text[0].setCharacterSize(14);
    //Sets co ordinates for text text
    text[0].setPosition(10,10);
    text[1].setPosition(40,40);
    text[2].setPosition(160,40);


    //Sting values for text text
    text[0].setString("Do  you  really  want  to  quit  this  game ?");
    text[1].setString("Yes");
    text[2].setString("No");

}
void quitGame::gameExit(sf::RenderWindow &win)
{ while(window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            sf::Vector2i mouse;
            mouse=sf::Mouse::getPosition(window);
            if(text[1].getGlobalBounds().contains(mouse.x,mouse.y))//checks if the mouse co-ordinates is in text boundary
            {
                text[1].setFillColor(sf::Color::Red);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    window.close();
                    win.close();
                }
            }
            else if(text[2].getGlobalBounds().contains(mouse.x,mouse.y))//checks if the mouse co-ordinates is in text boundary
            {
                text[2].setFillColor(sf::Color::Red);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    window.close();
                }
            }
            else
            {
                text[1].setFillColor(sf::Color::Black);
                text[2].setFillColor(sf::Color::Black);
            }
        }
        window.clear(sf::Color::White);
        for(int i=0;i<3;i++){
            window.draw(text[i]);
        }
        window.display();
    }

}