
#include <iostream>
#include <string>

#include "game/gamepanel.hpp"
#include "game/global.hpp"


namespace Game {

sf::RenderWindow Gamepanel::window(
        sf::VideoMode(Global::WIN_SIZE),
        "PacPac",
        sf::Style::Close
        );
Engine::ConsoleLog Gamepanel::console("PacPac");

Gamepanel::Gamepanel() {

}

void Gamepanel::Run() {
    
    while (isRunning())
    {
        while (const std::optional event = window.pollEvent())
        {
            if(event->is<sf::Event::Closed>())
                window.close();
        }
        Render();
    } 
}

Gamepanel::~Gamepanel() {

}

bool Gamepanel::isRunning() {
    return window.isOpen();
}

void Gamepanel::Render() {

    sf::RectangleShape square(sf::Vector2f(100.f, 100.f)); 
    square.setFillColor(sf::Color::Green);
    square.setPosition(sf::Vector2f(350.f, 250.f));
    
    window.clear(sf::Color::Black);
    window.draw(square);
    window.display();

}

}
