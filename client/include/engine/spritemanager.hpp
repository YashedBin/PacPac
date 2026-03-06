#pragma once
#include "core/consolelog.hpp"

#include <string>
#include <unordered_map>
#include <SFML/Graphics/Sprite.hpp>

namespace Engine {

    struct SpriteData {
        std::string name;
        int id;
        int frame_index = 0; // two useful index values for Animation
        int frame_count;
        float frame_duration; //optional might delete it later
            
        SpriteData() = default;
        SpriteData(int id, int count, float fd, std::string name) : 
            id(id),
            frame_count(count),
            frame_duration(fd),
            name(name) {
                std::string msg = "SpriteData Obj " + std::to_string(id) + " Initialized " + name;
                Core::Clog::log("SpriteData", LogType::INFO, msg);
            };
    };

    class SpriteManager {
        public:
            ~SpriteManager();
            static SpriteManager& getInstance();
            std::vector<sf::Sprite>& getFrames(std::string name);
            void loadFrames(const std::string& name, std::vector<sf::Sprite> frames);
            void clear();
        private:
            SpriteManager() = default;
            std::unordered_map<std::string, std::vector<sf::Sprite>> spriteMap;
    };

}


