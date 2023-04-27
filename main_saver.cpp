#include "Pet.hpp"
#include <unistd.h>
#include <QApplication>
#include <QScreen>
#include <QGridLayout>
#include <QMainWindow>
#include "PetsWidget.hpp"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <iostream>
#include <fstream>
#include "Inventory.hpp"

void loadInventoryFromFile(Inventory *inventory);

int main(int argc, char *argv[])
{
    // write own pid into kernel module
    pid_t pid = getpid();
    std::cout << "my pid is " << pid << "\n";

    int fd = open("/dev/kscreensaverlauncher", O_WRONLY);
    if (fd < 0)
    {
        perror("kernel module not loaded to /dev/kscreensaverlauncher. exiting...");
        return -1;
    }
    if (write(fd, &pid, sizeof(pid_t)) != sizeof(pid_t))
    {
        perror("pid write failed");
        return -1;
    }
    close(fd);

    // Set the random seed based on the current time
    srand(time(NULL));

    QApplication app(argc, argv);

    // Create a container widget to hold the pet widgets
    QWidget *containerWidget = new QWidget();
    containerWidget->setContentsMargins(0, 0, 0, 0);
    // containerWidget->setStyleSheet("background-image: url(:sprites/_background.png);");

    // containerWidget->setMinimumSize(480, 272);
    //  Create a grid layout to arrange the pet widgets
    QGridLayout *layout = new QGridLayout(containerWidget);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);

    // Create the widget
    std::vector<Pet> pets = generatePets();

    std::vector<Pet> user_list = {};
    QObject* nothing = new QObject;
    Inventory *inventory = new Inventory(nothing, 10, 7, user_list);

    loadInventoryFromFile(inventory);

    PetsWidget barn(containerWidget, inventory);
    layout->addWidget(&barn);

    QMainWindow mainWindow;
    mainWindow.setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    mainWindow.setWindowState(Qt::WindowFullScreen);
    mainWindow.setCentralWidget(containerWidget);
    mainWindow.show();
    // Get the available geometry of the primary screen
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect availableGeometry = screen->availableGeometry();
    mainWindow.setGeometry(availableGeometry);

    return app.exec();
}

void loadInventoryFromFile(Inventory *inventory)
{
    std::ifstream file("inventory.txt");

    std::vector<Pet> pets = generatePets();

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