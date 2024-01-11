
#include <boost/test/unit_test.hpp>

#include "../../src/shared/engine.h"
#include "../../src/shared/state.h"

using namespace ::engine;

BOOST_AUTO_TEST_CASE(Test_engine) {

    Engine *theEngine = new Engine();
    //RollDicesCommand->rollDices(theEngine->state);
    BOOST_CHECK(1);

}

BOOST_AUTO_TEST_CASE(Test_init_game_command) {

    Engine *theEngine = new engine::Engine;
    CommandTypeId a=INITGAME;
    std::vector<state::Token> b{state::BOAT,state::CAR};
    std::vector<std::string>c{"abc","def"};

    InitGameCommand initgame=InitGameCommand(3,b,c,a);
    theEngine->addCommand(&initgame);
    theEngine->executeCommand();
    //RollDicesCommand->rollDices(theEngine->state);
    BOOST_CHECK_EQUAL(theEngine->getState().getNbPlayer(),3);

}