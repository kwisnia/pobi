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
        VehicleRepository();
        virtual ~VehicleRepository();
        void add(VehiclePtr);
        int RepoSize();
        std::_List_iterator<std::shared_ptr<Vehicle>> begin();
        std::_List_iterator<std::shared_ptr<Vehicle>> end();

};


#endif //CARRENTAL_VEHICLEREPOSITORY_H
