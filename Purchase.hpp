#ifndef PURCHASE_HPP
#define PURCHASE_HPP

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

class Purchase : public QWidget
{
public:
    Purchase(QWidget *parent, QStackedWidget *stackedWidget, Inventory *inventory);

    //function:
    void returnToMain();

private slots:
    void on_returnButton_clicked();

private:
    QLabel *egg_count_label;
    QLabel *coin_count_label; 

    QStackedWidget *stackedWidget;
    QPushButton *purchase_egg;
    Inventory *inventory;
    // QLabel* imageLabel;
    QPushButton* returnButton;

    void updateInventory();
};

#endif // SCREEN1_HPP
