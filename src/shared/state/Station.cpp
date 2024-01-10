#include "Station.h"
#include <typeinfo>


using namespace std;
using namespace state;


Station::Station(int position, std::string name, long long valuePurchase, long long *rent) : Property(position, name, valuePurchase),
                 nbStationPossessed(0){
                     for(int i = 0; i < 4; i++){
                         this->rent[i] = rent[i];
                     }

}

long long Station::getRent() {
    switch (nbStationPossessed) {
        case 1:
            return rent[0];
        case 2:
            return rent[1];
        case 3:
            return rent[2];
        case 4:
            return rent[3];
    }
    return 0;
}

void Station::modifyNbPossessed(Player player){

    int nbStation=0;
    for( auto &property : player.getPlayerProperties()){
        if(typeid(property)==typeid(Station)){
            nbStation++;
        }
    }
    this->nbStationPossessed = nbStation;
}

void Station::resetPossessions() {
    this->nbStationPossessed = 0;
}
