#include "engine/spritemanager.hpp"


void Engine::SpriteManager::loadFrames(std::string name, std::vector<sf::Sprite> frames) {
    spriteMap[name] = frames;
    std::string msg = name + "'s Frames added into spriteMap!!";
    Core::Clog::log("SpriteManager", LogType::INFO, msg);
}

Engine::SpriteManager& Engine::SpriteManager::getInstance() {
    
    static SpriteManager instance;
    return instance;
}

Engine::SpriteManager::~SpriteManager() {

}

std::vector<sf::Sprite>& Engine::SpriteManager::getFrames(std::string name) {
    return spriteMap[name];
}

