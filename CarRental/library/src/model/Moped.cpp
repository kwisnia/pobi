//
// Created by student on 25.04.2020.
//

#include "model/Moped.h"
using namespace std;
Moped::Moped(const string &plateNumber, const int &basePrice, int engineDisplacement)
        : MotorVehicle(plateNumber, basePrice, engineDisplacement) {}

unsigned int Moped::getActualRentalPrice() {
    return MotorVehicle::getActualRentalPrice();
}

Moped::~Moped() {

}

std::string Moped::getVehicleInfo() {
    ostringstream out;
    out <<"Typ pojazdu: Motorower"<<endl<<MotorVehicle::getVehicleInfo();
    return out.str();
}
