//
// Created by alexis on 15/12/23.
//
#include "buyApartCommand.h"
#include "state/City.h"


void engine::buyApartCommand::execute (state::State& state){

}



bool engine::buyApartCommand::buyApart(state::State &state) {
    state::Player* player=state.getCurrentPlayer();
    std::vector<state::Property> myproperties=player->getPlayerProperties();
    int minpos=9999999;
    std::vector<state::Property> propertySameColor;
    for (int i=0;i<myproperties.size();i++) {
        if (myproperties[i].getColor()== this->getColor()) {
            propertySameColor.push_back(myproperties[i]);
        }
    }
    for (int i = 0; i < propertySameColor.size(); i++) {
        state::City* city =dynamic_cast<state::City*>(&propertySameColor[i]);
        city->getNbApart();

    }

    return false;
}
