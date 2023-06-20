#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <windows.h>


std::string normalizarPalavra(const std::string& palavra) {
    std::string palavraNormalizada;
    for (char c : palavra) {
            palavraNormalizada += std::tolower(c);
    }
    return palavraNormalizada;
}

std::map<std::string, std::string> lerArquivosDaPasta(const std::string& pasta) {
    std::map<std::string, std::string> conteudos;

    WIN32_FIND_DATAA findData;
    HANDLE hFind = FindFirstFileA((pasta + "\\*").c_str(), &findData);

    if (hFind == INVALID_HANDLE_VALUE) {
        std::cerr << "Erro ao abrir a pasta." << std::endl;
        return conteudos;
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
                if (std::isalpha(c) || c == ' ' || c == '\n') {
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

            conteudos.insert(std::pair<std::string, std::string>(nomeArquivo, conteudoNormalizado));

            arquivo.close();
        }
        else {
            std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        }
    } while (FindNextFileA(hFind, &findData));

    FindClose(hFind);

    return conteudos;
}

int main() {
    std::string pasta = "C:\\Users\\alici\\Documents\\documentos_teste_tp2";

    std::map<std::string, std::string> conteudos = lerArquivosDaPasta(pasta);

    for (const auto& conteudo : conteudos) {
        std::cout << "Nome do Arquivo: " << conteudo.first << "\nConteudo:\n" << conteudo.second << std::endl;
    }

    return 0;
}

