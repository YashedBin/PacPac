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
        std::string Map1 = std::string(PATH::MAPS_PATH) + "map_classic.txt";
        auto result = Core::FileLoader::load(Map1.c_str());
        m_mapData = std::get<std::vector<std::string>>(result);

        Core::Clog::log("Map", LogType::INFO, "m_mapData has been Initialized!! from :" + std::string(Map1));
    }

    Map::~Map() {
        
    }

    void Map::drawMap(sf::RenderWindow& window, int MapIndex) {
        
        sf::RectangleShape square(sf::Vector2f(32.f, 32.f));
        square.setPosition(sf::Vector2f(0.f ,0.f));
            
        // mapData might not ever replace
        // MapIndex Will be called in Map() later when
        // a CERTAIN LEVEL must be call To Save Complex Buffer move to 
        // do LEVEL[m_mapData] 
        int ROWS = m_mapData.size();
        int COLS = m_mapData[0].size();
        
        for(int row = 0; row < ROWS; row++) {
            for(int col = 0; col < COLS; col++) {
                 if(m_mapData[row][col] == 'W') {
                    square.setFillColor(sf::Color(25, 25, 166));
                    square.setPosition(sf::Vector2f(col * CONFIG::TILE_SIZE + CONFIG::MAP_OFFSET, row * CONFIG::TILE_SIZE + CONFIG::MAP_OFFSET));
                    window.draw(square);
                 }
                 if(m_mapData[row][col] == 'P') {
                    square.setFillColor(sf::Color::Green);
                    square.setPosition(sf::Vector2f(col * CONFIG::TILE_SIZE + CONFIG::MAP_OFFSET, row * CONFIG::TILE_SIZE + CONFIG::MAP_OFFSET));
                    window.draw(square);
                 }
            }
        }
    }
}
