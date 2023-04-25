#ifndef Menu_HPP
#define Menu_HPP

// #include "MainScreen.hpp"
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <QDebug>
#include "PetsWidget.hpp"
#include "Pet.hpp"
#include "Inventory.hpp"

class Menu : public QWidget
{
public:
    Menu(QWidget *parent, QStackedWidget *stackedWidget, Inventory *inventory);


private slots:
    void showScreen1();
    void showScreen2();
    void showScreen3();

private:
    Inventory *inventory;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QStackedWidget *stackedWidget;
    QLabel* imageLabel;
    QPushButton* returnButton;
};

#endif // SCREEN1_HPP

