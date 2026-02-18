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


std::vector<std::string> FileLoader::loadLines() {
    std::vector<std::string> dataLines;
    
    std::string line;

    while(std::getline(m_file, line)) {
        dataLines.push_back(line);
    }

    return dataLines;

}

std::vector<std::vector<char>> FileLoader::loadGrid() {
    std::vector<std::vector<char>> dataGrid;

    char c;
    
    return dataGrid;
}

}
