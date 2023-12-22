#include "City.h"

using namespace std;
using namespace state;


City::City(int position, std::string name, long long valuePurchase, long long *rent, Color color, long long priceApartHostel) : Property(position, name, valuePurchase),
           nbApart(0), hostel(0), color(color), monopoly(false), priceApartHostel(priceApartHostel){
    for(int i = 0; i < 6; i++){
        this->rent[i] = rent[i];
    }

}

long long City::getRent() {

    if(hostel){
        return rent[5];
    }
    switch(nbApart){
        case 1:
            return rent[1];
        case 2:
            return rent[2];
        case 3:
            return rent[3];
        case 4:
            return rent[4];
        case 0:
            if(monopoly){return rent[0]*2;}
            else{return rent[0];}
        default:
            return rent[0];
    }
}

Color City::getColor(){
    return this->color;
}

void City::modifyNbPossessed(Player player) {

    int nbCityOfTheColor;
    // Trouve le nombre de propriétés de la même couleur dans le jeu
    if(this->color == PINK or this->color == DARK_BLUE){
        nbCityOfTheColor = 2;
    }
    else{
        nbCityOfTheColor = 3;
    }
    // Trouve le nombre de propriétés de la même couleur que la propriété courante possédée par le joueur
    int nbCityOfTheColorPossessed = 0;

    for( auto &property : player.getPlayerProperties()){
        if ( City* city = dynamic_cast< City*>(&property)){
            if(this->color == city->getColor()){
                nbCityOfTheColorPossessed++;
            }
        }
    }
    //Si le nombre de carte de la même couleur possédées par le joueur est maximal, monopoly passe à true
    if(nbCityOfTheColorPossessed == nbCityOfTheColor){
        this->monopoly = true;
    }
}

int City::getNbApart() {
    return this->nbApart;
}

void City::setNbApart(int nbApart) {
    this->nbApart=nbApart;
}


