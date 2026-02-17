
#include <iostream>
#include <string>

#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "game/gamepanel.hpp"
#include "game/global.hpp"
#include "game/map.hpp"


namespace Game {

sf::RenderWindow Gamepanel::window(
        sf::VideoMode(Global::WIN_SIZE),
        "PacPac",
        sf::Style::Close
        );
Engine::ConsoleLog Gamepanel::console("PacPac");

Gamepanel::Gamepanel() {
    window.setFramerateLimit(Global::FPS);
    //ImGui::SFML::Init(window, true);
    if (!ImGui::SFML::Init(window, true)) {
        std::cerr << "Failed to Init ImGui::SFML" << std::endl;
        return;
    }

}




void Gamepanel::Run() {
    
    sf::Clock deltaClock;
    while (isRunning()) {

        while (const auto event = window.pollEvent()) {

            ImGui::SFML::ProcessEvent(window, *event);
            if(event->is<sf::Event::Closed>())
                window.close();
        }
        
        ImGui::SFML::Update(window, deltaClock.restart());
        ImGui::ShowDemoWindow();

        ImGui::Begin("Is it a HEllow Worls?");
        ImGui::Button("Don't tab on me!!");
        ImGui::End();
        Render();
    } 
}


Gamepanel::~Gamepanel() {

    ImGui::SFML::Shutdown();
}


bool Gamepanel::isRunning() {
    return window.isOpen();
}


void Gamepanel::Render() {

    sf::RectangleShape square(sf::Vector2f(100.f, 100.f)); 
    square.setFillColor(sf::Color::Green);
    square.setPosition(sf::Vector2f(350.f, 250.f));
    
    window.clear();
    window.draw(square);

    ImGui::SFML::Render(window);
    window.display();

}

}
