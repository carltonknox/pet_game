#ifndef PET_HPP
#define PET_HPP
// #include <String>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtGui/QPainter>
#include <QtGui/QPixmap>
#include <QtCore/QTimer>
#include <QtGui/QBitmap>
#include <QtGui/QPaintEvent>

class Pet
{
public:
    // Constructor
    Pet(const std::string &name, const std::string &description,
        const std::string &sprite1, const std::string &sprite2,
        int rarity);
    Pet();

    // functions
    const std::string &getName() const { return name; };
    const std::string &getDescription() const { return description; };
    const QPixmap &getSprite1() const { return sprite1; };
    const QPixmap &getSprite2() const { return sprite2; };
    int getRarity() const { return rarity; };

private:
    std::string name;
    std::string description;
    QPixmap sprite1;
    QPixmap sprite2;
    unsigned rarity; // 0-99
};
class PetWidget : public QWidget
{
public:
    // Constructor
    PetWidget(QWidget *parent=nullptr, const Pet &pet=Pet());
    // PetWidget(QWidget* parent, const Pet& pet, int x, int y);

    // Update the pet's animation and repaint the widget
    void updatePet();

    // bounce
    void bounceImage();

    void paintEvent(QPaintEvent *event) override;
    // void resizeEvent(QResizeEvent* event);

private:
    Pet pet;
    QPixmap currentSprite;
    QRegion visibleRegion;
    bool sprite_state;
    int x, y, vx, vy;
};

#endif
