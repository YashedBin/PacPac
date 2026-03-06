#include "engine/spritemanager.hpp"


void Engine::SpriteManager::loadFrames(const std::string& name, std::vector<sf::Sprite> frames) {
    spriteMap[name] = std::move(frames);
    std::string msg = name + "'s Frames added into spriteMap!!";
    Core::Clog::log("SpriteManager", LogType::INFO, msg);
}

Engine::SpriteManager& Engine::SpriteManager::getInstance() {
    
    static SpriteManager instance;
    return instance;
}

Engine::SpriteManager::~SpriteManager() {

}

void Engine::SpriteManager::clear() {
    spriteMap.clear();
}

std::vector<sf::Sprite>& Engine::SpriteManager::getFrames(std::string name) {
    return spriteMap[name];
}

