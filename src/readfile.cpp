#include "readfile.hpp"
#include "normalize.hpp"


std::map<std::string, std::map<std::string, int>> ReadFile::lerArquivosDaPasta(const std::string& pasta) {

    DIR* dir;
    struct dirent* ent;

    if ((dir = opendir(pasta.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            std::string nomeArquivo = ent->d_name;
            std::ifstream arquivo(pasta + "/" + nomeArquivo);

            if (arquivo) {
                std::string conteudo;
                std::string linha;

                while (std::getline(arquivo, linha)) {
                    conteudo += linha + "\n";
                }


                Normalize n;
                std::string conteudoNormalizado = n.normalizeContent(conteudo);

                std::istringstream iss(conteudoNormalizado);

                do {
                    std::string word;
                    iss >> word;

                    if (this->ocorrencias.empty()) {
                        this->ocorrencias.insert(std::make_pair(word, std::map<std::string, int>{ {nomeArquivo, 1} }));
                    }
                    else {
                        bool found = false;
                        for (auto& ocorrencia : this->ocorrencias) {
                            if (ocorrencia.first == word) {
                                ocorrencia.second[nomeArquivo]++;
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            this->ocorrencias.insert(std::make_pair(word, std::map<std::string, int>{ {nomeArquivo, 1}}));
                        }
                    }
                } while (iss);

                arquivo.close();
            }
            else {
                std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
            }
        }
        closedir(dir);
    }
    else {
        std::cerr << "Erro ao abrir a pasta." << std::endl;
    }

    return this->ocorrencias;
}