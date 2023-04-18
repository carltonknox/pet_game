#include "Pet.hpp"
int main(int argc, char* argv[]) {

// Set the random seed based on the current time
    srand(time(NULL));

    QApplication app(argc, argv);

    PetWidget widget1(nullptr,Pet("AvoCato","food?","AvoCato1","AvoCato2",0));
    widget1.show();


    // Create the widget
    PetWidget widget2(nullptr,Pet("Pet Rock","Active","Rock1","Rock2",0));
    widget2.show();


    return app.exec();
}