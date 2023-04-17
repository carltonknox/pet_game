#ifndef PET_HPP
#define PET_HPP
#include <QString>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtGui/QPainter>
#include <QtGui/QPixmap>
#include <QtCore/QTimer>
#include <QtGui/QBitmap>
#include <QtGui/QPaintEvent>
class Pet {
public:
    // Constructor
    Pet(const QString& name, const QString& description,
        const QString& sprite1, const QString& sprite2,
        int rarity);

    functions
    const QString& getName() const{ return name};
    const QString& getDescription() const{return description};
    const QPixmap& getSprite1() const{return sprite1};
    const QPixmap& getSprite2() const{return sprite2};
    int getRarity(){return rarity} const;
    void bounceImage();

private:
    QString name;
    QString description;
    QPixmap sprite1;
    QPixmap sprite2;
    unsigned rarity;//0-99
};
class PetWidget : public QWidget {
public:
    // Constructor
    PetWidget(QWidget* parent, const Pet& pet);

    // Update the pet's animation and repaint the widget
    void updatePet();

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    Pet pet;
    QPixmap currentSprite;
    QRegion visibleRegion;
    bool sprite_state;
    int x,y, vx, vy;
};

#endif