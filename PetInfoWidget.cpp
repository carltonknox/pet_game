#include "PetInfoWidget.hpp"
#include <QVBoxLayout>
#include <QLabel>
#include <QGraphicsView>

PetInfoWidget::PetInfoWidget(QWidget*parent):QWidget(parent),pet(){
    // setFixedSize(300, 400);
    setStyleSheet("background-color: white; border: 2px solid black;");
    // Create labels for the pet's name, description, and rarity
    nameLabel = new QLabel(this);
    descriptionLabel = new QLabel(this);
    rarityLabel = new QLabel(this);
    // Create a graphics view for the pet's sprite
    spriteView = new QGraphicsView(this);
//    spriteView->setFixedSize(100, 100);
    // Add the labels and sprite view to the layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(spriteView);
    layout->addWidget(nameLabel);
    layout->addWidget(descriptionLabel);
    layout->addWidget(rarityLabel);
    

    setLayout(layout);
    setPet(pet);
    this->hide();
}
void PetInfoWidget::setPet(const Pet& pet){
    this->pet=pet;

    nameLabel->setText(QString::fromStdString(pet.getName()));
    descriptionLabel->setText(QString::fromStdString(pet.getDescription()));
    rarityLabel->setText(QString("Rarity: %1").arg(pet.getRarity()));
    spriteView->setScene(new QGraphicsScene());
    spriteView->scene()->addPixmap(pet.getSprite().scaled(100, 100, Qt::KeepAspectRatio));
}
