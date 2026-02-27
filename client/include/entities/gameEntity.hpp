#pragma once
#include "engine/entity.hpp"
#include "game/direction.hpp"
#include "engine/spritemanager.hpp"
#include "core/consolelog.hpp"
#include "game/global.hpp"
#include "core/fileloader.hpp"


#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Image.hpp>

namespace Entity {
    class Pacman : public Engine::Entity {
        private:
            Engine::SpriteData s_info;
            std::vector<sf::Sprite> s_Sprite;
            Direction dir = Direction::UP;
            float frameTime = 0;
            sf::Texture texture;
        public:
            Pacman(Position p);
            ~Pacman();
            void update(float dt) override;
            void render(sf::RenderWindow& window) override;
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
