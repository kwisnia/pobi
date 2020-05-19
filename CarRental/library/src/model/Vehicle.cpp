//
// Created by student on 18.04.2020.
//

#include "model/Vehicle.h"
using namespace std;

Vehicle::Vehicle(const string &plateNumber, const int &basePrice) try: plateNumber(plateNumber),
                                                                           basePrice(basePrice) {
    if (basePrice<0)
        throw VehicleException("Podano ujemna cene bazowa pojazdu");
}
catch (const VehicleException& ex)
{
    cout << "Wystapil blad!"<<endl;
    cout << ex.what()<<endl;
}
const string &Vehicle::getPlateNumber() const {
    return plateNumber;
}

void Vehicle::setPlateNumber(const string &plateNumber) {
    try {
        if (plateNumber.length() != 0)
            Vehicle::plateNumber = plateNumber;
        else
            throw VehicleException("Wprowadzono puste pole!");
    }
    catch (const VehicleException& ex) {
        cout << "Wystapil problem: "<<endl;
        cout << ex.what()<<endl;
        throw;
    }
}

const unsigned int Vehicle::getBasePrice() const {
    return basePrice;
}

void Vehicle::setBasePrice(const int &basePrice) {
    try{
    if (basePrice<0)
        throw VehicleException("Podana cena jest ujemna!");
    else
    Vehicle::basePrice = basePrice;}
    catch (const VehicleException& ex) {
        cout << "Wystapil problem: "<<endl;
        cout << ex.what()<<endl;
    }
}

Vehicle::~Vehicle() {

}

bool Vehicle::isArchive1() const {
    return isArchive;
}

void Vehicle::setIsArchive(bool isArchive) {
    Vehicle::isArchive = isArchive;
}
std::string Vehicle::getVehicleInfo() {
    ostringstream out;
    out << "Numer rejestracyjny pojazdu: " << plateNumber << endl << "Cena bazowa pojazdu: " << basePrice << endl;
    return out.str();
}
