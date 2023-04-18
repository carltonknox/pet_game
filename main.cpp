#include "Pet.hpp"
#include <unistd.h>
#include <QGridLayout>
#include <QMainWindow>
int main(int argc, char* argv[]) {

// Set the random seed based on the current time
    srand(time(NULL));

    QApplication app(argc, argv);

    // Create a container widget to hold the pet widgets
    QWidget* containerWidget = new QWidget();
//    containerWidget->show();
    // Create a grid layout to arrange the pet widgets
    QGridLayout* layout = new QGridLayout(containerWidget);
    layout->setSpacing(0);

    // Create the widget
    PetWidget widget1(containerWidget,Pet("AvoCato","A cross between an avocado and a cat?!?!? the scientific comunity will be in shambles","AvoCato1","AvoCato2",0));
    layout->addWidget(&widget1);

    PetWidget widget2(containerWidget,Pet("Pet Rock","Active","Rock1","Rock2",0));
    layout->addWidget(&widget2);

    QMainWindow mainWindow;
    mainWindow.setCentralWidget(containerWidget);
    mainWindow.show();

    return app.exec();
}
