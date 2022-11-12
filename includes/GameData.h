#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <stdint.h>
#include "state.h"
#include "asset_manager.h"

struct GameData {
    uint32_t width, height;
    StateMachine state_machine;
    AssetManager asset_manager;
    bool is_running = true;
    sf::RenderWindow window;

    GameData(int _width, int _height) {
        this->width = _width;
        this->height = _height;
        window.create(sf::VideoMode(width, height), "Baagchaal", sf::Style::Default);
        asset_manager.load_font("main_font", "Media/Fonts/font.ttf");
        asset_manager.load_texture("tiger_image", "Media/Images/tiger.jpg");
        asset_manager.load_texture("goat_image", "Media/Images/goat.jpg");
    }
};