//
// Created by alexis on 15/12/23.
//

#include "RollDicesCommand.h"
#include <random>


int engine::RollDicesCommand::payTheBank(state::State &state, long long int valueMoney) {
    state::Player* playerCurrent = state.getCurrentPlayer();

    if((playerCurrent->getMoney() - valueMoney)<0){
        playerCurrent->setDebt(state::DEBT_BANK);
    }
    state.modifyMoney(*playerCurrent, -valueMoney);
}

void engine::RollDicesCommand::rollDices(state::State &state) {

    /* Génération de 2 chiffres aléatoires*/

    // Initialise le générateur de nombres aléatoires avec une graine
    std::random_device rd;
    std::mt19937 gen(rd());
    // Définit la plage de nombres aléatoires que vous voulez générer
    std::uniform_int_distribution<> dis(1, 6); // Pour des nombres entre 1 et 100

    // Génère 2 entiers aléatoire
    int randomNumber1 = dis(gen);
    int randomNumber2 = dis(gen);

    state.modifyDices(randomNumber1, randomNumber2);



}


