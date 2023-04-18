#include "Pet.hpp"
#include <unistd.h>
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // Create the widget
    // PetWidget widget(nullptr,Pet("Pet Rock","Active","Rock1","Rock2",0));
    PetWidget widget(nullptr,Pet("AvoCato","A cross between an avocado and a cat?!?!? the scientific comunity will be in shambles","AvoCato1","AvoCato2",0));
    widget.show();

    // Create a timer to move the image every 20 milliseconds
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, &widget, &PetWidget::bounceImage);
    timer.start(20);

    // sleep(1);
    // PetWidget widget2(nullptr,Pet("Egg","It's an eggfull time for all","Eggo","EggCrack",0));
    // widget2.show();
    // QObject::connect(&timer, &QTimer::timeout, &widget2, &PetWidget::bounceImage);


    return app.exec();
}