#include <iostream>
#include <string>

#include "core/fileloader.hpp"


namespace Core {
    
    FileLoader::FileLoader(const std::filesystem::path& path)
        : m_file(path) {
            // default neg
            if(!m_file.is_open()) {
                std::string errorMsg = "Failed to open File: " + path.string();
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


    std::vector<std::string> FileLoader::loadLines(const std::filesystem::path& path) {
        std::ifstream m_file(path);
        std::vector<std::string> dataLines;
        
        std::string line;

        while(std::getline(m_file, line)) {
            dataLines.push_back(line);
        }

        return dataLines;

    }

    sf::Image FileLoader::loadImage(const std::filesystem::path& path) {
        sf::Image img;
        if(!img.loadFromFile(path)){
            std::string errorMsg = "Failed to open File: " + path.string();
            Core::Clog::log("FileLoader", LogType::ERROR, errorMsg);
            throw std::runtime_error(errorMsg);
        }
        return img;        
    }

    std::vector<uint8_t> FileLoader::loadBinMap(const std::filesystem::path& path) {
        std::ifstream file(path, std::ios::binary);

        file.seekg(0, std::ios::end);
        size_t size = file.tellg();
        file.seekg(0, std::ios::beg);

        std::vector<uint8_t> data(size);
        file.read(reinterpret_cast<char*>(data.data()), size);

        return data;
    }

    std::variant<sf::Image, std::vector<std::string>, std::string, std::vector<uint8_t>> FileLoader::load(const std::filesystem::path& filepath) {
            
            auto [prefix, suffix] = getPrefixSuffix(filepath);
             
            Core::Clog::log("FileLoader", LogType::INFO, "Loaded a " + suffix + " from :" + filepath.string());

            if (suffix == ".png" && prefix == "ani_") {
               return loadImage(filepath);
            }
            if (suffix == ".txt" && prefix == "map_") {
                return loadLines(filepath);
            }
            if (suffix == ".bin" && prefix == "map_") {
                return loadBinMap(filepath);
            }    
            if (suffix == ".png") {
                // return loadImage(path);
                // for Temps or Logos
            }
            if(suffix == ".txt" && prefix != "map_") {
                // normal txt so far
            }

            Core::Clog::log("FileLoader", LogType::ERROR, "Unsupported File Type : " + suffix);
            throw std::runtime_error("Unsupported file type"); 
    }

    std::pair<std::string, std::string> FileLoader::getPrefixSuffix(const std::filesystem::path& path) {
        std::filesystem::path filepath = path;

        /*
         * All Assets are suppose to have 3 length starting Prefix 
         * describing their Main Use
         */
        std::string prefix = path.stem().string().substr(0,4);
        std::string suffix = path.extension().string();   
        
        return {prefix,suffix};
    }

}
