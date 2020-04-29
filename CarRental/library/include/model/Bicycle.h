//
// Created by student on 25.04.2020.
//

#ifndef CARRENTAL_BICYCLE_H
#define CARRENTAL_BICYCLE_H


#include "model/Vehicle.h"

class Bicycle : public Vehicle {
public:
    unsigned int getActualRentalPrice();

    virtual ~Bicycle();

    Bicycle(const std::string &plateNumber, const unsigned int &basePrice);
    std::string getVehicleInfo();
};


#endif //CARRENTAL_BICYCLE_H
