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
#include <vector>
class Pet {
public:
    // Constructor
    Pet(const std::string& name, const std::string& description,
        const std::string& sprite1, const std::string& sprite2,
        int rarity);
    Pet();

    //functions
    const std::string& getName() const{ return name;};
    const std::string& getDescription() const{return description;};
    // const QPixmap& getSprite1() const{return sprite1;};
    // const QPixmap& getSprite2() const{return sprite2;};
    const QPixmap& getSprite() const{return (sprite_state)?sprite2:sprite1;};
    int getRarity() const{return rarity;};
    void updateSprite();
    const QRect& getVisibleRect() const{return visibleRect;};
    //public position values
    int x,y, vx, vy;
private:
    std::string name;
    std::string description;
    QPixmap sprite1;
    QPixmap sprite2;
    unsigned rarity;//0-99
    //grapics values
    bool sprite_state;
    
    QRect visibleRect;
};
class PetsWidget : public QWidget
{
public:
    // Constructor
    PetsWidget(QWidget *parent=nullptr, const std::vector<Pet> &pets=std::vector<Pet>());
    // PetWidget(QWidget* parent, const Pet& pet, int x, int y);

    // Update the pet's animation and repaint the widget
    void updatePets();

    // bounce
    void bounceImages();

    void paintEvent(QPaintEvent *event) override;
    // void resizeEvent(QResizeEvent* event);

    void addPet(const Pet& pet);
    void removePet(unsigned pid);

private:
    std::vector<Pet> pets;
};

#endif
