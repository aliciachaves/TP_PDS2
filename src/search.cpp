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
    for (int i = 0; i < words.size(); i++){
        words[i] = n.normalizeContent(words[i]);
    }

bool compareByValue(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
    return a.second > b.second;
}


std::vector<std::pair<std::string, int>> Search::returnFiles(std::map<std::string, std::map<std::string, int>> frequency) {
    
    normalizeSearch();

    std::map<std::string, File> files;

    for (const auto& word : this->words) {
        for (const auto& f : frequency[word]) {
            files[f.first].hits += f.second;
            files[f.first].freq++;
            files[f.first].nome = f.first;
        }
    }

    int len = this->words.size();
    std::map<std::string, int> repeatedFiles;
    for (const auto& file : files) {
        if (file.second.freq == len) {
            repeatedFiles[file.first] = files[file.first].hits;
        }
    }

    std::vector<std::pair<std::string, int>> sortedVector(repeatedFiles.begin(), repeatedFiles.end());
    std::sort(sortedVector.begin(), sortedVector.end(), compareByValue);

    return sortedVector;
}