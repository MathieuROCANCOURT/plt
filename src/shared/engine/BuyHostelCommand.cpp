#include "BuyHostelCommand.h"
#include "state/City.h"


void engine::BuyHostelCommand::execute(state::State &state) {
    buyHostel(state);
}


bool engine::BuyHostelCommand::buyHostel(state::State &state) {
    state::Player *playerAchetant = state.getCurrentPlayer();
    std::vector<state::Property> myproperties = playerAchetant->getPlayerProperties();
    std::vector<state::Property> propertySameColor;
    std::vector<state::City> listville;
    for (int i = 0; i < int(myproperties.size()); i++) {
        //met toutes les propriétés ayant la même couleur dans un vecteur à part
        if (myproperties[i].getColor() == this->getColor()) {
            propertySameColor.push_back(myproperties[i]);
        }
    }
    for (int i = 0; i < int(propertySameColor.size()); i++) { //transforme les propriétés en ville
        state::City *city = dynamic_cast<state::City *>(&propertySameColor[i]);
        listville.push_back(*city);
    }
    int a[listville.size()];
    for (int i = 0; i < int(listville.size()); i++) {
        a[i] = listville[i].getNbHostel();
    }
    int b = a[listville.size() - 1];
    int nbMemenbApart = 0;
    for (int i = 0; i < int(listville.size()); i++) {
        //compte le nombre de villes ayant le même nombre d'appartements
        if (b == a[i]) {
            nbMemenbApart++;
        }
    }

    state::City cityHostelAchetable = listville[listville.size() - 1];
    //si toutes les villes ont le même nombre d'appartements choisi la ville ayant la position la plus faible
    if (nbMemenbApart == int(listville.size())) {
        for (int i = 0; i < int(listville.size()); i++) {
            if (listville[i].getPosition() < cityHostelAchetable.getPosition()) {
                cityHostelAchetable = listville[i];
            }
        }
    }
    std::vector<state::City> cityLessApart;
    if (nbMemenbApart < int(listville.size())) {
        for (int i = 0; i < int(listville.size()); i++) {
            //si pas toutes les villes ont le même nombre d'appartements choisi les villes ayant le moins d'appartement
            if (listville[i].getNbHostel() == cityHostelAchetable.getNbHostel()) {
                cityLessApart.push_back(listville[i]);
            }
        }
        for (int i = 0; i < int(cityLessApart.size()); i++) {
            //choisi la ville parmi celle qui ont le moins d'appartement la ville avec la position la moins élevée
            if (cityHostelAchetable.getPosition() > cityLessApart[i].getPosition()) {
                cityHostelAchetable = cityLessApart[i];
            }
        }

    }

    if (cityHostelAchetable.getNbHostel()) {
        return false;
    }
    state::Bank bank = state.getBank();
    if (bank.getNbHostelBank() == 0) {
        return false;
    }
    payTheBank(state, cityHostelAchetable.getPriceApartHostel());//paiement de l'argent
    playerAchetant = state.getCurrentPlayer();
    playerAchetant->setNbTotalApart(playerAchetant->getNbTotalHostel() + 1);//nbApartTotal du joueur augmenté de 1
    cityHostelAchetable.setNbHostel(cityHostelAchetable.getNbHostel() + 1);//nbApart de la propriété augmentée de 1
    bank.setNbHostelBank(bank.getNbHostelBank() - 1);
    return true;
}
void engine::BuyHostelCommand::payTheBank(state::State &state, long long int valueMoney) {
    state::Player *playerCurrent = state.getCurrentPlayer();

    if ((playerCurrent->getMoney() - valueMoney) < 0) {
        playerCurrent->setDebt(state::DEBT_BANK);
    }
    state.modifyMoney(*playerCurrent, -valueMoney);
}