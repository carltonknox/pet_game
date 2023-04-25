#include <QWidget>
#include <QScrollArea>
#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include "Pet.hpp"
#include "PetGridWidget.hpp"
#include <QScroller>
#define ICON_SIZE 100
//#define GRID_LENGTH ((width()>0)?width()/ICON_SIZE:4)
#define GRID_LENGTH 4
PetGridWidget::PetGridWidget(QWidget* parent, Inventory *inventory) : QScrollArea(parent), inventory(inventory),spriteLabels() {
    QScroller::grabGesture(this, QScroller::TouchGesture);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // Create a grid layout to arrange the pet icons
    QWidget* containerWidget = new QWidget(this);
    QGridLayout* layout = new QGridLayout(containerWidget);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);

    // Add the pet icons to the grid
    for (unsigned long i = 0; i < inventory->user_list.size(); i++) {
        // Create a label for the pet's sprite
        spriteLabels.push_back(new QLabel(this));

        spriteLabels[i]->setPixmap(inventory->user_list[i].getSprite().scaled(ICON_SIZE, ICON_SIZE, Qt::KeepAspectRatio));
        spriteLabels[i]->setAlignment(Qt::AlignCenter);

        layout->addWidget(spriteLabels[i], i / GRID_LENGTH, i % GRID_LENGTH);
    }
    containerWidget->setLayout(layout);
    setWidgetResizable(true);
    setWidget(containerWidget);

    QTimer* sprite_timer = new QTimer(this);
    connect(sprite_timer, &QTimer::timeout, this, &PetGridWidget::updatePets);
    sprite_timer->start(500);
}
void PetGridWidget::updatePets(){
    for(unsigned long i=0;i<inventory->user_list.size();i++){
        inventory->user_list[i].updateSprite();
        spriteLabels[i]->setPixmap(inventory->user_list[i].getSprite().scaled(ICON_SIZE, ICON_SIZE, Qt::KeepAspectRatio));
    }
    update();
}
