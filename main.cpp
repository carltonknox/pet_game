#include "Pet.hpp"
#include "PetsWidget.hpp"
#include <unistd.h>
#include <QGridLayout>
#include <QMainWindow>
#include <QScrollArea>
#include "PetsListWidget.hpp"
#include "PetGridWidget.hpp"

int main(int argc, char* argv[]) {

// Set the random seed based on the current time
    srand(time(NULL));

    QApplication app(argc, argv);

    // Create a container widget to hold the pet widgets
    QWidget* containerWidget = new QWidget();
    containerWidget->setContentsMargins(0, 0, 0, 0);
//    containerWidget->setStyleSheet("background-image: url(:sprites/_background.png); background-size: cover;");

    containerWidget->setFixedSize(480, 272);
    // Create a grid layout to arrange the pet widgets
     QGridLayout* layout = new QGridLayout(containerWidget);
     layout->setSpacing(0);
     layout->setContentsMargins(0, 0, 0, 0);

    // Create the widget
    std::vector<Pet> pets = generatePets();

    //Overall Widget to display:

    // Create Pet Bouncing Widget
//    PetsWidget barn(containerWidget,pets);
//    barn.setStyleSheet("background-image: url(:sprites/_background.png); background-size: cover;");
//    layout->addWidget(&barn);

    // Create Pet List Widget
//    PetsListWidget collection(containerWidget,pets);
//    layout->addWidget(&collection);


    // Create the pet grid widget
    PetGridWidget* petGrid = new PetGridWidget( containerWidget, pets);
    layout->addWidget(petGrid);

    QMainWindow mainWindow;
    mainWindow.setCentralWidget(containerWidget);
    mainWindow.show();

    return app.exec();
}
