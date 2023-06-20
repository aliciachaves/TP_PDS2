#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <windows.h>


std::string normalizarPalavra(const std::string& palavra) {
    std::string palavraNormalizada;
    for (char c : palavra) {
        palavraNormalizada += std::tolower(c);
    }
    return palavraNormalizada;
}

std::map<std::string, std::map<std::string, int>> lerArquivosDaPasta(const std::string& pasta) {

    std::map<std::string, std::map<std::string, int>> ocorrencias;

    WIN32_FIND_DATAA findData;
    HANDLE hFind = FindFirstFileA((pasta + "\\*").c_str(), &findData);

    if (hFind == INVALID_HANDLE_VALUE) {
        std::cerr << "Erro ao abrir a pasta." << std::endl;
        return ocorrencias;
    }

    do {
        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            continue;
        }

        std::string nomeArquivo = findData.cFileName;
        std::ifstream arquivo(pasta + "\\" + nomeArquivo);

        if (arquivo) {
            std::string conteudo;
            std::string linha;

            while (std::getline(arquivo, linha)) {
                conteudo += linha + "\n";
            }

            std::string conteudoNormalizado;
            std::string palavra;

            for (char c : conteudo) {
                if (std::isalpha(c) || c == ' ' || c == '\n') { // é preciso a condição de espaço e quebra de linha?
                    palavra += std::tolower(c);
                }
                else if (!std::isalpha(c)) {
                    palavra += "";
                }
                else if (!palavra.empty()) {
                    conteudoNormalizado += normalizarPalavra(palavra) + " ";

                    palavra.clear();
                }
            }

            if (!palavra.empty()) {
                conteudoNormalizado += normalizarPalavra(palavra) + " ";
            }

            //std::string str = normalizarPalavra(palavra);
            std::istringstream iss(conteudoNormalizado);

            do {
                std::string word;
                iss >> word;

                if (ocorrencias.empty()) {
                    ocorrencias.insert(std::make_pair(word, std::map<std::string, int>{ {nomeArquivo, 1} }));
                }
                else {
                    bool found = false;
                    for (auto& ocorrencia : ocorrencias) {
                        if (ocorrencia.first == word) {
                            ocorrencia.second[nomeArquivo]++;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        ocorrencias.insert(std::make_pair(word, std::map<std::string, int>{ {nomeArquivo, 1}}));
                    }
                }

            } while (iss);

            arquivo.close();
        }
        else {
            std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        }
    } while (FindNextFileA(hFind, &findData));

    FindClose(hFind);

    return ocorrencias;
}

int main() {
    std::string pasta = "C:\\Users\\Clara Garcia\\OneDrive\\Documentos\\documentos_teste_tp2";

    std::map<std::string, std::map<std::string, int>> ocorrencias = lerArquivosDaPasta(pasta);

    for (const auto& palavra : ocorrencias) {
        if (palavra.first != "\n") {
            std::cout << "\n" << palavra.first;
            for (const auto& arquivo : palavra.second) {
                if (palavra.second.empty()) {
                 std::cout << " (" << arquivo.first << ", " << arquivo.second << ")";
                }
                else {
                    std::cout << ", (" << arquivo.first << ", " << arquivo.second << ")";
                }
            }
        }
    }

    return 0;
}
