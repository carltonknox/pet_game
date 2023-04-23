#include "Purchase.hpp"

Purchase::Purchase(QWidget *parent, QStackedWidget *stackedWidget, Inventory *inventory)
    : QWidget(parent), stackedWidget(stackedWidget), inventory(inventory)
{

    // Create buttons
    button1 = new QPushButton(QIcon(":sprites/Carton.png"), "", this);

    // Set button size to match the size of the sprites
    QSize sizeButton(135, 80);
    QSize sizeIcon(250, 170);
    QString buttonStyleSheet = "QPushButton {"
                               "    background-color: transparent;"
                               "    border: none;"
                               "}";

    button1->setIconSize(sizeIcon);
    button1->setFixedSize(sizeButton);
    button1->setStyleSheet(buttonStyleSheet);

    QObject::connect(button1, &QPushButton::clicked, inventory, &Inventory::addEgg);

    // Create label for the text
    QLabel *label = new QLabel("Click to purchase~", this);
    label->setAlignment(Qt::AlignCenter);

    // Create return button
    returnButton = new QPushButton("Return", this);
    returnButton->setFixedSize(50, 30);
    returnButton->move(10, 10);
    connect(returnButton, &QPushButton::clicked, this, &Purchase::on_returnButton_clicked);

    // Create layout for button1 and center it
    QVBoxLayout *layout1 = new QVBoxLayout();
    layout1->addWidget(button1);
    layout1->addWidget(label);
    layout1->setAlignment(Qt::AlignCenter);

    // Create layout for returnButton and align it to the top left corner
    QVBoxLayout *layout2 = new QVBoxLayout();
    layout2->addWidget(returnButton);
    layout2->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    // Create main layout and add the two layouts to it
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(layout2);
    mainLayout->addLayout(layout1);

    setLayout(mainLayout);
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
