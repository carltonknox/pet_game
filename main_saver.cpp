#include "Pet.hpp"
#include <unistd.h>
#include <QApplication>
#include <QScreen>
#include <QGridLayout>
#include <QMainWindow>
#include "PetsWidget.hpp"
int main(int argc, char* argv[]) {

// Set the random seed based on the current time
    srand(time(NULL));

    QApplication app(argc, argv);

    // Create a container widget to hold the pet widgets
    QWidget* containerWidget = new QWidget();
    containerWidget->setContentsMargins(0, 0, 0, 0);
    containerWidget->setStyleSheet("background-image: url(:sprites/_background.png);");

    //containerWidget->setMinimumSize(480, 272);
    // Create a grid layout to arrange the pet widgets
    QGridLayout* layout = new QGridLayout(containerWidget);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);


    // Create the widget
    std::vector<Pet> pets=generatePets();

    PetsWidget barn(containerWidget,pets);
    layout->addWidget(&barn);

    QMainWindow mainWindow;
    mainWindow.setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    mainWindow.setWindowState(Qt::WindowFullScreen);
    mainWindow.setCentralWidget(containerWidget);
    mainWindow.show();
    // Get the available geometry of the primary screen
    QScreen* screen = QGuiApplication::primaryScreen();
    QRect availableGeometry = screen->availableGeometry();
    mainWindow.setGeometry(availableGeometry);

    return app.exec();
}
