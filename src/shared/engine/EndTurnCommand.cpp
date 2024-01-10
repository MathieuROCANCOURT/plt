#include "EndTurnCommand.h"

void engine::EndTurnCommand::changeTurn(state::State& state) {

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

void engine::EndTurnCommand::execute(state::State &state) {
    changeTurn(state);
}
