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
            static std::pair<std::string, std::string> getPrefixSuffix(const char* path);
            static std::vector<std::string> loadLines(const char*);

        public:
            explicit FileLoader(const char* path);
            virtual ~FileLoader();
            static std::variant<sf::Image, std::vector<std::string>, std::string> load(const char* filepath);
            // json , yaml later 
    };
}
