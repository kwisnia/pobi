//
// Created by student on 03.05.2020.
//

#include "managers/VehicleManager.h"
#include <iostream>
using namespace std;
VehiclePtr VehicleManager::registerBicycle(string& plateNumber, int basePrice) {
    VehiclePtr repeatCheck=vehicleRepository->find([plateNumber](VehiclePtr c){return c->getPlateNumber()==plateNumber;});
    if (repeatCheck != nullptr)
        return nullptr;
    else {
        VehiclePtr newc(new Bicycle(plateNumber, basePrice));
        vehicleRepository->add(newc);
        return newc;
    }}

VehiclePtr VehicleManager::registerMoped(string& plateNumber, int basePrice, int engineDisplacement) {
    VehiclePtr repeatCheck=vehicleRepository->find([plateNumber](VehiclePtr c){return c->getPlateNumber()==plateNumber;});
    if (repeatCheck != nullptr)
        return nullptr;
    else {
        VehiclePtr newc(new Moped(plateNumber, basePrice,engineDisplacement));
        vehicleRepository->add(newc);
        return newc;
    }
}

VehiclePtr VehicleManager::registerCar(string& plateNumber, int basePrice, int engineDisplacement, Car::segmentType segment) {
    VehiclePtr repeatCheck=vehicleRepository->find([plateNumber](VehiclePtr c){return c->getPlateNumber()==plateNumber;});
    if (repeatCheck != nullptr)
        return nullptr;
    else {
        VehiclePtr newc(new Car(plateNumber, basePrice,engineDisplacement,segment));
        vehicleRepository->add(newc);
        return newc;
    }}

void VehicleManager::unregisterVehicle(VehiclePtr v) {
    if (v->isArchive1())
        cout << "Pojazd jest juz odrejestrowany"<<endl;
    else
        v->setIsArchive(true);
}

VehiclePtr VehicleManager::getVehicle(string& plateNumber) {
    return vehicleRepository->find([plateNumber](VehiclePtr c){return c->getPlateNumber()==plateNumber;});
}
