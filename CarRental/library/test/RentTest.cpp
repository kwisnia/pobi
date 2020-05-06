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
    ClientPtr testClient;
    VehiclePtr testCar;
    AddressPtr testaddress;

    R() {
        testaddress = std::make_shared<Address>("Teges", "Szmeges", "Fafafa");
        testClient = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress);
        testCar = std::make_shared<Bicycle>(testPlateNumber, testBasePrice);
    }

    ~R() {
    }
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, R)

    BOOST_AUTO_TEST_CASE(RentConstructorTestGivenBeginTime) {
        RentPtr r(new Rent(testID, testClient, testCar, testBeginTime));
        BOOST_TEST_REQUIRE(r->getClient() == testClient);
        BOOST_TEST_CHECK(r->getId() == testID);
        BOOST_TEST_REQUIRE(r->getVehicle() == testCar);
        BOOST_TEST_CHECK(r->getBeginTime() == testBeginTime);
        BOOST_TEST_CHECK(r->getEndTime() == pt::not_a_date_time);
    }

    BOOST_AUTO_TEST_CASE(RentConstructorTestGivenDefaultTime) {
        RentPtr r(new Rent(testID, testClient, testCar, testDefaultTime));
        BOOST_TEST_REQUIRE(!r->getBeginTime().is_not_a_date_time());
        pt::time_period skew = pt::time_period(r->getBeginTime(), testCurrentTime);
        BOOST_TEST_CHECK((skew.length().hours() == 0 && skew.length().minutes() == 0));
    }

    BOOST_AUTO_TEST_CASE(EndRentTestSetCurrentTime) {
        RentPtr r(new Rent(testID, testClient, testCar, testBeginTime));
        r->endRent(testDefaultTime);
        RentPtr r2(new Rent(testID, testClient, testCar, testBeginTime));
        r2->endRent(testCurrentTime);
        BOOST_TEST_CHECK(r->getEndTime() == testCurrentTime);
        BOOST_TEST_CHECK(r2->getEndTime() == testCurrentTime);

    }

    BOOST_AUTO_TEST_CASE(EndRentTestSetGivenEndTimeAfterBeginTime) {
        RentPtr r(new Rent(testID, testClient, testCar, testBeginTime));
        r->endRent(testEndTime);
        BOOST_TEST_CHECK(r->getEndTime() == testEndTime);
    }

    BOOST_AUTO_TEST_CASE(EndRentTestSetGivenEndTimeEqualsBeginTime) {
        RentPtr r(new Rent(testID, testClient, testCar, testBeginTime));
        r->endRent(testBeginTime);
        BOOST_TEST_CHECK(r->getEndTime() == testBeginTime);
    }

    BOOST_AUTO_TEST_CASE(EndRentTestSetGivenEndTimeBeforeBeginTime) {
        RentPtr r(new Rent(testID, testClient, testCar, testEndTime));
        r->endRent(testBeginTime);
        BOOST_TEST_CHECK(r->getEndTime() == testEndTime);
    }

    BOOST_AUTO_TEST_CASE(RentDaysTestRentNotEnded) {
        RentPtr r(new Rent(testID, testClient, testCar, testBeginTime));
        BOOST_TEST_CHECK(r->getRentDays() == 0);
    }

    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedWithinMinute) {
        RentPtr r(new Rent(testID, testClient, testCar, testBeginTime));
        pt::ptime preminute = pt::ptime(gr::date(2020, 4, 17), pt::hours(9) + pt::minutes(25) + pt::seconds(40));
        r->endRent(preminute);
        BOOST_TEST_CHECK(r->getRentDays() == 0);
    }

    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter1m) {
        RentPtr r(new Rent(testID, testClient, testCar, testBeginTime));
        pt::ptime minute = pt::ptime(gr::date(2020, 4, 17), pt::hours(9) + pt::minutes(26));
        r->endRent(minute);
        BOOST_TEST_CHECK(r->getRentDays() == 1);
    }

    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter23h59m) {
        RentPtr r(new Rent(testID, testClient, testCar, testBeginTime));
        pt::ptime notquiteaday = pt::ptime(gr::date(2020, 4, 18), pt::hours(9) + pt::minutes(24));
        r->endRent(notquiteaday);
        BOOST_TEST_CHECK(r->getRentDays() == 1);
    }

    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter24h0m) {
        RentPtr r(new Rent(testID, testClient, testCar, testBeginTime));
        pt::ptime aday = pt::ptime(gr::date(2020, 4, 18), pt::hours(9) + pt::minutes(25));
        r->endRent(aday);
        BOOST_TEST_CHECK(r->getRentDays() == 2);
    }

    BOOST_AUTO_TEST_CASE(RentDaysTestRentTryEndRentAlreadyEnded) {
        RentPtr r(new Rent(testID, testClient, testCar, testBeginTime));
        r->endRent(testEndTime);
        int temp = r->getRentDays();
        r->endRent(testDefaultTime);
        BOOST_TEST_CHECK(r->getRentDays() == temp);
    }

    BOOST_AUTO_TEST_CASE(RentCostTestRentDaysIs0) {
        RentPtr r(new Rent(testID, testClient, testCar, testBeginTime));
        r->endRent(testBeginTime);
        BOOST_TEST_CHECK(r->getRentCost() == 0);
    }

    BOOST_AUTO_TEST_CASE(RentCostTestRentDaysIsPositive) {
        RentPtr r(new Rent(testID, testClient, testCar, testBeginTime));
        r->endRent(testEndTime);
        BOOST_TEST_CHECK(r->getRentCost() == 90);
    }

    BOOST_AUTO_TEST_CASE(RentCostTestRentCostIsPermanentWhenVehiclePriceChanged) {
        RentPtr r(new Rent(testID, testClient, testCar, testBeginTime));
        r->endRent(testEndTime);
        testCar->setBasePrice(100);
        BOOST_TEST_CHECK(r->getRentCost() == 90);
    }

BOOST_AUTO_TEST_SUITE_END()