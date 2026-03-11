#include <iostream>

#include "game/map.hpp"


namespace Game {

   // Core::FileLoader Map::FileLoader();
   //
   // Just so I can remember
   // MapIndex will be set from GamePanel/Menu when User selects that
   // certain Map Constructor would know the path Ill figure it out
   // So right now its static Type

    Map::Map() :
        ROW(0),
        COL(0)
    {
        std::filesystem::path mapPath = PATH::MAPS_PATH / "map_level1.bin";
        auto result = Core::FileLoader::load(mapPath);
        // first check
        if (auto* flfl = std::get_if<std::vector<uint8_t>>(&result)) {
            ROW = *reinterpret_cast<uint16_t*>(flfl->data());
            COL = *reinterpret_cast<uint16_t*>(flfl->data() + 2);
            m_mapData = std::vector<uint8_t>(flfl->begin() + 4, flfl->end());
            // Man C++ Iterators are scary
        }
        else {
            Core::Clog::log("Map", LogType::ERROR, "Failed to load map!! ");
        }

        Core::Clog::log("Map", LogType::INFO, "m_mapData has been Initialized!! from :" + mapPath.string());
    }

    Map::~Map() {
        
    }

    void Map::drawMap(sf::RenderWindow& window, int MapIndex) {
        
        sf::RectangleShape square(sf::Vector2f(32.f, 32.f));
        square.setPosition(sf::Vector2f(0.f ,0.f));

        /*
        Looking at this WALL OF CODE
        Will be shifting to map lookups and drawing it but need to check the latency
        */
        for(int row = 0; row < ROW; row++) {
            for(int col = 0; col < COL; col++) {
                 if(m_mapData[row * COL + col] == 0) { // WALL
                    square.setFillColor(sf::Color(0,0,0));
                    square.setPosition(sf::Vector2f(col * CONFIG::TILE_SIZE + CONFIG::MAP_OFFSET, row * CONFIG::TILE_SIZE + CONFIG::MAP_OFFSET));
                    window.draw(square);
                 }
                 if (m_mapData[row * COL + col] == 1) { // PATH
                    square.setFillColor(sf::Color::Green);
                    square.setPosition(sf::Vector2f(col * CONFIG::TILE_SIZE + CONFIG::MAP_OFFSET, row * CONFIG::TILE_SIZE + CONFIG::MAP_OFFSET));
                    window.draw(square);
                 }
                 if (m_mapData[row * COL + col] == 3) { // GHOST HOUSE
                     square.setFillColor(sf::Color(35, 103, 78));
                     square.setPosition(sf::Vector2f(col * CONFIG::TILE_SIZE + CONFIG::MAP_OFFSET, row * CONFIG::TILE_SIZE + CONFIG::MAP_OFFSET));
                     window.draw(square);
                 }
                 if (m_mapData[row * COL + col] == 4) { // WARP
                     square.setFillColor(sf::Color(36, 159, 222));
                     square.setPosition(sf::Vector2f(col * CONFIG::TILE_SIZE + CONFIG::MAP_OFFSET, row * CONFIG::TILE_SIZE + CONFIG::MAP_OFFSET));
                     window.draw(square);
                 }
                 if (m_mapData[row * COL + col] == 5 || m_mapData[row * COL + col] == 6 || m_mapData[row * COL + col] == 7) { // TELEPORT
                     square.setFillColor(sf::Color(118, 66, 138));
                     square.setPosition(sf::Vector2f(col * CONFIG::TILE_SIZE + CONFIG::MAP_OFFSET, row * CONFIG::TILE_SIZE + CONFIG::MAP_OFFSET));
                     window.draw(square);
                 }
                 if (m_mapData[row * COL + col] == 8) { // DOOR
                     square.setFillColor(sf::Color(113, 65, 59));
                     square.setPosition(sf::Vector2f(col * CONFIG::TILE_SIZE + CONFIG::MAP_OFFSET, row * CONFIG::TILE_SIZE + CONFIG::MAP_OFFSET));
                     window.draw(square);
                 }
            }
        }
    }
}
