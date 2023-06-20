#include "normalize.hpp"


std::string Normalize::normalizeContent(std::string conteudo){
    std::string conteudoNormalizado;
    std::string palavra;

    for (char c : conteudo) {

                if (std::isalpha(c) || c == ' ' || c == '\n') {
                    palavra += std::tolower(c);
                    }
                else if (!std::isalpha(c)) {
                    palavra += "";
                    }
                else if (!palavra.empty()) {
                        conteudoNormalizado += palavra + " ";
                        palavra.clear();
                    }
                }   

                if (!palavra.empty()) {
                    conteudoNormalizado += palavra + " ";
                }

    return conteudoNormalizado;
}