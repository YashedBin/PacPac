#pragma once

#include <iostream>

#include "core/fileloader.hpp"
#include "core/consolelog.hpp"
#include "game/global.hpp"
#include <SFML/Graphics/RenderWindow.hpp>


namespace Game {

    class Map {
        private:
            //std::vector<std::string> m_mapData;
            std::vector<uint8_t> m_mapData;
            uint16_t ROW, COL;
            static Core::FileLoader FileLoader;
    
        public: 
            Map();
            virtual ~Map();
            void drawMap(sf::RenderWindow& window, int MapIndex);
    
    };

}
