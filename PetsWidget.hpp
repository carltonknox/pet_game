#ifndef PETSWIDGET_HPP
#define PETSWIDGET_HPP
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtGui/QPainter>
#include <QtGui/QPixmap>
#include <QtCore/QTimer>
#include <QtGui/QBitmap>
#include <QtGui/QPaintEvent>
#include <vector>
#include "Pet.hpp"
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
    void removePet(std::vector<Pet>::iterator pid);

private:
    std::vector<Pet> pets;
};
#endif