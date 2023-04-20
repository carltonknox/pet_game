QT += widgets

SOURCES = main.cpp Pet.cpp PetsListWidget.cpp PetGridWidget.cpp PetsWidget.cpp

# install
target.path = .
INSTALLS += target

RESOURCES += \
    sprites.qrc

HEADERS += \
    Pet.hpp \
    PetGridWidget.hpp \
    PetsListWidget.hpp \
    PetGridWidget.hpp \
    PetsListWidget.hpp \
    PetsWidget.hpp