#include "Station.h"

using namespace std;
using namespace state;


Station::Station(int position, bool isProperty, bool isCard, bool money, bool chance, bool goToJail, std::string name,
                 int valuePurchase, int *rent) : Property(position, isProperty, isCard, money, chance, goToJail, name, valuePurchase),
                 nbStationPossessed(0){
                     for(int i = 0; i < 4; i++){
                         this->rent[i] = rent[i];
                     }

}
