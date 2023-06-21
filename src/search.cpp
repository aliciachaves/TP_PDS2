#include "search.hpp"
#include "normalize.hpp"
#include "readfile.hpp"
#include <utility>
#include <algorithm>


 void Search::readWords() {
        std::string line;
        std::cout << "Pressione Enter para finalizar a busca." << std::endl;

        while (std::getline(std::cin, line) && !line.empty()) {
            std::istringstream iss(line);
            std::string word;
            while (iss >> word) {
                words.push_back(word);
            }
        }
    }

void Search::normalizeSearch(){
    Normalize n;
    for (const auto& w : words){
        n.normalizeContent(w);
    }
}

bool comparePairs(const std::pair<std::string, int>& pair1, const std::pair<std::string, int>& pair2) {
    if (pair1.second > pair2.second) return true;
    else if (pair1.second < pair2.second) return false;

    return pair1.first < pair2.first;
}

std::vector<std::pair<std::string, int>> Search::returnFiles(std::map<std::string, std::map<std::string, int>> frequency) {
    
    normalizeSearch();

    std::map<std::string, File> files;

    for (const auto& w : words) {
        for (const auto& f : frequency.find(w)->second) {
            files[f.first].hits += f.second;
            files[f.first].freq++;
            files[f.first].nome = f.first;
        }
    }

    int len = words.size();
    for (const auto& f : files) {
        if (f.second.freq == len) {
            fullFiles[f.first] = files[f.first].hits;
        }
    }

    for (const auto& f : fullFiles) {
        std::pair<std::string, int> p;
        p.first = f.first;
        p.second = f.second;
        sortedVector.push_back(p);
    }
    
    std::sort(sortedVector.begin(), sortedVector.end(), comparePairs);

    return sortedVector;
}