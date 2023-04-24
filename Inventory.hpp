#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <QObject>
#include <iostream>

class Inventory : public QObject {
    Q_OBJECT
public:
    Inventory(QObject* parent = nullptr, int initialEggCount = 10, int initialCoinCount = 100);
    int getEggCount() const;
    int getCoinCount() const;
    void addEgg();
    int removeEgg();
    void addCoin(int count = 1);
    int removeCoin();

private:
    int eggCount;
    int coinCount;
};

#endif // INVENTORY_HPP
