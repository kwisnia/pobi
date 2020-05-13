//
// Created by student on 13.05.2020.
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

BOOST_FIXTURE_TEST_SUITE(TestSuiteManager,Repos)

    BOOST_AUTO_TEST_CASE(RepositoriesAddTest){
        ClientRepoPtr CR(new ClientRepository());
        CR->add(testClient);
        BOOST_TEST_CHECK(CR->RepoSize()==1);
    }
    BOOST_AUTO_TEST_CASE(RepositoriesBeginEndListTest){
        VehicleRepoPtr VR(new VehicleRepository());
        VR->add(testCar);
        BOOST_TEST_CHECK((*VR->begin())==testCar);
    }
BOOST_AUTO_TEST_SUITE_END()
