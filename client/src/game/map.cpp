#include <iostream>

#include "game/map.hpp"


namespace Game {

   // Core::FileLoader Map::FileLoader();
   //
   // Just so I can remember
   // MapIndex will be set from GamePanel/Menu when User selects that
   // certain Map Constructor would know the path Ill figure it out
   // So right now its static Type

    Map::Map() {
        std::string Map1 = std::string(Global::MAPS_PATH) + "map_classic.txt";
        Core::FileLoader FileLoader(Map1.c_str());
        m_mapData = FileLoader.loadLines();
    } // hopes so FileLoader dies here

    Map::~Map() {
        
    }

    void Map::drawMap(sf::RenderWindow& window, int MapIndex) {
        
        sf::RectangleShape square(sf::Vector2f(32.f, 32.f));
        square.setFillColor(sf::Color::Green);
        square.setPosition(sf::Vector2f(0.f ,0.f));

        // temp var replace by new Global.hpp
        int ROWS = 21, COLS = 21;
        float TILE_SIZE = 32;
        
        for(int row = 0; row < ROWS; row++) {
            for(int col = 0; col < COLS; col++) {
                 if(m_mapData[row][col] == 'W') {
                    square.setPosition(sf::Vector2f(col * TILE_SIZE, row * TILE_SIZE));
                    window.draw(square);
                 }
                 if(m_mapData[row][col] == 'P') {
                    square.setFillColor(sf::Color::Blue);
                    square.setPosition(sf::Vector2f(col * TILE_SIZE, row * TILE_SIZE));
                    window.draw(square);
                 }
            }
        }
    }
}
