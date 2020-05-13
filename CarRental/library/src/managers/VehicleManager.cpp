//
// Created by student on 03.05.2020.
//

#include "managers/VehicleManager.h"
#include <iostream>
using namespace std;
list<VehiclePtr> VehicleManager::findAll(VehiclePredicate check) {
    list<VehiclePtr > found;
    for (list<VehiclePtr>::const_iterator iter = this->vehicleRepository->begin(),
                 end = this->vehicleRepository->end();
         iter != end;
         ++iter)
    {
        if(check(*iter))
            found.push_back(*iter);
    }
    return found;
}

std::string VehicleManager::report() {
    ostringstream out;
    for (list<VehiclePtr>::const_iterator iter = this->vehicleRepository->begin(),
                 end = this->vehicleRepository->end();
         iter != end;
         ++iter)
    {
        out << (*iter)->getVehicleInfo()<<endl;
    }
    return out.str();
}

VehiclePtr VehicleManager::find(VehiclePredicate check) {
    for (list<VehiclePtr>::const_iterator iter = this->vehicleRepository->begin(),
                 end = this->vehicleRepository->end();
         iter != end;
         ++iter)
    {
        if(check(*iter))
            return *iter;
    }
    return nullptr;
}

VehiclePtr VehicleManager::registerBicycle(string plateNumber, int basePrice) {
    VehiclePtr repeatCheck=find([plateNumber](VehiclePtr c){return c->getPlateNumber()==plateNumber;});
    if (repeatCheck != nullptr)
        return nullptr;
    else {
        VehiclePtr newv(new Bicycle(plateNumber, basePrice));
        vehicleRepository->add(newv);
        return newv;
    }}

VehiclePtr VehicleManager::registerMoped(string plateNumber, int basePrice, int engineDisplacement) {
    VehiclePtr repeatCheck=find([plateNumber](VehiclePtr c){return c->getPlateNumber()==plateNumber;});
    if (repeatCheck != nullptr)
        return nullptr;
    else {
        VehiclePtr newm(new Moped(plateNumber, basePrice,engineDisplacement));
        vehicleRepository->add(newm);
        return newm;
    }
}

VehiclePtr VehicleManager::registerCar(string plateNumber, int basePrice, int engineDisplacement, Car::segmentType segment) {
    VehiclePtr repeatCheck=find([plateNumber](VehiclePtr c){return c->getPlateNumber()==plateNumber;});
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

VehiclePtr VehicleManager::getVehicle(string plateNumber) {
    return find([plateNumber](VehiclePtr c){return c->getPlateNumber()==plateNumber;});
}

unsigned int VehicleManager::RepoSize() {
    return vehicleRepository->RepoSize();
}

