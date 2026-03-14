#pragma once
#include "engine/entity.hpp"
#include "game/direction.hpp"
#include "engine/spritemanager.hpp"
#include "core/consolelog.hpp"
#include "game/global.hpp"
#include "game/map.hpp"
#include "core/fileloader.hpp"


#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Image.hpp>

namespace Entities {
    class Pacman : public Engine::Entity {
        private:
            Engine::SpriteData s_info;
            std::vector<sf::Sprite> s_Sprite;
            inline static Direction pacDir = Direction::IDLE;
            inline static Direction nextDir = Direction::IDLE;
            float frameTime = 0;
            sf::Texture texture;
            Position m_prevPos;
            Game::Map m_map;

        public:
            Pacman(Position p);
            ~Pacman();
            void update(float dt) override;
            void render(sf::RenderWindow& window) override;
            void move(float dt);
            bool isAligned() const ;
            sf::Vector2i dirToVec(Direction dir) const ;
            bool checkPath(float nx, float ny) const;
            void snapToGrid();
            static void changeDirection(Direction newDir);
    };


    class Ghost : public Engine::Entity {
        private:
            Engine::SpriteData s_info;
            std::vector<sf::Sprite> s_Sprite;
            Direction dir;
        public:
            Ghost(Position p);
            ~Ghost();
            void update(float dt) override;
            void render(sf::RenderWindow& window) override;
    };
}
