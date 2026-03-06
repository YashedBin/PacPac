#pragma once
#include "filesystem"

#include <SFML/Graphics.hpp>

    // Refe
    // W = 22
    // A = 0
    // S = 18
    // D = 3


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

    constexpr float PAC_SPEED = 100.0f; // 100% of FPS
    constexpr float GHOST_SPEED = 3.0f; // 120

    constexpr unsigned int SCORE_PELLET = 10;
    constexpr unsigned int SCORE_P_PELLET = 20;
    constexpr unsigned int SCORE_GHOST = 30;
}
