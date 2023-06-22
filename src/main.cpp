#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include "readfile.hpp"
#include "normalize.hpp"
#include "search.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

int main() {
    try {
        //std::string folder = "./documentos/.";
        std::string folder = "/home/joselinux_/pds2/TP_PDS2/documentos_teste_tp2";

        ReadFile read;

        std::map<std::string, std::map<std::string, int>> frequency = read.readFromFolder(folder);

        Search s;

        std::cout << BLUE << "Digite as palavras que deseja buscar: " << std::endl;
        s.readWords();

        std::vector<std::pair<std::string, int>> orderedVec = s.returnFiles(frequency);
        for(const auto& pair : orderedVec){
            if (pair.second == orderedVec[0].second){
                std::cout << GREEN << pair.first << " " << pair.second << std::endl;
            } else {
                std::cout << YELLOW << pair.first << " " << pair.second << std::endl;
            }
        }
    } catch (dirNotOpenException& e) {
        std::cout << RED << e.what() << std::endl;
    } catch (fileNotOpenException& e) {
        std::cout << RED << e.what() << std::endl;
    } catch (searchNotFoundException& e) {
        std::cout << RED << e.what() << std::endl;
    } catch (std::exception& e) {
        std::cout << RED << e.what() << std::endl;
    } catch (...) {
        std::cout << RED << "Erro desconhecido" << std::endl;
    }

    std::cout << "*************" << RESET << std::endl;

    return 0;
}