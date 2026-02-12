#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "engine/consoleLog.hpp"

namespace Game {

class Gamepanel {
    private:
        static sf::RenderWindow window;
        static Engine::ConsoleLog console;
        
    public:
        Gamepanel();
        ~Gamepanel();
        void Run();
        bool isRunning();
        void Render(); 
};

}


