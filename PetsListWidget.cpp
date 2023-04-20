#include <QWidget>
#include <QScrollArea>
#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include "Pet.hpp"
#include "PetsListWidget.hpp"

PetsListWidget::PetsListWidget(QWidget* parent, std::vector<Pet>& pets) : QScrollArea(parent), pets(pets),spriteLabels() {
    QWidget* containerWidget = new QWidget(this);
    QGridLayout* layout = new QGridLayout(containerWidget);

    for (unsigned long i = 0; i < pets.size(); i++) {
        // Create a label for the pet's sprite
        spriteLabels.push_back(new QLabel(this));
        
        spriteLabels[i]->setPixmap(pets[i].getSprite().scaled(64, 64, Qt::KeepAspectRatio));

        // Create a label for the pet's name
        QLabel* nameLabel = new QLabel(QString::fromStdString(pets[i].getName()), this);

        // Create a label for the pet's description
        QLabel* descriptionLabel = new QLabel(QString::fromStdString(pets[i].getDescription()), this);
        descriptionLabel->setWordWrap(true);

        // Add the labels to the layout
        layout->addWidget(spriteLabels[i], i, 0);
        layout->addWidget(nameLabel, i, 1);
        layout->addWidget(descriptionLabel, i, 2);
    }

    containerWidget->setLayout(layout);
    setWidgetResizable(true);
    setWidget(containerWidget);

    QTimer* sprite_timer = new QTimer(this);
    connect(sprite_timer, &QTimer::timeout, this, &PetsListWidget::updatePets);
    sprite_timer->start(500);
}
void PetsListWidget::updatePets(){
    for(unsigned long i=0;i<pets.size();i++){
        pets[i].updateSprite();
        spriteLabels[i]->setPixmap(pets[i].getSprite().scaled(64, 64, Qt::KeepAspectRatio));
    }
    update();
}
