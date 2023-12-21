
#include <boost/test/unit_test.hpp>

#include "../../src/shared/state.h"

using namespace ::state;

BOOST_AUTO_TEST_CASE(TestStaticAssert){
    Dices dices {};
    dices.setScore(2);
    BOOST_CHECK_EQUAL(dices.getScore(), 2);
    dices.setIsDouble(true);
    BOOST_CHECK_EQUAL(dices.getIsDouble(), true);
    //init.modifyNbPlayer(5);
    //BOOST_CHECK_EQUAL(init.getNbPlayer(), 5);
    Card* go_dunkerque = new Card("go_dunkerque",false,false,false,true,true, false, std::vector<int> {40});
    BOOST_CHECK_EQUAL(go_dunkerque->getFreeJail(), false);
    State state1;
    Player A=Player ("papa Noël", Token::BOAT);
    state1.addPlayer( A);
    BOOST_CHECK_EQUAL(state1.getNbPlayer(), 1);


}

/* Effacer TestExemple car suppression Exemple.cpp */
//BOOST_AUTO_TEST_CASE(TestExemple){
//  {
//    Exemple ex {};
//    BOOST_CHECK_EQUAL(ex.x, 0);
//    ex.setX(21);
//    BOOST_CHECK_EQUAL(ex.x, 21);
//  }
//
//  {
//    Exemple ex {};
//    ex.setX(21);
//    BOOST_CHECK_LE(ex.x, 32); // Less than equal
//    BOOST_CHECK_GT(ex.x, 11); // Greater than equl
//  }
//}


/* vim: set sw=2 sts=2 et : */
