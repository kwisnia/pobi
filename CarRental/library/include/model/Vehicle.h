//
// Created by student on 18.04.2020.
//

#ifndef CARRENTAL_VEHICLE_H
#define CARRENTAL_VEHICLE_H
#include <iostream>
#include <string>
#include <sstream>
#include "model/typedefs.h"
#include "exceptions/VehicleException.h"

class Vehicle {
private:
    std::string plateNumber;
    unsigned int basePrice;
    bool isArchive=false;
public:
    bool isArchive1() const;

    void setIsArchive(bool isArchive);

    Vehicle(const std::string &plateNumber, const int &basePrice);

    const std::string &getPlateNumber() const;

    void setPlateNumber(const std::string &plateNumber);

    const unsigned int getBasePrice() const;

    void setBasePrice(const int &basePrice);

    virtual ~Vehicle();

    virtual std::string getVehicleInfo();

    virtual unsigned int getActualRentalPrice() = 0;

};


#endif //CARRENTAL_VEHICLE_H
