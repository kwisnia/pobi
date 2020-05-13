//
// Created by student on 03.05.2020.
//

#ifndef CARRENTAL_VEHICLEMANAGER_H
#define CARRENTAL_VEHICLEMANAGER_H
#include "repositories/VehicleRepository.h"

class VehicleManager {
private:
    VehicleRepoPtr vehicleRepository=std::make_shared<VehicleRepository>();
public:
    VehiclePtr registerBicycle(std::string,int);
    VehiclePtr registerMoped(std::string,int,int);
    VehiclePtr registerCar(std::string, int, int, Car::segmentType);
    void unregisterVehicle(VehiclePtr);
    VehiclePtr getVehicle(std::string);
    std::list<VehiclePtr> findAll(VehiclePredicate);
    VehiclePtr find(VehiclePredicate);
    std::string report();
    unsigned int RepoSize();
};


#endif //CARRENTAL_VEHICLEMANAGER_H
