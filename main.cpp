#include "Pet.hpp"
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
    std::vector<Pet> pets;
    pets.push_back(Pet("Pet Rock","Active","Rock1","Rock2",0));
    pets.push_back(Pet("AvoCato","A cross between an avocado and a cat?!?!? the scientific comunity will be in shambles","AvoCato1","AvoCato2",0));
    pets.push_back(Pet("Catcus", "cacteye", "CATcus1", "CATcus2", 0));
    pets.push_back(Pet("The Great Catsbty", "So we pounce on, paws against the current, borne back ceaselessly into the past", "Catsby1", "Catsby2", 0));
    pets.push_back(Pet("CatBall","Ball","CatBall1","CatBall2",0));
    pets.push_back(Pet("CatBall","Ball","CatBall3","CatBall4",0));
    pets.push_back(Pet("CatBall","Ballin'","CatBall5","CatBall6",0));
    pets.push_back(Pet("CatBall","Baller","CatBall7","CatBall8",0));
    pets.push_back(Pet("CatBall","Balloon","CatBall9","CatBall10",0));
    pets.push_back(Pet("CatBall","o","CatBall11","CatBall12",0));
    pets.push_back(Pet("Cats Mol","it be small","Catsmol1","CatSmol2",0));
    pets.push_back(Pet("Cats Moll","it be small","CatSmol3","CatSmol4",0));
    pets.push_back(Pet("Cats Molll","it be small","CatSmol5","CatSmol6",0));
    pets.push_back(Pet("Cats MoIV","it be small","CatSmol7","CatSmol8",0));

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
