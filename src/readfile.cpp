#include "readfile.hpp"
#include "normalize.hpp"


std::map<std::string, std::map<std::string, int>> ReadFile::readFromFolder(const std::string& folder) {

    DIR* dir;
    struct dirent* ent;

    if ((dir = opendir(folder.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            std::string fileName = ent->d_name;
            std::ifstream file(folder + "/" + fileName);

            if (file) {
                std::string content;
                std::string line;

                while (std::getline(file, line)) {
                 content += line + "\n";
                }


                Normalize n;
                std::string normalizedcontent = n.normalizeContent(content);

                std::istringstream iss(normalizedcontent);

                do {
                    std::string word;
                    iss >> word;

                    if (this->frequency.empty()) {
                        this->frequency.insert(std::make_pair(word, std::map<std::string, int>{ {fileName, 1} }));
                    }
                    else {
                        bool found = false;
                        for (auto& ocorrencia : this->frequency) {
                            if (ocorrencia.first == word) {
                                ocorrencia.second[fileName]++;
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            this->frequency.insert(std::make_pair(word, std::map<std::string, int>{ {fileName, 1}}));
                        }
                    }
                } while (iss);

                file.close();
            }
            else {
                std::cerr << "Erro ao abrir o arquivo: " << fileName << std::endl;
            }
        }
        closedir(dir);
    }
    else {
        std::cerr << "Erro ao abrir a pasta." << std::endl;
    }

    return this->frequency;
}
