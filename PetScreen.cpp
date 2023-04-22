#include "PetScreen.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

PetScreen::PetScreen(QWidget* parent, QStackedWidget *stackedWidget) 
    : QWidget(parent), stackedWidget(stackedWidget){

    srand(time(NULL));

    // Create the widget
    std::vector<Pet> pets = generatePets();

    // Create the pet grid widget
    PetGridWidget* petGrid = new PetGridWidget( this, pets);

    // Create return button
    returnButton = new QPushButton("Return", this);
    connect(returnButton, &QPushButton::clicked, this, &PetScreen::on_returnButton_clicked);

    // Set layout for screen
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(petGrid);
    layout->addWidget(returnButton);
    setLayout(layout);
}

void PetScreen::returnToMain(){
    stackedWidget->setCurrentIndex(0);
}

void PetScreen::on_returnButton_clicked() {
    // Emit a signal to indicate that the return button was clicked
    emit returnToMain();
}
