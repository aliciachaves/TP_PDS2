#ifndef READFILE_H
#define READFILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <dirent.h>

// classe responsável por ler os arquivos e construir o índice invertido 
class ReadFile {
    public:
        std::map<std::string, std::map<std::string, int>> readFromFolder(const std::string& folder);
    private:
        std::map<std::string, std::map<std::string, int>> frequency;
};

// struct da exceção lançada quando ocorre um erro ao abrir um diretório
struct dirNotOpenException : public std::exception {
   const char * what () const throw () {
      return "Diretório não encontrado";
   }
};

// struct da exceção lançada quando ocorre um erro ao abrir um arquivo
struct fileNotOpenException : public std::exception {
   const char * what () const throw () {
      return "Arquivo não encontrado";
   }
};


#endif