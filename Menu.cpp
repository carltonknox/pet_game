// Include necessary headers
#include "Menu.hpp"
#include "Pet.hpp"
#include "PetsWidget.hpp"
#include <QStackedLayout>
Menu::Menu(QWidget *parent, QStackedWidget *stackedWidget,const std::vector<Pet>&pets)
    : QWidget(parent), stackedWidget(stackedWidget)
{



    // Create buttons
    button1 = new QPushButton(QIcon(":sprites/MenuCarton.png"), "", this);
    button2 = new QPushButton(QIcon(":sprites/MenuCrack.png"), "", this);
    button3 = new QPushButton(QIcon(":sprites/MenuCat.png"), "", this);

    // Set button size to match the size of the sprites
    QSize sizeButton(120, 150);
    QSize sizeIcon(190, 170);
    QString buttonStyleSheet = "QPushButton {"
                               "    background-color: transparent;"
                               "    border: none;"
                               "}";

    button1->setIconSize(sizeIcon);
    button1->setFixedSize(sizeButton);
    button1->setStyleSheet(buttonStyleSheet);

    button2->setIconSize(sizeIcon);
    button2->setFixedSize(sizeButton);
    button2->setStyleSheet(buttonStyleSheet);

    button3->setIconSize(sizeIcon);
    button3->setFixedSize(sizeButton);
    button3->setStyleSheet(buttonStyleSheet);


//    std::vector<Pet> pets=generatePets();
    // Create pets widget
    PetsWidget* petswidget = new PetsWidget(this, pets);
    petswidget->setMinimumSize(480,272);
    // Set up layouts

    QWidget* buttonWidget = new QWidget(this);
    QHBoxLayout* buttonLayout = new QHBoxLayout(buttonWidget);
    QVBoxLayout *menuLayout = new QVBoxLayout(buttonWidget);
    // Add buttons to button layout
    buttonLayout->addWidget(button1, 0, Qt::AlignCenter);
    buttonLayout->addWidget(button2, 0, Qt::AlignCenter);
    buttonLayout->addWidget(button3, 0, Qt::AlignCenter);

    menuLayout->addLayout(buttonLayout);

    // Set the main layout for this widget
//    setLayout(menuLayout);
    setLayout(buttonLayout);


    connect(button1, &QPushButton::clicked, this, &Menu::showScreen1);
    connect(button2, &QPushButton::clicked, this, &Menu::showScreen2);
    connect(button3, &QPushButton::clicked, this, &Menu::showScreen3);

    stackedWidget->setCurrentIndex(0);
    stackedWidget->setContentsMargins(0,0,0,0);



//    // Set up layout for main window
//    QHBoxLayout *layout = new QHBoxLayout;
//    layout->addWidget(button1, 0, Qt::AlignCenter);
//    layout->addWidget(button2, 0, Qt::AlignCenter);
//    layout->addWidget(button3, 0, Qt::AlignCenter);
//    setLayout(layout);
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
