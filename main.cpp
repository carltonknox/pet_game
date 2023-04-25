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

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    // Create main window
    MainScreen mainWindow;

    mainWindow.setFixedSize(480, 272);
    // SuperBackgroundPainter blah(":sprites/_background.png");
    // mainWindow.setStyleSheet("background-image: url(:sprites/_background.png);");
    // mainWindow.installEventFiler(blah);
    mainWindow.setStyleSheet("border:none;");
    mainWindow.setContentsMargins(0,0,0,0);
    // Show main window
    mainWindow.show();

    // Start event loop
    return app.exec();
}
