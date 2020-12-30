//
// Created by Sergey on 29.12.2020.
//

#ifndef QUICK_CRYPTO_CHAIN_BLOCKCHAIN_H
#define QUICK_CRYPTO_CHAIN_BLOCKCHAIN_H

#include <vector>

#include "block.h"

class Blockchain {
private:
    std::vector<Block> chain;

public:
    /// @brief конструктор по умолчанию
    Blockchain();

    /// @brief деструктор
    ~Blockchain();

    /// @brief Добавление нового блока.
    /// @param data данные
    void addBlock(std::string data);

    /// @brief получение размера блокчейна
    /// @return длина цепи
    int getLength();

    Block getElementByIndex(long index);

    void print();
};

#endif //QUICK_CRYPTO_CHAIN_BLOCKCHAIN_H
