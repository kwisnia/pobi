//
// Created by student on 29.04.2020.
//

#ifndef CARRENTAL_VEHICLEREPOSITORY_H
#define CARRENTAL_VEHICLEREPOSITORY_H

#include <list>
#include "model/Vehicle.h"
#include "model/Moped.h"
#include "model/Bicycle.h"
#include "model/Car.h"

class VehicleRepository {
    private:
        std::list<VehiclePtr> VehicleRepo;
public:
    const std::list<VehiclePtr> &getVehicleRepo() const;

public:
        VehicleRepository();
        virtual ~VehicleRepository();
        VehiclePtr get(unsigned int&);
        unsigned int size();
        void add(VehiclePtr);
        std::list<VehiclePtr> findAll(VehiclePredicate);
        VehiclePtr find(VehiclePredicate);
        std::string report();
    };


#endif //CARRENTAL_VEHICLEREPOSITORY_H
