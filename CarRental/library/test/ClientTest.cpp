//
// Created by student on 05.04.2020.
//

#include <boost/test/unit_test.hpp>
#include "model/Client.h"
BOOST_AUTO_TEST_SUITE(TestSuiteClient)
    Client klient("Kuba","Wrzesien","223913");

    BOOST_AUTO_TEST_CASE(ClientGetTest) {
        BOOST_TEST(klient.getfirstName()=="Kuba");
        BOOST_TEST(klient.getlastName()=="Wrzesien");
        BOOST_TEST(klient.getpersonalID()=="223913");
    }
    BOOST_AUTO_TEST_CASE(ClientSetTest) {
        klient.setfirstName("Marta");
        BOOST_TEST(klient.getfirstName()=="Marta");
        klient.setfirstName("");
        BOOST_TEST(klient.getfirstName()=="Marta");
    }
BOOST_AUTO_TEST_SUITE_END()