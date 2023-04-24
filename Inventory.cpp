#include "Inventory.hpp"

Inventory::Inventory(QObject* parent, int initialEggCount, int initialCoinCount)
    : QObject(parent), eggCount(initialEggCount), coinCount(initialCoinCount) {}

int Inventory::getEggCount() const {
    return eggCount;
}

int Inventory::getCoinCount() const {
    return coinCount;
}

void Inventory::addEgg() {
    eggCount += 6;
    std::cout << "egg: " << eggCount << std::endl;
}

int Inventory::removeEgg() {
    eggCount -= 1;
    if (eggCount < 0) {
        eggCount = 0;
        return -1;
    }
    return 0;
}

void Inventory::addCoin(int count) {
    coinCount += count;
}

int Inventory::removeCoin(){
    coinCount -= 7;
    if (coinCount < 0) {
        coinCount += 7;
        return -1;
    }
    return 0;
}
