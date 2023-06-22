#include "normalize.hpp"


std::string Normalize::normalizeContent(std::string content){
    // string para armazenar o conteúdo normalizado
    std::string n_content;
    // string temporária para construir cada palavra normalizada
    std::string word;

    // itera por cada caractere do conteúdo
    for (char c : content) {
                //se o caractere for letra, espaço branco e nova linha, converte para 
                //minúsculo e adiciona à palavra temporária
                if (std::isalpha(c) || c == ' ' || c == '\n') {
                    word += std::tolower(c);
                    }
                //se o caractere não for uma letra então mantém palavra vazia
                else if (!std::isalpha(c)) {
                    word += "";
                    }
                // se a palavra temporária não estiver vazia adiciona a palavra normalizada à string final
                else if (!word.empty()) {
                        n_content += word + " ";
                        word.clear();
                    }
                }   
                // se a palavra temporária não estiver vazia no final do loop 
                //adiciona a última palavra normalizada à string final
                if (!word.empty()) {
                    n_content += word + " ";
                }

    return n_content;
}