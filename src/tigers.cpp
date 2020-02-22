//
// Created bx imsanskar on 2020-01-05.
//
#include"../includes/tigers.h"



//void Tiger::render(sf::RenderWindow &mWindow)
//{
//    tigerImage.setPosition(tigerPos.x,tigerPos.y);
//    mWindow.draw(tigerImage);
////    tigerImage.setPosition(pos.getCoord().x,pos.getCoord().y);
//}

Tiger::Tiger()
{
    texture.loadFromFile("../Media/Images/tiger.png");
    image.setTexture(&texture);
    image.setRadius(35);
}
