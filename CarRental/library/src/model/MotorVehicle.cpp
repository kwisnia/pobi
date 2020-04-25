//
// Created by student on 25.04.2020.
//

#include "model/MotorVehicle.h"

unsigned int MotorVehicle::ActualRentalPrice() {
if (engineDisplacement<1000)
    return basePrice;
else if (engineDisplacement>=1000 and engineDisplacement<=2000)
    return (0.0005*engineDisplacement+0.5)*basePrice;
else
    return 1.5*basePrice;
}
MotorVehicle::~MotorVehicle() {}

MotorVehicle::MotorVehicle(const std::string &plateNumber, const unsigned int &basePrice,
                           unsigned int engineDisplacement) : Vehicle(plateNumber, basePrice),
                                                              engineDisplacement(engineDisplacement) {}

unsigned int MotorVehicle::getEngineDisplacement() const {
    return engineDisplacement;
}

void MotorVehicle::setEngineDisplacement(unsigned int engineDisplacement) {
    MotorVehicle::engineDisplacement = engineDisplacement;
}

