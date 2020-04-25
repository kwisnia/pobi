//
// Created by student on 05.04.2020.
//

#include <boost/test/unit_test.hpp>
#include "model/Client.h"
struct C {
    const std::string testFirstName = "Michal";
    const std::string testLastName = "Milowicz";
    const std::string testPersonalID = "0123456789";
    const std::string noweImie = "Marta";
    Address *testaddress1;
    Address *testaddress2;

    C() {
        testaddress1 = new Address("Teges", "Szmeges", "Fafafa");
        testaddress2 = new Address("Gameming", "Pitus", "66");
    }

    ~C() {
        delete testaddress1;
        delete testaddress2;
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, C)
    BOOST_AUTO_TEST_CASE(ClientConstructorTest) {
        Client klient(testFirstName, testLastName, testPersonalID, testaddress1);
        BOOST_TEST_CHECK(klient.getFirstName()==testFirstName);
        BOOST_TEST_CHECK(klient.getLastName()==testLastName);
        BOOST_TEST_CHECK(klient.getPersonalId()==testPersonalID);
        BOOST_TEST_CHECK(klient.getAddress()==testaddress1);
        BOOST_TEST_CHECK(klient.getCurrentRents().empty());
    }
    BOOST_AUTO_TEST_CASE(SetFirstNamePositiveTest) {
        Client klient(testFirstName, testLastName, testPersonalID, testaddress1);
        klient.setFirstName(noweImie);
        BOOST_TEST_CHECK(klient.getFirstName()=="Marta");
    }
    BOOST_AUTO_TEST_CASE(SetFirstNameNegativeTest){
        Client klient(testFirstName, testLastName, testPersonalID, testaddress1);
        klient.setFirstName("");
        BOOST_TEST_CHECK(klient.getFirstName()=="Michal");
}
    BOOST_AUTO_TEST_CASE(SetLastNamePositiveTest){
        Client klient(testFirstName, testLastName, testPersonalID, testaddress1);
        klient.setLastName("Gebel");
        BOOST_TEST_CHECK(klient.getLastName()=="Gebel");

}
    BOOST_AUTO_TEST_CASE(SetLastNameNegativeTest){
        Client klient(testFirstName, testLastName, testPersonalID, testaddress1);
        klient.setLastName("");
        BOOST_TEST_CHECK(klient.getLastName()==testLastName);
}
    BOOST_AUTO_TEST_CASE(SetAddressPositiveTest){
        Client klient(testFirstName, testLastName, testPersonalID, testaddress1);
        klient.setAddress(testaddress2);
        BOOST_TEST_CHECK(klient.getAddress()==testaddress2);
}
    BOOST_AUTO_TEST_CASE(SetAddressNegativeTest){
        Client klient(testFirstName, testLastName, testPersonalID, testaddress1);
        klient.setAddress(nullptr);
        BOOST_TEST_CHECK(klient.getAddress()==testaddress1);

}
BOOST_AUTO_TEST_SUITE_END()