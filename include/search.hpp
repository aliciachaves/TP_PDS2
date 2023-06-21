#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

// struct que representa um arquivo encontrado durante a busca
struct File{
    std::string nome;
    int freq;
    int hits;    
};

class Search{
    public:

        //função responsável por ler as palavras de busca fornecidas pelo usuário
        void readWords();
        std::vector<std::pair<std::string, int>> returnFiles(std::map<std::string, std::map<std::string, int>> frequency);
    
    private:
        //função recebe um mapa com o índice invertido das palavras nos arquivos e busca correspondentes
        std::vector <std::string> words;
        std::map <std::string, int> fullFiles;
        //retorna vetor de pares contendo o nome do arquivo e o número de ocorrências das palavras de busca nesse arquivo
        std::vector<std::pair<std::string, int>> sortedVector;

};

// struct responsável pela exceção lançada quando a busca realizada não encontra nenhum arquivo correspondente
struct searchNotFoundException : public std::exception {
   const char * what () const throw () {
      return "Nenhum arquivo corresponde à busca";
   }
};

#endif