// Include necessary headers
#include "MainScreen.hpp"

MainScreen::MainScreen(QWidget *parent)
    : QWidget(parent)
{
    std::vector<Pet> pets = generatePets();
    std::vector<Pet> user_list={};
    std::cout << "size in main: " << user_list.size() << std::endl;
    // Create stacked widget to hold all screens
    stackedWidget = new QStackedWidget(this);

    inventory = new Inventory(this, 10, 100);

    // Create screens and add them to the stacked widget
    menu = new Menu(this, stackedWidget, pets);
    screen1 = new Purchase(this, stackedWidget, inventory);
    screen2 = new Crack(this, stackedWidget, inventory, user_list);
    screen3 = new PetScreen(this, stackedWidget, user_list);

    // connect(screen1, &Purchase::returnToMain, this, &MainScreen::showScreen1);
    // connect(screen2, &Crack::returnToMain, this, &MainScreen::showScreen2);
    // connect(screen3, &Pet::returnToMain, this, &MainScreen::showScreen3);
    stackedWidget->addWidget(menu);
    stackedWidget->addWidget(screen1);
    stackedWidget->addWidget(screen2);
    stackedWidget->addWidget(screen3);
    stackedWidget->setCurrentIndex(0);

    // Set up layout for main window
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(stackedWidget);
    setLayout(layout);

    stackedWidget->show();
}

// void MainScreen::showMain()
// {
//     stackedWidget->setCurrentIndex(0);
// }
