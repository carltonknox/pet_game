#include "Purchase.hpp"

Purchase::Purchase(QWidget* parent, QStackedWidget *stackedWidget) 
    : QWidget(parent), stackedWidget(stackedWidget){
    // Create label with PNG image
    QPixmap image(":sprites/Carton.png");
    imageLabel = new QLabel(this);
    imageLabel->setPixmap(image);

    // Create return button
    returnButton = new QPushButton("Return", this);
    connect(returnButton, &QPushButton::clicked, this, &Purchase::on_returnButton_clicked);

    // Set layout for screen
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(imageLabel);
    layout->addWidget(returnButton);
    setLayout(layout);
}

void Purchase::returnToMain(){
    stackedWidget->setCurrentIndex(0);
}

void Purchase::on_returnButton_clicked() {
    // Emit a signal to indicate that the return button was clicked
    emit returnToMain();
}
