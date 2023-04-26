#include "PetScreen.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

PetScreen::PetScreen(QWidget* parent, QStackedWidget *stackedWidget, Inventory *inventory)
    : QWidget(parent), stackedWidget(stackedWidget), inventory(inventory){

    srand(time(NULL));

    // Create the widget
//    std::vector<Pet> pets = generatePets();

    // Create the pet grid widget
    petGrid = new PetGridWidget( this, inventory);
    petGrid->setContentsMargins(0,0,0,0);

    // Create return button
    QString buttonStyleSheet = "QPushButton {"
                               "    background-color: transparent;"
                               "    border: none;"
                               "}";

    returnButton = new QPushButton(QIcon(":sprites/Ret.png"), "", this);
    connect(returnButton, &QPushButton::clicked, this, &PetScreen::on_returnButton_clicked);
    returnButton->setStyleSheet(buttonStyleSheet);
    returnButton->move(10,10);

    // Set button size to match the size of the sprites
    QSize ret_sizeButton(50, 50);
    QSize ret_sizeIcon(100, 80);

    returnButton->setIconSize(ret_sizeIcon);
    returnButton->setFixedSize(ret_sizeButton);

    // Set layout for screen
    QVBoxLayout* layout = new QVBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(petGrid);
//    layout->addWidget(returnButton);
    setLayout(layout);
    this->setContentsMargins(0,0,0,0);
}

void PetScreen::returnToMain(){
    stackedWidget->setCurrentIndex(0);

}

void PetScreen::on_returnButton_clicked() {
    // Emit a signal to indicate that the return button was clicked
    if(petGrid->petInfo.isVisible())
        petGrid->petInfo.hide();
    else
        emit returnToMain();
}
