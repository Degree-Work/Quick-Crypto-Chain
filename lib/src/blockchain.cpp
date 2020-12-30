#include <iostream>

#include "blockchain.h"

Blockchain::Blockchain() {
    // При создании blockChain добавляем первый элемент
    Block genesisBlock = Block::genesisBlock();
    std::cout << genesisBlock.toString() << std::endl;
    chain.push_back(genesisBlock);
    std::cout << chain.at(chain.size()).toString() << std::endl;
    chain.size();
}

Blockchain::~Blockchain() = default;

void Blockchain::addBlock(std::string data) {
    Block lastBlock = chain[getLength() - 1];
    Block newBlock = Block::mineBlock(lastBlock, data);
    chain.push_back(newBlock);
    std::cout << "Blockchain add new block: " << newBlock.toString() << std::endl;
}

int Blockchain::getLength() {
    return chain.size();
}

Block Blockchain::getElementByIndex(long index) {
    return chain.at(index);
}

void Blockchain::print() {
    for (const auto& block: chain) {
        std::cout << block.toString() << std::endl;
    }
}
