//
// Created by student on 05.04.2020.
//
#include <iostream>
#include "model/Client.h"
#include <boost/date_time.hpp>
#include "model/Rent.h"
using namespace std;
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;
int main()
{
    Address address("London","Queen","12");
    string fname1 = "Jon";
    Client c(fname1, "Arbuckle", "0123456789",&address);
    fname1.assign("Doc Boy");
    cout << c.getFirstName() << endl;

    string fname2 = "Garfield";
    c.setFirstName(fname2);
    fname2.assign("Liz");
    cout << c.getFirstName() << endl;
    Vehicle* bmw=new Vehicle("KMWTW",12);
    cout << bmw->getVehicleInfo()<<endl;
    //cout << c.getCurrentRents()<<endl;
    pt::ptime empty = pt::not_a_date_time;
    cout << empty << endl;
    pt::ptime now = pt::second_clock::local_time();
    cout << empty.is_not_a_date_time();
    cout << now << endl;
    pt::ptime then = pt::ptime(gr::date(2020,4,17),pt::hours(9)+pt::minutes(25));
    pt::ptime then2 = pt::ptime(gr::date(2020,4,17),pt::hours(12)+pt::minutes(25));
    cout << then << endl;
    pt::time_period period(then, then2);
    cout << period << endl;
    cout << period.length() << endl;
    cout << period.length().hours() << endl;
    cout << period.length().minutes() << endl;
    //cout << (then>now) << endl;
    //cout << (then<=now) << endl;
    Rent wypozyczonko(1, &c, bmw, then);
    wypozyczonko.endRent(now);
    //cout << wypozyczonko.getRentDays()<<endl;
    //cout << c.getFullClientInfo();


    return 0;

}
