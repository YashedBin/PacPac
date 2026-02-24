#pragma once

#include <iostream>
#include <string>
#include "core/timer.hpp"


enum class LogType {
    INFO,
    DEBUG,
    WARNING,
    ERROR
};


namespace Core {

    class CLog {
        public:
            CLog() = default;
            
            static void log(const std::string& scope, const LogType& type, const std::string& task){
                std::string typeStr;

                switch(type) {
                    case LogType::INFO: typeStr = "INFO"; break;
                    case LogType::DEBUG: typeStr = "DEBUG"; break;
                    case LogType::WARNING: typeStr = "WARN"; break;
                    case LogType::ERROR: typeStr = "ERROR"; break;
                }
                std::cout << "[" << Timer::getFormattedTime() << "][" << scope << "][" << typeStr << "]: " << task << std::endl;
    
            }
    };

}
