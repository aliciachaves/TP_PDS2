#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <string>
#include <map>
#include <vector>


class Search{
    public:
        void normalizeSearch();
        void readWords();
    
    private:
        std::vector <std::string> words;

};

#endif