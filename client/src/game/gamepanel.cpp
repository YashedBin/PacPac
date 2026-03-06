
#include <iostream>
#include <string>

#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include "game/gamepanel.hpp"


namespace Game {

    
    Gamepanel::Gamepanel() 
            : m_window(sf::VideoMode(CONFIG::WIN_SIZE), "PacPac", sf::Style::Close),
              m_map(),
              m_entityman(),
              m_eventhand()
        {
        m_window.setFramerateLimit(60);
        m_window.setPosition(sf::Vector2i(100, 100));

        if (!ImGui::SFML::Init(m_window, true)) {

            std::string errorMsg = "Failed to Init ImGui::SFML";
            Core::Clog::log("Gamepanel", LogType::ERROR, errorMsg);
            std::cerr << errorMsg << std::endl;
            return;
        }

        Core::Clog::log("Gamepanel", LogType::INFO, "Game PacPac got Initialized!");

        }

    void Gamepanel::Run() {
        const sf::Time frameTime = sf::seconds(1.f / 60.f);
        float frameDelta = frameTime.asSeconds();

        sf::Clock deltaClock;
        sf::Time timeSinceLastUpdate = sf::Time::Zero;

        while (isRunning()) {

            //sf::Time deltaTime = deltaClock.restart();
            //float dt = deltaTime.asSeconds();

            sf::Time elapsedTime = deltaClock.restart();
            timeSinceLastUpdate += elapsedTime;

           while (const auto event = m_window.pollEvent()) {
        
               ImGui::SFML::ProcessEvent(m_window, *event);
               if(event->is<sf::Event::Closed>()){
                   m_window.close();
               }

               if(event->is<sf::Event::KeyPressed>()) {
                    auto* key = event->getIf<sf::Event::KeyPressed>();
                    sf::Keyboard::Scancode code = key->scancode;

                    switch(code) {
                        case sf::Keyboard::Scancode::W:
                            m_eventhand.broadcast(Engine::EventType::PACMAN_MOVED, Direction::UP);
                            break;
                    
                        case sf::Keyboard::Scancode::A:
                            m_eventhand.broadcast(Engine::EventType::PACMAN_MOVED, Direction::LEFT);
                            break;

                        case sf::Keyboard::Scancode::S:
                            m_eventhand.broadcast(Engine::EventType::PACMAN_MOVED, Direction::DOWN);
                            break;

                        case sf::Keyboard::Scancode::D:
                            m_eventhand.broadcast(Engine::EventType::PACMAN_MOVED, Direction::RIGHT);
                            break;
                    }
               }
           }

            ImGui::SFML::Update(m_window, deltaClock.restart());
            ImGui::Begin("PacPac"); 
            ImGui::End();

            while (timeSinceLastUpdate > frameTime)
            {
                timeSinceLastUpdate -= frameTime;
                // Event Processing
                update(frameDelta);
            }
            //update(dt);
            render();
        } 
    }

    void Gamepanel::update(float dt) {
        m_entityman.updateAll(dt);
    }
    
    Gamepanel::~Gamepanel() {
        Engine::SpriteManager::getInstance().clear();
        ImGui::SFML::Shutdown();
    }


    bool Gamepanel::isRunning() {
        return m_window.isOpen();
    }


    void Gamepanel::render() {

    
        m_window.clear();
        m_map.drawMap(m_window , 0);
        
        m_entityman.renderAll(m_window);

        ImGui::SFML::Render(m_window);
        m_window.display();

    }

}
