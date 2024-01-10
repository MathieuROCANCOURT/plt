
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

BOOST_AUTO_TEST_CASE(TestState) {
    State a;
    a=State();
}

/* vim: set sw=2 sts=2 et : */
