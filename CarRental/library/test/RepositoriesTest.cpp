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
    const unsigned int testBasePrice = 100;
    pt::ptime testDefaultTime = pt::not_a_date_time;
    Client *testClient;
    Car *testCar;
    Address *testAddress;

    Repos(){
        testAddress=new Address("Luzik","Fiku","69");
        testClient=new Client (testFirstName,testLastName,testPersonalID,testAddress);
        testCar=new Car (testPlateNumber,testBasePrice,400,Car::B);
    }
    ~Repos()
    {
        delete testAddress;
    }

};
typedef bool (*RentPredicate)(clientptr);
bool checkFirstName(clientptr c)
{
    return (c->getFirstName()=="Antoni");
}
BOOST_FIXTURE_TEST_SUITE(TestSuiteRepos,Repos)

    BOOST_AUTO_TEST_CASE(RepoGetTest)
    {
        unsigned int testint=1;
        ClientRepository* testCR=new ClientRepository();
        VehicleRepository* testVR=new VehicleRepository();
        RentRepository* testRR=new RentRepository();
        fillRepos(testCR,testVR,testRR);
        rentptr test=testRR->get(testint);
        BOOST_TEST_CHECK(test->getClient()->getFirstName()=="Antoni");
        delete testCR;
        delete testVR;
        delete testRR;
    }
    BOOST_AUTO_TEST_CASE(RepoFindTest)
    {
        ClientRepository* testCR=new ClientRepository();
        VehicleRepository* testVR=new VehicleRepository();
        RentRepository* testRR=new RentRepository();
        fillRepos(testCR,testVR,testRR);
        RentPredicate test=checkFirstName;
        std::list<clientptr> found=testCR->find(test);
        BOOST_TEST_CHECK(found.front()->getFirstName()=="Antoni");
        delete testCR;
        delete testVR;
        delete testRR;
    }
    BOOST_AUTO_TEST_CASE(RepoAddTest)
    {
        ClientRepository* testCR=new ClientRepository();
        unsigned int testint=1;
        testCR->add(testClient);
        BOOST_TEST_CHECK(testCR->get(testint)->getFirstName()=="Mikolaj");
        delete testCR;
    }
    BOOST_AUTO_TEST_CASE(RepoReportTest)
    {
        ClientRepository* testCR=new ClientRepository();
        testCR->add(testClient);
        BOOST_TEST_CHECK(testCR->report()==testClient->getClientInfo()+"\n");
        delete testCR;
    }
BOOST_AUTO_TEST_SUITE_END()