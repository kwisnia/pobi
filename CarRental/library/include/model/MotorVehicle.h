//
// Created by student on 25.04.2020.
//

#ifndef CARRENTAL_MOTORVEHICLE_H
#define CARRENTAL_MOTORVEHICLE_H


#include "model/Vehicle.h"

class MotorVehicle : public Vehicle {
protected:
    unsigned int engineDisplacement;
    unsigned int ActualRentalPrice();
public:
    virtual ~MotorVehicle() = 0;

    MotorVehicle(const std::string &plateNumber, const unsigned int &basePrice, unsigned int engineDisplacement);

    unsigned int getEngineDisplacement() const;

    void setEngineDisplacement(unsigned int engineDisplacement);
};


#endif //CARRENTAL_MOTORVEHICLE_H
