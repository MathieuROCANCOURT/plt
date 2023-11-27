#include "City.h"

using namespace std;
using namespace state;


City::City(int position, bool isProperty, bool isCard, bool money, bool chance, bool goToJail, std::string name,
           int valuePurchase, int *rent, Color color) : Property(position, isProperty, isCard, money, chance, goToJail, name, valuePurchase),
           nbApart(0), hostel(0), color(color), monopoly(false){
    for(int i = 0; i < 6; i++){
        this->rent[i] = rent[i];
    }

}
