#include <iostream>
#include <vector>

#include "block.h"
#include "blockchain.h"

using namespace std;

void average_work();

long averageList(vector<long> vector);

int main() {
    average_work();
    return 0;
}

long averageList(vector<long> vector) {
    auto sum_of_elems = 0;
    for (auto &n : vector)
        sum_of_elems += n;
    return sum_of_elems / vector.size();
}

void average_work() {
    // Создаем Blockchain
    cout << "Step 1. Create Blockchain" << endl;
    auto *blockchain = new Blockchain();
    blockchain->print();

//    auto times = vector<long>();
//    for (int i = 0; i < 3; i++) {
//        auto length = blockchain->getLength();
//        Block block = blockchain->getElementByIndex(length - 1);
//        cout << block.toString() << endl;
//        auto prevTimeStamp = block.getTimestamp();
//        blockchain->addBlock("block " + std::to_string(i));
//        auto nextBlock = blockchain->getElementByIndex(length);
//        auto nextTimestamp = nextBlock.getTimestamp();
//        std::chrono::duration<double, std::nano> timeDiff = nextTimestamp - prevTimeStamp;
//        times.push_back(timeDiff.count());
//        long average = averageList(times);
//        cout << "Time to mine block: " << timeDiff.count() << "nano. Difficulty: " << nextBlock.getDifficulty()
//             << ". Average time: " << average << "nano" << endl;
//    }
//
//    cout << blockchain->getLength() << endl;
}