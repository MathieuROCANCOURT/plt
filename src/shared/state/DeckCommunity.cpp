#include "DeckCommunity.h"

using namespace std;
using namespace state;


DeckCommunity::DeckCommunity(){

    Card* free_prison = new Card("free_prison", true, false, false, false, false, false, new int[1]{0});
    Card* go_back_lens = new Card("go_back_lens", false, false, false, false, false, false, new int[1]{0});
    Card* go_prison = new Card("go_prison", false, false, false, false, false, true, new int[1]{0});
    Card* go_start = new Card("go_start", false, false, false, true, false, false, new int[1]{0});
    Card* pay_big_sell = new Card("pay_big_sell", false, true, false, false, false, false, new int[1]{-1000000});
    Card* pay_hostel_stars = new Card("pay_hostel_stars", false, true, false, false, false, false, new int[1]{-500000});
    Card* pay_picture_damage = new Card("pay_picture_damage", false, true, false, false, false, false, new int[1]{-500000});
    Card* pay_ticket = new Card("pay_ticket", false, true, false, false, false, false, new int[1]{-100000});
    Card* win_auto_reimbursement = new Card("win_auto_reimbursement", false, true, false, false, false, false, new int[1]{250000});
    Card* win_company_interneet = new Card("win_company_interneet", false, true, false, false, false, false, new int[1]{2000000});
    Card* win_game_show = new Card("win_game_show", false, true, false, false, false, false, new int[1]{100000});
    Card* win_heritage = new Card("win_heritage", false, true, false, false, false, false, new int[1]{1000000});
    Card* win_jet_rental = new Card("win_jet_rental", false, true, false, false, false, false, new int[1]{1000000});
    Card* win_on_players = new Card("win_on_players", false, true, false, false, true, false, new int[1]{100000});
    Card* win_show = new Card("win_show", false, true, false, false, false, false, new int[1]{200000});
    Card* win_taxes = new Card("win_taxes", false, true, false, false, false, false, new int[1]{500000});

    stack.push_back(free_prison);
    stack.push_back(go_back_lens);
    stack.push_back(go_prison);
    stack.push_back(go_start);
    stack.push_back(pay_big_sell);
    stack.push_back(pay_hostel_stars);
    stack.push_back(pay_picture_damage);
    stack.push_back(pay_ticket);
    stack.push_back(win_auto_reimbursement);
    stack.push_back(win_company_interneet);
    stack.push_back(win_game_show);
    stack.push_back(win_heritage);
    stack.push_back(win_jet_rental);
    stack.push_back(win_on_players);
    stack.push_back(win_show);
    stack.push_back(win_taxes);

}
