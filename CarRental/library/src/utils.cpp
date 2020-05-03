//
// Created by student on 29.04.2020.
//
#include "utils.h"
using namespace std;
void fillRepos(ClientRepoPtr CR, VehicleRepoPtr VR, RentRepoPtr RR){
    AddressPtr a(new Address("Boralus","Proudmoore","23"));
    AddressPtr a1(new Address("Aleksandrow","Piracka","15"));
    ClientPtr c(new Client("Antoni","Karwowski","131431",a));
    ClientPtr c1(new Client("Antoni","Dygasinski","2300913",a1));
    VehiclePtr mclaren(new Car("ELW9132", 500, 8000, Car::E));
    VehiclePtr bmx(new Bicycle("bleee", 20));
    pt::ptime testDefaultTime = pt::not_a_date_time;
    RentPtr r(new Rent(1,c,mclaren,testDefaultTime));
    RentPtr r1(new Rent(2,c1,bmx,testDefaultTime));
    CR->add(c);
    CR->add(c1);
    VR->add(mclaren);
    VR->add(bmx);
    RR->add(r);
    RR->add(r1);
};