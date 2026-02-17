#pragma once

#include <fstream>
#include <vector>
#include <string>
#include <iostream>


namespace Core {

    class FileLoader {
        private:
            std::ifstream m_file;

        public:
            explicit FileLoader(const char* path);
            virtual ~FileLoader();
            std::vector<std::string> loadLines();
            std::vector<std::vector<char>> loadGrid();
    };

}
