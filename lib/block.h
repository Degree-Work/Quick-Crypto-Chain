/// @file block.h
/// @brief описание блока

#ifndef MATHCYB2020_BLOCK_H
#define MATHCYB2020_BLOCK_H

#include <string>
#include <chrono>
#include <ctime>
#include <vector>
#include <iostream>

class Block {
private:
    int nounce; // параметр proof-of-work
    int difficulty; // сложность
    std::chrono::high_resolution_clock::time_point timestamp; // время создания блока
    std::string lastHash; // хэш предыдущего блока, либо 0 для первого блока
    std::string hash; // хэш предыдущего блока, либо 0 для первого блока
    std::string data; // данные, хранящихся в блоке

public:
    /// Конструктор создания блока, время создания блока будет равно времени вызова.
    /// \param lastHash предыдущий хэш
    /// \param hash хэш
    /// \param data данные
    /// \param nonce параметр proof-of-work
    /// \param difficulty сложность
    Block(std::string lastHash,
          std::string hash,
          std::string data,
          int nonce,
          int difficulty);

    /// Конструктор создания блока, с заданным временем.
    /// \param timestamp время создания блока
    /// \param lastHash предыдущий хэш
    /// \param hash хэш
    /// \param data данные
    /// \param nonce параметр proof-of-work
    /// \param difficulty сложность
    Block(std::chrono::high_resolution_clock::time_point timestamp,
          std::string lastHash,
          std::string hash,
          std::string data,
          int nounce,
          int difficulty);

    /// @brief конструктор копирования
    /// @param ссылка на копируемый блок
    Block(const Block &block);

    /// @brief деструктор
    ~Block();

    int getNounce() const;

    int getDifficulty() const;

    const std::chrono::high_resolution_clock::time_point &getTimestamp() const;

    const std::string &getLastHash() const;

    const std::string &getHash() const;

    const std::string &getData() const;


    /// Создание нового блока.
    /// @param lastBlock последний блок
    /// @param data данные
    /// @return созданный новый блок
    static Block mineBlock(Block lastBlock, const std::string &data);


    /// @brief функция возвращает первый блок
    static Block genesisBlock();

    static int adjustDifficulty(Block &lastBlock, std::chrono::high_resolution_clock::time_point timestamp);

    std::string toString() const;
};

#endif //MATHCYB2020_BLOCK_H
