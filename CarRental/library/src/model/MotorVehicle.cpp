//
// Created by student on 25.04.2020.
//

#include "model/MotorVehicle.h"
using namespace std;
unsigned int MotorVehicle::getActualRentalPrice() {
if (engineDisplacement<1000)
    return getBasePrice();
else if (engineDisplacement>=1000 and engineDisplacement<=2000)
    return (0.0005*engineDisplacement+0.5)*getBasePrice();
else
    return 1.5*getBasePrice();
}
MotorVehicle::~MotorVehicle() {}

MotorVehicle::MotorVehicle(const string &plateNumber, const int &basePrice,
                           const int engineDisplacement) try : Vehicle(plateNumber, basePrice),
                                                              engineDisplacement(engineDisplacement) {
    if (this->engineDisplacement<0)
        throw VehicleException("Pojemnosc silnika nie moze byc ujemna!");
}
catch (VehicleException& ex)
{
    cout << "Wystapil blad!"<<endl;
    cout<<ex.what()<<endl;
}

unsigned int MotorVehicle::getEngineDisplacement() const {
    return engineDisplacement;
}

void MotorVehicle::setEngineDisplacement(int engineDisplacement) {
    try{
        if (basePrice<0)
            throw VehicleException("Podana pojemnosc silnika jest ujemna!");
        else
            MotorVehicle::engineDisplacement = engineDisplacement;}
    catch (const VehicleException& ex) {
        cout << "Wystapil problem: "<<endl;
        cout << ex.what()<<endl;
        throw;
    }
}
std::string MotorVehicle::getVehicleInfo() {
    ostringstream out;
    out << Vehicle::getVehicleInfo()<<"Pojemnosc silnika: "<<engineDisplacement<<" cm3"<<endl;
    return out.str();
}
