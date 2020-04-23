//
// Created by student on 18.04.2020.
//
#include <boost/test/unit_test.hpp>
#include "model/Vehicle.h"
struct F{
    const std::string testPlateNumber="KLW69";
    const std::string newPlateNumber="WKW12";
    const unsigned int testBasePrice=300;
    const unsigned int newBasePrice=400;
    F(){}
    ~F(){}
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicle,F)



    BOOST_AUTO_TEST_CASE(VehicleConstructorTest) {
        Vehicle mclaren(testPlateNumber,testBasePrice);
        BOOST_TEST_CHECK(mclaren.getBasePrice()==testBasePrice);
        BOOST_TEST_CHECK(mclaren.getPlateNumber()==testPlateNumber);
        BOOST_TEST_CHECK(!mclaren.isRented());
    }
    BOOST_AUTO_TEST_CASE(SetBasePriceTest)
    {
        Vehicle mclaren(testPlateNumber,testBasePrice);
        mclaren.setBasePrice(newBasePrice);
        BOOST_TEST_CHECK(mclaren.getBasePrice()==newBasePrice);
    }
    BOOST_AUTO_TEST_CASE(SetPlateNumberPositiveTest)
    {
        Vehicle mclaren(testPlateNumber,testBasePrice);
        mclaren.setPlateNumber(newPlateNumber);
        BOOST_TEST_CHECK(mclaren.getPlateNumber()==newPlateNumber);
    }
    BOOST_AUTO_TEST_CASE(SetPlateNumberNegativeTest)
    {
        Vehicle mclaren(testPlateNumber,testBasePrice);
        mclaren.setPlateNumber("");
        BOOST_TEST_CHECK(mclaren.getPlateNumber()==testPlateNumber);
    }
BOOST_AUTO_TEST_SUITE_END()
