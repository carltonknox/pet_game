#include "Pet.hpp"
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // Create the widget
    PetWidget widget(nullptr,Pet("Pet Rock","Active","Rock1","Rock2",0));
    widget.show();

    // Create a timer to move the image every 20 milliseconds
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, &widget, &PetWidget::bounceImage);
    timer.start(20);

    return app.exec();
}