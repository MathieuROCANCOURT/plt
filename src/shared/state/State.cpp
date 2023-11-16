#include <iostream>
#include <algorithm>
#include "State.h"

using namespace std;
using namespace state;



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
    for (Player i : this->listPlayer){
        cout << i << endl;
    }

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
        else{ cout << "le nombre de doubles est supérieur à 3 pour le tour d'un même joueur"}
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
    cout << "le joueur" << player << "est sur la case "<< player.getPosition() << endl;
}

void State::modifyTurn(Playing tour) {
    this->turn = tour;

    //test non effectue
    cout << "l'instancec turn de l'enumerate Playing vaut " << this->turn << endl;
}

void State::modifyMoney(Player player, int value) {

    long long moneyOfPlayer = player.getMoney();
    moneyOfPlayer += value;
    player.setMoney(moneyOfPlayer);

    //test non effectué
    cout << "le joueur" << player << "possède "<< player.getMoney() << "euros" << endl;

}

void State::addPropertyBank(Property property) {

    this->bank.addToBankProperties(property);

    //test non effectué
    cout << "les propriete de la banque sont" << endl;
    for (Player i : this->bank.getbankProperties()) {
        cout << i << endl;
    }
}

void State::removePropertyBank(Property property) {

//    const vector<Property> &myListOfBankProperties = this->bank.getbankProperties();
//    std::vector<Property>::iterator it = std::find(myListOfBankProperties.begin(), myListOfBankProperties.end(),
//                                                   property);
//
//    if (it != myListOfBankProperties.end()) { // Si l'élément est trouvé dans le vecteur
//        this->bank.eraseFromBankProperties(it);// Supprime l'élément à cette position
//        std::cout << "Element supprime !" << std::endl;
//    } else {
//        std::cout << "Element non trouve dans le vecteur." << std::endl;
//    }
}

void State::addPropertyPlayer(Player player, Property property) {
    player.addToPlayerProperties(property);

    //test non effectué
    cout << "les propriete du joueur " << player << endl;
    for (Player i : player.getPlayerProperties()) {
        cout << i << endl;
    }
}

void State::moveCardInDeckLuck() {

    /*Pour que cela fonctionne, il va falloir récuper le vecteur de carte de stackLuck et non pas stackLuck directement*/

//    if (!this->stackLuck.empty()) { // Vérifie si le vecteur n'est pas vide
//        std::rotate(this->stackLuck.begin(), this->stackLuck.begin() + 1, this->stackLuck.end());
//        // Déplace le premier élément à la dernière position du vecteur
//    }
//
//    // Affichage pour vérifier le déplacement
//    for (const auto& this->stackLuck : this->stackLuck) {
//        // Affichage des cartes pour vérifier le déplacement
//        // test non effectué
//    }
}

void State::gameStatus(Player player, GameStatus status) {

    player.setGameStatus(status);

}









