#ifndef PETGRIDWIDGET_HPP
#define PETGRIDWIDGET_HPP

#include <QGridLayout>
#include <QScrollArea>
#include <QPixmap>
#include "Pet.hpp"
#include "Inventory.hpp"
#include <vector>
#include <QLabel>
#include "PetInfoWidget.hpp"

class PressLabel:public QLabel{
    Q_OBJECT
    public:
        PressLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    signals:
        void clicked();
    protected:
        void mousePressEvent(QMouseEvent* event);
};

class PetGridWidget : public QScrollArea {
    Q_OBJECT
public:
    PetGridWidget(QWidget* parent, Inventory* inventory);
    void updatePets();

private:
    Inventory* inventory;
    std::vector<PressLabel*> spriteLabels;
    QGridLayout* layout;
    PetInfoWidget petInfo;
public slots:
    void showPetInfo(const Pet& pet);

};

#endif
