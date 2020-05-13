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
#include "Repository.h"

class VehicleRepository : public Repository<Vehicle>  {
public:
        VehicleRepository();
        virtual ~VehicleRepository();
};


#endif //CARRENTAL_VEHICLEREPOSITORY_H
