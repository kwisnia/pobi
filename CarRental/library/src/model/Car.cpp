//
// Created by student on 25.04.2020.
//

#include "model/Car.h"

Car::Car(const std::string &plateNumber, const unsigned int &basePrice, unsigned int engineDisplacement,
         Car::segmentType segment) : MotorVehicle(plateNumber, basePrice, engineDisplacement), segment(segment) {}

Car::~Car() {

}

unsigned int Car::getActualRentalPrice() {
    switch (segment)
    {
        case A:
            return ActualRentalPrice();
            break;
        case B:
            return 1.1*ActualRentalPrice();
            break;
        case C:
            return 1.2*ActualRentalPrice();
            break;
        case D:
            return 1.3*ActualRentalPrice();
            break;
        case E:
            return 1.5*ActualRentalPrice();
            break;
    }
    return 0;
}

Car::segmentType Car::getSegment() const {
    return segment;
}

void Car::setSegment(Car::segmentType segment) {
    Car::segment = segment;
}
