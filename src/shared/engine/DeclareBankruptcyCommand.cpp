//
// Created by ensea on 22/12/23.
//

#include "DeclareBankruptcyCommand.h"


void engine::DeclareBankruptcyCommand::changeTurn(state::State &state) {
    std::vector<state::Player> listPlayers = state.getListPlayer();
    int nbPlayers = state.getNbPlayer();
    state::Player* playerCurrent = state.getCurrentPlayer();


    //On récupère l'indice du joueur courant dans la liste des players
    int indice = 0;
    for(int i = 0; i < nbPlayers; i++ ){
        if(playerCurrent == &listPlayers[i]){
            indice = i;
            //On incrémente le nombre de tours en prison si le joueur dont le tour se termine est en prison
            if(playerCurrent->getGameStatus() == state::PLAYINGJAIL){
                state.modifyNbTurnInJail(1);
            }
            break;
        }
    }

    //On balaye la liste des players à partir du joueur suivant le joueur courant jusqu'à trouver un joueur actif
    for(int j = 0; j < nbPlayers ; j++){
        int indiceBis = (j + indice + 1)%nbPlayers;
        if(listPlayers[indiceBis].getGameStatus() == state::PLAYINGFREE or listPlayers[indiceBis].getGameStatus() == state::PLAYINGJAIL){
            state.modifyTurn((state::Playing) indiceBis);
            break;
        }
    }

    state.modifyNbDouble(0);

}

void engine::DeclareBankruptcyCommand::declareBankruptcy(state::State &state) {

    state::Bank theBank = state.getBank();

    /*Rendre les apparts du joueur à la banque */
    int nbTotalApartPlayer = this->playerInDebt.getNbTotalApart();
    int nbTotalApartBank = theBank.getNbApartBank();
    theBank.setNbApartBank(nbTotalApartBank + nbTotalApartPlayer);

    /*Rendre les hotels du joueur à la banque */
    int nbTotalHostelPlayer = this->playerInDebt.getNbTotalHostel();
    int nbTotalHostelBank = theBank.getNbHostelBank();
    theBank.setNbApartBank(nbTotalHostelBank + nbTotalHostelPlayer);


    /********** DEBT ENVERS LA BANQUE **********/

    if(this->playerInDebt.getDebt()== state::DEBT_BANK or this->playerInDebt.getDebt()== state::NOT_DEBT){

        /*Met la somme d'argent du joueur à zéro*/
        this->playerInDebt.setMoney(0);

        /*Rendre les propriétés du joueur à la banque*/

        for(auto property : this->playerInDebt.getPlayerProperties()){
            property.resetPossessions();
            state.addPropertyBank(&property);
        }
        this->playerInDebt.getPlayerProperties().clear();


    }
        /********** DEBT ENVERS L'AUTRE JOUEUR **********/

    else if(this->playerInDebt.getDebt() != state::DEBT_BANK and this->playerInDebt.getDebt() != state::NOT_DEBT){

        /*Donne la somme d'argent restante du joueur en dette à celui envers qui il est en dette*/

        //Trouver le joueur envers qui il est en dette
        state::Player* playerWaitingMoney;
        switch(this->playerInDebt.getDebt()) {
            case state::DEBT_PLAYERA :
                playerWaitingMoney = &(state.getListPlayer()[0]);
                break;
            case state::DEBT_PLAYERB :
                playerWaitingMoney = &(state.getListPlayer()[1]);
                break;
            case state::DEBT_PLAYERC :
                playerWaitingMoney = &(state.getListPlayer()[2]);
                break;
            case state::DEBT_PLAYERD :
                playerWaitingMoney = &(state.getListPlayer()[3]);
                break;
            case state::DEBT_PLAYERE :
                playerWaitingMoney = &(state.getListPlayer()[4]);
                break;
            case state::DEBT_PLAYERF :
                playerWaitingMoney = &(state.getListPlayer()[5]);
                break;
            default :
                break;
        }

        long long moneyLeft = this->playerInDebt.getMoney();
        state.modifyMoney(*playerWaitingMoney, moneyLeft);
        this->playerInDebt.setMoney(0);


        /*Donner les propriétés du joueur à l'autre joueur*/

        for(auto property : this->playerInDebt.getPlayerProperties()){
            property.resetPossessions();
            state.addPropertyPlayer(*playerWaitingMoney, property);
            state.modifyNbPropertyType(*playerWaitingMoney, property);
        }
        this->playerInDebt.getPlayerProperties().clear();

    }

    /* Reset les attributs du joueur*/
    this->playerInDebt.setDebt(state::NOT_DEBT);
    this->playerInDebt.setGameStatus(state::LOST);
    this->playerInDebt.setNbTurnInJail(0);

    while(this->playerInDebt.getFreeJailCard() != 0){
        state.returnJailCard();
        int nbFreeJailCardPlayer = this->playerInDebt.getFreeJailCard();
        this->playerInDebt.setFreeJailCard(nbFreeJailCardPlayer-1);
    }

}

void engine::DeclareBankruptcyCommand::execute(state::State &state) {
    declareBankruptcy(state);
}
