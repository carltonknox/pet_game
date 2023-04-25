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
#include <vector>
#include <random>
#include <QPushButton>
#include "Inventory.hpp"
#include "Pet.hpp"

class Crack : public QWidget
{
public:
    Crack(QWidget *parent, QStackedWidget *stackedWidget, Inventory *inventory);

    // function:
    void returnToMain();

private slots:
    void on_returnButton_clicked();
    void crackEggButton();

private:
    QStackedWidget *stackedWidget;
    QLabel *imageLabel;
    // Create egg and coin count labels
    QLabel *egg_count_label;
    QLabel *coin_count_label;
    QLabel *label; // text label

    Inventory *inventory;
    QPushButton *crackEgg;
    QPushButton *returnButton;

    // random pets
    int rand_rarity;
    std::vector<Pet> pet_list;
    Pet random_pet;    
    QPixmap random_pet_sprite;
    // std::vector<Pet> user_list;

    int loop = 0;

    void updateLoop();
    void updatePetSprites();
    int generateNumber();
    Pet generateRandomPet(std::vector<Pet> petlist, int rarity);
};

#endif // SCREEN1_HPP
