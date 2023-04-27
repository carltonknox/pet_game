#include "Pet.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

//---Pet---
Pet::Pet(int id, const std::string &name, const std::string &description,
         const std::string &sprite1, const std::string &sprite2,
         int rarity)
    : id(id), name(name), description(description), rarity(rarity), sprite_state(0)
{

    std::string s1 = ":sprites/" + sprite1 + ".png";
    std::string s2 = ":sprites/" + sprite2 + ".png";

    this->sprite1 = QPixmap(QString::fromStdString(s1)).scaled(QSize(100, 100));
    this->sprite2 = QPixmap(QString::fromStdString(s2)).scaled(QSize(100, 100));

    if (this->sprite1.isNull() || this->sprite2.isNull() || !(this->sprite1.size().width() > 0 && this->sprite2.size().width() > 0))
        throw std::runtime_error("Failed to load images: " + sprite1 + " " + sprite2);

    assert(rarity <= 10);

    x = 0;
    y = 0;
    vx = rand() % 8 - 4;
    vy = rand() % 8 - 4;

    visibleRect = QRegion(getSprite().createMaskFromColor(QColor(0, 0, 0), Qt::MaskOutColor)).boundingRect();
    // visibleRegion = QRegion(boundingRect);
}
Pet::Pet()
    : id(3), name("Pet Rock"), description("Energetic"), rarity(10)
{
    this->sprite1 = QPixmap(":sprites/Rock1.png").scaled(QSize(100, 100));
    this->sprite2 = QPixmap(":sprites/Rock2.png").scaled(QSize(100, 100));
    assert(this->sprite1.size().width() > 0);

    x = 0;
    y = 0;
    vx = rand() % 8 - 4;
    vy = rand() % 8 - 4;

    visibleRect = QRegion(getSprite().createMaskFromColor(QColor(0, 0, 0), Qt::MaskOutColor)).boundingRect();
    // visibleRegion = QRegion(boundingRect);
}
void Pet::updateSprite()
{
    sprite_state = !sprite_state;
}

std::vector<Pet> generatePets()
{
    std::vector<Pet> pets;
    pets.push_back(Pet(0, "AristoCat", "A member of the aristoCATcy", "AristoCat1", "AristoCat2", 9));
    pets.push_back(Pet(1, "AvoCato", "A cross between an avocado and a cat?!?!? the scientific comunity will be in shambles", "AvoCato1", "AvoCato2", 7));
    pets.push_back(Pet(2, "Busniss Cat", "Money Power Treats", "BusinessCat1", "BusinessCat1", 6));
    pets.push_back(Pet(3, "Pet Rock", "Active", "Rock1", "Rock2", 10));
    pets.push_back(Pet(4, "Catcus", "cacteye", "CATcus1", "CATcus2", 8));
    pets.push_back(Pet(5, "CatGPT", "As an meow meow AI, I cannot form emotional attachment to stoopid hooman. Meow~", "CatGpt", "CatGpt", 7));
    pets.push_back(Pet(6, "The Great Catsbty", "So we pounce on, paws against the current, borne back ceaselessly into the past", "Catsby1", "Catsby2", 5));
    pets.push_back(Pet(7, "CatBall", "Ball", "CatBall1", "CatBall2", 0));
    pets.push_back(Pet(8, "CatBall", "Ball", "CatBall3", "CatBall4", 0));
    pets.push_back(Pet(9, "CatBall", "Ballin'", "CatBall5", "CatBall6", 2));
    pets.push_back(Pet(10, "CatBall", "Baller", "CatBall7", "CatBall8", 0));
    pets.push_back(Pet(11, "CatBall", "Balloon", "CatBall9", "CatBall10", 1));
    pets.push_back(Pet(12, "CatBall", "o", "CatBall11", "CatBall12", 3));
    pets.push_back(Pet(13, "Cat sMol", "it be small", "Catsmol1", "CatSmol2", 0));
    pets.push_back(Pet(14, "Cat sMoll", "it be small", "CatSmol3", "CatSmol4", 0));
    pets.push_back(Pet(15, "Cat sMolll", "it be small", "CatSmol5", "CatSmol6", 1));
    pets.push_back(Pet(16, "Cat sMoIV", "it be small", "CatSmol7", "CatSmol8", 1));
    pets.push_back(Pet(17, "Cat sMoV", "it be small", "CatSmol9", "CatSmol8", 2));
    pets.push_back(Pet(18, "Cat sMoVI", "it be small", "CatSmol11", "CatSmol12", 0));
    pets.push_back(Pet(19, "Cat sMoIV", "it be small", "CatSmol13", "CatSmol14", 3));
    pets.push_back(Pet(20, "Cat sMoIV", "it be small", "CatSmol15", "CatSmol16", 2));
    pets.push_back(Pet(21, "Cat sMoIV", "it be small", "CatSmol17", "CatSmol18", 1));
    pets.push_back(Pet(22, "Cat sMoIV", "it be small", "CatSmol19", "CatSmol20", 0));
    pets.push_back(Pet(23, "Curdo", "It's a Curby! but is it...?", "Curdo1", "Curdo2", 5));
    pets.push_back(Pet(24, "DiscoCat", "Y~~M~~C!A!~~~", "DiscoCat1", "DiscoCat2", 5));
    pets.push_back(Pet(25, "FishCat", "Woo is it something rare?! Nvm, it's just Catfish...", "FishCat1", "FishCat2", 4));
    pets.push_back(Pet(26, "FishCat", "An abomination", "FishCat3", "FishCat4", 5));
    pets.push_back(Pet(27, "FishCat", "There are many fish in the sea, but this is not one of them", "FishCat5", "FishCat6", 5));
    pets.push_back(Pet(28, "FishCat", "Fish go meow!", "FishCat7", "FishCat8", 5));
    pets.push_back(Pet(29, "FishCat", "Woo is it something rare?! Nvm, it's just catfish...", "FishCat9", "FishCat10", 4));
    pets.push_back(Pet(30, "Jiji", "I'm going to put my paws together and pray that you're not serious", "Jiji1", "Jiji2", 7));
    pets.push_back(Pet(31, "Mona LiCat", "The Mona LiCat is a half-length portrait painting by Italian artist LeoMeowdo da Catci", "MonaLicat", "MonaLicat", 9));
    pets.push_back(Pet(32, "Paper Baggie", "Biodegradable.", "PaperBag", "PaperBag", 8));
    pets.push_back(Pet(33, "PopCat", "We are all insects. Groping towards something terrible or divine. -- Pop Cat", "PopCat1", "PopCat2", 8));

    return pets;
}