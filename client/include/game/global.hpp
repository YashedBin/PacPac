#pragma once
#include "filesystem"

#include <SFML/Graphics.hpp>

namespace PATH {

    inline const std::filesystem::path SPRITE_PATH = "assets/sprites/";
    inline const std::filesystem::path SOUND_PATH = "assets/audio/"; 
    inline const std::filesystem::path FONT_PATH = "assets/fonts/";
    inline const std::filesystem::path MAPS_PATH = "assets/maps/";
}

namespace CONFIG {


    //inline sf::Vector2u getWindowSizeVu() {
    //  auto desktop = sf::VideoMode::getDesktopMode();
        //return sf::Vector2u(desktop.width * 0.8, desktop.height * 0.8);
    //}
    
    //inline const sf::Vector2u WIN_SIZE = getWindowSizeVu();

    constexpr sf::Vector2u WIN_SIZE = {1024, 1024};
    constexpr unsigned int FPS = 60;


    constexpr unsigned MAP_OFFSET = 32; // Need Map Edit
    constexpr unsigned TILE_SIZE = 32;     
}

namespace CONST {

    constexpr float PAC_SPEED = 2.0f; 
    constexpr float GHOST_SPEED = 1.5f; 

    constexpr unsigned int SCORE_PELLET = 10;
    constexpr unsigned int SCORE_P_PELLET = 20;
    constexpr unsigned int SCORE_GHOST = 30;
}
