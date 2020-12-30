//
// Created by Sergey on 29.12.2020.
//

#include "hashUtils.h"
#include "sha256.h"
#include <vector>
#include <string>

using namespace std;

/**
 * Метод для хэширования.
 * @param vector строка хэширования
 * @return хэш
 */
string HashUtils::hash(std::string input) {

    return sha256(input);
}