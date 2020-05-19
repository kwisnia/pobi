//
// Created by student on 29.04.2020.
//
#include <boost/test/unit_test.hpp>
#include "utils.h"
struct Manager{
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

    Manager(){
        testAddress=std::make_shared<Address>("Luzik","Fiku","69");
        testClient=std::make_shared<Client>(testFirstName,testLastName,testPersonalID,testAddress);
        testCar=std::make_shared<Car>(testPlateNumber,testBasePrice,400,Car::B);
    }
    ~Manager()
    {
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteManager,Manager)

    BOOST_AUTO_TEST_CASE(RepoConstructorTest)
    {
        ClientManagerPtr testCM(new ClientManager());
        VehicleManagerPtr testVM(new VehicleManager());
        RentManagerPtr testRM(new RentManager());
        fillRepos(testCM,testVM,testRM);
        RentPtr test=testRM->findCurrent([](RentPtr r){return r->getClient()->getFirstName()=="Antoni";});
        BOOST_TEST_CHECK(test->getClient()->getFirstName()=="Antoni");
    }
    BOOST_AUTO_TEST_CASE(RepoFindAllTest) {
        ClientManagerPtr testCM(new ClientManager());
        VehicleManagerPtr testVM(new VehicleManager());
        RentManagerPtr testRM(new RentManager());
        fillRepos(testCM,testVM,testRM);
        FirstNamePredicate check(checkedFirstName);
        std::list<ClientPtr> found = testCM->findAll(check);
        BOOST_TEST_CHECK(found.front()->getLastName() == "Karwowski");
        auto i=std::next(found.begin(), 1);
        BOOST_TEST_CHECK((*i)->getLastName()=="Dygasinski");
    }
    BOOST_AUTO_TEST_CASE(RepoFindTest)
    {
        ClientManagerPtr testCM(new ClientManager());
        VehicleManagerPtr testVM(new VehicleManager());
        RentManagerPtr testRM(new RentManager());
        fillRepos(testCM,testVM,testRM);
        FirstNamePredicate check(checkedFirstName);
        BOOST_TEST_CHECK(testCM->find(check)->getFirstName()==checkedFirstName);
    }
    BOOST_AUTO_TEST_CASE(RepoReportTest)
    {
        ClientManagerPtr testCM(new ClientManager());
        testCM->registerClient(testFirstName,testLastName,testPersonalID,testAddress);
        BOOST_TEST_CHECK(testCM->report()==testClient->getClientInfo()+"\n");
    }
    BOOST_AUTO_TEST_CASE(RegisterNewClientTest)
    {
        ClientManagerPtr testCM(new ClientManager());
        BOOST_TEST_CHECK(testCM->registerClient(testFirstName,testLastName,testPersonalID,testAddress)->getClientInfo()==testClient->getClientInfo());
        BOOST_TEST_CHECK(testCM->RepoSize()==1);
    }
    BOOST_AUTO_TEST_CASE(RegisterExistingClientTest)
    {
        ClientManagerPtr testCM(new ClientManager());
        testCM->registerClient(testFirstName,testLastName,testPersonalID,testAddress);
        FirstNamePredicate check(testFirstName);
        BOOST_TEST_CHECK(testCM->registerClient(testFirstName,testLastName,testPersonalID,testAddress)==(testCM->find(check)));
        BOOST_TEST_CHECK(testCM->RepoSize()==1);
    }
    BOOST_AUTO_TEST_CASE(RegisterNullAddressTest)
    {
        ClientManagerPtr testCM(new ClientManager());
        BOOST_TEST_CHECK(testCM->registerClient(testFirstName,testLastName,testPersonalID,nullptr)==nullptr);
    }
    BOOST_AUTO_TEST_CASE(UnregisterClientTest)
    {
        ClientManagerPtr testCM(new ClientManager());
        ClientPtr newClient=testCM->registerClient(testFirstName,testLastName,testPersonalID,testAddress);
        testCM->unregisterClient(newClient);
        BOOST_TEST_CHECK(newClient->isArchive1());
    }
    BOOST_AUTO_TEST_CASE(RegisterBicycleTest)
    {
        VehicleManagerPtr testVM(new VehicleManager());
        BOOST_TEST_CHECK(testVM->registerBicycle(testPlateNumber,testBasePrice)->getPlateNumber()==testPlateNumber);
        BOOST_TEST_CHECK(testVM->RepoSize()==1);
    }
    BOOST_AUTO_TEST_CASE(RegisterMopedTest)
    {
        VehicleManagerPtr testVM(new VehicleManager());
        BOOST_TEST_CHECK(testVM->registerMoped(testPlateNumber,testBasePrice,400)->getPlateNumber()==testPlateNumber);
        BOOST_TEST_CHECK(testVM->RepoSize()==1);
    }
    BOOST_AUTO_TEST_CASE(RegisterCarTest)
    {
        VehicleManagerPtr testVM(new VehicleManager());
        BOOST_TEST_CHECK(testVM->registerCar(testPlateNumber,testBasePrice,400,Car::B)->getPlateNumber()==testPlateNumber);
        BOOST_TEST_CHECK(testVM->RepoSize()==1);
    }
    BOOST_AUTO_TEST_CASE(RegisterVehicleNegativeTest)
    {
        VehicleManagerPtr testVM(new VehicleManager());
        testVM->registerBicycle(testPlateNumber,testBasePrice);
        BOOST_TEST_CHECK(testVM->registerBicycle(testPlateNumber,testBasePrice)==nullptr);
        BOOST_TEST_CHECK(testVM->RepoSize()==1);
    }
    BOOST_AUTO_TEST_CASE(UnregisterVehicleTest)
    {
        VehicleManagerPtr testVM(new VehicleManager());
        VehiclePtr newVehicle=testVM->registerBicycle(testPlateNumber,testBasePrice);
        testVM->unregisterVehicle(newVehicle);
        BOOST_TEST_CHECK(newVehicle->isArchive1());
    }
    BOOST_AUTO_TEST_CASE(RentVehiclePositiveTest)
    {
        RentManagerPtr testRM(new RentManager());
        BOOST_TEST_CHECK(testRM->rentVehicle(testClient,testCar,testDefaultTime)->getClient()==testClient);
        BOOST_TEST_CHECK(testRM->currentRepoSize()==1);
    }
    BOOST_AUTO_TEST_CASE(RentVehicleOverTheMaxTest)
    {
        RentManagerPtr testRM(new RentManager());
        VehiclePtr newBicycle(new Bicycle("JPMWZK",20));
        testRM->rentVehicle(testClient,testCar,testDefaultTime);
        BOOST_TEST_CHECK(testRM->rentVehicle(testClient,newBicycle,testDefaultTime)==nullptr);
        BOOST_TEST_CHECK(testRM->currentRepoSize()==1);
        BOOST_TEST_CHECK(testRM->getAllClientRents(testClient).size()==1);
    }
    BOOST_AUTO_TEST_CASE(RentVehicleAlreadyRentedTest)
    {
        RentManagerPtr testRM(new RentManager());
        ClientManagerPtr testCM(new ClientManager());
        ClientPtr newClient(new Client("Jaina","Proudmoore","23323",testAddress));
        testRM->rentVehicle(testClient,testCar,testDefaultTime);
        BOOST_TEST_CHECK(testRM->rentVehicle(newClient,testCar,testDefaultTime)==nullptr);
    }
    BOOST_AUTO_TEST_CASE(ReturnVehicleBasicTest)
    {
        RentManagerPtr testRM(new RentManager());
        testRM->rentVehicle(testClient,testCar,testDefaultTime);
        testRM->returnVehicle(testCar);
        BOOST_TEST_CHECK(testRM->archiveRepoSize()==1);
        BOOST_TEST_CHECK(testRM->currentRepoSize()==0);
    }
    BOOST_AUTO_TEST_CASE(ReturnVehicleTypeChangeTest)
    {
        RentManagerPtr testRM(new RentManager());
        pt::ptime preminute = pt::ptime(gr::date(2020, 4, 17), pt::hours(9) + pt::minutes(25) + pt::seconds(40));
        testRM->rentVehicle(testClient,testCar,preminute);
        testRM->returnVehicle(testCar);
        BOOST_TEST_CHECK(testClient->getMaxVehicles()==2);
    }
    BOOST_AUTO_TEST_CASE(MultipleVehiclesBalanceCheckTest)
    {
        RentManagerPtr testRM(new RentManager());
        ClientTypePtr bronze(new Bronze());
        testClient->setClientType(bronze);
        VehiclePtr newBicycle2(new Bicycle("JPMWZK1",50));
        VehiclePtr newBicycle3(new Bicycle("JPMWZK2",40));
        pt::ptime preminute = pt::ptime(gr::date(2020, 5, 16), pt::hours(9) + pt::minutes(25) + pt::seconds(40));
        testRM->rentVehicle(testClient,newBicycle2,preminute);
        testRM->rentVehicle(testClient,newBicycle3,preminute);
        testRM->returnVehicle(newBicycle2);
        testRM->returnVehicle(newBicycle3);
        BOOST_TEST_CHECK(testClient->getMaxVehicles()==3);
    }
    BOOST_AUTO_TEST_CASE(GetAllClientRentsTest)
    {
        RentManagerPtr testRM(new RentManager());
        ClientTypePtr gold(new Gold());
        testClient->setClientType(gold);
        VehiclePtr newBicycle2(new Bicycle("JPMWZK1",50));
        VehiclePtr newBicycle3(new Bicycle("JPMWZK2",40));
        pt::ptime preminute = pt::ptime(gr::date(2020, 5, 5), pt::hours(9) + pt::minutes(25) + pt::seconds(40));
        RentPtr rent1=testRM->rentVehicle(testClient,newBicycle2,preminute);
        RentPtr rent2=testRM->rentVehicle(testClient,newBicycle3,preminute);
        testRM->returnVehicle(newBicycle2);
        std::list<RentPtr> testResult=testRM->getAllClientRents(testClient);
        BOOST_TEST_CHECK(testResult.front()==rent2);
        BOOST_TEST_CHECK(testResult.back()==rent1);
        BOOST_TEST_CHECK(testResult.size()==2);
    }
BOOST_AUTO_TEST_SUITE_END()
