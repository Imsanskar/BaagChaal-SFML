#pragma once
#include "state.h"
#include "GameData.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Window.hpp>
#include <cstdint>

class MenuItem {
    sf::Text text;
    sf::Color color;

    static sf::Font font;

    void render(sf::RenderWindow *window) {
        window->draw(text);
    }
};

struct MainMenuState: public State {
    GameData *game_data;
    sf::Text menu_items[3];
    int selected_index = 0;
    int action = 0;

    // images
    sf::RectangleShape menu_image;

    MainMenuState() {}
    MainMenuState(GameData *_game_data): game_data(_game_data) {}

    void init() {
        for(int j = 0; j < 3; j++) {
            menu_items[j].setFont(game_data->asset_manager.get_font("main_font"));//sets font for text
            menu_items[j].setStyle(sf::Text::Bold);//creates bold text
        }
        for(int i = 0; i < 3; i++) {
            menu_items[i].setCharacterSize(50);
            menu_items[i].setFillColor(sf::Color::Black);
        }

        // menu items 
        menu_items[0].setString("Play Game");
        menu_items[1].setString("About");
        menu_items[2].setString("Exit");
        //Sets co ordinates for menu_items text
        menu_items[0].setPosition(520, 240);
        menu_items[1].setPosition(590, 370);
        menu_items[2].setPosition(625, 500);
        menu_items[0].setFillColor(sf::Color::Red);
        menu_items[1].setFillColor(sf::Color::Black);
        menu_items[2].setFillColor(sf::Color::Black);

        // load texture and bind image
        game_data->asset_manager.load_texture("menu_image", "Media/Images/baaghchaal.jpg");
        menu_image.setTexture(&game_data->asset_manager.get_texture("menu_image"));
        menu_image.setPosition(0,0);
        menu_image.setSize(sf::Vector2f(1377,720));//size of the image
    }

    void handle_input() {
        sf::Event event;
        while (game_data->window.pollEvent(event)) {
            sf::Vector2i mouse;
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Key::Up) {
                    action = (selected_index > 0);
                    selected_index -= (selected_index > 0);
                } else if (event.key.code == sf::Keyboard::Key::Down) {
                    action = -(selected_index < 2);
                    selected_index += (selected_index < 2);
                } else if (event.key.code == sf::Keyboard::Key::Q) {
                    game_data->is_running = false;
                }
            }

            if (event.type == sf::Event::Closed) {
                game_data->is_running = false;
            }
        }
    }
    void update() {
        if (action) {
            menu_items[selected_index].setFillColor(sf::Color::Red);
            menu_items[selected_index + action].setFillColor(sf::Color::Black);
            action = 0;
        }
    }

    void render (float dt) {
        game_data->window.clear(sf::Color::White);
        game_data->window.draw(menu_image);
        for(int i = 0; i < 3;i++) {
            game_data->window.draw(menu_items[i]);
        }
        game_data->window.display();
    }

    void resume() {

    }

    void pause() {
        
    }

    ~ MainMenuState() {

    }
};