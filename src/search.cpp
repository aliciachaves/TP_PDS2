#include "search.hpp"
#include "normalize.hpp"
#include "readfile.hpp"
#include <utility>
#include <algorithm>

// lê as palavras digitadas pelo usuário
 void Search::readWords() {
        std::string line;

        while (std::getline(std::cin, line) && !line.empty()) {
            
            std::string word;

            Normalize n;
            std::string nline = n.normalizeContent(line);
            std::istringstream iss(nline);

            while (iss >> word) {
                words.push_back(word);
            }
        }
    }

// função de comparação utilizada para ordenar o vetor de pares de strings e inteiros
bool comparePairs(const std::pair<std::string, int>& pair1, const std::pair<std::string, int>& pair2) {
    if (pair1.second > pair2.second) return true;
    else if (pair1.second < pair2.second) return false;

    return pair1.first < pair2.first;
}

// retorna os arquivos correspondentes à busca, ordenados por número de hits
std::vector<std::pair<std::string, int>> Search::returnFiles(std::map<std::string, std::map<std::string, int>> frequency) {


    std::map<std::string, File> files;

    // percorre as palavras buscadas e os arquivos correspondentes no índice invertido
    for (const auto& w : words) {
        for (const auto& f : frequency.find(w)->second) {
            files[f.first].hits += f.second;
            files[f.first].freq++;
            files[f.first].nome = f.first;
        }
    }

    int len = words.size();
    
    // verifica se os arquivos encontrados são arquivos completos (todas as palavras foram encontradas)
    for (const auto& f : files) {
        if (f.second.freq == len) {
            fullFiles[f.first] = files[f.first].hits;
        }
    }

    // Copia as informações dos arquivos completos para o vetor ordenado
    for (const auto& f : fullFiles) {
        std::pair<std::string, int> p;
        p.first = f.first;
        p.second = f.second;
        sortedVector.push_back(p);
    }
    
    // Verifica se o vetor ordenado está vazio e lança uma exceção se nenhum arquivo corresponder à busca
    if (sortedVector.empty()) throw searchNotFoundException();
    else {
        std::sort(sortedVector.begin(), sortedVector.end(), comparePairs);
        return sortedVector;
    }
}