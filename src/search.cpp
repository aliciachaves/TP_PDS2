#include "search.hpp"
#include "normalize.hpp"
#include "readfile.hpp"

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
    