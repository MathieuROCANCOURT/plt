#include <iostream>
#include <algorithm>
#include "State.h"

using namespace std;
using namespace state;


State::State() : nbPlayer(0), bank(), dices(), nbDouble(0), stackCommunity(), stackLuck(), turn(NO_PLAYER) {


    //instanciation des cases propriétés
    board.emplace(2, Box(2, true, false, false, false, false));
    board.emplace(4, Box(4, true, false, false, false, false));
    board.emplace(7, Box(7, true, false, false, false, false));
    board.emplace(9, Box(9, true, false, false, false, false));
    board.emplace(10, Box(10, true, false, false, false, false));
    board.emplace(12, Box(12, true, false, false, false, false));
    board.emplace(14, Box(14, true, false, false, false, false));
    board.emplace(15, Box(15, true, false, false, false, false));
    board.emplace(17, Box(17, true, false, false, false, false));
    board.emplace(19, Box(19, true, false, false, false, false));
    board.emplace(20, Box(20, true, false, false, false, false));
    board.emplace(22, Box(22, true, false, false, false, false));
    board.emplace(24, Box(24, true, false, false, false, false));
    board.emplace(25, Box(25, true, false, false, false, false));
    board.emplace(27, Box(27, true, false, false, false, false));
    board.emplace(28, Box(28, true, false, false, false, false));
    board.emplace(30, Box(30, true, false, false, false, false));
    board.emplace(32, Box(32, true, false, false, false, false));
    board.emplace(33, Box(33, true, false, false, false, false));
    board.emplace(35, Box(35, true, false, false, false, false));
    board.emplace(38, Box(38, true, false, false, false, false));
    board.emplace(40, Box(40, true, false, false, false, false));

    //instanciation des cases communauté
    board.emplace(3, Box(3, false, true, false, false, false));
    board.emplace(18, Box(18, false, true, false, false, false));
    board.emplace(34, Box(34, false, true, false, false, false));
    //instanciation des cases chance
    board.emplace(8, Box(8, false, true, false, true, false));
    board.emplace(23, Box(23, false, true, false, true, false));
    board.emplace(37, Box(37, false, true, false, true, false));

    //instanciation des autres cases
    board.emplace(1, Box(1, false, false, true, false, false));
    board.emplace(5, Box(5, false, false, true, false, false));
    board.emplace(11, Box(11, false, false, false, false, false));
    board.emplace(21, Box(21, false, false, false, false, false));
    board.emplace(31, Box(31, false, false, true, false, true));
    board.emplace(39, Box(39, false, false, true, false, false));



}


void State::modifyNbPlayer(int nbPlayer) {
    if (nbPlayer > 1 and nbPlayer < 7) {
        this->nbPlayer = nbPlayer;
    }

    //test non effectue
    cout << this->nbPlayer << endl;
}

void State::addPlayer(Player player) {

    this->listPlayer.push_back(player);

    //test non effectue
    //for (Player i : this->listPlayer){
      //  cout << i << endl;
    //}

}

void State::modifyDices(int value1, int value2) {
    if (value1 == value2){
        this->dices.setIsDouble(true);
        modifyNbDouble(1);
    }
    this->dices.setScore(value1+value2);

    //test non effectue
    cout << "il y a un double ? " << this->dices.getIsDouble() << endl;
    cout << "le score au dés est : " << this->dices.getScore() << endl;

}

void State::modifyNbDouble(bool isDouble) {
    if(isDouble){
        if (this->nbDouble<3){
            this->nbDouble += 1;
        }
        else{ cout << "le nombre de doubles est supérieur à 3 pour le tour d'un même joueur"<<endl;}
    }
    if(!isDouble){
        this->nbDouble = 0;
    }
    // test non effectué
}

void State::modifyPosition(Player player, int position) {

    if(position < 41 and position > 0){
        player.setPosition(position);
    }

    // test non effectue
    cout << "le joueur est sur la case "<< player.getPosition() << endl;
}

void State::modifyTurn(Playing tour) {
    this->turn = tour;

    //test non effectue
    cout << "l'instance turn de l'enumerate Playing vaut " << this->turn << endl;
}

void State::modifyMoney(Player player, int value) {

    long long moneyOfPlayer = player.getMoney();
    moneyOfPlayer += value;
    player.setMoney(moneyOfPlayer);

    //test non effectué
    cout << "le joueur possède "<< player.getMoney() << "euros" << endl;

}

