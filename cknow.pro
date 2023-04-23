QT += widgets

SOURCES = main.cpp \
    Pet.cpp \
    PetsListWidget.cpp PetGridWidget.cpp PetsWidget.cpp \
    MainScreen.cpp Crack.cpp Purchase.cpp PetScreen.cpp Menu.cpp

# install
target.path = .
INSTALLS += target

HEADERS += \
    MainScreen.hpp \
    Pet.hpp \
    PetScreen.hpp \
    Pet.hpp \
    PetGridWidget.hpp \
    PetsListWidget.hpp \
    PetGridWidget.hpp \
    PetsListWidget.hpp \
    PetsWidget.hpp \
    Crack.hpp Purchase.hpp Menu.hpp

RESOURCES += \
    sprites.qrc