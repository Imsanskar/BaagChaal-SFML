//
// Created by imsanskar on 2020-01-10.
//
#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include "MainMenuState.h"
#include "asset_manager.h"
#include "GameData.h"
#include "state.h"


struct Game {
private:
    GameData game_data;
    MainMenuState main_menu;

public:
    Game(uint16_t width, uint16_t height); 

    void run() {
        while (game_data.is_running) {
            StateRef state = game_data.state_machine.get_current_state();
            state->render(0.3);
            state->handle_input();
            state->update();
        }
    }
};
