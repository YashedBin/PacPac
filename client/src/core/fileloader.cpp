#include <iostream>
#include <string>

#include "core/fileloader.hpp"


namespace Core {
    
    FileLoader::FileLoader(const char* path)
        : m_file(path) {
            // default neg
            if(!m_file.is_open()) {
                std::string errorMsg = "Failed to open File: " + std::string(path);
                Core::Clog::log("FileLoader", LogType::ERROR, errorMsg);
                throw std::runtime_error(errorMsg);
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
        sf::Image img;
        if(!img.loadFromFile(path)){
            std::string errorMsg = "Failed to open File: " + std::string(path);
            Core::Clog::log("FileLoader", LogType::ERROR, errorMsg);
            throw std::runtime_error(errorMsg);
        }
        return img;        
    }

    std::variant<sf::Image, std::vector<std::string>, std::string> FileLoader::load(const char* filepath) {
            
            auto [prefix, suffix] = getPrefixSuffix(filepath);
             
            Core::Clog::log("FileLoader", LogType::INFO, "Loaded a " + suffix + " from :" + std::string(filepath));

            if (suffix == ".png" && prefix == "ani_") {
               return loadImage(filepath);
            }
            if (suffix == ".txt" && prefix == "map_") {
                return loadLines(filepath);
            }
            if (suffix == ".bin" && prefix == "map_") {
                //return loadBinary(filepath);
            }    
            if (suffix == ".png") {
                // return loadImage(path);
                // for Temps or Logos
            }
            if(suffix == ".txt" && prefix != "map_") {
                // normal txt so far
            }

            throw std::runtime_error("Unsupported file type"); 
            Core::Clog::log("FileLoader", LogType::ERROR, "Unsupported File Type : " + suffix);
    }

    std::pair<std::string, std::string> FileLoader::getPrefixSuffix(const char* path) {
        
        // Path path 
        std::string filepath = std::string(path);
        size_t lastSlash = filepath.find_last_of('/');
        std::string fpath = filepath.substr(lastSlash + 1);

        /*
         * All Assets are suppose to have 3 len Prefix 
         * describing their Main Use
         */
        std::string prefix = fpath.substr(0,4);
        size_t pos = fpath.find_last_of('.');
        if (pos == std::string::npos) return {"", ""};
        std::string suffix = fpath.substr(pos);   
        
        return {prefix,suffix};
    }

}
