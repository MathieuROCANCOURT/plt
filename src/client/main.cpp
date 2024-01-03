#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>


#include <state.h>

#include <cstring>

using namespace std;
using namespace state;


int main(int argc, char *argv[]) {
    if (argc == 2) {
        if (strcmp(argv[1], "hello") == 0) {
            cout << "Bonjour le monde!" << endl;
        } else if (strcmp(argv[1], "state") == 0) {
            cout << R"(Veillez utiliser les commandes "make unittest" et "make code-coverage" depuis le dossier build)"
                 << endl;


            State* myState =  new State();
            myState->getIsDouble();
            //int nbP = 3;
            //myState->State::modifyNbPlayer(nbP);



        }
    } else {
        cout << "It works !" << endl;
    }

    return EXIT_SUCCESS;
}