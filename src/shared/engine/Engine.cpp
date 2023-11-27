//
// Created by alexis on 27/11/23.
//
#include <random>
#include "Engine.h"
#include "state/State.h"

using namespace std;
using namespace state;

void engine::Engine::rollDices() {
    int dice1,dice2;
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1,6);
    dice1=distribution(generator);
    dice2=distribution(generator);
    if (dice1==dice2){
        this->state.modifyNbDouble(1);
    }
//    if (this->state.getNBdouble>=3){//getNBdouble
        this->state
//waiting for getCurrentPlayer        moveInJail(state::)
    }

}

void engine::Engine::moveInJail(Player player){
    //this->state.moveToken(player,11);//est déplacé à la case 11 prison
    //this->state.gameStatus(player,PLAYINGJAIL);//est considérer comme en prison
}
