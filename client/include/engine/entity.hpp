#pragma once

#include "drawable.hpp"
#include "spritemanager.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

struct Position {
    float x,y;
    Position() = default;
    Position(float x, float y) : x(x), y(y) {}
};

namespace Engine {


    class Entity : public Drawable {
        protected:
            Position pos;
        public:
            Entity() = default;
            explicit Entity(Position p) : pos(p) {};
            virtual ~Entity() = default;
            virtual void update(float delta) = 0;
            virtual void render(sf::RenderWindow& window) = 0;
    };

}

