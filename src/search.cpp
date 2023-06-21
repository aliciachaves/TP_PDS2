#include "search.hpp"
#include "normalize.hpp"
#include "readfile.hpp"
#include <algorithm>

void Search::readWords(){
    std::string w;
    while(std::cin >> w){
        words.push_back(w);
    }
}

void Search::normalizeSearch(){
    Normalize n;
    for (const auto& w : words){
        n.normalizeContent(w);
    }
}

bool compareByValue(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
    return a.second > b.second;
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
            repeatedFiles[f.first] = files[f.first].hits;
        }
    }

    for (const auto& f : repeatedFiles) {
        std::pair<std::string, int> p;
        p.first = f.first;
        p.second = f.second;
        sortedVector.push_back(p);
    }
    std::sort(sortedVector.begin(), sortedVector.end(), compareByValue);

    return sortedVector;
}