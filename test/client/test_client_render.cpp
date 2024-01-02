#include <boost/test/unit_test.hpp>
#include "../../src/client/render.h"
#include <SFML/Graphics.hpp>

BOOST_AUTO_TEST_CASE(TestStaticAssert) {
    BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestButtonPlayer) {
    std::vector<state::Player> listPlayer{
            *new state::Player("TEST", state::BOAT),
            *new state::Player("TEST", state::CAR)
    };
    for (int nbPlayer = 2; nbPlayer <= 6; nbPlayer++) {
        render::GameInformation gameInformation = *new render::GameInformation(sf::Vector2u(0, 0), listPlayer,
                                                                               state::Bank());
        listPlayer.push_back(*new state::Player("TEST", state::IRON));
        BOOST_CHECK_EQUAL(nbPlayer, gameInformation.getPlayerInformation().size());
    }
}

BOOST_AUTO_TEST_CASE(TestColorOutlineCases) {
    render::AllCases cases = render::AllCases(sf::Vector2u(0, 0), 6);
    BOOST_CHECK_EQUAL(28, cases.getListCases().size());

    BOOST_CHECK_EQUAL(sf::Color(0xFE90C9FF).toInteger(),
                      cases.getListCases()[0]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color(0xFE90C9FF).toInteger(),
                      cases.getListCases()[1]->getSquare().getOutlineColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color::Cyan.toInteger(), cases.getListCases()[2]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Cyan.toInteger(), cases.getListCases()[3]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Cyan.toInteger(), cases.getListCases()[4]->getSquare().getOutlineColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color::Magenta.toInteger(),
                      cases.getListCases()[5]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Magenta.toInteger(),
                      cases.getListCases()[6]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Magenta.toInteger(),
                      cases.getListCases()[7]->getSquare().getOutlineColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color(0xE79C62FF).toInteger(),
                      cases.getListCases()[8]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color(0xE79C62FF).toInteger(),
                      cases.getListCases()[9]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color(0xE79C62FF).toInteger(),
                      cases.getListCases()[10]->getSquare().getOutlineColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color::Red.toInteger(), cases.getListCases()[11]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Red.toInteger(), cases.getListCases()[12]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Red.toInteger(), cases.getListCases()[13]->getSquare().getOutlineColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color::Yellow.toInteger(),
                      cases.getListCases()[14]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Yellow.toInteger(),
                      cases.getListCases()[15]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Yellow.toInteger(),
                      cases.getListCases()[16]->getSquare().getOutlineColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color::Green.toInteger(),
                      cases.getListCases()[17]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Green.toInteger(),
                      cases.getListCases()[18]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Green.toInteger(),
                      cases.getListCases()[19]->getSquare().getOutlineColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color::Blue.toInteger(), cases.getListCases()[20]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Blue.toInteger(), cases.getListCases()[21]->getSquare().getOutlineColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color(0xB8B8B8FF).toInteger(),
                      cases.getListCases()[22]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color(0xB8B8B8FF).toInteger(),
                      cases.getListCases()[23]->getSquare().getOutlineColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color(0x66666FF).toInteger(),
                      cases.getListCases()[24]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color(0x66666FF).toInteger(),
                      cases.getListCases()[25]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color(0x66666FF).toInteger(),
                      cases.getListCases()[26]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color(0x66666FF).toInteger(),
                      cases.getListCases()[27]->getSquare().getOutlineColor().toInteger());
}

BOOST_AUTO_TEST_CASE(TestFillColorCase) {
    render::AllCases listCases = render::AllCases(sf::Vector2u(0, 0), 6);
    for (auto cases: listCases.getListCases()) {
        cases->setFillColor(cases->getSquare().getOutlineColor());
    }

    BOOST_CHECK_EQUAL(sf::Color(0xFE90C9FF).toInteger(),
                      listCases.getListCases()[0]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color(0xFE90C9FF).toInteger(),
                      listCases.getListCases()[1]->getSquare().getFillColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color::Cyan.toInteger(), listCases.getListCases()[2]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Cyan.toInteger(), listCases.getListCases()[3]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Cyan.toInteger(), listCases.getListCases()[4]->getSquare().getFillColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color::Magenta.toInteger(),
                      listCases.getListCases()[5]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Magenta.toInteger(),
                      listCases.getListCases()[6]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Magenta.toInteger(),
                      listCases.getListCases()[7]->getSquare().getFillColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color(0xE79C62FF).toInteger(),
                      listCases.getListCases()[8]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color(0xE79C62FF).toInteger(),
                      listCases.getListCases()[9]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color(0xE79C62FF).toInteger(),
                      listCases.getListCases()[10]->getSquare().getFillColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color::Red.toInteger(), listCases.getListCases()[11]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Red.toInteger(), listCases.getListCases()[12]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Red.toInteger(), listCases.getListCases()[13]->getSquare().getFillColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color::Yellow.toInteger(), listCases.getListCases()[14]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Yellow.toInteger(), listCases.getListCases()[15]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Yellow.toInteger(), listCases.getListCases()[16]->getSquare().getFillColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color::Green.toInteger(), listCases.getListCases()[17]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Green.toInteger(), listCases.getListCases()[18]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Green.toInteger(), listCases.getListCases()[19]->getSquare().getFillColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color::Blue.toInteger(), listCases.getListCases()[20]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Blue.toInteger(), listCases.getListCases()[21]->getSquare().getFillColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color(0xB8B8B8FF).toInteger(),
                      listCases.getListCases()[22]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color(0xB8B8B8FF).toInteger(),
                      listCases.getListCases()[23]->getSquare().getFillColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color(0x66666FF).toInteger(),
                      listCases.getListCases()[24]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color(0x66666FF).toInteger(),
                      listCases.getListCases()[25]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color(0x66666FF).toInteger(),
                      listCases.getListCases()[26]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color(0x66666FF).toInteger(),
                      listCases.getListCases()[27]->getSquare().getFillColor().toInteger());
}

/* vim: set sw=2 sts=2 et : */
