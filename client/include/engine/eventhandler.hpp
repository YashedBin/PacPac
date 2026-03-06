#pragma once
#include <vector>
#include <unordered_map>
#include <functional>
#include "core/consolelog.hpp"
#include "entities/gameEntity.hpp"

namespace Engine {
    enum class EventType {
        PACMAN_MOVED,
        POWERUP_TAKEN,
        COLLISION_DETECTED
        // More when encounter
    };

 
    template<typename T>
    class EventHandler {

        public:
            explicit EventHandler();
            ~EventHandler();

            void subscribe(EventType event, std::function<void(T)> callback_func) {
                m_handlers[event].push_back(callback_func);
            }

            void broadcast(EventType event, T event_data) {
                for (auto& callback_func : m_handlers[event]) {
                    callback_func(event_data);
                }
            }

            void loadHandlers();

        private:
            std::unordered_map<EventType, std::vector<std::function<void(T)>>> m_handlers;
    };



    template <typename T>
    EventHandler<T>::EventHandler() {
        Core::Clog::log("EventHandler", LogType::INFO, "Ehandler is Initialized!!");

        loadHandlers();
    }

    template <typename T>
    void EventHandler<T>::loadHandlers() {
        subscribe(EventType::PACMAN_MOVED, [](Direction dir) {
                Entities::Pacman::changeDirection(dir); 
        });
    }

    template <typename T>
    EventHandler<T>::~EventHandler() {
        m_handlers.clear();
    }

}   // namespace Engine
