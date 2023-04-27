// Include necessary headers
#include "MainScreen.hpp"

MainScreen::MainScreen(QWidget *parent)
    : QWidget(parent)
{
    pets = generatePets();
    user_list = {};
    inventory = new Inventory(this, 5, 7, user_list);

    // check if it's the first time program started
    loadInventoryFromFile(inventory);

    // std::cout << "current egg count: " << inventory->getEggCount() << std::endl;
    // std::cout << "current coin count: " << inventory->getCoinCount() << std::endl;
    // std::cout << "current user list size: " << inventory->user_list.size() << std::endl;

    // Create stacked widget to hold all screens
    stackedWidget = new QStackedWidget(this);
    stackedWidget->setStyleSheet("QStackedWidget { border: none; }");

    // Create screens and add them to the stacked widget
    menu = new Menu(this, stackedWidget, inventory);
    screen1 = new Purchase(this, stackedWidget, inventory);
    screen2 = new Crack(this, stackedWidget, inventory);
    screen3 = new PetScreen(this, stackedWidget, inventory);

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
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);

    // create a timer to update the pet sprites
    QTimer *sprite_timer = new QTimer(this);
    connect(sprite_timer, &QTimer::timeout, [=]
    {
        inventory->mutex.lockForRead();
        for (auto& pet : inventory->user_list) 
        {
            pet.updateSprite();
        }
        inventory->mutex.unlock();
        // std::cout << "timer connect" << std::endl;
    });
    sprite_timer->start(500);

    stackedWidget->show();

    // Create a signal handler for when the program is about to quit
    connect(qApp, &QCoreApplication::aboutToQuit, [=]()
            { writeInventoryToFile(inventory); });
}

void MainScreen::writeInventoryToFile(Inventory *inventory)
{
    // Open the file for writing
    std::ofstream file("inventory.txt");

    // Write the egg count, coin count, and vector of pets to the file
    file << inventory->user_list.size() << std::endl;
    file << inventory->getEggCount() << std::endl;
    file << inventory->getCoinCount() << std::endl;
    for (auto &pet : inventory->user_list)
    {
        file << pet.getId() << std::endl;
    }

    // Close the file
    file.close();
}

void MainScreen::loadInventoryFromFile(Inventory *inventory)
{
    std::ifstream file("inventory.txt");
    if (file.is_open())
    {
        int pet_count, egg_count, coin_count, pet_id;
        file >> pet_count >> egg_count >> coin_count;
        for (int i = 0; i < pet_count; i++)
        {
            file >> pet_id;
            inventory->user_list.push_back(pets[pet_id]);
        }
        inventory->setEggCount(egg_count);
        inventory->setCoinCount(coin_count);
        file.close();
    }
}
