//
// Created by student on 29.04.2020.
//

#include "repositories/VehicleRepository.h"
using namespace std;
VehicleRepository::VehicleRepository() {}

VehicleRepository::~VehicleRepository() {
}
void VehicleRepository::add(VehiclePtr c) {
        VehicleRepo.push_back(c);
}

int VehicleRepository::RepoSize() {
    return VehicleRepo.size();
}

_List_iterator<shared_ptr<Vehicle>> VehicleRepository::begin() {
    return VehicleRepo.begin();
}

_List_iterator<shared_ptr<Vehicle>> VehicleRepository::end() {
    return VehicleRepo.end();
}