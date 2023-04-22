#include "MainScreen.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Create main window
    MainScreen mainWindow;

    mainWindow.setFixedSize(480, 272);
    mainWindow.setContentsMargins(0,0,0,0);
    // Show main window
    mainWindow.show();

    // Start event loop
    return app.exec();
}
