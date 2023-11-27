#include "Station.h"

using namespace std;
using namespace state;


Station::Station(int position, std::string name, int valuePurchase, int *rent) : Property(position, name, valuePurchase),
                 nbStationPossessed(0){
                     for(int i = 0; i < 4; i++){
                         this->rent[i] = rent[i];
                     }

}
