//
// Created by student on 25.04.2020.
//

#include "model/Moped.h"

Moped::Moped(const std::string &plateNumber, const unsigned int &basePrice, unsigned int engineDisplacement)
        : MotorVehicle(plateNumber, basePrice, engineDisplacement) {}

unsigned int Moped::getActualRentalPrice() {
    return ActualRentalPrice();
}

Moped::~Moped() {

}
