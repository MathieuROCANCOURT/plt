#include "BuyPropertyCommand.h"


void engine::BuyPropertyCommand::buyTheProperty(state::State &state) {
    state::Player playerCurrent = state.getCurrentPlayer();
    long long valuePurchase = this->property.getValuePurchase();

    if((playerCurrent.getMoney() - valuePurchase) > 0){
        payTheBank(state, valuePurchase);
        state.addPropertyPlayer(playerCurrent, this->property);
        state.removePropertyBank(this->property);
        state.modifyNbPropertyType(playerCurrent, this->property);
    }
    //Achat de property (argument de la commande)
}

void engine::BuyPropertyCommand::execute(state::State &state) {
    buyTheProperty(state);
}

void engine::BuyPropertyCommand::payTheBank(state::State &state, long long int valueMoney) {
    state::Player playerCurrent = state.getCurrentPlayer();

    if((playerCurrent.getMoney() - valueMoney)<0){
        playerCurrent.setDebt(state::DEBT_BANK);
    }
    state.modifyMoney(playerCurrent, -valueMoney);
}
