#include <iostream>
#include "entities/gameEntity.hpp"


Entity::Pacman::Pacman(Position p) : Entity(p) {
    Core::Clog::log("Pacman", LogType::INFO, "Pacman Object Initialized!!");
    Core::Clog::log("Pacman", LogType::INFO, "Pacman Position: " + std::to_string(pos.x) + ","+ std::to_string(pos.y));
    
    std::string pacmanPath = std::string(PATH::SPRITE_PATH) + "ani_pacman_sheet.png";
    auto result = Core::FileLoader::load(pacmanPath.c_str());
    sf::Image pacmanImage  = std::get<sf::Image>(result);

    s_info.name = "pacman";
    s_info.frame_duration = 0.06f; // 300ms
    s_info.frame_count = 9;
    s_info.id = 1; // UUID but Manual 

    std::vector<sf::Sprite> frames;

    if(!texture.loadFromImage(pacmanImage)) {

        std::string errorMsg = "Failed to Initialized Texture Obj for Pacman "; 
        Core::Clog::log("Pacman", LogType::ERROR, errorMsg);
        throw std::runtime_error(errorMsg);
    }

    for(int i = 0; i < 9; i++ ){
        sf::Sprite sprite(texture);
        sprite.setTextureRect(sf::IntRect(sf::Vector2i(i * 32, 0), sf::Vector2i(32, 32)));
        frames.push_back(sprite);
    }

    Engine::SpriteManager::getInstance().loadFrames("pacman", frames);
}


Entity::Pacman::~Pacman() {

    Core::Clog::log("Pacman", LogType::INFO, "Pacman Object Destroyed!!");
}

void Entity::Pacman::update(float dt) {
    frameTime += dt;
    if(frameTime >= s_info.frame_duration) {
        frameTime = 0;
        s_info.frame_index = (s_info.frame_index + 1) % s_info.frame_count;
    }

    // rest of Direction Logic.
}


void Entity::Pacman::render(sf::RenderWindow& window) {
    
    auto& frames = Engine::SpriteManager::getInstance().getFrames("pacman");
    frames[s_info.frame_index].setPosition(sf::Vector2f{pos.x, pos.y});
    window.draw(frames[s_info.frame_index]);
    
}

