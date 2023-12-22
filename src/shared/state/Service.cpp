#include "Service.h"
#include <typeinfo>

using namespace std;
using namespace state;


Service::Service(int position, std::string name, long long valuePurchase) : Property(position, name, valuePurchase),
                 nbServicePossessed(0){ }

long long Service::getRent() {

    int score = dices.getScore();
    if(nbServicePossessed == 1){
        return 4*score;
    }
    if(nbServicePossessed==2){
        return 10*score;
    }
    return -1;
}

void Service::modifyNbPossessed(Player player){
    int nbService=0;
    for( auto &property : player.getPlayerProperties()){
        if(typeid(property)==typeid(Service)){
            nbService++;
        }
    }
    this->nbServicePossessed = nbService;
}