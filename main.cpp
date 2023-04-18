#include "Pet.hpp"
#include <unistd.h>
int main(int argc, char* argv[]) {

// Set the random seed based on the current time
    srand(time(NULL));

    QApplication app(argc, argv);



    // Create the widget
    PetWidget widget1(nullptr,Pet("AvoCato","A cross between an avocado and a cat?!?!? the scientific comunity will be in shambles","AvoCato1","AvoCato2",0));
    widget1.show();
    PetWidget widget2(nullptr,Pet("Pet Rock","Active","Rock1","Rock2",0));
    widget2.show();


    return app.exec();
}