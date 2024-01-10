#include <iostream>
#include <algorithm>
#include "State.h"
#include <fstream>
#include <map>
#include <sstream>
#include <vector>
#include <cstring>
#include "config.h"

using namespace std;
using namespace state;

string readFileIntoString(const string &path) {

    auto ss = ostringstream{};
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '" << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    ss << input_file.rdbuf();
    return ss.str();
}

State::State() : nbPlayer(0), bank(), dices(), nbDouble(0), stackCommunity(), stackLuck(), turn(PLAYERA) {
    string path = RES_DIR;
    string filename(path + "Properties/propiété.csv");
    string file_contents;

    char delimiter = ',';

    file_contents = readFileIntoString(filename);

    istringstream sstream(file_contents);

    string record;
    int pos;
    bool isprop, iscard, money, chance, gojail;

    while (std::getline(sstream, record)) {
        istringstream line(record);
        getline(line, record, delimiter);
        pos = stoi(record);
        getline(line, record, delimiter);
        isprop = (strcasecmp("true", record.c_str()) == 0);
        getline(line, record, delimiter);
        iscard = (strcasecmp("true", record.c_str()) == 0);
        getline(line, record, delimiter);
        money = (strcasecmp("true", record.c_str()) == 0);
        getline(line, record, delimiter);
        chance = (strcasecmp("true", record.c_str()) == 0);
        getline(line, record, delimiter);
        gojail = (strcasecmp("true", record.c_str()) == 0);
        this->board.emplace(pos, Box(pos, isprop, iscard, money, chance, gojail));

    }
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
    this->nbPlayer = this->nbPlayer + 1;
    //test non effectue
    //for (Player i : this->listPlayer){
    //  cout << i << endl;
    //}

}

void State::modifyDices(int value1, int value2) {
    if (value1 == value2) {
        this->dices.setIsDouble(true);
        modifyNbDouble(1);
    } else { this->dices.setIsDouble(false); }
    this->dices.setScore(value1 + value2);

    //test non effectue
    //cout << "il y a un double ? " << this->dices.getIsDouble() << endl;
    //cout << "le score au dés est : " << this->dices.getScore() << endl;

}

void State::modifyNbDouble(bool isDouble) {
    if (isDouble) {
        if (this->nbDouble < 3) {
            this->nbDouble += 1;
        } else { cout << "le nombre de doubles est supérieur à 3 pour le tour d'un même joueur" << endl; }
    }
    if (!isDouble) {
        this->nbDouble = 0;
    }
    // test non effectué
}

void State::modifyPosition(Player player, int position) {

    if (position < 41 and position > 0) {
        player.setPosition(position);
    }

    // test non effectue
    cout << "le joueur est sur la case " << player.getPosition() << endl;
}

void State::modifyTurn(Playing tour) {
    this->turn = tour;

    //test non effectue
    cout << "l'instance turn de l'enumerate Playing vaut " << this->turn << endl;
}

void State::modifyMoney(Player player, long long value) {

    long long moneyOfPlayer = player.getMoney();
    moneyOfPlayer += value;
    player.setMoney(moneyOfPlayer);

    //test non effectué
    cout << "le joueur possède " << player.getMoney() << "euros" << endl;

}

void State::addPropertyBank(Property property) {

    this->bank.addToBankProperties(property);

    //test non effectué
    cout << "les propriete de la banque sont" << endl;
    //for (Player i : this->bank.getbankProperties()) {
    //  cout << i << endl;
    //}
}

