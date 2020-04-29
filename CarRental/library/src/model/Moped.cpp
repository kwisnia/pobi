//
// Created by student on 25.04.2020.
//

#include "model/Moped.h"
using namespace std;
Moped::Moped(const string &plateNumber, const unsigned int &basePrice, unsigned int engineDisplacement)
        : MotorVehicle(plateNumber, basePrice, engineDisplacement) {}

unsigned int Moped::getActualRentalPrice() {
    return ActualRentalPrice();
}

Moped::~Moped() {

}

std::string Moped::getVehicleInfo() {
    ostringstream out;
    out <<"Typ pojazdu: Motorower"<<endl<<"Numer rejestacyjny: "<<plateNumber<<endl<<"Cena bazowa pojazdu: "<<getActualRentalPrice()<<endl<<"Pojemnosc silnika: "<<engineDisplacement<<" cm3"<<endl;
    return out.str();
}
