#include "PetInfoWidget.hpp"
#include <QVBoxLayout>
#include <QLabel>
#include <QGraphicsView>
#include <QPushButton>
#include <QScrollArea>
#include <QScroller>

PetInfoWidget::PetInfoWidget(QWidget*parent):QScrollArea(parent),pet(){
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

    QPushButton* sellButton = new QPushButton(QIcon(":sprites/Ret.png"), "", this);
    connect(sellButton, &QPushButton::clicked, this, &PetInfoWidget::sell);
    sellButton->setStyleSheet(buttonStyleSheet);
    sellButton->move(400,10);

    // Set button size to match the size of the sprites
    QSize ret_sizeButton(50, 50);
    QSize ret_sizeIcon(100, 80);

    sellButton->setIconSize(ret_sizeIcon);
    sellButton->setFixedSize(ret_sizeButton);



    // Add the labels and sprite view to the layout
    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addLayout(hboxLayout);
    layout->addWidget(nameLabel);
    layout->addWidget(descriptionLabel);
    layout->addWidget(rarityLabel);

    setLayout(layout);
    setPet(pet);
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
void PetInfoWidget::setPet(const Pet& pet){
    this->pet=pet;

    nameLabel->setText(QString::fromStdString(pet.getName()));
    descriptionLabel->setText(QString::fromStdString(pet.getDescription()));
    rarityLabel->setText(QString("Rarity: %1").arg(pet.getRarity()));
    spriteView->setScene(new QGraphicsScene());
    spriteView->scene()->addPixmap(pet.getSprite().scaled(100, 100, Qt::KeepAspectRatio));
}
void PetInfoWidget::sell(){

}
