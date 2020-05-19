//
// Created by student on 25.04.2020.
//

#include "model/Bicycle.h"
using namespace std;
unsigned int Bicycle::getActualRentalPrice() {
    return basePrice;
}

Bicycle::Bicycle(const string &plateNumber, const int &basePrice) : Vehicle(plateNumber, basePrice) {}

Bicycle::~Bicycle() {

}
std::string Bicycle::getVehicleInfo() {
        ostringstream out;
        out <<"Typ pojazdu: Rower"<<endl<<Vehicle::getVehicleInfo();
        return out.str();
}
