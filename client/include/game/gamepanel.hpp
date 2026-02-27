#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "engine/drawable.hpp"
#include "engine/entity.hpp"

#include "game/map.hpp"
#include "game/global.hpp"

#include "core/timer.hpp"
#include "core/consolelog.hpp"

#include "entities/gameEntity.hpp"


namespace Game {

class Gamepanel : public Drawable {
    private:
        static sf::RenderWindow window;
        static Map map;
        static Entity::Pacman pac;

    public:
        Gamepanel();
        ~Gamepanel();
        void Run();
        bool isRunning();

        /*Run is master, update() is for Events and Updating*/
        void update(float dt); 
        void render(sf::RenderWindow& window); 
    };

}


