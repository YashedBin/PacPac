
#include <iostream>
#include <string>

#include "game/gamepanel.hpp"
#include "game/global.hpp"


namespace Game {

sf::RenderWindow Gamepanel::window;
Engine::ConsoleLog Gamepanel::console("PacPac");

Gamepanel::Gamepanel() {
    window.create({WIN_WIDTH, WIN_HEIGHT},"PacPac");    
}

void Gamepanel::Run() {
    
    while (isRunning())
    {
        sf::Event event;
        // Engine::EventListner will be added
        while (window.pollEvent(event))
        {
            console.writeLine("Event Occured");
            if (event.type == sf::Event::Closed)
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
    square.setPosition(350.f, 250.f);
    
    window.clear(sf::Color::Black);
    window.draw(square);
    window.display();

}

}
