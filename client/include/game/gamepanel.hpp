#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "engine/drawable.hpp"
#include "engine/entity.hpp"
#include "engine/eventhandler.hpp"
#include "engine/entitymanager.hpp"

#include "game/map.hpp"
#include "game/global.hpp"

#include "core/timer.hpp"
#include "core/consolelog.hpp"

#include "entities/gameEntity.hpp"


namespace Game {

class Gamepanel {
    private:
        sf::RenderWindow m_window;
        Map m_map;
        Engine::EntityManager m_entityman;
        Engine::EventHandler<Direction> m_eventhand;

    public:
        Gamepanel();
        ~Gamepanel();
        void Run();
        bool isRunning();

        /*Run is master, update() is for Events and Updating*/
        void update(float dt); 
        void render(); 
    };

}


