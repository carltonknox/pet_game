#include "Crack.hpp"

Crack::Crack(QWidget* parent, QStackedWidget *stackedWidget, Inventory *inventory)
    : QWidget(parent), stackedWidget(stackedWidget), inventory(inventory)
{
    // generate random pet:
    int rand_rarity = generateNumber();
    std::vector<Pet> pet_list = generatePets();
    Pet random_pet = generateRandomPet(pet_list, rand_rarity);

    
    // Create buttons
    crackEgg = new QPushButton(QIcon(":sprites/Eggo.png"), "", this);

    // Set button size to match the size of the sprites
    QSize sizeButton(140, 130);
    QSize sizeIcon(920, 300);
    QString buttonStyleSheet = "QPushButton {"
                               "    background-color: transparent;"
                               "    border: none;"
                               "}";

    crackEgg->setIconSize(sizeIcon);
    crackEgg->setFixedSize(sizeButton);
    crackEgg->setStyleSheet(buttonStyleSheet);

    // Create egg and coin count labels
    QLabel *egg_count_label = new QLabel("", this);
    QLabel *coin_count_label = new QLabel("", this);

    // Update the label texts with the current egg and coin counts
    int egg_count = inventory->getEggCount();
    int coin_count = inventory->getCoinCount();
    egg_count_label->setText(QString("Egg: %1").arg(egg_count));
    coin_count_label->setText(QString("Coin: %1").arg(coin_count));

    // Create label for the text
    QLabel *label = new QLabel("Click to Crack~", this);
    label->setAlignment(Qt::AlignCenter);

    int loop = 0;
    // Connect the clicked signal of crackEgg to a lambda function that updates the egg and coin counts and label texts
    QObject::connect(crackEgg, &QPushButton::clicked, [=, &loop]()
    {
        loop++;

        if(loop == 1){
            if(inventory->removeEgg() == 0) {
                // Change the button sprite when the last egg is removed
                QPixmap newIcon(":sprites/EggCrack.png");
                crackEgg->setIcon(QIcon(newIcon));

                // Update the egg and coin counts
                int egg_count = inventory->getEggCount();
                int coin_count = inventory->getCoinCount();

                // Update the label texts
                egg_count_label->setText(QString("Egg: %1").arg(egg_count));
                coin_count_label->setText(QString("Coin: %1").arg(coin_count)); 
            } else {
                loop = 0;
            }
        } else if(loop == 2){
            // randomly generates a pet
            label->setText(QString("You got a cato~"));
        } else if(loop == 3){
            // go back to cracking an egg
            QPixmap newIcon(":sprites/Eggo.png");
            crackEgg->setIcon(QIcon(newIcon));
            label->setText(QString("Click to crack~"));
            loop = 0;
        }
    });
    

    // Create return button


    returnButton = new QPushButton(QIcon(":sprites/Ret.png"), "", this);
    // returnButton->move(10, 10);
    connect(returnButton, &QPushButton::clicked, this, &Crack::on_returnButton_clicked);
    returnButton->setStyleSheet(buttonStyleSheet);
    
    // Set button size to match the size of the sprites
    QSize ret_sizeButton(50, 50);
    QSize ret_sizeIcon(100, 80);
    
    returnButton->setIconSize(ret_sizeIcon);
    returnButton->setFixedSize(ret_sizeButton);
        

    // Create layout for crackEgg and center it
    QVBoxLayout *layout1 = new QVBoxLayout();
    layout1->addWidget(crackEgg);
    layout1->addWidget(label);
    layout1->setAlignment(Qt::AlignCenter);

    // Create layout for returnButton and align it to the top left corner
    QHBoxLayout *layout2 = new QHBoxLayout();
    layout2->addWidget(returnButton);
    layout2->addWidget(egg_count_label);
    layout2->addWidget(coin_count_label);
    layout2->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    // Create main layout and add the two layouts to it
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(layout2);
    mainLayout->addLayout(layout1);

    setLayout(mainLayout);
}

void Crack::returnToMain(){
    stackedWidget->setCurrentIndex(0);
}

void Crack::on_returnButton_clicked() {
    // Emit a signal to indicate that the return button was clicked
    emit returnToMain();
}

int Crack::generateNumber(){
    std::random_device rd;
    std::mt19937 gen(rd());

    // Set the probability of generating a 0 to 0.5
    std::geometric_distribution<int> dist(0.5);

    // Generate a number using the distribution
    int number = dist(gen);

    // Cap the number at 10 to ensure it is within the range 0-10
    number = std::min(number, 10);

    return number;
}

Pet Crack::generateRandomPet(std::vector<Pet> petlist, int rarity)
{
    std::vvector<Pet> rarity_pets;

    for(auto pet : pet_list)
    {
        if(pet.rarity = rarity_level){
            rarity_pets.push_back(pet);
        }
    }

    if(rarity_pets.empty()){
        std::cout << "not ennough rarities: fix pets list" << std::endl;
        return;
    }

    int random_index = rand() % rarity_pets.size();
    return rarity_pets[random_index];
}
