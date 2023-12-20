//
// Created by alexis on 15/12/23.
//

#include "RollDicesCommand.h"
#include <random>


void engine::RollDicesCommand::payTheBank(state::State &state, long long int valueMoney) {
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

    /*Identification de la situation du joueur*/

    state::Player* playerCurrent = state.getCurrentPlayer();

    if(playerCurrent->getGameStatus() == state::PLAYINGFREE){
        if(state.getNbDouble() == 3){
            moveInJail(state);
        }
        else{
            int score = state.getScoreDices();
            int position = playerCurrent->getPosition();
            int futurPosition = (position+score)%40 +1;
            moveToken(state, position, futurPosition, true);
        }
    }else{
        if(state.getIsDouble()){
            freeByDices(state);
        }
        else if(playerCurrent->getNbTurnInJail() == 3){
            freeMandatory(state);
        }
    }
}

void engine::RollDicesCommand::execute(state::State &state) {
    rollDices(state);
}

void engine::RollDicesCommand::moveToken(state::State &state, int currentPosition, int futurPosition, bool startBoxTested) {

    if(startBoxTested){
        startBox(state, currentPosition, futurPosition);
    }

    if(futurPosition< 41 and futurPosition > 0){
        state::Player* playerCurrent = state.getCurrentPlayer();
        state.modifyPosition(*playerCurrent, futurPosition);

        std::map<int, state::Box> board = state.getBoard();
        state::Box* currentBox = &(board[futurPosition]);

        boxEffect(state, *currentBox);
    }

}

void engine::RollDicesCommand::startBox(state::State &state, int previousPosition, int newPosition) {

    if(newPosition < previousPosition){
        state::Player* playerCurrent = state.getCurrentPlayer();
        state.modifyMoney(*playerCurrent, 2000000);
    }
}

void engine::RollDicesCommand::boxEffect(state::State &state, state::Box box) {

    state::Player* playerCurrent = state.getCurrentPlayer();

    if(box.getIsProperty()){
        propertyBox(state, playerCurrent->getPosition());
        return;
    }else if(box.getIsCard()){
        if(box.getChance()){
            luckBox(state);
            return;
        }else{
            communityBox(state);
            return;
        }
    }else if(box.getMoney()){
        if(playerCurrent->getPosition()==5){
            state.modifyMoney(*playerCurrent, -2000000);
            return;
        }else if(playerCurrent->getPosition()==39){
            state.modifyMoney(*playerCurrent, -1000000);
            return;
        }
    }else if(box.getGoToJail()){
        moveInJail(state);
        return;
    }

}

void engine::RollDicesCommand::luckBox(state::State &state) {
    state::Card* luckCard = state.drawCardLuck();
    cardEffect(state, *luckCard);
}

void engine::RollDicesCommand::communityBox(state::State &state) {
    state::Card* communityCard = state.drawCardCommunity();
    cardEffect(state, *communityCard);
}

void engine::RollDicesCommand::cardEffect(state::State &state, state::Card card) {

    state::Player* playerCurrent = state.getCurrentPlayer();

    if(card.getFreeJail()){
        state.modifyNbFreeJailCard(*playerCurrent, true);
        return;
    }else if(card.getMoney()){
        if(card.getFctHostel()){
            cardFctHostels(state, card);
            return;
        }else if(card.getFromOthers()){
            cardBirthday(state, card);
            return;
        }else{
            cardWinLostMoney(state, card);
            return;
        }
    }else if(card.getMoveForward()){
        std::vector<int> arguments = card.getArgs();
        moveToken(state, playerCurrent->getPosition(), arguments[0], true);
        return;
    }else if(card.getJail()){
        moveInJail(state);
        return;
    }else{
        std::vector<int> arguments = card.getArgs();
        if(arguments[0] < 0){
            moveToken(state, playerCurrent->getPosition(), playerCurrent->getPosition() - arguments[0], false);
            return;
        }else{
            moveToken(state, playerCurrent->getPosition(), arguments[0], false);
            return;
        }

    }

}

void engine::RollDicesCommand::moveInJail(state::State &state) {

    state::Player* playerCurrent = state.getCurrentPlayer();
    moveToken(state, playerCurrent->getPosition(), 11, false);
    state.gameStatus(*playerCurrent, state::PLAYINGJAIL);

}

void engine::RollDicesCommand::freeMandatory(state::State &state) {

    state::Player* playerCurrent = state.getCurrentPlayer();
    payTheBank(state, 500000);
    state.gameStatus(*playerCurrent, state::PLAYINGFREE);
    state.modifyNbTurnInJail(false);

    int score = state.getScoreDices();
    int futurPosition = (11+score)%40 +1;

    moveToken(state, 11, futurPosition , true);

}

void engine::RollDicesCommand::freeByDices(state::State &state) {

    state::Player* playerCurrent = state.getCurrentPlayer();

    state.gameStatus(*playerCurrent, state::PLAYINGFREE);
    state.modifyNbTurnInJail(false);

    int score = state.getScoreDices();
    int futurPosition = (11+score)%40 +1;

    moveToken(state, 11, futurPosition , true);


}

void engine::RollDicesCommand::cardWinLostMoney(state::State &state, state::Card card) {

    state::Player* playerCurrent = state.getCurrentPlayer();
    std::vector<int> arguments = card.getArgs();

    if(arguments[0] < 0){ //Lost Money
        payTheBank(state, arguments[0]);
    }
    else{ //Win Money
        state.modifyMoney(*playerCurrent, arguments[0]);
    }

}

void engine::RollDicesCommand::cardBirthday(state::State &state, state::Card card) {

    state::Player* playerCurrent = state.getCurrentPlayer();
    std::vector<state::Player> listPlayers = state.getListPlayer();
    int nbPlayers = state.getNbPlayer();
    std::vector<int> arguments = card.getArgs();

    for(int i = 0; i < nbPlayers; i++){
        if(listPlayers[i] != *playerCurrent){
            if(listPlayers[i].getGameStatus() != state::LOST){
                payOtherPlayer(state, listPlayers[i], *playerCurrent, arguments[0]);
            }
        }
    }


}










