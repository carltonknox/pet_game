#include "Purchase.hpp"

Purchase::Purchase(QWidget *parent, QStackedWidget *stackedWidget, Inventory *inventory)
    : QWidget(parent), stackedWidget(stackedWidget), inventory(inventory)
{

    // Create buttons
    purchase_egg = new QPushButton(QIcon(":sprites/Carton.png"), "", this);

    // Set button size to match the size of the sprites
    QSize sizeButton(250, 130);
    QSize sizeIcon(920, 300);
    QString buttonStyleSheet = "QPushButton {"
                               "    background-color: transparent;"
                               "    border: none;"
                               "}";

    purchase_egg->setIconSize(sizeIcon);
    purchase_egg->setFixedSize(sizeButton);
    purchase_egg->setStyleSheet(buttonStyleSheet);

    // Create egg and coin count labels
    QLabel *egg_count_label = new QLabel("Egg: 0", this);
    QLabel *coin_count_label = new QLabel("Coin: 0", this);

    // Update the label texts with the current egg and coin counts
    int egg_count = inventory->getEggCount();
    int coin_count = inventory->getCoinCount();
    egg_count_label->setText(QString("Egg: %1").arg(egg_count));
    coin_count_label->setText(QString("Coin: %1").arg(coin_count));

    // Connect the clicked signal of purchase_egg to a lambda function that updates the egg and coin counts and label texts
    QObject::connect(purchase_egg, &QPushButton::clicked, [=]()
    {
        if(inventory->removeCoin() == 0) {
            inventory->addEgg();
        } 

        // Update the egg and coin counts
        int egg_count = inventory->getEggCount();
        int coin_count = inventory->getCoinCount();

        // Update the label texts
        egg_count_label->setText(QString("Egg: %1").arg(egg_count));
        coin_count_label->setText(QString("Coin: %1").arg(coin_count)); 
    });
    
    // Create label for the text
    QLabel *label = new QLabel("Click to purchase~", this);
    label->setAlignment(Qt::AlignCenter);

    // Create return button


    returnButton = new QPushButton(QIcon(":sprites/Ret.png"), "", this);
    // returnButton->move(10, 10);
    connect(returnButton, &QPushButton::clicked, this, &Purchase::on_returnButton_clicked);
    returnButton->setStyleSheet(buttonStyleSheet);
    
    // Set button size to match the size of the sprites
    QSize ret_sizeButton(30, 30);
    QSize ret_sizeIcon(50, 50);
    
    returnButton->setIconSize(ret_sizeIcon);
    returnButton->setFixedSize(ret_sizeButton);
        

    // Create layout for purchase_egg and center it
    QVBoxLayout *layout1 = new QVBoxLayout();
    layout1->addWidget(purchase_egg);
    layout1->addWidget(label);
    layout1->setAlignment(Qt::AlignCenter);

    // Create layout for returnButton and align it to the top left corner
    QHBoxLayout *layout2 = new QHBoxLayout();
    layout2->addWidget(returnButton);
    layout2->addWidget(egg_count_label);
    layout2->addWidget(coin_count_label);
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
