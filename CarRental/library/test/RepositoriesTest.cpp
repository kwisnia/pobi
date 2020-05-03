//
// Created by student on 29.04.2020.
//
#include <boost/test/unit_test.hpp>
#include "utils.h"
struct Repos{
    const std::string testFirstName = "Mikolaj";
    const std::string testLastName = "Kotkowski";
    const std::string testPersonalID = "23132132";
    const std::string testPlateNumber = "149123";
    const std::string checkedFirstName = "Antoni";
    const unsigned int testBasePrice = 100;
    pt::ptime testDefaultTime = pt::not_a_date_time;
    ClientPtr testClient;
    VehiclePtr testCar;
    AddressPtr testAddress;

    Repos(){
        testAddress=std::make_shared<Address>("Luzik","Fiku","69");
        testClient=std::make_shared<Client>(testFirstName,testLastName,testPersonalID,testAddress);
        testCar=std::make_shared<Car>(testPlateNumber,testBasePrice,400,Car::B);
    }
    ~Repos()
    {
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRepos,Repos)

    BOOST_AUTO_TEST_CASE(RepoGetTest)
    {
        unsigned int testint=1;
        ClientRepoPtr testCR(new ClientRepository());
        VehicleRepoPtr testVR(new VehicleRepository());
        RentRepoPtr testRR(new RentRepository());
        fillRepos(testCR,testVR,testRR);
        RentPtr test=testRR->get(testint);
        BOOST_TEST_CHECK(test->getClient()->getFirstName()=="Antoni");
    }
    BOOST_AUTO_TEST_CASE(RepoFindAllTest) {
        ClientRepoPtr testCR(new ClientRepository());
        VehicleRepoPtr testVR(new VehicleRepository());
        RentRepoPtr testRR(new RentRepository());
        fillRepos(testCR, testVR, testRR);
        std::list<ClientPtr> found = testCR->findAll([this](ClientPtr c) { return c->getFirstName() == checkedFirstName;});
        BOOST_TEST_CHECK(found.front()->getLastName() == "Karwowski");
        auto i=std::next(found.begin(), 1);
        BOOST_TEST_CHECK((*i)->getLastName()=="Dygasinski");
    }
    BOOST_AUTO_TEST_CASE(RepoFindTest)
    {
        ClientRepoPtr testCR(new ClientRepository());
        VehicleRepoPtr testVR(new VehicleRepository());
        RentRepoPtr testRR(new RentRepository());
        fillRepos(testCR,testVR,testRR);
        BOOST_TEST_CHECK(testCR->find([this](ClientPtr c) {return c->getFirstName()==checkedFirstName;})->getFirstName()==checkedFirstName);
    }
    BOOST_AUTO_TEST_CASE(RepoAddTest)
    {
        ClientRepoPtr testCR(new ClientRepository());
        unsigned int testint=1;
        testCR->add(testClient);
        BOOST_TEST_CHECK(testCR->get(testint)->getFirstName()=="Mikolaj");
    }
    BOOST_AUTO_TEST_CASE(RepoReportTest)
    {
        ClientRepoPtr testCR(new ClientRepository());
        testCR->add(testClient);
        BOOST_TEST_CHECK(testCR->report()==testClient->getClientInfo()+"\n");
    }
BOOST_AUTO_TEST_SUITE_END()