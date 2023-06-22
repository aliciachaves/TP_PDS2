#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

struct File{
    std::string nome;
    int freq;
    int hits;    
};

class Search{
    public:
        void normalizeSearch();
        void readWords();
        std::vector<std::pair<std::string, int>> returnFiles(std::map<std::string, std::map<std::string, int>> frequency);
    
    private:
        std::vector <std::string> words;
        std::map <std::string, int> repeatedFiles;
        std::vector<std::pair<std::string, int>> sortedVector;

};

struct searchNotFoundException : public std::exception {
   const char * what () const throw () {
      return "Nenhum arquivo corresponde à busca";
   }
};

#endif