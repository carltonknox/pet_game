#include "PetInfoWidget.hpp"
#include <QVBoxLayout>
#include <QLabel>
#include <QGraphicsView>
#include <QPushButton>
#include <QScrollArea>
#include <QScroller>
#include <vector>
#include <QDebug>

PetInfoWidget::PetInfoWidget(QWidget*parent, Inventory* inventory):QScrollArea(parent),pet(), inventory(inventory){
    // setFixedSize(300, 400);
    setStyleSheet("background-color: white; border: 2px solid black;");
    // Create labels for the pet's name, description, and rarity
    nameLabel = new QLabel(this);
    descriptionLabel = new QLabel(this);
    descriptionLabel->setWordWrap(true);
    rarityLabel = new QLabel(this);
    // Create a graphics view for the pet's sprite
    spriteView = new QGraphicsView(this);
    spriteView->setFixedSize(105, 105);
    QHBoxLayout *hboxLayout = new QHBoxLayout;
    hboxLayout->addWidget(spriteView, 0, Qt::AlignCenter);


    QString buttonStyleSheet = "QPushButton {"
                               "    background-color: transparent;"
                               "    border: none;"
                               "}";

    QPushButton* sellButton = new QPushButton(QIcon(":sprites/sell.png"), "", this);
    connect(sellButton, &QPushButton::clicked, this, &PetInfoWidget::sell);
    sellButton->setStyleSheet(buttonStyleSheet);
    sellButton->move(400,0);

    // Set button size to match the size of the sprites
    QSize ret_sizeButton(60, 50);
    QSize ret_sizeIcon(110, 80);

    sellButton->setIconSize(ret_sizeIcon);
    sellButton->setFixedSize(ret_sizeButton);

    priceLabel = new QLabel(this);
    priceLabel->setText("Sell Price: ");
    priceLabel->move(360,50);



    // Add the labels and sprite view to the layout
    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addLayout(hboxLayout);
    layout->addWidget(nameLabel);
    layout->addWidget(descriptionLabel);
    layout->addWidget(rarityLabel);

    setLayout(layout);
    setPet(pet,0);
    this->hide();
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=]() {
        pet.updateSprite();
        spriteView->scene()->clear();
        spriteView->scene()->addPixmap(pet.getSprite().scaled(100, 100, Qt::KeepAspectRatio));
        spriteView->update();

    });
    timer->start(500);

    QScroller::grabGesture(this, QScroller::TouchGesture);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}
void PetInfoWidget::setPet(const Pet& pet,unsigned index){
    this->pet=pet;
    this->index=index;
    price = pet.getRarity()*pet.getRarity()/3.5 + pet.getRarity()*2+2;
    priceLabel->setText(QString("Sell Price: %1").arg(price));

    nameLabel->setText(QString::fromStdString(pet.getName()));
    descriptionLabel->setText(QString::fromStdString(pet.getDescription()));
    rarityLabel->setText(QString("Rarity: %1").arg(pet.getRarity()));
    spriteView->setScene(new QGraphicsScene());
    spriteView->scene()->addPixmap(pet.getSprite().scaled(100, 100, Qt::KeepAspectRatio));

}
void PetInfoWidget::sell(){

    this->hide();

    inventory->mutex.lockForWrite();
    inventory->user_list.erase(inventory->user_list.begin()+index);
    inventory->mutex.unlock();

    inventory->setCoinCount(inventory->getCoinCount() + price);

}
