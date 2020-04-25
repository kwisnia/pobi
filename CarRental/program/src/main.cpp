//
// Created by student on 05.04.2020.
//
#include <iostream>
#include "model/Client.h"
#include <boost/date_time.hpp>
#include "model/Rent.h"
#include "model/Bicycle.h"
#include "model/Car.h"
#include "model/Moped.h"
using namespace std;
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;
int main()
{
    Bicycle* d=new Bicycle("30",90);
    //cout << d->getPlateNumber();
    //cout << d->getActualRentalPrice();
    Car* bemka=new Car("40",870,1450,Car::C);
    cout << bemka->getActualRentalPrice()<<endl;
    Moped* wrum= new Moped("wii", 300,2500);
    cout << wrum->getActualRentalPrice();

    return 0;
}
