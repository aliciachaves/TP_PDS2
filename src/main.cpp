#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <dirent.h>
#include "readfile.hpp"
#include "normalize.hpp"



int main() {
    std::string pasta = "/home/alicia/TP_PDS2/documentos_teste_tp2";

    ReadFile read;

    std::map<std::string, std::map<std::string, int>> ocorrencias = read.lerArquivosDaPasta(pasta);

    for (const auto& palavra : ocorrencias) {
        if (palavra.first != "\n") {
            std::cout << "\n" << palavra.first;
            for (const auto& arquivo : palavra.second) {
                if (palavra.second.empty()) {
                 std::cout << " (" << arquivo.first << ", " << arquivo.second << ")";
                }
                else {
                    std::cout << ", (" << arquivo.first << ", " << arquivo.second << ")";
                }
            }
        }
    }

    return 0;
}
