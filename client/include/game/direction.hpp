

enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    IDLE
};

inline std::string dirToString(Direction dir) {
    switch (dir) {
    case Direction::UP: return "UP";
    case Direction::DOWN: return "DOWN";
    case Direction::LEFT: return "LEFT";
    case Direction::RIGHT:  return "RIGHT";
    case Direction::IDLE: return "IDLE";
    default: return "GAME UNKNOWN";
    }
}

