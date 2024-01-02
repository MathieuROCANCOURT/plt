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
    render::AllCases *cases = new render::AllCases(sf::Vector2u(0, 0), 6);
    BOOST_CHECK_EQUAL(28, cases->getListCases().size());
    std::vector<render::Cases *> listCases = cases->getListCases();

    BOOST_CHECK_EQUAL(sf::Color(0xFE90C9FF).toInteger(), listCases[0]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color(0xFE90C9FF).toInteger(), listCases[1]->getSquare().getOutlineColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color::Cyan.toInteger(), listCases[2]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Cyan.toInteger(), listCases[3]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Cyan.toInteger(), listCases[4]->getSquare().getOutlineColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color::Magenta.toInteger(), listCases[5]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Magenta.toInteger(), listCases[6]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Magenta.toInteger(), listCases[7]->getSquare().getOutlineColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color(0xE79C62FF).toInteger(), listCases[8]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color(0xE79C62FF).toInteger(), listCases[9]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color(0xE79C62FF).toInteger(), listCases[10]->getSquare().getOutlineColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color::Red.toInteger(), listCases[11]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Red.toInteger(), listCases[12]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Red.toInteger(), listCases[13]->getSquare().getOutlineColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color::Yellow.toInteger(), listCases[14]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Yellow.toInteger(), listCases[15]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Yellow.toInteger(), listCases[16]->getSquare().getOutlineColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color::Green.toInteger(), listCases[17]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Green.toInteger(), listCases[18]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Green.toInteger(), listCases[19]->getSquare().getOutlineColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color::Blue.toInteger(), listCases[20]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Blue.toInteger(), listCases[21]->getSquare().getOutlineColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color(0xB8B8B8FF).toInteger(), listCases[22]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color(0xB8B8B8FF).toInteger(), listCases[23]->getSquare().getOutlineColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color(0x66666FF).toInteger(), listCases[24]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color(0x66666FF).toInteger(), listCases[25]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color(0x66666FF).toInteger(), listCases[26]->getSquare().getOutlineColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color(0x66666FF).toInteger(), listCases[27]->getSquare().getOutlineColor().toInteger());
}

BOOST_AUTO_TEST_CASE(TestFillColorCase) {
    render::AllCases *listCases = new render::AllCases(sf::Vector2u(0, 0), 6);
    for (auto cases: listCases->getListCases()) {
        cases->setFillColor(cases->getSquare().getOutlineColor());
    }
    std::vector<render::Cases *> listC = listCases->getListCases();

    BOOST_CHECK_EQUAL(sf::Color(0xFE90C9FF).toInteger(), listC[0]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color(0xFE90C9FF).toInteger(), listC[1]->getSquare().getFillColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color::Cyan.toInteger(), listC[2]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Cyan.toInteger(), listC[3]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Cyan.toInteger(), listC[4]->getSquare().getFillColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color::Magenta.toInteger(), listC[5]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Magenta.toInteger(), listC[6]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Magenta.toInteger(), listC[7]->getSquare().getFillColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color(0xE79C62FF).toInteger(), listC[8]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color(0xE79C62FF).toInteger(), listC[9]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color(0xE79C62FF).toInteger(), listC[10]->getSquare().getFillColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color::Red.toInteger(), listC[11]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Red.toInteger(), listC[12]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Red.toInteger(), listC[13]->getSquare().getFillColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color::Yellow.toInteger(), listC[14]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Yellow.toInteger(), listC[15]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Yellow.toInteger(), listC[16]->getSquare().getFillColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color::Green.toInteger(), listC[17]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Green.toInteger(), listC[18]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Green.toInteger(), listC[19]->getSquare().getFillColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color::Blue.toInteger(), listC[20]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color::Blue.toInteger(), listC[21]->getSquare().getFillColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color(0xB8B8B8FF).toInteger(), listC[22]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color(0xB8B8B8FF).toInteger(), listC[23]->getSquare().getFillColor().toInteger());

    BOOST_CHECK_EQUAL(sf::Color(0x66666FF).toInteger(), listC[24]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color(0x66666FF).toInteger(), listC[25]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color(0x66666FF).toInteger(), listC[26]->getSquare().getFillColor().toInteger());
    BOOST_CHECK_EQUAL(sf::Color(0x66666FF).toInteger(), listC[27]->getSquare().getFillColor().toInteger());
}

/* vim: set sw=2 sts=2 et : */
