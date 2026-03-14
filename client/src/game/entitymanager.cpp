#include "engine/entitymanager.hpp"
#include "entities/gameEntity.hpp"
#include "game/global.hpp"
#include "engine/entity.hpp"



namespace Engine {

    EntityManager::EntityManager() {
        Core::Clog::log("EntityManager", LogType::INFO, "EntityManager Object Initialized!");
        addEntity(new Entities::Pacman(Position(CONFIG::MAP_OFFSET + 32 * 7 + CONFIG::TILE_SIZE / 2, CONFIG::MAP_OFFSET + 32 * 15 + CONFIG::TILE_SIZE / 2)));

    }

    EntityManager::~EntityManager() {
        for (auto& entity : m_entities) {
            delete entity;
        }
        m_entities.clear();
    }

    void EntityManager::updateAll(float dt) {
        for (auto& entity : m_entities) {
            entity->update(dt);
        }
    }
    
    void EntityManager::renderAll(sf::RenderWindow& window) {
        for (auto& entity : m_entities) {
            entity->render(window);
        }
    }

}
