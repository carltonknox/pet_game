#include "Purchase.hpp"

Purchase::Purchase(QWidget *parent, QStackedWidget *stackedWidget, Inventory *inventory)
    : QWidget(parent), stackedWidget(stackedWidget), inventory(inventory)
{

    // // Create buttons
    // button1 = new QPushButton(QIcon(":sprites/Carton.png"), "", this);

    // // Set button size to match the size of the sprites
    // QSize sizeButton(135, 80);
    // QSize sizeIcon(250, 170);
    // QString buttonStyleSheet = "QPushButton {"
    //                            "    background-color: transparent;"
    //                            "    border: none;"
    //                            "}";

    // button1->setIconSize(sizeIcon);
    // button1->setFixedSize(sizeButton);
    // button1->setStyleSheet(buttonStyleSheet);

    // QObject::connect(button1, &QPushButton::clicked, inventory, &Inventory::addEgg);

    // Create return button
    returnButton = new QPushButton("Return", this);
    returnButton->setFixedSize(50,30);
    returnButton->move(10,10);
    connect(returnButton, &QPushButton::clicked, this, &Purchase::on_returnButton_clicked);

    // Set layout for screen
    QVBoxLayout *layout = new QVBoxLayout(this);
    // layout->addWidget(button1);
    layout->addWidget(returnButton);
    // layout->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    setLayout(layout);
}

void Purchase::returnToMain()
{
    stackedWidget->setCurrentIndex(0);
}

void Purchase::on_returnButton_clicked()
{
    // Emit a signal to indicate that the return button was clicked
    emit returnToMain();
}
