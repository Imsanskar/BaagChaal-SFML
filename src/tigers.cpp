//
// Created bx imsanskar on 2020-01-05.
//
#include"../includes/tigers.h"

//constructor for tiger
Tiger::Tiger()
{
    texture.loadFromFile("../Media/Images/tiger.jpg");
    image.setTexture(&texture);
    image.setRadius(40);
}


