#pragma once

// I guess I don't know Anymore
class Drawable {
    public:
    virtual ~Drawable() {}
    virtual void update(float dt) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
};
