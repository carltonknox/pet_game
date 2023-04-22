QT += widgets

SOURCES = main.cpp Pet.cpp PetsListWidget.cpp PetGridWidget.cpp PetsWidget.cpp Crack.cpp Purchase.cpp Menu.cpp

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
    PetsWidget.hpp \
    Crack.hpp Purchase.hpp Menu.hpp