void State::removePropertyBank(Property property) {

    const vector<Property> &myListOfBankProperties = this->bank.getBankProperties();
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

Card *State::drawCardLuck() {

    Card *firstCard = this->stackLuck.drawCard();
    return firstCard;
}

void State::gameStatus(Player player, GameStatus status) {

    player.setGameStatus(status);

}

void State::removePropertyPlayer(Player player, Property property) {

    for (auto &currentPlayer: listPlayer) {
        if (currentPlayer.getName() == player.getName()) {
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
    return this->getCurrentPlayer().getNbdouble();
}

Card *State::drawCardCommunity() {
    Card *firstCard = this->stackLuck.drawCard();
    return firstCard;
}

void State::modifyNbFreeJailCard(Player player, bool increase) {

    int nbFreeJailCard = player.getFreeJailCard();

    if (increase) {
        if (nbFreeJailCard < 2) {
            nbFreeJailCard++;
            player.setFreeJailCard(nbFreeJailCard);
        } else {
            cout << "erreur : ce joueur possède trop de carte libéré de prison" << endl;
        }
    } else {
        if (nbFreeJailCard > 0) {
            nbFreeJailCard--;
            player.setFreeJailCard(nbFreeJailCard);
        } else {
            cout << "erreur : ce joueur ne possède pas assez de carte libéré de prison" << endl;
        }
    }

}

void State::returnJailCard() {

    int nbCardCommunity = stackCommunity.sizeDeck();
    int nbCardLuck = stackLuck.sizeDeck();

    if (nbCardCommunity == 15) {
        stackCommunity.returnJailCard();
    }
    if (nbCardLuck == 15) {
        stackLuck.returnJailCard();
    }

}

void State::debtPlayer(Player playerInDebt, Player playerCreditor) {

    string name = playerCreditor.getName();


    if (name == "A") { playerInDebt.setDebt(DEBT_PLAYERA); }
    else if (name == "B") { playerInDebt.setDebt(DEBT_PLAYERB); }
    else if (name == "C") { playerInDebt.setDebt(DEBT_PLAYERC); }
    else if (name == "D") { playerInDebt.setDebt(DEBT_PLAYERD); }
    else if (name == "E") { playerInDebt.setDebt(DEBT_PLAYERE); }
    else if (name == "F") { playerInDebt.setDebt(DEBT_PLAYERF); }
    else { cout << "erreur : le player envers qui il y a dette n'a pas été trouvé" << endl; }

}

Player State::getCurrentPlayer() {

    Player *currentPlayer;

    Playing turn = this->turn;
    if (turn == PLAYERA) {
        currentPlayer = &listPlayer[0];
    }
    if (turn == PLAYERB) {
        currentPlayer = &listPlayer[1];
    }
    if (turn == PLAYERC) {
        currentPlayer = &listPlayer[2];
    }
    if (turn == PLAYERD) {
        currentPlayer = &listPlayer[3];
    }
    if (turn == PLAYERE) {
        currentPlayer = &listPlayer[4];
    }
    if (turn == PLAYERF) {
        currentPlayer = &listPlayer[5];
    }

    return *currentPlayer;
}

void State::debtBank(Player player) {
    player.setDebt(DEBT_BANK);
}

long long State::getRentToPay(Property property) {
    return property.getRent();
}

void State::modifyNbPropertyType(Player player, Property property) {
    property.modifyNbPossessed(player);

}

std::vector<Player> State::getListPlayer() {
    return this->listPlayer;
}

int State::getNbPlayer() {
    return this->nbPlayer;
}


void State::modifyNbTurnInJail(bool isInJail) {

    Player playerCurrent = getCurrentPlayer();

    if (isInJail) {
        if (int nbTurn = playerCurrent.getNbTurnInJail() < 3) {
            playerCurrent.setNbTurnInJail(nbTurn + 1);
        } else { std::cout << "le nombre de tours en prison est supérieur à 3" << std::endl; }
    }
    if (!isInJail) {
        playerCurrent.setNbTurnInJail(0);
    }
}

Bank State::getBank() {
    return this->bank;
}

int State::getScoreDices() {
    return dices.getScore();
}

bool State::getIsDouble() {
    return dices.getIsDouble();
}

std::map<int, Box> State::getBoard() {
    return this->board;
}

void State::setCurrentPlayer(const Player& currentPlayer) {
    int count = 0;
    for (const auto& player: this->getListPlayer()) {
        if (currentPlayer == player) {
            this->indiceCurrentPlayer = count;
        }
        count++;
    }
}















