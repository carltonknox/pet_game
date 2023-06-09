#include "PetsWidget.hpp"
#include "Pet.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
//---PetsWidget---

PetsWidget::PetsWidget(QWidget* parent, Inventory* inventory)
    : QWidget(parent), inventory(inventory)
{
    //Set the widget size to match the visible dimensions of the sprite
//     setFixedSize(480, 272);
    
    // Create a timer to move the image every 20 milliseconds
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &PetsWidget::bounceImages);
    timer->start(20);
    
    // // create a timer to update the pet sprites
    // QTimer *sprite_timer = new QTimer(this);
    // connect(sprite_timer, &QTimer::timeout, this, &PetsWidget::updatePets);
    // sprite_timer->start(500);

    // this->setFixedSize(480,272);
    this->setStyleSheet("border: none; background-image: url(:sprites/_background.png);");

}
void PetsWidget::paintEvent(QPaintEvent* event){
    (void)event;
    QPainter painter(this);
    inventory->mutex.lockForRead();
    for (auto& pet : inventory->user_list) {
        painter.drawPixmap(pet.x, pet.y, pet.getSprite());
    }
    inventory->mutex.unlock();
}
void PetsWidget::updatePets(){
    // for (auto& pet : inventory->user_list) {
    //     pet.updateSprite();
    // }
    update();
}
void PetsWidget::bounceImages(){
    inventory->mutex.lockForRead();
    for (auto& pet : inventory->user_list) {
        QRect visibleRect = pet.getVisibleRect();
        
        pet.x+=pet.vx;
        pet.y+=pet.vy;

        // Check bouncing on the left and right edges
        if (pet.x + visibleRect.left() < 0) {
            pet.x = -visibleRect.left();
            pet.vx = -pet.vx;
        } else if (pet.x + visibleRect.right() > width()) {
            pet.x = width() - visibleRect.right() - 1;
            pet.vx = -pet.vx;
        }
        // Check bouncing on the top and bottom edges
        if (pet.y + visibleRect.top() < 0) {
            pet.y = -visibleRect.top();
            pet.vy = -pet.vy;
        } else if (pet.y + visibleRect.bottom() > height()) {
            // std::cout << "height: " << height();
            pet.y = height() - visibleRect.bottom() - 1;
            pet.vy = -pet.vy;
        }

        
    }
    inventory->mutex.unlock();
    //redraw
    update();
}
void PetsWidget::addPet(const Pet& pet){
    //add pet to pets vector, and do other stuff
    inventory->mutex.lockForWrite();
    inventory->user_list.push_back(pet);
    inventory->mutex.unlock();
}
void PetsWidget::removePet(std::vector<Pet>::iterator pid){
    inventory->mutex.lockForWrite();
    inventory->user_list.erase(pid);
    inventory->mutex.unlock();
}
