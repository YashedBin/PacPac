#include <iostream>
#include "entities/gameEntity.hpp"
#include <fstream>

// Pacman Constructor
Entities::Pacman::Pacman(Position p) :
    Entity(p),
    m_map(),
    m_prevPos()
{
    Core::Clog::log("Pacman", LogType::INFO, "Pacman Object Initialized!!");
    Core::Clog::log("Pacman", LogType::INFO, "Pacman Position: " + std::to_string(pos.x) + ","+ std::to_string(pos.y));
    
    std::filesystem::path pacmanPath = PATH::SPRITE_PATH / "ani_pacman_sheet.png";
    auto result = Core::FileLoader::load(pacmanPath);
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


Entities::Pacman::~Pacman() {

    Core::Clog::log("Pacman", LogType::INFO, "Pacman Object Destroyed!!");
}

void Entities::Pacman::update(float dt) {
    // m_prevPos = pos; // KEY to Animation Stopper
    move(dt);

    std::cout<< "dir: " << dirToString(pacDir) << " pos.x: " << pos.x << " pos.y: " << pos.y << "\n";

    if (m_prevPos == pos) {
        frameTime = 0; 
        return;
    }
    std::cout << "Previous: (" << m_prevPos.x << "," << m_prevPos.y << ")\n";

    frameTime += dt;
    if(frameTime >= s_info.frame_duration) {
        frameTime = 0;
        s_info.frame_index = (s_info.frame_index + 1) % s_info.frame_count;
    }
}

void Entities::Pacman::changeDirection(Direction newDir) {
    Core::Clog::log("Pacman", LogType::DEBUG, "Pacman changed to ");
    nextDir = newDir;
}

bool Entities::Pacman::isAligned() const {
    int half = CONFIG::TILE_SIZE / 2;
    int rx = static_cast<int>(pos.x) % CONFIG::TILE_SIZE;
    int ry = static_cast<int>(pos.y) % CONFIG::TILE_SIZE;
    return (std::abs(rx - half) < CONST::PAC_SPEED) &&
        (std::abs(ry - half) < CONST::PAC_SPEED);
}

void Entities::Pacman::snapToGrid() {
    int half = CONFIG::TILE_SIZE / 2;
    pos.x = (static_cast<int>(pos.x) / CONFIG::TILE_SIZE) * CONFIG::TILE_SIZE + half;
    pos.y = (static_cast<int>(pos.y) / CONFIG::TILE_SIZE) * CONFIG::TILE_SIZE + half;
	std::cout << "Snapped to Grid: (" << pos.x << "," << pos.y << ")\n";
}

void Entities::Pacman::move(float dt) {
    std::cout << "isAligned: " << (isAligned() ? "true" : "false") << "\n";

    if (!isAligned()) {
        sf::Vector2i dirVec = dirToVec(pacDir);
        m_prevPos = pos;
        pos.x += dirVec.x * CONST::PAC_SPEED;
        pos.y += dirVec.y * CONST::PAC_SPEED;
        return;
    }

    snapToGrid();
	
    if (nextDir != Direction::IDLE) {
        sf::Vector2i intVec = dirToVec(nextDir);
        int tRow = ((static_cast<int>(pos.y) - CONFIG::TILE_SIZE / 2) / CONFIG::TILE_SIZE) + intVec.y;
        int tCol = ((static_cast<int>(pos.x) - CONFIG::TILE_SIZE / 2) / CONFIG::TILE_SIZE) + intVec.x;
        if (!m_map.isTile(tRow, tCol, 0) && !m_map.isTile(tRow, tCol, 2))
            pacDir = nextDir;
        nextDir = Direction::IDLE;
    }
    
    sf::Vector2i dirVec = dirToVec(pacDir);
    int nextRow = ((static_cast<int>(pos.y) - CONFIG::TILE_SIZE / 2) / CONFIG::TILE_SIZE) + dirVec.y;
    int nextCol = ((static_cast<int>(pos.x) - CONFIG::TILE_SIZE / 2) / CONFIG::TILE_SIZE) + dirVec.x;
    m_map.printMap(nextRow, nextCol);

    if (m_map.isTile(nextRow, nextCol, 0) ||
        m_map.isTile(nextRow, nextCol, 2)) return;

    m_prevPos = pos;
    pos.x += dirVec.x * CONST::PAC_SPEED;
    pos.y += dirVec.y * CONST::PAC_SPEED;

}

sf::Vector2i Entities::Pacman::dirToVec(Direction dir) const {
    switch (dir) {
    case Direction::RIGHT: return { 1,  0 };
    case Direction::LEFT:  return { -1,  0 };
    case Direction::UP:    return { 0, -1 };
    case Direction::DOWN:  return { 0,  1 };
    }
    return { 0,0 };
}


void Entities::Pacman::render(sf::RenderWindow& window) {
    
    auto& frames = Engine::SpriteManager::getInstance().getFrames("pacman");
    frames[s_info.frame_index].setOrigin(sf::Vector2f(CONFIG::TILE_SIZE / 2.f, CONFIG::TILE_SIZE / 2.f));

    switch(pacDir) {
        case Direction::RIGHT:
                frames[s_info.frame_index].setRotation(sf::degrees(0.f)); break;
        case Direction::LEFT:    
                frames[s_info.frame_index].setRotation(sf::degrees(180.f)); break;
        case Direction::UP:    
                frames[s_info.frame_index].setRotation(sf::degrees(270.f)); break;
        case Direction::DOWN:   
                frames[s_info.frame_index].setRotation(sf::degrees(90.f)); break;
    }
    frames[s_info.frame_index].setPosition(sf::Vector2f{
        pos.x + CONFIG::MAP_OFFSET,
		pos.y + CONFIG::MAP_OFFSET
        });
    window.draw(frames[s_info.frame_index]);
    
}

// Pacman.cpp

