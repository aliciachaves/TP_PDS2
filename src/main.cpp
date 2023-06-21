#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include "readfile.hpp"
#include "normalize.hpp"
#include "search.hpp"


int main() {
    try {
        std::string folder;
        std::cout << "Digite o caminho da pasta que deseja buscar: " << std::endl;
        std::cin >> folder;

        ReadFile read;

        std::map<std::string, std::map<std::string, int>> frequency = read.readFromFolder(folder);

        Search s;

        s.readWords();
        std::vector<std::pair<std::string, int>> orderedVec = s.returnFiles(frequency);
        for(const auto& pair : orderedVec){
                std::cout << pair.first << " " << pair.second << std::endl;
        }
    } catch (dirNotOpenException& e) {
        std::cout << e.what() << std::endl;
    } catch (fileNotOpenException& e) {
        std::cout << e.what() << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}