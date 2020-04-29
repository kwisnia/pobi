//
// Created by student on 29.04.2020.
//

#ifndef CARRENTAL_VEHICLEREPOSITORY_H
#define CARRENTAL_VEHICLEREPOSITORY_H

#include <list>
#include "model/Vehicle.h"
typedef Vehicle* vehicleptr ;
class VehicleRepository {
    private:
        std::list<vehicleptr> VehicleRepo;
    public:
        VehicleRepository();
        virtual ~VehicleRepository();
        vehicleptr get(unsigned int&);
        unsigned int size();
        void add(vehicleptr);
        std::list<vehicleptr> find(bool (*fun)(vehicleptr));
        std::string report();
    };


#endif //CARRENTAL_VEHICLEREPOSITORY_H
