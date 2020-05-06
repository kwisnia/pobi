//
// Created by student on 29.04.2020.
//

#ifndef CARRENTAL_UTILS_H
#define CARRENTAL_UTILS_H
#include "managers/ClientManager.h"
#include "managers/RentManager.h"
#include "managers/VehicleManager.h"
#include "model/Car.h"
#include "model/Bicycle.h"


void fillRepos(ClientManagerPtr, VehicleManagerPtr, RentManagerPtr);

#endif //CARRENTAL_UTILS_H
