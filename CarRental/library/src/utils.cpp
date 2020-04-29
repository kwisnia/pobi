//
// Created by student on 29.04.2020.
//
#include "utils.h"
using namespace std;
void fillRepos(ClientRepository* CR, VehicleRepository* VR, RentRepository* RR){
    Address* a=new Address("Boralus","Proudmoore","23");
    Address* a1=new Address("Aleksandrow","Piracka","15");
    Client* c=new Client("Antoni","Karwowski","131431",a);
    Client* c1=new Client("Bartek","Dygasinski","2300913",a1);
    Car* mclaren=new Car("ELW9132", 500, 8000, Car::E);
    Bicycle* bmx=new Bicycle("bleee", 20);
    pt::ptime testDefaultTime = pt::not_a_date_time;
    Rent* r=new Rent(1,c,mclaren,testDefaultTime);
    Rent* r1=new Rent(2,c1,bmx,testDefaultTime);
    CR->add(c);
    CR->add(c1);
    VR->add(mclaren);
    VR->add(bmx);
    RR->add(r);
    RR->add(r1);
};