void State::addPropertyBank(Property* property) {

    this->bank.addToBankProperties(property);

    //test non effectué
    cout << "les propriete de la banque sont" << endl;
    //for (Player i : this->bank.getbankProperties()) {
      //  cout << i << endl;
    //}
}

void State::removePropertyBank(Property* property) {

    const vector<Property*> &myListOfBankProperties = this->bank.getBankProperties();
    auto it = std::find(myListOfBankProperties.begin(), myListOfBankProperties.end(),
                                                   property);

    if (it != myListOfBankProperties.end()) { // Si l'élément est trouvé dans le vecteur

        // On obtient l'index à partir de l'itérateur trouvé pour modifier le vecteur original
        int index = std::distance(myListOfBankProperties.begin(), it);

        // On obtient un itérateur non-constant pour bankProperties
        auto bankIterator = this->bank.getBankProperties().begin() + index;

        this->bank.eraseFromBankProperties(bankIterator);// Supprime l'élément à cette position
        std::cout << "Element supprime !" << std::endl;
    } else {
        std::cout << "Element non trouve dans le vecteur." << std::endl;
    }
}

void State::addPropertyPlayer(Player player, Property property) {
    player.addToPlayerProperties(property);

    //test non effectué
    //cout << "les propriete du joueur " << player << endl;
    //for (Player i : player.getPlayerProperties()) {
      //  cout << i << endl;
    //}
}

Card* State::drawCardLuck() {

    Card* firstCard = this->stackLuck.drawCard();
    return firstCard;
}

void State::gameStatus(Player player, GameStatus status) {

    player.setGameStatus(status);

}

void State::removePropertyPlayer(Player player, Property property) {

    for(auto& currentPlayer : listPlayer) {
        if (currentPlayer.getName() == player.getName()){
            const vector<Property> &myListOfPlayerProperties = currentPlayer.getPlayerProperties();
            auto it = std::find(myListOfPlayerProperties.begin(), myListOfPlayerProperties.end(),
                                property);

            if (it != myListOfPlayerProperties.end()) { // Si l'élément est trouvé dans le vecteur

                // On obtient l'index à partir de l'itérateur trouvé pour modifier le vecteur original
                int index = std::distance(myListOfPlayerProperties.begin(), it);

                // On obtient un itérateur non-constant pour bankProperties
                auto bankIterator = currentPlayer.getPlayerProperties().begin() + index;

                currentPlayer.eraseFromPlayerProperties(bankIterator);// Supprime l'élément à cette position
                std::cout << "Element supprime !" << std::endl;
            } else {
                std::cout << "Element non trouve dans le vecteur." << std::endl;
            }
        }
    }

}

int State::getNbDouble() {
    return this->nbDouble;
}

Card *State::drawCardCommunity() {
    Card* firstCard = this->stackLuck.drawCard();
    return firstCard;
}

void State::modifyNbFreeJailCard(Player player, bool increase) {

    int nbFreeJailCard = player.getFreeJailCard();

    if(increase) {
        if (nbFreeJailCard < 2) {
            nbFreeJailCard++;
            player.setFreeJailCard(nbFreeJailCard);
        } else {
            cout << "erreur : ce joueur possède trop de carte libéré de prison" << endl;
        }
    }
    else{
        if(nbFreeJailCard > 0){
            nbFreeJailCard--;
            player.setFreeJailCard(nbFreeJailCard);
        }
        else{
            cout << "erreur : ce joueur ne possède pas assez de carte libéré de prison" << endl;
        }
    }

}

void State::returnJailCard() {

    int nbCardCommunity = stackCommunity.sizeDeck();
    int nbCardLuck = stackLuck.sizeDeck();

    if(nbCardCommunity == 15){
        stackCommunity.returnJailCard();
    }
    if(nbCardLuck == 15){
        stackLuck.returnJailCard();
    }

}

void State::debtPlayer(Player playerInDebt, Player playerCreditor) {

    string name = playerCreditor.getName();


    if( name == "A" ){ playerInDebt.setDebt(DEBT_PLAYERA);}
    else if(name == "B"){ playerInDebt.setDebt(DEBT_PLAYERB);}
    else if(name == "C"){ playerInDebt.setDebt(DEBT_PLAYERC);}
    else if(name == "D"){ playerInDebt.setDebt(DEBT_PLAYERD);}
    else if(name == "E"){ playerInDebt.setDebt(DEBT_PLAYERE);}
    else if(name == "F"){ playerInDebt.setDebt(DEBT_PLAYERF);}
    else{ cout << "erreur : le player envers qui il y a dette n'a pas été trouvé" << endl;}

}













