
#include <boost/test/unit_test.hpp>

#include "../../src/shared/engine.h"
#include "../../src/shared/state.h"

using namespace ::engine;

BOOST_AUTO_TEST_CASE(Test_engine) {

    Engine *theEngine = new Engine();
    theEngine->getState();
    //RollDicesCommand->rollDices(theEngine->state);
    BOOST_CHECK(1);

}

BOOST_AUTO_TEST_CASE(Test_init_game_command) {

    Engine *theEngine = new engine::Engine;
    CommandTypeId a = INITGAME;
    std::vector<state::Token> b{state::BOAT, state::CAR, state::DOG};
    std::vector<std::string> c{"abc", "def", "ghi"};

    InitGameCommand initgame = InitGameCommand(3, b, c, a);
    theEngine->addCommand(&initgame);
    theEngine->executeCommand();
    //RollDicesCommand->rollDices(theEngine->state);
    BOOST_CHECK_EQUAL(theEngine->getState().getNbPlayer(), 3);

}

BOOST_AUTO_TEST_CASE(Test_init_game_endturn) {

    Engine *theEngine = new engine::Engine;
    CommandTypeId a = INITGAME;
    std::vector<state::Token> b{state::BOAT, state::CAR, state::DOG};
    std::vector<std::string> c{"abc", "def", "ghi"};

    InitGameCommand initgame = InitGameCommand(3, b, c, a);
    theEngine->addCommand(&initgame);
    theEngine->executeCommand();


    theEngine->getState().setCurrentPlayer(theEngine->getState().getListPlayer()[0]);
    CommandTypeId a1 = ENDTURN;
    EndTurnCommand endturn = EndTurnCommand(a1);
    theEngine->addCommand(&endturn);
    theEngine->executeCommand();
    //RollDicesCommand->rollDices(theEngine->state);
    BOOST_CHECK_EQUAL(theEngine->getState().getCurrentPlayer().getName(),
                      theEngine->getState().getListPlayer()[1].getName());

}

BOOST_AUTO_TEST_CASE(Test_roll_dices) {

    Engine *theEngine = new engine::Engine;
    CommandTypeId a = INITGAME;
    std::vector<state::Token> b{state::BOAT, state::CAR, state::DOG};
    std::vector<std::string> c{"abc", "def", "ghi"};

    InitGameCommand initgame = InitGameCommand(3, b, c, a);
    theEngine->addCommand(&initgame);
    theEngine->executeCommand();



    CommandTypeId a1 = ROLLDICES;
    RollDicesCommand roll = RollDicesCommand(a1);
    theEngine->addCommand(&roll);
    theEngine->executeCommand();

    //RollDicesCommand->rollDices(theEngine->state);
    int t1 = theEngine->getState().getCurrentPlayerptr()->getPosition();
    int t2 = 1 + theEngine->getState().getScoreDices();
    BOOST_CHECK_EQUAL(t1,t2);

}