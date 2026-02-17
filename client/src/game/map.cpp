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

    void Map::drawMap(int MapIndex) {
        for(auto& line: m_mapData) {
            std::cout << line << std::endl;
        } 
    }
}
