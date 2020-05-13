//
// Created by student on 29.04.2020.
//
#include "utils.h"
using namespace std;
void fillRepos(ClientManagerPtr CM, VehicleManagerPtr VM, RentManagerPtr RM){
    AddressPtr a(new Address("Boralus","Proudmoore","23"));
    AddressPtr a1(new Address("Aleksandrow","Piracka","15"));
    CM->registerClient("Antoni","Karwowski","131431",a);
    CM->registerClient("Antoni","Dygasinski","2300913",a1);
    VM->registerCar("ELW9132", 500, 8000, Car::E);
    VM->registerBicycle("bleee", 20);
    pt::ptime testDefaultTime = pt::not_a_date_time;
    RM->rentVehicle(CM->getClient("131431"),VM->getVehicle("ELW9132"),testDefaultTime);
    RM->rentVehicle(CM->getClient("2300913"),VM->getVehicle("bleee"),testDefaultTime);
};