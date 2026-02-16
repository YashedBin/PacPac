#pragma once

#include <SFML/Graphics.hpp>


// GamePanel Constants

namespace Global {


    constexpr unsigned int WIN_H = 900;
    constexpr unsigned int WIN_W = 900;
    //constexpr sf::Vector2u WIN_SIZE = {900,900};
    constexpr unsigned int FPS = 60;

    constexpr const char* SPRITE_PATH = "assets/sprites";
    constexpr const char* SOUND_PATH = "assets/audio"; 
    constexpr const char* FONT_PATH = "assests/fonts";

    constexpr unsigned TILE_SIZE = 32;
    // can be 64 Let us decide the Map3 first
    // constexpr unsigned CELL_W = 32;
    // constexpr unsigned CELL_H = 32;

    constexpr float PAC_SPEED = 5.0f;
    constexpr float GHOST_SPEED = 3.5f;

    // all values would be tweaked 
    constexpr unsigned int SCORE_PELLET = 10;
    constexpr unsigned int SCORE_P_PELLET = 20;
    constexpr unsigned int SCORE_GHOST = 30;
}
