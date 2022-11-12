#pragma once
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string_view>
#include <map>

struct AssetManager {
    std::map<std::string_view, sf::Texture> textures;
    std::map<std::string_view, sf::Font> fonts;

    AssetManager() {

    }

    void load_texture(std::string_view name, std::string_view file_name) {
        sf::Texture texture;
        if (texture.loadFromFile(file_name.data())) {
            this->textures[name] = texture;
        } else {
            printf("Error loading texture: %.*s \n", file_name.length(), file_name.data());
        }
    }

    sf::Texture& get_texture(std::string_view name) {
        return this->textures.at(name);
    }


    void load_font(std::string_view name, std::string_view file_name) {
        sf::Font font;
        if (font.loadFromFile(file_name.data())) {
            this->fonts[name] = font;
        } else {
            printf("Error loading filfont: %.*s \n", file_name.length(), file_name.data());
        }
    }

    sf::Font& get_font(std::string_view name) {
        return fonts[name];
    }

    ~AssetManager() {

    }
};