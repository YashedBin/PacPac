#pragma once
#include <vector>
#include <memory>


namespace Engine {
    class Entity;

    class EntityManager {
        public:
            explicit EntityManager();
            ~EntityManager();

            template<typename T>
            void addEntity(T* entity) {
                m_entities.push_back(dynamic_cast<Entity*>(entity));
                Core::Clog::log("EntityManager", LogType::INFO, "new Entity Added!");
            }

            void updateAll(float dt);

            void renderAll(sf::RenderWindow& window);

        private:
            std::vector<Entity*> m_entities;
    };  

}   // namespace Engine
