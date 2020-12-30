//
// Created by Sergey on 29.12.2020.
//

#ifndef QUICK_CRYPTO_CHAIN_CRYPTOHASH_H
#define QUICK_CRYPTO_CHAIN_CRYPTOHASH_H

#include <vector>
#include <string>
/**
 * Вспомогательная утилита для хэширования.
 */
class HashUtils {
public:
    static std::string hash(std::string input);
};

#endif //QUICK_CRYPTO_CHAIN_CRYPTOHASH_H
