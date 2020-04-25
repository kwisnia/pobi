//
// Created by student on 19.04.2020.
//
#include <boost/test/unit_test.hpp>
#include "model/Rent.h"
#include "model/Car.h"
#include "model/Moped.h"
#include "model/Bicycle.h"

struct R {
    const std::string testFirstName = "Piotr";
    const std::string testLastName = "Tomczak";
    const std::string testPersonalID = "0123456789";
    const std::string testPlateNumber = "2310";
    const unsigned int testBasePrice = 30;
    pt::ptime testBeginTime = pt::ptime(gr::date(2020, 4, 17), pt::hours(9) + pt::minutes(25));
    pt::ptime testEndTime = pt::ptime(gr::date(2020, 4, 19), pt::hours(9) + pt::minutes(25));
    pt::ptime testDefaultTime = pt::not_a_date_time;
    pt::ptime testCurrentTime = pt::second_clock::local_time();
    const unsigned int testID = 10;
    Client *testClient;
    Car *testCar;
    Address *testaddress;

    R() {
        testaddress = new Address("Teges", "Szmeges", "Fafafa");
        testClient = new Client(testFirstName, testLastName, testPersonalID, testaddress);
        testCar = new Car(testPlateNumber, testBasePrice, 1000, Car::B);
    }

    ~R() {
        delete testaddress;
        delete testClient;
        delete testCar;
    }
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, R)

    BOOST_AUTO_TEST_CASE(RentConstructorTestGivenBeginTime) {
        Rent *r = new Rent(testID, testClient, testCar, testBeginTime);
        BOOST_TEST_REQUIRE(r->getClient() == testClient);
        BOOST_TEST_CHECK(r == testClient->getCurrentRents()[0]);
        BOOST_TEST_CHECK(r->getId() == testID);
        BOOST_TEST_REQUIRE(r->getVehicle() == testCar);
        BOOST_TEST_CHECK(testCar->isRented());
        BOOST_TEST_CHECK(r->getBeginTime() == testBeginTime);
        BOOST_TEST_CHECK(r->getEndTime() == pt::not_a_date_time);
        delete r;
    }

    BOOST_AUTO_TEST_CASE(RentConstructorTestGivenDefaultTime) {
        Rent *r = new Rent(testID, testClient, testCar, testDefaultTime);
        BOOST_TEST_REQUIRE(!r->getBeginTime().is_not_a_date_time());
        pt::time_period skew = pt::time_period(r->getBeginTime(), testCurrentTime);
        BOOST_TEST((skew.length().hours() == 0 && skew.length().minutes() == 0));
        delete r;
    }

    BOOST_AUTO_TEST_CASE(EndRentBasicTest) {
        Rent *r = new Rent(testID, testClient, testCar, testBeginTime);
        r->endRent(testEndTime);
        BOOST_TEST_CHECK(!r->getVehicle()->isRented());
        BOOST_TEST_CHECK(&r != &testClient->getCurrentRents()[0]);
        delete r;
    }

    BOOST_AUTO_TEST_CASE(EndRentTestSetCurrentTime) {
        Rent *r = new Rent(testID, testClient, testCar, testBeginTime);
        r->endRent(testDefaultTime);
        Rent *r2 = new Rent(testID, testClient, testCar, testBeginTime);
        r2->endRent(testCurrentTime);
        BOOST_TEST_CHECK(r->getEndTime() == testCurrentTime);
        BOOST_TEST_CHECK(r2->getEndTime() == testCurrentTime);

        delete r;
        delete r2;
    }

    BOOST_AUTO_TEST_CASE(EndRentTestSetGivenEndTimeAfterBeginTime) {
        Rent *r = new Rent(testID, testClient, testCar, testBeginTime);
        r->endRent(testEndTime);
        BOOST_TEST_CHECK(r->getEndTime() == testEndTime);
        delete r;
    }

    BOOST_AUTO_TEST_CASE(EndRentTestSetGivenEndTimeEqualsBeginTime) {
        Rent *r = new Rent(testID, testClient, testCar, testBeginTime);
        r->endRent(testBeginTime);
        BOOST_TEST_CHECK(r->getEndTime() == testBeginTime);
        delete r;
    }

    BOOST_AUTO_TEST_CASE(EndRentTestSetGivenEndTimeBeforeBeginTime) {
        Rent *r = new Rent(testID, testClient, testCar, testEndTime);
        r->endRent(testBeginTime);
        BOOST_TEST_CHECK(r->getEndTime() == testEndTime);
        delete r;
    }

    BOOST_AUTO_TEST_CASE(RentDaysTestRentNotEnded) {
        Rent *r = new Rent(testID, testClient, testCar, testBeginTime);
        BOOST_TEST_CHECK(r->getRentDays() == 0);
        delete r;
    }

    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedWithinMinute) {
        Rent *r = new Rent(testID, testClient, testCar, testBeginTime);
        pt::ptime preminute = pt::ptime(gr::date(2020, 4, 17), pt::hours(9) + pt::minutes(25) + pt::seconds(40));
        r->endRent(preminute);
        BOOST_TEST_CHECK(r->getRentDays() == 0);
        delete r;
    }

    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter1m) {
        Rent *r = new Rent(testID, testClient, testCar, testBeginTime);
        pt::ptime minute = pt::ptime(gr::date(2020, 4, 17), pt::hours(9) + pt::minutes(26));
        r->endRent(minute);
        BOOST_TEST_CHECK(r->getRentDays() == 1);
        delete r;
    }

    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter23h59m) {
        Rent *r = new Rent(testID, testClient, testCar, testBeginTime);
        pt::ptime notquiteaday = pt::ptime(gr::date(2020, 4, 18), pt::hours(9) + pt::minutes(24));
        r->endRent(notquiteaday);
        BOOST_TEST_CHECK(r->getRentDays() == 1);
        delete r;
    }

    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter24h0m) {
        Rent *r = new Rent(testID, testClient, testCar, testBeginTime);
        pt::ptime aday = pt::ptime(gr::date(2020, 4, 18), pt::hours(9) + pt::minutes(25));
        r->endRent(aday);
        BOOST_TEST_CHECK(r->getRentDays() == 2);
        delete r;
    }

    BOOST_AUTO_TEST_CASE(RentDaysTestRentTryEndRentAlreadyEnded) {
        Rent *r = new Rent(testID, testClient, testCar, testBeginTime);
        r->endRent(testEndTime);
        int temp = r->getRentDays();
        r->endRent(testDefaultTime);
        BOOST_TEST_CHECK(r->getRentDays() == temp);
        delete r;
    }

    BOOST_AUTO_TEST_CASE(RentCostTestRentDaysIs0) {
        Rent *r = new Rent(testID, testClient, testCar, testBeginTime);
        r->endRent(testBeginTime);
        BOOST_TEST_CHECK(r->getRentCost() == 0);
        delete r;
    }

    BOOST_AUTO_TEST_CASE(RentCostTestRentDaysIsPositive) {
        Rent *r = new Rent(testID, testClient, testCar, testBeginTime);
        r->endRent(testEndTime);
        BOOST_TEST_CHECK(r->getRentCost() == 90);
        delete r;
    }

    BOOST_AUTO_TEST_CASE(RentCostTestRentCostIsPermanentWhenVehiclePriceChanged) {
        Rent *r = new Rent(testID, testClient, testCar, testBeginTime);
        r->endRent(testEndTime);
        testCar->setBasePrice(100);
        BOOST_TEST_CHECK(r->getRentCost() == 90);
        delete r;
    }

BOOST_AUTO_TEST_SUITE_END()