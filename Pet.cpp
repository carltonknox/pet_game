#include "Pet.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

//---Pet---
Pet::Pet(const std::string& name, const std::string& description,
        const std::string& sprite1, const std::string& sprite2,
        int rarity)
        : name(name), description(description), rarity(rarity), sprite_state(0){

    std::string s1 = ":sprites/"+sprite1+".png";
    std::string s2 = ":sprites/"+sprite2+".png";


    this->sprite1 = QPixmap(QString::fromStdString(s1)).scaled(QSize(100, 100));
    this->sprite2 = QPixmap(QString::fromStdString(s2)).scaled(QSize(100, 100));


    if(this->sprite1.isNull() || this->sprite2.isNull() || !(this->sprite1.size().width()>0&&this->sprite2.size().width()>0))
        throw std::runtime_error("Failed to load images: " + sprite1 +" "+ sprite2);
        
    assert(rarity <100);

    x=0;
    y=0;
    vx=rand()%8-4;
    vy=rand()%8-4;

    visibleRect = QRegion(getSprite().createMaskFromColor(QColor(0,0,0),Qt::MaskOutColor)).boundingRect();
    // visibleRegion = QRegion(boundingRect);
}
Pet::Pet()
        :name("Pet Rock"), description("Energetic"), rarity(0) {
    this->sprite1 = QPixmap(":sprites/Rock1.png").scaled(QSize(100, 100));
    this->sprite2 = QPixmap(":sprites/Rock2.png").scaled(QSize(100, 100));
    assert(this->sprite1.size().width()>0);

    x=0;
    y=0;
    vx=rand()%8-4;
    vy=rand()%8-4;

    visibleRect = QRegion(getSprite().createMaskFromColor(QColor(0,0,0),Qt::MaskOutColor)).boundingRect();
    // visibleRegion = QRegion(boundingRect);
}
void Pet::updateSprite()
{
    sprite_state = !sprite_state;
}

//---PetsWidget---

PetsWidget::PetsWidget(QWidget* parent, const std::vector<Pet> &pets)
    : QWidget(parent), pets(pets)
{
    //Set the widget size to match the visible dimensions of the sprite
//     setFixedSize(480, 272);
    
    // Create a timer to move the image every 20 milliseconds
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &PetsWidget::bounceImages);
    timer->start(20);
    //create a timer to update the pet sprites
    QTimer* sprite_timer = new QTimer(this);
    connect(sprite_timer, &QTimer::timeout, this, &PetsWidget::updatePets);
    sprite_timer->start(500);
}
void PetsWidget::paintEvent(QPaintEvent* event){
    (void)event;
    QPainter painter(this);
    for (int i = 0; i < pets.size(); i++) {
        painter.drawPixmap(pets[i].x, pets[i].y, pets[i].getSprite());
    }
}
void PetsWidget::updatePets(){
    for (auto& pet : pets) {
        pet.updateSprite();
    }
    update();
}
void PetsWidget::bounceImages(){
    for (auto& pet : pets) {
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
    //redraw
    update();
}
void PetsWidget::addPet(const Pet& pet){
    //add pet to pets vector, and do other stuff
    pets.push_back(pet);
}
void PetsWidget::removePet(unsigned pid){
    //TODO Remove Timers, make timers vector
    return;
}
