#ifndef PETSLISTWIDGET_HPP
#define PETSLISTWIDGET_HPP
#include <QWidget>
#include <QScrollArea>
#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include "Pet.hpp"

class PetsListWidget : public QScrollArea {
public:
    PetsListWidget(QWidget* parent, std::vector<Pet>& pets);
    void updatePets();

private:
    std::vector<Pet> pets;
    std::vector<QLabel*> spriteLabels;
};


#endif
