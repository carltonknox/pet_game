#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <QObject>
#include <iostream>
#include "Pet.hpp"

class Inventory : public QObject
{
    Q_OBJECT
public:
    Inventory(QObject *parent, int initialEggCount, int initialCoinCount, std::vector<Pet> &user_list);
    std::vector<Pet> user_list;
    int getEggCount() const;
    int getCoinCount() const;
    void addEgg();
    int removeEgg();
    void addCoin(int count = 1);
    int removeCoin();

    void setEggCount(int egg);
    void setCoinCount(int coin);

private:
    int eggCount;
    int coinCount;
};

#endif // INVENTORY_HPP
