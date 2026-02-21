#pragma once

// I guess I don't know Anymore
class Drawable {
    public:
    virtual ~Drawable {}
    virtual void update() = 0;
    virtual void render() = 0;
};
