//
// Created by student on 25.04.2020.
//

#ifndef CARRENTAL_CAR_H
#define CARRENTAL_CAR_H

#include "model/MotorVehicle.h"

class Car : public MotorVehicle {
public:
    enum segmentType{
        A,
        B,
        C,
        D,
        E
    };
private:
    segmentType segment;
public:
    Car(const std::string &plateNumber, const int &basePrice, int engineDisplacement,
        segmentType segment);

    virtual ~Car();

    unsigned int getActualRentalPrice() override;

    segmentType getSegment() const;

    void setSegment(segmentType segment);

    std::string getVehicleInfo() override;
};


#endif //CARRENTAL_CAR_H
