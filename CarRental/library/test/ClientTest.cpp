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
    AddressPtr testaddress1;
    AddressPtr testaddress2;

    C() {
        testaddress1=std::make_shared<Address>("Teges", "Szmeges", "Fafafa");
        testaddress2=std::make_shared<Address>("Gameming", "Pitus", "66");
    }

    ~C() {
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, C)
    BOOST_AUTO_TEST_CASE(ClientConstructorTest) {
        ClientPtr klient(new Client(testFirstName, testLastName, testPersonalID, testaddress1));
        BOOST_TEST_CHECK(klient->getFirstName()==testFirstName);
        BOOST_TEST_CHECK(klient->getLastName()==testLastName);
        BOOST_TEST_CHECK(klient->getPersonalId()==testPersonalID);
        BOOST_TEST_CHECK(klient->getAddress()==testaddress1);
    }
    BOOST_AUTO_TEST_CASE(SetFirstNamePositiveTest) {
        ClientPtr klient(new Client(testFirstName, testLastName, testPersonalID, testaddress1));
        klient->setFirstName(noweImie);
        BOOST_TEST_CHECK(klient->getFirstName()=="Marta");
    }
    BOOST_AUTO_TEST_CASE(SetFirstNameNegativeTest){
        ClientPtr klient(new Client(testFirstName, testLastName, testPersonalID, testaddress1));
        klient->setFirstName("");
        BOOST_TEST_CHECK(klient->getFirstName()=="Michal");
}
    BOOST_AUTO_TEST_CASE(SetLastNamePositiveTest){
        ClientPtr klient(new Client(testFirstName, testLastName, testPersonalID, testaddress1));
        klient->setLastName("Gebel");
        BOOST_TEST_CHECK(klient->getLastName()=="Gebel");

}
    BOOST_AUTO_TEST_CASE(SetLastNameNegativeTest){
        ClientPtr klient(new Client(testFirstName, testLastName, testPersonalID, testaddress1));
        klient->setLastName("");
        BOOST_TEST_CHECK(klient->getLastName()==testLastName);
}
    BOOST_AUTO_TEST_CASE(SetAddressPositiveTest){
        ClientPtr klient(new Client(testFirstName, testLastName, testPersonalID, testaddress1));
        klient->setAddress(testaddress2);
        BOOST_TEST_CHECK(klient->getAddress()==testaddress2);
}
    BOOST_AUTO_TEST_CASE(SetAddressNegativeTest){
        ClientPtr klient(new Client(testFirstName, testLastName, testPersonalID, testaddress1));
        klient->setAddress(nullptr);
        BOOST_TEST_CHECK(klient->getAddress()==testaddress1);

}
BOOST_AUTO_TEST_SUITE_END()