#ifndef PETGRIDWIDGET_HPP
#define PETGRIDWIDGET_HPP

#include <QGridLayout>
#include <QScrollArea>
#include <QPixmap>
#include "Pet.hpp"
#include "Inventory.hpp"
#include <vector>
#include <QLabel>

class PetGridWidget : public QScrollArea {
public:
    PetGridWidget(QWidget* parent, Inventory* inventory);
    void updatePets();

private:
    Inventory* inventory;
    std::vector<QLabel*> spriteLabels;
    QGridLayout* layout;
};

#endif
