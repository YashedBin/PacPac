#pragma once

#include <iostream>
#include <string>

namespace Engine {

class ConsoleLog {
    private:
        std::string m_scope;

    public:
        ConsoleLog(const char* scope);
        virtual ~ConsoleLog();
        void writeLine(const char* task);
};

}
