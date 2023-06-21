#ifndef READFILE_H
#define READFILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <dirent.h>

class ReadFile {
    public:
        std::map<std::string, std::map<std::string, int>> readFromFolder(const std::string& folder);
    private:
        std::map<std::string, std::map<std::string, int>> frequency;
};

#endif