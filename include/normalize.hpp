#ifndef NORMALIZE_H
#define NORMALIZE_H

#include <iostream>
#include <string>

// classe responsável por realizar a normalização das palavras excluindo numeros e caracteres especiais

class Normalize{
    public:
        std::string normalizeContent(std::string content);
};

#endif