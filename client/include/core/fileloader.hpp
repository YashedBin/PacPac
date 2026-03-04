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
            static std::pair<std::string, std::string> getPrefixSuffix(const std::filesystem::path& path);
            static std::vector<std::string> loadLines(const std::filesystem::path& path);
            static sf::Image loadImage(const std::filesystem::path& path);

        public:
            explicit FileLoader(const std::filesystem::path& path);
            
            virtual ~FileLoader();
            static std::variant<sf::Image, std::vector<std::string>, std::string> load(const std::filesystem::path& filepath);
            // json , yaml later 
    };
}
