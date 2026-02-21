#pragman once

struct Position {
    float x,y;
};

template <typename T>
class Entity {
    protected:
        T pos;

    public:
        Entity(T p) : pos(p) {}
        T& get() { return pos; }
};


#include "entity.tpp"
