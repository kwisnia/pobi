//
// Created by student on 08.04.2020.
//
#include <boost/test/unit_test.hpp>
#include "model/Address.h"
BOOST_AUTO_TEST_SUITE(TestSuiteAddress)


    BOOST_AUTO_TEST_CASE(AddressConstructorTest) {
        AddressPtr adres(new Address("Koluszki","Brzezinska","69"));
        BOOST_TEST_CHECK(adres->getCity()=="Koluszki");
        BOOST_TEST_CHECK(adres->getStreet()=="Brzezinska");
        BOOST_TEST_CHECK(adres->getNumber()=="69");
    }
BOOST_AUTO_TEST_SUITE_END()
