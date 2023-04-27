#ifndef MAINSCREEN_HPP
#define MAINSCREEN_HPP

#include <QWidget>
#include <QPushButton>
#include <QStackedWidget>
#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>
#include <QCoreApplication>
#include <QFile>
#include <QLabel>
#include <signal.h>
#include <fstream>

#include "PetsWidget.hpp"
#include "PetScreen.hpp"
#include "Crack.hpp"
#include "Purchase.hpp"
#include "Menu.hpp"
#include "Inventory.hpp"


class MainScreen : public QWidget
{
    Q_OBJECT
public:
    MainScreen(QWidget *parent = nullptr);
    void writeInventoryToFile(int sig);
// public slots:
//     void showMain();

// private slots:
//     void showMenu();
    // void returnToMain();

private:
    std::vector<Pet> pets;
    std::vector<Pet> user_list;
    QStackedWidget *stackedWidget;
    Inventory *inventory;
    Menu *menu;
    Purchase *screen1;
    Crack *screen2;
    PetScreen *screen3;

    
    void loadInventoryFromFile(Inventory *inventory);
};

#endif // MAINSCREEN_HPP
