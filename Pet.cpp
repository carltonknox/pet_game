#include "Pet.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

//---Pet---
Pet::Pet(const std::string& name, const std::string& description,
        const std::string& sprite1, const std::string& sprite2,
        int rarity)
        : name(name), description(description), rarity(rarity), sprite_state(0){

    std::string s1 = ":sprites/"+sprite1+".png";
    std::string s2 = ":sprites/"+sprite2+".png";


    this->sprite1 = QPixmap(QString::fromStdString(s1)).scaled(QSize(100, 100));
    this->sprite2 = QPixmap(QString::fromStdString(s2)).scaled(QSize(100, 100));


    if(this->sprite1.isNull() || this->sprite2.isNull() || !(this->sprite1.size().width()>0&&this->sprite2.size().width()>0))
        throw std::runtime_error("Failed to load images: " + sprite1 +" "+ sprite2);
        
    assert(rarity <100);

    x=0;
    y=0;
    vx=rand()%8-4;
    vy=rand()%8-4;

    visibleRect = QRegion(getSprite().createMaskFromColor(QColor(0,0,0),Qt::MaskOutColor)).boundingRect();
    // visibleRegion = QRegion(boundingRect);
}
Pet::Pet()
        :name("Pet Rock"), description("Energetic"), rarity(0) {
    this->sprite1 = QPixmap(":sprites/Rock1.png").scaled(QSize(100, 100));
    this->sprite2 = QPixmap(":sprites/Rock2.png").scaled(QSize(100, 100));
    assert(this->sprite1.size().width()>0);

    x=0;
    y=0;
    vx=rand()%8-4;
    vy=rand()%8-4;

    visibleRect = QRegion(getSprite().createMaskFromColor(QColor(0,0,0),Qt::MaskOutColor)).boundingRect();
    // visibleRegion = QRegion(boundingRect);
}
void Pet::updateSprite()
{
    sprite_state = !sprite_state;
}

std::vector<Pet> generatePets(){
    std::vector<Pet> pets;
    pets.push_back(Pet("Pet Rock","Active","Rock1","Rock2",0));
    pets.push_back(Pet("AvoCato","A cross between an avocado and a cat?!?!? the scientific comunity will be in shambles","AvoCato1","AvoCato2",0));
    pets.push_back(Pet("Catcus", "cacteye", "CATcus1", "CATcus2", 0));
    pets.push_back(Pet("The Great Catsbty", "So we pounce on, paws against the current, borne back ceaselessly into the past", "Catsby1", "Catsby2", 0));
    pets.push_back(Pet("CatBall","Ball","CatBall1","CatBall2",0));
    pets.push_back(Pet("CatBall","Ball","CatBall3","CatBall4",0));
    pets.push_back(Pet("CatBall","Ballin'","CatBall5","CatBall6",0));
    pets.push_back(Pet("CatBall","Baller","CatBall7","CatBall8",0));
    pets.push_back(Pet("CatBall","Balloon","CatBall9","CatBall10",0));
    pets.push_back(Pet("CatBall","o","CatBall11","CatBall12",0));
    pets.push_back(Pet("Cats Mol","it be small","Catsmol1","CatSmol2",0));
    pets.push_back(Pet("Cats Moll","it be small","CatSmol3","CatSmol4",0));
    pets.push_back(Pet("Cats Molll","it be small","CatSmol5","CatSmol6",0));
    pets.push_back(Pet("Cats MoIV","it be small","CatSmol7","CatSmol8",0));
    return pets;
}
