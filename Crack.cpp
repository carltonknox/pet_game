#include "Crack.hpp"

Crack::Crack(QWidget* parent, QStackedWidget *stackedWidget) 
    : QWidget(parent), stackedWidget(stackedWidget){
    // Create label with PNG image
    QPixmap image(":sprites/Eggo.png");
    imageLabel = new QLabel(this);
    imageLabel->setPixmap(image);

    // Create return button
    returnButton = new QPushButton("Return", this);
    connect(returnButton, &QPushButton::clicked, this, &Crack::on_returnButton_clicked);

    // Set layout for screen
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(imageLabel);
    layout->addWidget(returnButton);
    setLayout(layout);
}

void Crack::returnToMain(){
    stackedWidget->setCurrentIndex(0);
}

void Crack::on_returnButton_clicked() {
    // Emit a signal to indicate that the return button was clicked
    emit returnToMain();
}
