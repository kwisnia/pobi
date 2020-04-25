//
// Created by student on 18.04.2020.
//

#include "model/Vehicle.h"
using namespace std;

Vehicle::Vehicle(const std::string &plateNumber, const unsigned int &basePrice) : plateNumber(plateNumber),
                                                                           basePrice(basePrice) {}

const std::string &Vehicle::getPlateNumber() const {
    return plateNumber;
}

void Vehicle::setPlateNumber(const std::string &plateNumber) {
    if(plateNumber.length()!=0)
    Vehicle::plateNumber = plateNumber;
}

const unsigned int Vehicle::getBasePrice() const {
    return basePrice;
}

void Vehicle::setBasePrice(const unsigned int &basePrice) {
    Vehicle::basePrice = basePrice;
}
std::string Vehicle::getVehicleInfo()
{
    ostringstream out;
    out << plateNumber<<" "<<basePrice;
    return out.str();
}

bool Vehicle::isRented() const {
    return rented;
}

void Vehicle::setRented(bool rented) {
    Vehicle::rented = rented;
}

Vehicle::~Vehicle() {

}

