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
    containerWidget->setContentsMargins(0, 0, 0, 0);
    //containerWidget->setMinimumSize(480, 272);
    // Create a grid layout to arrange the pet widgets
    QGridLayout* layout = new QGridLayout(containerWidget);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);


    // Create the widget
    std::vector<Pet> pets;
    pets.push_back(Pet("Pet Rock","Active","Rock1","Rock2",0));
    pets.push_back(Pet("AvoCato","A cross between an avocado and a cat?!?!? the scientific comunity will be in shambles","AvoCato1","AvoCato2",0));
    pets.push_back(Pet("Catcus", "cacteye", "CATcus1", "CATcus2", 0));
    pets.push_back(Pet("the great catsbty", "the great", "Catsby1", "Catsby2", 0));

    PetsWidget barn(containerWidget,pets);
    layout->addWidget(&barn);

    QMainWindow mainWindow;
    mainWindow.setCentralWidget(containerWidget);
    mainWindow.show();

    return app.exec();
}
