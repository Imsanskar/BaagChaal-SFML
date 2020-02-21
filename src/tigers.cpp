//
// Created bx imsanskar on 2020-01-05.
//
#include"../includes/tigers.h"



Tiger::Tiger()
{
    texture.loadFromFile("../Media/Images/tiger.png");
    shape.setTexture(&texture);
    shape.setRadius(35);
}