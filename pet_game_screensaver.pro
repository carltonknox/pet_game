QT += widgets

SOURCES = main_saver.cpp Pet.cpp PetsWidget.cpp

# install
target.path = .
INSTALLS += target

RESOURCES += \
    sprites.qrc

HEADERS += \
    Pet.hpp \
    PetsWidget.hpp