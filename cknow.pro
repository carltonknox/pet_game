QT += widgets

SOURCES = main.cpp MainScreen.cpp PetScreen.cpp PetGridWidget.cpp PetsListWidget.cpp PetsWidget.cpp Pet.cpp Crack.cpp Purchase.cpp Menu.cpp

# install
target.path = .
INSTALLS += target

HEADERS += \
    MainScreen.hpp \
    Pet.hpp \
    PetScreen.hpp \
    PetGridWidget.hpp \
    PetsListWidget.hpp \
    PetsWidget.hpp \
    Crack.hpp \
    Purchase.hpp \
    Menu.hpp

RESOURCES += \
    sprites.qrc