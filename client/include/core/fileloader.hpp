#pragma once

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <variant>

#include <SFML/Graphics/Image.hpp>


namespace Core {

    class FileLoader {
        private:
            std::ifstream m_file;
            sf::Image img;

        public:
            explicit FileLoader(const char* path);
            virtual ~FileLoader();
            std::vector<std::string> loadLines(const char*);
            static std::variant<sf::Image, std::vector<std::string>, std::string> load(const char* filepath);
            // json , yaml later 
            std::pair<std::string, std::string> FileLoader::getPrefixSuffix(const char* path);
    };
}
