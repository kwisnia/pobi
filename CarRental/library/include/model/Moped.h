//
// Created by student on 25.04.2020.
//

#ifndef CARRENTAL_MOPED_H
#define CARRENTAL_MOPED_H

#include "model/MotorVehicle.h"

class Moped : public MotorVehicle {
public:
    Moped(const std::string &plateNumber, const int &basePrice, int engineDisplacement);

    unsigned int getActualRentalPrice() override;

    virtual ~Moped();

    std::string getVehicleInfo() override;
};


#endif //CARRENTAL_MOPED_H
