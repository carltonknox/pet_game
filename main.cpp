#include "Pet.hpp"
#include <unistd.h>
#include <vector>
#include <QGridLayout>
#include <QMainWindow>

int main(int argc, char *argv[])
{

    // Set the random seed based on the current time
    srand(time(NULL));

    QApplication app(argc, argv);

    // Declare a vector of pets
    std::vector<Pet> pets;
    pets.push_back(Pet("AvoCato", "A cross between an avocado and a cat?!?!? the scientific community will be in shambles", "AvoCato1", "AvoCato2", 0));
    pets.push_back(Pet("Pet Rock", "Active", "Rock1", "Rock2", 0));
    pets.push_back(Pet("Catcus", "cacteye", "CATcus1", "CATcus2", 0));
    pets.push_back(Pet("the great catsbty", "the great", "Catsby1", "Catsby2", 0));

    // Create a container widget to hold the pet widgets
    QWidget *containerWidget = new QWidget();
//    containerWidget->setStyleSheet("background-color: #ADD8E6;"); // light blue


    // Create a grid layout to arrange the pet widgets
    QGridLayout *layout = new QGridLayout(containerWidget);
    layout->setSpacing(0);

    // Create the first pet widget
    std::vector<PetWidget*> petWidgets;

    for (int i = 0; i < pets.size(); i++) {
        PetWidget *petWidget = new PetWidget(containerWidget, pets[i]);
        petWidgets.push_back(petWidget);

    }

    // Remove any existing layout from the container widget
//    containerWidget->setLayout(nullptr);

    // Add the widgets to the container widget
//    petWidget1->setParent(containerWidget);
//    petWidget2->setParent(containerWidget);

    // Set the size of the container widget and show it
//    containerWidget->setFixedSize(1000, 500);
    containerWidget->setMinimumSize(480, 272);
//    containerWidget->setStyleSheet("background-color: #f0f0f0;");
    containerWidget->show();

    return app.exec();
}
