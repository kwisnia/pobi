//
// Created by student on 18.04.2020.
//
#include <boost/test/unit_test.hpp>
#include "model/Car.h"
#include "model/Moped.h"
#include "model/Bicycle.h"
struct V{
    const std::string testPlateNumber="KLW69";
    const std::string newPlateNumber="WKW12";
    const unsigned int testBasePrice=300;
    const unsigned int newBasePrice=400;
    const unsigned int testEngineDisplacement=8000;
    const unsigned int newEngineDisplacement=4000;
    Car::segmentType testSegment=Car::A;
    V(){}
    ~V(){}
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicle,V)



    BOOST_AUTO_TEST_CASE(VehicleConstructorTest) {
        Car* mclaren=new Car(testPlateNumber,testBasePrice,testEngineDisplacement,testSegment);
        BOOST_TEST_CHECK(mclaren->getBasePrice()==testBasePrice);
        BOOST_TEST_CHECK(mclaren->getPlateNumber()==testPlateNumber);
        BOOST_TEST_CHECK(!mclaren->isRented());
        BOOST_TEST_CHECK(mclaren->getEngineDisplacement()==testEngineDisplacement);
        BOOST_TEST_CHECK(mclaren->getSegment()==testSegment);
        delete mclaren;
    }
    BOOST_AUTO_TEST_CASE(SetBasePriceTest)
    {
        Car* mclaren=new Car(testPlateNumber,testBasePrice,8000,Car::A);
        mclaren->setBasePrice(newBasePrice);
        BOOST_TEST_CHECK(mclaren->getBasePrice()==newBasePrice);
        delete mclaren;
    }
    BOOST_AUTO_TEST_CASE(SetEngineDisplacementTest)
    {
        Car* mclaren=new Car(testPlateNumber,testBasePrice,8000,Car::A);
        mclaren->setEngineDisplacement(newEngineDisplacement);
        BOOST_TEST_CHECK(mclaren->getEngineDisplacement()==newEngineDisplacement);
        delete mclaren;
    }
    BOOST_AUTO_TEST_CASE(SetPlateNumberPositiveTest)
    {
        Car* mclaren=new Car(testPlateNumber,testBasePrice,8000,Car::A);
        mclaren->setPlateNumber(newPlateNumber);
        BOOST_TEST_CHECK(mclaren->getPlateNumber()==newPlateNumber);
        delete mclaren;
    }
    BOOST_AUTO_TEST_CASE(SetPlateNumberNegativeTest)
    {
        Car* mclaren=new Car(testPlateNumber,testBasePrice,8000,Car::A);
        mclaren->setPlateNumber("");
        BOOST_TEST_CHECK(mclaren->getPlateNumber()==testPlateNumber);
        delete mclaren;
    }
    BOOST_AUTO_TEST_CASE(BicycleRentalPriceTest)
    {
        Bicycle* bmx=new Bicycle(testPlateNumber, testBasePrice);
        BOOST_TEST_CHECK(bmx->getActualRentalPrice()==testBasePrice);
        delete bmx;
    }
    BOOST_AUTO_TEST_CASE(MopedRentalPriceTest)
    {
        Moped* wrum= new Moped(testPlateNumber, testBasePrice,2500);
        BOOST_TEST_CHECK(wrum->getActualRentalPrice()==450);
        delete wrum;
    }
    BOOST_AUTO_TEST_CASE(CarRentalPriceTest)
    {
        Car* mclaren=new Car(testPlateNumber, testBasePrice, 8000, Car::E);
        BOOST_TEST_CHECK(mclaren->getActualRentalPrice()==675);
        delete mclaren;
    }
    BOOST_AUTO_TEST_CASE(CarRentalPriceInheritanceTest)
    {
        Vehicle* mclaren=new Car(testPlateNumber, testBasePrice, 8000, Car::E);
        BOOST_TEST_CHECK(mclaren->getActualRentalPrice()==675);
        delete mclaren;
    }
BOOST_AUTO_TEST_SUITE_END()
