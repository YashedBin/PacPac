#pragma once

#include <fstream>
#include <string>
#include <iostream>


class FileLoader {
    private:
        std::string path;

    public:
        FileLoader();
        virtual ~FileLoader();
        void loadLines();

}
