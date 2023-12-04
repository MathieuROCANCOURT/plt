#include <algorithm>
#include "DeckLuck.h"

using namespace std;
using namespace state;


DeckLuck::DeckLuck() {

    Card* free_prison = new Card("free_prison", true, false, false, false, false, false, new int[1]{0});
    Card* go_dunkerque = new Card("go_dunkerque", false, false, false, true, false, false, new int[1]{0});
    Card* go_lens = new Card("go_lens", false, false, false, true, false, false, new int[1]{0});
    Card* go_marseille_station = new Card("go_marseille_station", false, false, false, true, false, false, new int[1]{0});
    Card* go_metz = new Card("go_metz", false, false, false, true, false, false, new int[1]{0});
    Card* go_prison = new Card("go_prison", false, false, false, false, false, true, new int[1]{0});
    Card* go_start = new Card("go_start", false, false, false, true, false, false, new int[1]{0});
    Card* lose_construct_pool = new Card("lose_construct_pool", false, true, false, false, false, false, new int[1]{-200000});
    Card* move_back_bottleneck = new Card("move_back_bottleneck", false, false, false, false, false, false, new int[1]{0});
    Card* pay1_apart_and_hostel = new Card("pay(1)_apart_and_hostel", false, true, true, false, false, false, new int[2]{-250000, -1000000});
    Card* pay_apart_and_hostel = new Card("pay_apart_and_hostel", false, true, true, false, false, false, new int[2]{-400000, -1150000});
    Card* pay_phone = new Card("pay_phone", false, true, false, false, false, false, new int[1]{-150000});
    Card* pay_school_fees = new Card("pay_school_fees", false, true, false, false, false, false, new int[1]{-1500000});
    Card* win_loto = new Card("win_loto", false, true, false, false, false, false, new int[1]{1000000});
    Card* win_profit_shares = new Card("win_profit_shares", false, true, false, false, false, false, new int[1]{1500000});
    Card* win_rugby = new Card("win_rugby", false, true, false, false, false, false, new int[1]{500000});

    stack.push_back(free_prison);
    stack.push_back(go_dunkerque);
    stack.push_back(go_lens);
    stack.push_back(go_marseille_station);
    stack.push_back(go_metz);
    stack.push_back(go_prison);
    stack.push_back(go_start);
    stack.push_back(lose_construct_pool);
    stack.push_back(move_back_bottleneck);
    stack.push_back(pay1_apart_and_hostel);
    stack.push_back(pay_apart_and_hostel);
    stack.push_back(pay_phone);
    stack.push_back(pay_school_fees);
    stack.push_back(win_loto);
    stack.push_back(win_profit_shares);
    stack.push_back(win_rugby);

}

Card* DeckLuck::drawCard() {

    state::Card* firstCard = stack[0];

    if (!this->stack.empty()) { // Vérifie si le vecteur n'est pas vide
        std::rotate(this->stack.begin(), this->stack.begin() + 1, this->stack.end());
        // Déplace le premier élément à la dernière position du vecteur
    }

    if(firstCard->getText() == "free_prison"){
        this->stack.pop_back();
    }

    // TEST : Affichage pour vérifier le déplacement
   // for (const auto& this->stack : this->stack) {
        // Affichage des cartes pour vérifier le déplacement
        // test non effectué
   // }

    return firstCard;
}

void DeckLuck::returnJailCard() {

    Card* free_prison = new Card("free_prison", true, false, false, false, false, false, new int[1]{0});
    stack.push_back(free_prison);

}

int DeckLuck::sizeDeck() {
    return this->stack.size();
}



