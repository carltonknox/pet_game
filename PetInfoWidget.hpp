#ifndef PETINFOWIDGET_HPP
#define PETINFOWIDGET_HPP
#include "Pet.hpp"
#include <QtWidgets/QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QGraphicsView>
class PetInfoWidget : public QWidget
{
public:
    PetInfoWidget(QWidget *parent = nullptr);
    void setPet(const Pet& pet); // method to set the pet info to display
private:
    Pet pet;
    QLabel *nameLabel;
    QLabel *descriptionLabel;
    QLabel *rarityLabel;
    // Create a graphics view for the pet's sprite
    QGraphicsView *spriteView;
};
#endif