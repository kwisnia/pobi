//
// Created by student on 29.04.2020.
//

#ifndef CARRENTAL_UTILS_H
#define CARRENTAL_UTILS_H
#include "repositories/ClientRepository.h"
#include "repositories/RentRepository.h"
#include "repositories/VehicleRepository.h"
#include "model/Car.h"
#include "model/Bicycle.h"

void fillRepos(ClientRepository* CR, VehicleRepository* VR, RentRepository* RR);

#endif //CARRENTAL_UTILS_H
