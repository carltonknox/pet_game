#include <QWidget>
#include <QScrollArea>
#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include "Pet.hpp"
#include "PetGridWidget.hpp"
#include <QScroller>
#include "PetScreen.hpp"
#define ICON_SIZE 100
// #define GRID_LENGTH ((width()>0)?width()/ICON_SIZE:4)
#define GRID_LENGTH 4
PetGridWidget::PetGridWidget(QWidget *parent, Inventory *inventory) : QScrollArea(parent), inventory(inventory), spriteLabels(), petInfo(this)
{
    QScroller::grabGesture(this, QScroller::TouchGesture);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // Create a grid layout to arrange the pet icons
    QWidget *containerWidget = new QWidget(this);
    layout = new QGridLayout(containerWidget);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);

    // Add the pet icons to the grid
    updatePets();
    
    containerWidget->setLayout(layout);
    setWidgetResizable(true);
    setWidget(containerWidget);

    QTimer *sprite_timer = new QTimer(this);
    connect(sprite_timer, &QTimer::timeout, this, &PetGridWidget::updatePets);
    sprite_timer->start(100);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(&petInfo);

}
void PetGridWidget::updatePets()
{
    // Update the sprite labels and add/remove sprite labels from the grid layout
    int numPets = inventory->user_list.size();
    int numSpriteLabels = spriteLabels.size();

    for (int i = 0; i < numPets; i++)
    {
        if (i >= numSpriteLabels)
        {
            // Add a new sprite label to the grid layout
            spriteLabels.push_back(new PressLabel(this));
            spriteLabels.back()->setAlignment(Qt::AlignCenter);
        }
        else
        {
            if (numPets != numSpriteLabels){
                layout->removeWidget(spriteLabels[i]);
                QObject::disconnect(spriteLabels[i], &PressLabel::clicked, this, nullptr);
            }
        }

        // Create a label for the pet's sprite
        // inventory->user_list[i].updateSprite();
        spriteLabels[i]->setPixmap(inventory->user_list[i].getSprite().scaled(ICON_SIZE, ICON_SIZE, Qt::KeepAspectRatio));

        if(numPets!=numSpriteLabels){
            layout->addWidget(spriteLabels[i], i / GRID_LENGTH, i % GRID_LENGTH);
            QObject::connect(spriteLabels[i], &PressLabel::clicked, this, [this, i]() {
                showPetInfo(inventory->user_list[i]);
            });
        }
    }

    for (int i = numPets; i < numSpriteLabels; i++)
    {
        // Remove sprite labels from the grid layout
        PressLabel *label = spriteLabels.back();
        spriteLabels.pop_back();
        delete label;
    }

    update();
}
void PetGridWidget::showPetInfo(const Pet& pet)
{
    petInfo.setPet(pet);
    // Show the pet info widget
    petInfo.show();
}


PressLabel::PressLabel(QWidget* parent, Qt::WindowFlags f): QLabel(parent) {

}
void PressLabel::mousePressEvent(QMouseEvent* event) {
    emit clicked();
}
