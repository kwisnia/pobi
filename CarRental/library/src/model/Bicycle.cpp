//
// Created by student on 25.04.2020.
//

#include "model/Bicycle.h"

unsigned int Bicycle::getActualRentalPrice() {
    return basePrice;
}

Bicycle::Bicycle(const std::string &plateNumber, const unsigned int &basePrice) : Vehicle(plateNumber, basePrice) {}

Bicycle::~Bicycle() {

}
