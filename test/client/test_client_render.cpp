#include <boost/test/unit_test.hpp>
#include "../../src/client/render.h"
#include <SFML/Graphics.hpp>

BOOST_AUTO_TEST_CASE(TestStaticAssert){
    BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestRender)
{
    {
        state::State currentState = *new state::State();
        render::Render *r;
        r = new render::Render(currentState);
        int nbPlayer = 5;
        currentState.modifyNbPlayer(nbPlayer);
        BOOST_CHECK_EQUAL(5, r->getGameInfo().getListButtonPlayer().size());
    }
}

/* vim: set sw=2 sts=2 et : */
