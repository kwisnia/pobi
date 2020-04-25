//
// Created by student on 18.04.2020.
//

#ifndef CARRENTAL_VEHICLE_H
#define CARRENTAL_VEHICLE_H
#include <iostream>
#include <string>
#include <sstream>

class Vehicle {
protected:
    std::string plateNumber;
    unsigned int basePrice;
    bool rented=false;
public:
    bool isRented() const;

    void setRented(bool rented);

public:
    Vehicle(const std::string &plateNumber, const unsigned int &basePrice);

    const std::string &getPlateNumber() const;

    void setPlateNumber(const std::string &plateNumber);

    const unsigned int getBasePrice() const;

    void setBasePrice(const unsigned int &basePrice);

    virtual ~Vehicle();

    std::string getVehicleInfo();

    virtual unsigned int getActualRentalPrice() = 0;
};


#endif //CARRENTAL_VEHICLE_H
