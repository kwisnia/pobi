//
// Created by student on 25.04.2020.
//

#ifndef CARRENTAL_MOTORVEHICLE_H
#define CARRENTAL_MOTORVEHICLE_H


#include "model/Vehicle.h"

class MotorVehicle : public Vehicle {
private:
    unsigned int engineDisplacement;
public:
    unsigned int getActualRentalPrice();

    virtual ~MotorVehicle() = 0;

    MotorVehicle(const std::string &plateNumber, const int &basePrice, int engineDisplacement);

    unsigned int getEngineDisplacement() const;

    void setEngineDisplacement(int engineDisplacement);

    std::string getVehicleInfo();
};


#endif //CARRENTAL_MOTORVEHICLE_H
