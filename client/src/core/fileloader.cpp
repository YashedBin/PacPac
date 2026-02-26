#include <iostream>
#include <string>

#include "core/fileloader.hpp"


namespace Core {
    
    FileLoader::FileLoader(const char* path)
        : m_file(path) {
            // default neg
            if(!m_file.is_open()) {
                throw std::runtime_error("Failed to open File:" + std::string(path));
            }
    }


    FileLoader::~FileLoader() {
        // Check for Open File
        if (m_file.is_open()) {
            m_file.close();
        }
    }


    std::vector<std::string> FileLoader::loadLines(const char* path) {
        std::ifstream m_file(path);
        std::vector<std::string> dataLines;
        
        std::string line;

        while(std::getline(m_file, line)) {
            dataLines.push_back(line);
        }

        return dataLines;

    }

    sf::Image loadImage(const char* path) {
        if(!img.loadFromFile(path)){
            throw std::runtime_error("Failed to open File:" + std::string(path));
        }
        return img;        
    }

    std::variant<sf::Image, std::vector<std::string>, std::string> FileLoader::load(const char* filepath) {
        std::pair<std::string, std::string> preSuf = getPrefixSuffix(filepath);
            
        
            if (preSuf.second == ".png" && preSuf.first == "ani_") {
                return loadImage(filepath);
                // for SpriteSheets
            }

            if (preSuf.second == ".png") {
                // return loadImage(path);
                // for Temps or Logos
            }

            if (preSuf.second == ".txt" && preSuf.first == "map_") {
                return loadLines(filepath);
            }

            if (preSuf.second == ".bin" && preSuf.first == "map_") {
                // maps in binary
                // return loadBinary(filepath);
            }

            if(preSuf.second == ".txt" && preSuf.first != "map_") {
                // normal txt so far
            }

            throw std::runtime_error("Unsupported file type"); 
    }

    std::pair<std::string, std::string> FileLoader::getPrefixSuffix(const char* path) {
        std::string fpath = std::string(path);
        std::string prefix = fpath.substr(0,4);
        /*
         * All Assets are suppose to have 3 len Prefix 
         * describing their Main Use
         */
        size_t pos = fpath.find_last_of('.');
        if (pos == std::string::npos) return {"", ""};
        std::string suffix = fpath.substr(pos);   
        
        return {prefix,suffix};
    }

}
