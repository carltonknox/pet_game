#ifndef CRACK_HPP
#define CRACK_HPP

// #include "MainScreen.hpp"
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <iostream>
#include <string.h>
#include <QPushButton>
#include "Inventory.hpp"
#include "Pet.hpp"

class Crack : public QWidget
{
public:
    Crack(QWidget *parent, QStackedWidget *stackedWidget, Inventory *inventory);

    //function:
    void returnToMain();

    std::vector<Pet> pet_list;

private slots:
    void on_returnButton_clicked();

private:
    QStackedWidget *stackedWidget;
    QLabel* imageLabel;
    Inventory* inventory;
    QPushButton* crackEgg;
    QPushButton* returnButton;

    int generateNumber();
    Pet generateRandomPet(std::vector<Pet> petlist, int rarity);
};

#endif // SCREEN1_HPP
