#include <iostream>
#include <string>

#include "engine/consoleLog.hpp"

namespace Engine {

ConsoleLog::ConsoleLog(const char* scope) {
    m_scope = scope;
    std::cout << "ConsoleLog Initialized" << std::endl;
}

ConsoleLog::~ConsoleLog() {

}

void ConsoleLog::writeLine(const char* task) {
    std::cout << "[" << m_scope<< "]" << task << std::endl;

}

}
