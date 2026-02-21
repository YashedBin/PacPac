#include "entity.hpp"
#include "drawable.hpp"
#include "spritemanager.hpp"


class Pacman : public Entity<Position>, public Drawable {
    private:
        SpriteData sprite;
        // Position is inside alr!?
    public:
        void update override {
            
        }
        
        void render() override {
            
        }
};

class Ghost : public Entity<Position>, public Drawable {
    private:
        SpriteData sprite;

    public:
        void update() override {
            
        }

        void render() override {
            
        }
};


