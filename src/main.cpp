#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include "readfile.hpp"
#include "normalize.hpp"
#include "search.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

int main() {
    try {
        //std::string folder = "./documentos/.";
        std::string folder = "/home/alicia/TP_PDS2/documentos_teste_tp2";

        ReadFile read;

        //função que lê os arquivos presentes no diretório e retorna um mapa aninhado contendo as informações 
        //de frequência das palavras encontradas em cada arquivo
        std::map<std::string, std::map<std::string, int>> frequency = read.readFromFolder(folder);

        Search s;

        std::cout << BLUE << "Digite as palavras que deseja buscar: " << std::endl;
        std::cout << "Pressione Enter para finalizar a busca." << std::endl;
        s.readWords();

        //função que retorna um vetor de pares, onde cada par contém o nome do arquivo e o 
        //número de ocorrências das palavras de busca nesse arquivo
        std::vector<std::pair<std::string, int>> orderedVec = s.returnFiles(frequency);

        //itera sobre cada par, verificando se o número de ocorrências do par atual é igual ao do primeiro par do vetor
        for(const auto& pair : orderedVec){
            if (pair.second == orderedVec[0].second){
                std::cout << GREEN << pair.first << std::endl;
            } else {
                std::cout << YELLOW << pair.first << std::endl;
            }
        }

    //tratam exceções que podem ser lançadas durante a execução do programa e exibem mensagens de erros cospondentes
    } catch (dirNotOpenException& e) {
        std::cout << RED << e.what() << std::endl;
    } catch (fileNotOpenException& e) {
        std::cout << RED << e.what() << std::endl;
    } catch (searchNotFoundException& e) {
        std::cout << RED << e.what() << std::endl;
    } catch (std::exception& e) {
        std::cout << RED << e.what() << std::endl;
    } catch (...) {
        std::cout << RED << "Erro desconhecido" << std::endl;
    }

    std::cout << "*************" << RESET << std::endl;

    return 0;
}