//
// Created by student on 10.06.23.
//
#include <boost/test/unit_test.hpp>
#include "Zarzadca_Woluminu.h"
#include "Naukowa.h"
#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

BOOST_AUTO_TEST_CASE(DodajUsunWoluminTest)
{
    Zarzadca_Woluminu zarzadca;
    std::vector<std::string> autors = {"Autor1", "Autor2"};
    auto n1 = std::make_shared<Naukowa>("Wydawnictwo1", "Polski", "Tytuł1", autors, "Recenzja1", "Dział1");
    zarzadca.dodajWolumin(n1);
    BOOST_CHECK_EQUAL(zarzadca.znajdzWszystkieWoluminy().size(), 1);

    zarzadca.usunWolumin(n1);
    BOOST_CHECK_EQUAL(zarzadca.znajdzWszystkieWoluminy().size(), 0);

}

BOOST_AUTO_TEST_CASE(ZnajdzWoluminyTest)
{
    Zarzadca_Woluminu zarzadca;
    std::vector<std::string> autors = {"Autor1", "Autor2"};
    auto n1 = std::make_shared<Naukowa>("Wydawnictwo1", "Polski", "Tytuł1", autors, "Recenzja1", "Dział1");
    auto n2 = std::make_shared<Naukowa>("Wydawnictwo2", "Polski", "Tytuł2", autors, "Recenzj2", "Dział2");

    zarzadca.dodajWolumin(n1);
    zarzadca.dodajWolumin(n2);

    auto wynik = zarzadca.znajdzWoluminy([](const WoluminPtr& w) { return true; });
    BOOST_CHECK_EQUAL(wynik.size(), 2);
    std::string specificPublisher = "Wydawnictwo1";
    std::vector<std::string> authors2 = {"Autor3", "Autor4"};
    auto wolumin2 = std::make_shared<Naukowa>("Wydawnictwo2", "Angielski", "Tytuł2", authors2, "Recenzja2", "Dział2");
    zarzadca.dodajWolumin(wolumin2);

    auto foundVolumes = zarzadca.znajdzWoluminy([specificPublisher](const WoluminPtr& w) {
        return w->getWydawnictwo() == specificPublisher;
    });

    BOOST_REQUIRE_EQUAL(foundVolumes.size(), 1);
    BOOST_CHECK_EQUAL(foundVolumes[0]->getWydawnictwo(), specificPublisher);
}
BOOST_AUTO_TEST_CASE(ExceptionTest)
{
    Zarzadca_Woluminu zarzadca;
    BOOST_CHECK_THROW(zarzadca.dodajWolumin(nullptr), RepozytoriumException);
    BOOST_CHECK_THROW(zarzadca.usunWolumin(nullptr), RepozytoriumException);
}


