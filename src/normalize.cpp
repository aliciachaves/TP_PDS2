#include "normalize.hpp"


std::string Normalize::normalizeContent(std::string content){
    std::string n_content;
    std::string word;

    for (char c : content) {

                if (std::isalpha(c) || c == ' ' || c == '\n') {
                    word += std::tolower(c);
                    }
                else if (!std::isalpha(c)) {
                    word += "";
                    }
                else if (!word.empty()) {
                        n_content += word + " ";
                        word.clear();
                    }
                }   

                if (!word.empty()) {
                    n_content += word + " ";
                }

    return n_content;
}