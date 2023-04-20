#ifndef PETGRIDWIDGET_HPP
#define PETGRIDWIDGET_HPP

#include <QGridLayout>
#include <QScrollArea>
#include <QPixmap>
#include "Pet.hpp"
#include <vector>
#include <QLabel>

class PetGridWidget : public QScrollArea {
public:
    PetGridWidget(QWidget* parent, std::vector<Pet>& pets);
    void updatePets();

private:
    std::vector<Pet> pets;
    std::vector<QLabel*> spriteLabels;
};

#endif
