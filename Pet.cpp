#include "Pet.hpp"
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <ctime>
// #include <String>

//---Pet---
Pet::Pet(const std::string &name, const std::string &description,
         const std::string &sprite1, const std::string &sprite2,
         int rarity)
    : name(name), description(description), rarity(rarity)
{

    std::string s1 = ":sprites/" + sprite1 + ".png";
    std::string s2 = ":sprites/" + sprite2 + ".png";

    this->sprite1 = QPixmap(QString::fromStdString(s1)).scaled(QSize(100, 100));
    this->sprite2 = QPixmap(QString::fromStdString(s2)).scaled(QSize(100, 100));

    assert(this->sprite1.size().width() > 0);
    if (this->sprite1.isNull() || this->sprite2.isNull())
        throw std::runtime_error("Failed to load images: " + sprite1 + " " + sprite2);

    assert(rarity < 100);
}
Pet::Pet()
    : name("Pet Rock"), description("Energetic"), rarity(0)
{
    this->sprite1 = QPixmap(":sprites/Rock1.png").scaled(QSize(480, 272));
    this->sprite2 = QPixmap(":sprites/Rock2.png").scaled(QSize(480, 272));
    assert(this->sprite1.size().width() > 0);
}

//---PetWidget---
PetWidget::PetWidget(QWidget *parent, const Pet &pet)
    : QWidget(parent), pet(pet), sprite_state(0),
      vx(2), vy(2)
{
    this->setStyleSheet("border: 1px solid red;");

    currentSprite = pet.getSprite1();

    // Get the bounding rectangle of the non-transparent pixels
    assert(currentSprite.size().width() > 0);
    QRect boundingRect = QRegion(currentSprite.createMaskFromColor(QColor(0, 0, 0), Qt::MaskOutColor)).boundingRect();

    // create visible region
    visibleRegion = QRegion(boundingRect);

    // // Set the widget size to match the visible dimensions of the sprite
    setFixedSize(480, 272);

    // Set the widget size to match the visible dimensions of the sprite
    // setFixedSize(boundingRect.width(), boundingRect.height());

    // Create a timer to switch between the two images every 500 milliseconds
    QTimer *sprite_timer = new QTimer(this);
    connect(sprite_timer, &QTimer::timeout, this, &PetWidget::updatePet);
    sprite_timer->start(500);

    // Create a timer to move the image every 20 milliseconds
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &PetWidget::bounceImage);
    timer->start(20);
}

void PetWidget::paintEvent(QPaintEvent *event)
{
    (void)event;
    QPainter painter(this);
    painter.drawPixmap(x, y, currentSprite);
}

void PetWidget::updatePet()
{
    sprite_state = !sprite_state;
    if (sprite_state)
    {
        currentSprite = pet.getSprite2();
    }
    else
    {
        currentSprite = pet.getSprite1();
    }
    update();
}

void PetWidget::bounceImage() {
    // Move the image and bounce off the edges of the widget
    QRect visibleRect = visibleRegion.boundingRect();

    x += vx;
    y += vy;

    // Check bouncing on the left and right edges
    if (x + visibleRect.left() < 0) {
        x = -visibleRect.left();
        vx = -vx;
    } else if (x + visibleRect.right() > width()) {
        x = width() - visibleRect.right() - 1;
        vx = -vx;
    }

    // Check bouncing on the top and bottom edges
    if (y + visibleRect.top() < 0) {
        y = -visibleRect.top();
        vy = -vy;
    } else if (y + visibleRect.bottom() > height()) {
        // std::cout << "height: " << height();
        y = height() - visibleRect.bottom() - 1;
        vy = -vy;
    }

    // std::cout << "height: " << height();
    // std::cout << "width: " << width();

    // Redraw the widget
    update();
}
