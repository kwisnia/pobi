//
// Created by student on 19.05.2020.
//

#ifndef CARRENTAL_VEHICLEEXCEPTION_H
#define CARRENTAL_VEHICLEEXCEPTION_H
#include <stdexcept>


class VehicleException : public std::logic_error {
public:
    explicit VehicleException(const char* what);
};


#endif //CARRENTAL_VEHICLEEXCEPTION_H
