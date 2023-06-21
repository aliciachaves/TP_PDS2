#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include "readfile.hpp"
#include "normalize.hpp"
#include "search.hpp"


int main() {
    std::string folder = "/home/clara21gt/TP_PDS2/documentos_teste_tp2";

    ReadFile read;

    std::map<std::string, std::map<std::string, int>> frequency = read.readFromFolder(folder);

    Search s;

    s.readWords();
    std::vector<std::pair<std::string, int>> orderedVec = s.returnFiles(frequency);
    for(const auto& pair : orderedVec){
            std::cout << pair.first << std::endl;
    }

    return 0;
}