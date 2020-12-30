#include "block.h"
#include "hashUtils.h"
#include "vector"
#include <chrono>
#include <ctime>

Block::Block(const std::chrono::high_resolution_clock::time_point timestamp,
             const std::string lastHash,
             const std::string hash,
             const std::string data,
             const int nounce,
             const int difficulty)
        : timestamp(timestamp), lastHash(lastHash), hash(hash), data(data), nounce(nounce), difficulty(difficulty) {
}

Block::Block(const std::string lastHash,
             const std::string hash,
             const std::string data,
             const int nounce,
             const int difficulty)
        : data(data), lastHash(lastHash), hash(hash), nounce(nounce), difficulty(difficulty) {
    timestamp = std::chrono::system_clock::now();
}

Block::~Block() {

}

Block::Block(const Block &block) {
    // TODO копирование
}

Block Block::mineBlock(Block lastBlock, const std::string &data) {
    int difficulty = 0;
    std::string hash;
    std::chrono::high_resolution_clock::time_point timestamp;
    auto nounce = 0;
    auto lastHash = lastBlock.getHash();
    do {
        nounce++;
        timestamp = std::chrono::system_clock::now();
        std::vector<std::string> hashList;
        difficulty = Block::adjustDifficulty(lastBlock, timestamp);
        std::string input = std::to_string(timestamp.time_since_epoch().count()) +
                            lastHash +
                            data +
                            std::to_string(nounce);
        hash = HashUtils::hash(input);
    } while (hash.substr(0, difficulty).compare(std::string(difficulty, '0')));
    return Block(timestamp, lastHash, hash, data, nounce, difficulty);
}

Block Block::genesisBlock() {
    auto timestamp = std::chrono::system_clock::now();
    auto lastHash = "------";
    auto hash = "hash-one";
    auto difficulty = 5; // начальная сложность
    auto nounce = 0;
    auto data = "data";
    return Block(timestamp, lastHash, hash, data, nounce, difficulty);
}

/**
 * Регулировка сложности.
 * @param lastBlock  originalBlock предыдущий блок
 * @param timestamp время создания нового блока
 * @return новая сложность
 */
int Block::adjustDifficulty(Block &lastBlock, std::chrono::high_resolution_clock::time_point timestamp) {
    const int MINE_RATE = 1000000; // 1 миллисекунда
    int difficulty = lastBlock.getDifficulty();
    std::cout << "before: " << difficulty << std::endl;
    std::chrono::duration<double, std::nano> time_span = timestamp - lastBlock.getTimestamp();
    if (time_span.count() > MINE_RATE) {
        difficulty--;
    } else {
        difficulty++;
    }

    std::cout << difficulty << std::endl;
    if (difficulty < 1) {
        return 1;
    } else {
        return difficulty;
    }
}

int Block::getNounce() const {
    return nounce;
}

int Block::getDifficulty() const {
    return difficulty;
}

const std::chrono::high_resolution_clock::time_point &Block::getTimestamp() const {
    return timestamp;
}

const std::string &Block::getLastHash() const {
    return lastHash;
}

const std::string &Block::getHash() const {
    return hash;
}

const std::string &Block::getData() const {
    return data;
}

std::string Block::toString() const {
    return "Block(" + std::to_string(timestamp.time_since_epoch().count())
           + ", " + std::to_string(nounce)
           + std::to_string(difficulty) + ", " + lastHash + ", " + data + ", " + hash.substr(0, 10) + ")";
}
