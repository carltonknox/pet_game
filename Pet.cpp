#include "Pet.hpp"
//---Pet---
Pet::Pet(const QString& name, const QString& description,
        const QString& image1, const QString& image2,
        unsigned rarity)
        : name(name), description(description), rarity(rarity){
    
    sprite1 = QPixmap(":sprites/"+image1).scaled(QSize(100, 100));
    sprite2 = QPixmap(":sprites/"+image2).scaled(QSize(100, 100));
    assert(rarity <100);
}


//---PetWidget---

PetWidget::PetWidget(QWidget* parent=nullptr, const Pet& pet)
    : QWidget(parent), pet(pet), sprite_state(0),
    x(100),y(100),vx(2),vy(2)
{
    // Get the bounding rectangle of the non-transparent pixels
    QRect boundingRect = QRegion(currentSprite.createMaskFromColor(QColor(0,0,0),Qt::MaskOutColor)).boundingRect();
    // create visible region
    visibleRegion = QRegion(boundingRect);

    // Set the widget size to match the visible dimensions of the sprite
    setFixedSize(m_visibleRegion.boundingRect().size());

    // Create a timer to switch between the two images every 500 milliseconds
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &PetWidget::updatePet);
    timer->start(500);
}

void PetWidget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.drawPixmap(x, y, currentSprite);
}

void PetWidget::updatePet() {
    sprite_state = !sprite_state;
    if (sprite_state) {
        currentSprite = pet.getSprite2();
    } else {
        currentSprite = pet.getSprite1();
    }
    update();
}

void PetWidget::bounceImage(){
    // Move the image and bounce off the edges of the widget
    QRect visibleRect = visibleRegion.boundingRect();

    x += vx;
    y += vy;

    // Check bouncing on the left and right edges
    if (x + visibleRect.left() < 0) {
        x = -visibleRect.left();
        vx = -vx;
    } else if (x + visibleRect.right() > width()) {
        x = width() - visibleRect.right();
        vx = -vx;
    }

    // Check bouncing on the top and bottom edges
    if (y + visibleRect.top() < 0) {
        y = -visibleRect.top();
        vy = -vy;
    } else if (y + visibleRect.bottom() > height()) {
        y = height() - visibleRect.bottom();
        vy = -vy;
    }

    // Redraw the widget
    update();
}