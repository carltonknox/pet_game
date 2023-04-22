// Include necessary headers
#include "Menu.hpp"

Menu::Menu(QWidget *parent, QStackedWidget *stackedWidget)
    : QWidget(parent), stackedWidget(stackedWidget)
{

    // Create buttons
    button1 = new QPushButton("", this);
    button1->setStyleSheet("qproperty-icon: url(:sprites/MenuPurchase.png);");
    QSize size(500, 500);
    button1->setIconSize(size);

    button2 = new QPushButton(QIcon(":sprites/MenuCrack.png"), "", this);
    button3 = new QPushButton(QIcon(":sprites/MenuCat.png"), "", this);

    // Set button size to match the size of the sprites

    button2->setIconSize(size);
    button3->setIconSize(size);

    connect(button1, &QPushButton::clicked, this, &Menu::showScreen1);
    connect(button2, &QPushButton::clicked, this, &Menu::showScreen2);
    connect(button3, &QPushButton::clicked, this, &Menu::showScreen3);

    stackedWidget->setCurrentIndex(0);
    stackedWidget->setContentsMargins(0,0,0,0);

    // Set up layout for main window
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(button1, 0, Qt::AlignCenter);
    layout->addWidget(button2, 0, Qt::AlignCenter);
    layout->addWidget(button3, 0, Qt::AlignCenter);
    setLayout(layout);
}

void Menu::showScreen1()
{
    qDebug() << "Show Screen 1";
    stackedWidget->setCurrentIndex(1);
}

void Menu::showScreen2()
{
    qDebug() << "Show Screen 2";
    stackedWidget->setCurrentIndex(2);
}

void Menu::showScreen3()
{
    qDebug() << "Show Screen 3";
    stackedWidget->setCurrentIndex(3);
}
