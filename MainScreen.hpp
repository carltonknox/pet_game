#ifndef MAINSCREEN_HPP
#define MAINSCREEN_HPP

#include <QWidget>
#include <QPushButton>
#include <QStackedWidget>
#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>

#include <QLabel>

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

// public slots:
//     void showMain();

// private slots:
//     void showMenu();
    // void returnToMain();

private:

    QStackedWidget *stackedWidget;
    Inventory *inventory;
    Menu *menu;
    Purchase *screen1;
    Crack *screen2;
    PetScreen *screen3;
};

#endif // MAINSCREEN_HPP
