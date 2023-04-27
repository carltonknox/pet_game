#include "MainScreen.hpp"
#include "Pet.hpp"
#include "PetsWidget.hpp"
#include <unistd.h>
#include <QGridLayout>
#include <QMainWindow>
#include <QScrollArea>
#include "PetsListWidget.hpp"
#include "PetGridWidget.hpp"
#include "Crack.hpp"
#include "Purchase.hpp"
#include "Menu.hpp"
#include <QStackedWidget>
#include <QDebug>

// Create main window
MainScreen *p;

void signalHandler(int sig)
{
    p->writeInventoryToFile(sig);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainScreen mainWindow;
    p = &mainWindow;

    signal(SIGTERM, signalHandler);
    signal(SIGINT, signalHandler);

    mainWindow.setFixedSize(480, 272);
    mainWindow.setStyleSheet("border:none;");
    mainWindow.setContentsMargins(0, 0, 0, 0);
    // Show main window
    mainWindow.show();

    // Start event loop
    return app.exec();
}
