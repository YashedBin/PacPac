
#include <iostream>
#include <string>

#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include "game/gamepanel.hpp"


namespace Game {

// Static Class Objects
sf::RenderWindow Gamepanel::window(
        sf::VideoMode(CONFIG::WIN_SIZE),
        "PacPac",
        sf::Style::Close
        );

Game::Map Gamepanel::map;

Entity::Pacman Gamepanel::pac(Position(CONFIG::MAP_OFFSET + 32 , CONFIG::MAP_OFFSET + 32));

Gamepanel::Gamepanel() {

    window.setPosition(sf::Vector2i(100, 100));

    if (!ImGui::SFML::Init(window, true)) {

        std::string errorMsg = "Failed to Init ImGui::SFML";
        Core::Clog::log("Gamepanel", LogType::ERROR, errorMsg);
        std::cerr << errorMsg << std::endl;
        return;
    }

    Core::Clog::log("Gamepanel", LogType::INFO, "Game PacPac got Initialized!"); 
}

void Gamepanel::Run() {
    
    sf::Clock deltaClock;

    while (isRunning()) {

    float dt = deltaClock.restart().asSeconds();


        while (const auto event = window.pollEvent()) {
        
            ImGui::SFML::ProcessEvent(window, *event);
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
            // W = 22
            // A = 0
            // S = 18
            // D = 3
              
        }

        ImGui::SFML::Update(window, deltaClock.restart());
        ImGui::Begin("PacPac"); 
        ImGui::End();
        update(dt);
        render(this->window);
    } 
}

void Gamepanel::update(float dt) {
    pac.update(dt);
}

Gamepanel::~Gamepanel() {
    ImGui::SFML::Shutdown();
}


bool Gamepanel::isRunning() {
    return window.isOpen();
}


void Gamepanel::render(sf::RenderWindow& window) {

    
    window.clear();
    map.drawMap(window , 0);
    
    pac.render(this->window);

    ImGui::SFML::Render(window);
    window.display();

}

}
