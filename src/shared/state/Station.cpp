#include "Station.h"

using namespace std;
using namespace state;


Station::Station(int position, std::string name, long long valuePurchase, long long *rent) : Property(position, name, valuePurchase),
                 nbStationPossessed(0){
                     for(int i = 0; i < 4; i++){
                         this->rent[i] = rent[i];
                     }

}

long long Station::getRent() {

    if(nbStationPossessed==1){
        return rent[0];
    }
    if(nbStationPossessed==2){
        return rent[1];
    }
    if(nbStationPossessed==3){
        return rent[2];
    }
    if(nbStationPossessed==4){
        return rent[3];
    }
}
