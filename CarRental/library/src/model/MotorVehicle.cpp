//
// Created by student on 25.04.2020.
//

#include "model/MotorVehicle.h"
using namespace std;
unsigned int MotorVehicle::getActualRentalPrice() {
if (engineDisplacement<1000)
    return basePrice;
else if (engineDisplacement>=1000 and engineDisplacement<=2000)
    return (0.0005*engineDisplacement+0.5)*basePrice;
else
    return 1.5*basePrice;
}
MotorVehicle::~MotorVehicle() {}

MotorVehicle::MotorVehicle(const string &plateNumber, const unsigned int &basePrice,
                           unsigned int engineDisplacement) : Vehicle(plateNumber, basePrice),
                                                              engineDisplacement(engineDisplacement) {}

unsigned int MotorVehicle::getEngineDisplacement() const {
    return engineDisplacement;
}

void MotorVehicle::setEngineDisplacement(unsigned int engineDisplacement) {
    MotorVehicle::engineDisplacement = engineDisplacement;
}
std::string MotorVehicle::getVehicleInfo() {
    ostringstream out;
    out << Vehicle::getVehicleInfo()<<"Pojemnosc silnika: "<<engineDisplacement<<" cm3"<<endl;
    return out.str();
}
