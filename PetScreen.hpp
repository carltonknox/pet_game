#ifndef PETSCREEN_HPP
#define PETSCREEN_HPP

// #include "MainScreen.hpp"
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <unistd.h>
#include <QGridLayout>
#include <QMainWindow>
#include <QScrollArea>

#include "Pet.hpp"
#include "PetsWidget.hpp"
#include "PetsListWidget.hpp"
#include "PetGridWidget.hpp"
#include "Inventory.hpp"

class PetScreen : public QWidget
{
public:
    PetScreen(QWidget *parent, QStackedWidget *stackedWidget, Inventory *inventory);

    //function:
    void returnToMain();

private slots:
    void on_returnButton_clicked();

private:
    Inventory *inventory;
    QStackedWidget *stackedWidget;
    QLabel* imageLabel;
    QPushButton* returnButton;
};

#endif // SCREEN1_HPP
